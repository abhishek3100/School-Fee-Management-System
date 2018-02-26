//school fee management system- Trial 1
#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
char ch,choice;
class Fee
{
	private:
		int Class;
		float Tution,Facility,Science,Computer,Activity;
		void display(int);
		void modify_record(int,float,float,float,float,float);
	public:
		void addition(void);
		void modification(void);
		void feeslip(void);
		void list(void);
		void help(void);	
}fee1;
void mainmenu()
{
	cout<<"\n\n\tSelect Your Choice By Pressing Desire Key :\t"<<endl;
	cout<<"\n\n\t\tF. FEE SLIP"<<"\t\t\tM. MODIFY"<<endl;
	cout<<"\n\t\tL. LIST"<<"\t\t\t\tH. HELP"<<endl;
	cout<<"\n\t\tE. EXIT\n\t";
	choice=getch();
	ch=toupper(choice);
	switch(ch)
	{
		case 'F':
			fee1.feeslip();
			break;
		case 'M':
			fee1.modification();
			break;
		case 'L':
			fee1.list();
		case 'H':
			fee1.help();
			break;
		case 'E':
			exit(0);
			break;
		default:
			cout<<"\n\n\t\t\tWrong Input!! Please Check Input\n\t";
		getch();
		mainmenu();			
					
	}
}
//End of main menu
//*****FUNCTION TO ADD FEE 
void Fee::addition(void)
{
	fstream file;
	file.open("Add.txt",ios::in);
	if(!file.fail())
	file.close();
	file.open("Add.txt",ios::app);
	for(int i=1;i<=12;i++)
	{
		Class = i;
		Tution = 0.0;
		Facility = 0.0;
		Science = 0.0;
		Computer = 0.0;
		Activity = 0.0;
	file.write((char*)this,sizeof(Fee));	
	}
	file.close();
	modify_record(12,450,50,60,60,50);
	modify_record(11,450,50,60,60,50);
	modify_record(10,350,50,30,60,50);
	modify_record(9,350,50,30,60,50);
	modify_record(8,350,50,20,40,50);
	modify_record(7,300,50,20,40,50);
	modify_record(6,300,50,20,40,50);
	modify_record(5,250,50,0,40,40);
	modify_record(4,250,50,0,40,40);
	modify_record(3,250,50,0,40,40);
	modify_record(2,250,50,0,40,40);
	modify_record(1,250,50,0,40,40);
}
//FUNCTION TO DISPLAY TOTAL FEE AS LIST
void Fee::list()
{
	cout<<"\n\n\t\tTotal Fee For The Classes :"<<endl;
	float total;
	int row=8;
	fstream file;
	file.open("Fee.txt",ios::in);
	while(file.read((char*)this,sizeof(Fee)))
	{
		total = Tution+Facility+Science+Computer+Activity;
		cout<<"\n\t"<<Class;
		cout<<"\t"<<total;
		row++;
	}
	file.close();
	cout<<"\n\n\t\t\t\t\t\tPress Any Key To Continue...";
	getch();
	mainmenu();
}
//Function to display the record for the given class
void Fee::display(int tclass)
{
	fstream file;
	file.open("Fee.txt",ios::in);
	while(file.read((char*)this,sizeof(Fee)))
	{
		if(Class==tclass)
		{
			cout<<"Class :\t\t\t"<<Class<<endl;
			cout<<"-----------------------------------"<<endl;
			cout<<"Tution Fee:\t\t"<<Tution<<endl;
			cout<<"Annual Charge Fee:\t\t"<<Facility<<endl;
			cout<<"Science Fee:\t\t"<<Science;
			cout<<"Computer Fee:\t\t"<<Computer;
			cout<<"Activity Fee: \t\t"<<Activity;
			break;
		}
	}
	file.close();
}	
//function to modify the fee record

void Fee::modify_record(int tclass,float ttution,float tfacility,float tscience,float tcomputer, float tactivity)
{
	fstream file;
	file.open("Fee.txt",ios::in);
	fstream temp;
	temp.open("temp.txt",ios::out);
	file.seekg(0,ios::beg);
	while (!file.eof())
	{
		file.read((char*)this,sizeof(Fee));
		if(file.eof())
		break;
		if(tclass==Class)
		{
			Class=tclass;
			Tution=ttution;
			Facility=tfacility;
			Science=tscience;
			Activity=tactivity;
			temp.write((char*)this,sizeof(Fee));
		}
		else
		temp.write((char*)this,sizeof(Fee));
	}
	file.close();
	temp.close();
	file.open("Fee.txt",ios::out);
	temp.open("temp.txt",ios::in);
	temp.seekg(0,ios::beg);
	while(!temp.eof())
	{
		temp.read((char*)this,sizeof(Fee));
		if(temp.eof())
		break;
		file.write((char*)this,sizeof(Fee));
	}
	file.close();
	temp.close();
}
//function to give data to modify the fee record
void Fee::modification(void)
{
	char ch,t1[10];
	int valid=0,t=0,tclass=0;
	float t2=0;
	do
	{
		valid=1;
		cout<<"\n\t\tPress'ENTER or RETURN' to EXIT";
		cout<<"\n\n\n\t\tEnter class for the modification of the fee structure :\t";
		gets(t1);
		t=atoi(t1);
		tclass=t;
		if(strlen(t1)==0)
		return;
		if(tclass<1||tclass>12)
		{
			valid=0;
			cout<<"\n\n\t\tError! Please Check Input /---\t";
			getch();
		}
	}
		while(!valid);
		cout<<"<0> =EXIT";
		display(tclass);
		do
		{
			cout<<"\n\n\t\tDo you want to modify the fee structure (Press 'Y' for Yes 'N' for No)";
			ch=getche();
			if(ch=='0')
			return;
			ch=toupper(ch);
		}
		while(ch!='N'&& ch!='Y');
		if(ch=='N')
		mainmenu();
		float ttution=0.0,tfacility=0.0,tscience=0.0,tcomputer=0.0,tactivity=0.0;
		cout<<"\n\tTution Fee :\t";
		cout<<"\n\tFacility Fee:\t";
		cout<<"\n\tScience Fee :\t";
		cout<<"\n\tComputer Fee :\t";
		cout<<"\n\tActivity Fee :\t";
		int modified=5;
		fstream file;
		file.open("Fee.txt",ios::in);
		while(file.read((char*)this,sizeof(Fee)))
		if(Class==tclass)
		break;
		file.close();
		do
		{
			valid=1;
			cout<<"\n\n\t\tEnter TUTION FEE or <ENTER> for no change";
			gets(t1);
			t2=atof(t1);
			ttution =t2;
			if(t1[0]=='0')
			return;
			if(strlen(t1)==0)
			break;
			if(ttution>1000)
			{
				valid=0;
				cout<<"\n\t\aEnter Correctly";
				getch();
			}
		}
			while (!valid);
			if(strlen(t1)==0)
			{
				modified--;
				ttution=Tution;
				cout<<ttution;
			}
			do
			{
				valid=1;
				cout<<"\n\tEnter Facility Fee";
				gets(t1);
				t2=atof(t1);
				tfacility=t2;
				if(t1[0]=='0')
				return;
				if(strlen(t1)==0)
				break;
				if(tfacility>1000)
				{
					valid=0;
					cout<<"\n\tEnter Correctly";
					getch();
				}
			}
			while(!valid);
			if(strlen(t1)==0)
			{
				modified--;
				tfacility=Facility;
				cout<<"\n\t"<<Facility;
			}
			do
			{
				valid=1;
				cout<<"\n\tEnter Science Fee";
				gets(t1);
				t2=atof(t1);
				tscience=t2;
				if(t1[0]=='0')
				return;
				if(strlen(t1)==0)
				break;
				if(tscience>1000)
				{
					valid=0;
					cout<<"\n\tEnter Correctly";
					getch();
				}
			}
			while(!valid);
			if(strlen(t1)==0)
			{
				modified--;
				tscience=Science;
				cout<<tscience;
			}
			do
			{
				valid=1;
				cout<<"Enter Computer Fee";
				gets(t1);
				t2=atof(t1);
				tcomputer=t2;
				if(t1[0]=='0')
				return ;
				if(strlen(t1)==0)
				break;
				if(tcomputer>1000)
				{
					valid=0;
					cout<<"\n\tEnter Correctly";
					getch();
				}
			}
				while(!valid);
				if(strlen(t1)==0)
				{
					modified--;
					tcomputer=Computer;
					cout<<tcomputer;
				}
				do
				{
					valid=1;
					cout<<"\n\tEnter Activity Fee";
					gets(t1);
					t2=atof(t1);
					tactivity=t2;
					if(t1[0]=='0')
					return;
					if(strlen(t1)==0)
					break;
					if(tactivity>1000)
					{
						valid=0;
						cout<<"\n\tEnter Correctly";
						getch();
					}
				}
				while(!valid);
				if(strlen(t1)==0)
				{
					modified--;
					tactivity=Activity;
					cout<<tactivity;
				}
				if(!modified)
				mainmenu();
				do
				{
					cout<<"\n\tDo you want to save(y/n):\t";
					ch=getche();
					if(ch=='0');
					return;
					ch=toupper(ch);
					
				}
				while(ch!='N'&& ch!='Y');
				if(ch=='N')
				return;
				modify_record(tclass,ttution,tfacility,tscience,tcomputer,tactivity);
				cout<<"\n\tRecord Modified";
				cout<<"\n\tPress any key to continue......";
				getch();
				mainmenu();
}
//function to display fee slip
void Fee::feeslip(void)
{
	char ch,t1[10];
	int valid=0,t=0,tclass=0;
	do
	{
		valid=1;
		cout<<"\n\t<Press ENTER for EXIT";
		cout<<"\n\n\tEnter Class to see the fee structure:\t";
		gets(t1);
		t=atoi(t1);
		tclass=t;
		if(strlen(t1)==0)
		return;
		if(tclass<1||tclass>12)
		{
			valid=0;
			cout<<"\n\tEnter Correctly:";
			getch();
		}
	}
	while(!valid);
	char name[30];
	do
	{
		cout<<"\n\tEnter Name of Student:\t";
		valid=1;
		cout<<"\nName :\t";
		gets(name);
		if(strlen(name)<1||strlen(name)>29)
		{
			valid=0;
			cout<<"\n\tName Should Not Be Greater Than 29";
			getch();
		}
	}
	while(!valid);
	cout<<"\n\t\t\tSCHOOL NAME  "<<endl;
	int d1,m1,y1;
	time_t td=time(0);
	struct tm*now=localtime(&td);
	d1=now->tm_mday;
	m1=(now->tm_mon +1);
	y1=(now->tm_year +1900);
	cout<<"Date : "<<d1<<"/"<<m1<<"/"<<y1<<endl;
	cout<<"Name :"<<name<<endl;
	cout<<"Class:"<<tclass<<endl;
	cout<<"Particular Amount"<<endl;
	cout<<"Total"<<endl;
	cout<<"Cashier"<<endl;
	fstream file;
	file.open("Fee.txt",ios::in);
	while(!file.eof())
	{
		file.read((char *)this,sizeof(Fee));
		if(Class==tclass)
		{
			cout<<"Found"<<endl;
			break;
		}
		file.close();
	}
	float total=0.0;
	cout<<"Tution Fees"<<setprecision(2)<<Tution;
	total=total+Tution;
	cout<<"Facility Fee"<<setprecision(2)<<Facility;
	total=total+Facility;
	cout<<"Science Fee"<<setprecision(2)<<Science;
	total=total+Science;
	cout<<"Computer Fee"<<setprecision(2)<<Computer;
	total=total+Computer;
	cout<<"Activity Fee"<<setprecision(2)<<Activity;
	total=total+Activity;
	cout<<"Press Any Key to Return To Main Menu....";
	getch();
	mainmenu();	
}	
void Fee::help()
{
	cout<<"\t\tHello Welcome to this School Fee Management System"<<endl;
	cout<<"\t\tThis Program is made by using C++";
	cout<<"\nIt can be compiled on any compiler";
	cout<<"\nFor More contact administration";
	cout<<"\n\n\t\tPress any key to go back to mainmenu...";
	getch();
	mainmenu();
}		
		
int main()
{
	Fee fee1;
	cout<<"\t\t\t\tWelcome To School Fee Management"<<endl;
	cout<<"\n\nPress Any Key TO Continue..."<<endl;
	getch();
	mainmenu();
	return 0;
	
}
