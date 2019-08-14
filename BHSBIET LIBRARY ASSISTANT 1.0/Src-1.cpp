#include<iostream>
#include<conio.h>
#include<fstream>         //For File I/O
#include<Windows.h>      //for Sleep() function
#include<ctype.h>       //FOR-strlen();
#include<time.h>       //for time
#include<process.h>   //_beginthread() function
#include<direct.h>    // for mkdir()
#include<strsafe.h>
#include<iomanip>
#include"Header.h"    //Function Protype Collections

using namespace std;

 int choice=0,scount=0,bookcounter=0,numberofstudents=0,ctr,ctr2, length, currentclass=0, students, globalstudentcounter=0,count=0,acbooks=0,nl(0),ar[150],o(0),a(0),b(0) ,knt(0),shelf=0,lock=0,personalcounter,i=0, j=0,getnoofstudents(),lock_status(1); 
 char ans,var,var1,var2,var3,g,h,lg,lo, currentc[3],m1,var4,var5,var6,var7,var8,q_1,q_2,q_3,q_4;
 ifstream fin, bin, kin,din,ein;                 //fin for student data file input and bin for book data input 
 ofstream fout, bout, tout,dout, sout;          //fin for student data file output and bin for book data output 
     
class student                          
{
	public:
	 int roll;
	 char name[35];
	 char Class[4];
	 char Blood_Group[16];   //Capable of storing string "NOT AVAILABLE"
	 char Address[100];
	 int CurrentBookNumber;
	 long int regno;
	 int currentc;
	 int day,month,year;
	 int total_books_used;
	 char mobile[15];
	 student()
	 {
		 total_books_used=0;
		 CurrentBookNumber=0;
		 ::count++;
	 }
	 void AddStudent()
	 {
		 int CheckStudent(int);
		 void SaveStudentData();
		 int flag=1, status=1;
		 system("CLS");
	     cout<<"\t\t\t\t\t\t**************************************\n";
         cout<<"\t\t\t\t\t\t      ADD A NEW STUDENT TO DATABASE\n";
	     cout<<"\t\t\t\t\t\t**************************************\n";
		 cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
		 cout<<"\nCAUTION !:ALWAYS MAKE SURE YOU ARE ENTERING THE CORRECT DATA.....";
		 cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
		 int check=0;
		 cout<<"\n [Class Roll Number]      :";
		  try{
			 cin>>check;  }catch (exception){cout<<"Error Occured !!";_getch();} 
		 status=CheckStudent(check);
		 if(status)
		 {
		  roll=check;
		  cout<<"\n [Enter Name]\t\t  :";
		  cin.ignore();
		  gets_s(name);
		  ChangeToUpper(name);
		  if(!cin)
		  {
			 cout<<"\n\n Input Failed, Can't continue......Exiting Program, Sorry !!!! ";
			 Sleep(1000);
			 exit(0);
		 }
		 switch(currentclass)
		 {
		 case 1:
			     currentc=1;
			     break;
		  case 2:
			     currentc=2;
			     break;
		  case 3:
			  currentc=3;
			     break;
		  case 4:
			  currentc=4;
			     break;
		  case 5:
			  currentc=5;
			     break;
		  case 6:
			  currentc=6;
			     break;
		  case 7:
			  currentc=7;
			     break;
		  case 8:
			  currentc=8;
			     break;
		  case 9:
			  currentc=9;
			     break;
		  case 10:
			  currentc=10;
			     break;
		  case 11:
			 currentc=11;
			     break;
		  case 12:
			  currentc=12;
			     break;
		  case 13:
			  currentc=13;
			     break;
		  case 14:
			  currentc=14;
			     break;
		  case 15:
			  currentc=15;
			     break;
		  case 16:
			 currentc=16;
			     break;
		  case 17:
			  currentc=17;
			     break;
		 }
	

		 cout<<"\n [Register Number]\t  :";
		 try{
			 cin>>regno;  }catch (exception){cout<<"Error Occured !!";}   //Assigning a unique number ID for each student
		 cout<<"\n [ENTER BLOOD GROUP]\t  :";
		 cin.ignore();
		 gets_s(Blood_Group);
		 cout<<"\n [ENTER ADDRESS]\t  :";
		 gets(Address);
		 ChangeToUpper(Address);
		 cout<<"\n [ENTER MOBILE]\t\t :";
		 gets(mobile);
		 CurrentBookNumber=0;
		 SaveStudentData();
		 SaveLog(name,currentc,roll);
		 }
	 }
	 void PrintStudent()
	 {   int d=Countnoofdays();
		 cout<<"\n\n Name                :"<<name;
		 cout<<"\n Class               :";getclass(currentclass);
		 cout<<"\n Roll                :"<<roll;
		 cout<<"\n Register No         :"<<regno;
		 cout<<"\n Address             :"<<Address;
		 cout<<"\n Blood Group         :"<<Blood_Group;
		 cout<<"\n Mobile Number       :"<<mobile;
		 cout<<"\n Current book Number :";(CurrentBookNumber==0)?cout<<"NO BOOK TAKEN":cout<<CurrentBookNumber<<"\n Date of Book Taken  :"<<day<<"/"<<month<<"/"<<year;
		 if(CurrentBookNumber)
		 {
		  cout<<"\n Total Days Used     :";cout<<d<<endl;
		 }
		 cout<<"\n\n UNTIL NOW, "<<name<<" USED "<<total_books_used<<" BOOK(S) FROM THIS LIBRARY "; 
		 cout<<"\n\n-----------------------------------------------------------------";
		
	 }
	 void PrintStudent2()
	 {
		 cout<<"\n Name        :"<<name;
		 cout<<"\n Roll        :"<<roll;
		 cout<<"\n Register No :"<<regno;
		 cout<<"\n Current book Number :";(CurrentBookNumber==0)?cout<<"NO BOOK TAKEN\n":cout<<CurrentBookNumber<<endl;
		 cout<<"-----------------------------------------------------------------";
	 }
	 void PrintStudentToFile()
	 {
		 length=strlen(name);
		 if(length>4 && length<13)
		  {
			  tout<<"\n\t   "<<name<<"\t\t "<<roll<<"\t   "<<regno<<"\t\t";(CurrentBookNumber==0)?tout<<"No Book\t\t":tout<<CurrentBookNumber;
		  }
		 else if(length<=4)
		 {
          tout<<"\n\t   "<<name<<"\t\t\t "<<roll<<"\t   "<<regno<<"\t\t";(CurrentBookNumber==0)?tout<<"No Book\t\t":tout<<CurrentBookNumber;
		 }
		 else if(length>=13)
		 {
		  tout<<"\n   ";tout.write(name, 15);tout<<"..\t\t "<<roll<<"\t   "<<regno<<"\t\t";(CurrentBookNumber==0)?tout<<"No Book\t\t":tout<<CurrentBookNumber;
		 }

		 if(CurrentBookNumber)
		 {
			 tout<<"\t  "<<day<<"/"<<month<<"/"<<year<<"[ "<<(Countnoofdays())<<" ]";
		 }
		 tout<<" : -";putclass(currentc);tout<<endl;
	 }
	 void PrintTable()   //to print 'view all student' option table
	 {
		 length=strlen(name);
		 if(length>4 && length<13)
		  {
			  cout<<"\n\t   "<<name<<"\t\t "<<roll<<"\t   "<<regno<<"\t\t";(CurrentBookNumber==0)?cout<<"-NIL-":cout<<""<<CurrentBookNumber;
		  }
		 else if(length<=4)
		 {
          cout<<"\n\t   "<<name<<"\t\t\t "<<roll<<"\t   "<<regno<<"\t\t";(CurrentBookNumber==0)?cout<<"-NIL-":cout<<""<<CurrentBookNumber;
		 }
		 else if(length>=13)
		 {
		  cout<<"\n   ";cout.write(name, 15);cout<<"..\t\t "<<roll<<"\t   "<<regno<<"\t\t";(CurrentBookNumber==0)?cout<<"-NIL-":cout<<""<<CurrentBookNumber;
		 }

		 if(CurrentBookNumber)
		 {
			 cout<<"\t  "<<day<<"/"<<month<<"/"<<year<<"["<<(Countnoofdays())<<"]"<<"\n";
		 }
		 else
			 cout<<"\t     - NIL - \n";
	 }
	 void PrintTable3()
	 {
		 length=strlen(name);
		 if(1)
		  {
			  cout<<"\n\t  "<<roll<<"\t\t "<<regno<<"\t\t"<<CurrentBookNumber<<"\t     "<<day<<"/"<<month<<"/"<<year<<"\t\t"<<Countnoofdays();
		  }
	 }
	 void SetDate()
	 {
		 void ShowDate();
	  time_t t = time(0);   // get time now
      struct tm * now = localtime(& t);
	  int yearo=now->tm_year + 1900;
	  int montho=now->tm_mon + 1;
	  int dayo=now->tm_mday;
	  ShowDate();
	  day=dayo;
	  month=montho;
	  year=yearo;
	  cout<<"\n Date Saved !";
	 }
	 void DeleteDate()
	 {
		 day=0, month=0, year=0;
	 }
	 int  Countnoofdays()
	 {
	  time_t t = time(0);   // get time now
      struct tm * now = localtime( & t );
	  int yearo=now->tm_year + 1900;
	  int montho=now->tm_mon + 1;
	  int dayo=now->tm_mday;
	  int nday,nmonth,nyear=yearo-year;
	  if(nyear)
	  {
		  int kp=nyear--;
		  nmonth=(kp*12)+montho+(12-month);
	  }
	  else 
		  nmonth=montho-month;

	  if(nmonth)
	  {
		  int mp=nmonth-1;
		  nday=(30-day)+(mp*30)+dayo;
	  }
	  else
		  nday=dayo-day;
	  return nday;
	 }
	 void PrintForReading()
	 {
		 sout<<roll;
		 sout<<name;sout<<"|";
		 sout<<regno;sout<<"|"<<"\n";
		 sout.close();
	 }
	 void ReadFromFile(int u)
	 {
		 ifstream sin;
		if(u)
		{
			sin.seekg(+2, ios::cur);
		}
		sin>>roll;
		sin.seekg(+1, ios::cur);
		sin.getline(name, 30, '\t');
		sin.seekg(+1, ios::cur);
		sin>>regno;
		switch(currentclass)
		 {
		 case 1:
			     currentc=1;
			     break;
		  case 2:
			     currentc=2;
			     break;
		  case 3:
			  currentc=3;
			     break;
		  case 4:
			  currentc=4;
			     break;
		  case 5:
			  currentc=5;
			     break;
		  case 6:
			  currentc=6;
			     break;
		  case 7:
			  currentc=7;
			     break;
		  case 8:
			  currentc=8;
			     break;
		  case 9:
			  currentc=9;
			     break;
		  case 10:
			  currentc=10;
			     break;
		  case 11:
			 currentc=11;
			     break;
		  case 12:
			  currentc=12;
			     break;
		  case 13:
			  currentc=13;
			     break;
		  case 14:
			  currentc=14;
			     break;
		  case 15:
			  currentc=15;
			     break;
		  case 16:
			 currentc=16;
			     break;
		  case 17:
			  currentc=17;
			     break;
		 }
		 CurrentBookNumber=0;
		 SaveStudentData();
	 }
	 void EditData()
	 {
		 int ch;
		 cout<<"n\n WHAT DO YOU WANT TO CHANGE ?  ";
		 cout<<"\n\n\t 1. CHANGE ROLL \t\t 2. CHANGE NAME \n\t 3. CHANGE ADDRESS \t\t 4. CHANGE REG.NO \n\t 5. RETURN \n\n Enter Coice :";
	     ch = _getch();
		 switch(ch)
		 {
		 case 49: int temp, flag;
			      cout<<"\n\n ENTER NEW ROLL :";
				  cin>>temp;
				  flag  = CheckStudent(temp);
			      if(!flag)
					  goto term;
				  roll = temp;
			      cout<<"\n SAVE : (y/n)?";
				  cin>>ans;
				  if(ans=='y'||ans=='Y')
				  {
					  _beginthread(SaveNow,0,(void*)12);
				  }else
					  cout<<"\n ABORTED";
				  break;
		  case 50:cout<<"\n\n ENTER NEW NAME :";
			  cin.ignore();
			      gets_s(name);
				  cout<<"\n SAVE : (y/n)?";
				  cin>>ans;
				  if(ans=='y'||ans=='Y')
				  {
					  _beginthread(SaveNow,0,(void*)12);
				  }else
					  cout<<"\n ABORTED";
				  break;
		  case 51:cout<<"\n\n ENTER NEW ADDRESS:";
			  gets_s(Address);
				  cin>>ans;
				  if(ans=='y'||ans=='Y')
				  {
					  _beginthread(SaveNow,0,(void*)12);
				  }else
					  cout<<"\n ABORTED";
				  break;
		  case 52: cout<<"\n\n ENTER REGISTER NUMBER :";
			       cin>>regno;
				   /*cnti = CheckStudentRegisterNumber(regno);
				   if(!cnti)
					   goto term;*/
				  cout<<"\n SAVE : (y/n)? ";
				  char c;
				  cin>>c;
				  if(c=='y'||c=='Y')
				  {
					  _beginthread(SaveNow,0,(void*)12);
				  }else
					  cout<<"\n ABORTED";
				  break;
		  case 53 :break;
		  default :cout<<"\n INVALID CHOICE !";
	term:;
		 }
	 }

}stu[2000]; 
class Book  //consumes 72 bytes per object
{
public:	
	char author[100];
	char title[100];
	float price;
	char publisher[100];
	int shelf; 
	int currentholdernumber;
	int availability;          //to check whether the book is available at library or not
	int bookno;
	int current_holder;
	void ShowDate();
	friend student;
	Book()   //Constructor
	{
		shelf = 0;
	}
	void AddBook()
     {
	   int CheckBook(int);
	   int status=1;
	   int tempbooknumber=0;
	   system("CLS");
	   cout<<"\t\t\t\t\t\t**************************************\n"; 
       cout<<"\t\t\t\t\t\t       ADD A NEW BOOK TO DATABASE\n";
	   cout<<"\t\t\t\t\t\t**************************************\n";
	   void SaveBook(void *arg);
	   cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
	   cout<<"\nCAUTION !:ALWAYS ENTER CORRECT DATA.....";
	   cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
	   cout<<"\n Enter Book Number   :";
	   cin>>tempbooknumber;
	   if(!cin)
		  {
			 cout<<"\n\n Input Failed, Can't continue......Exiting Program, Sorry !!!! ";
			 Sleep(100);
			 exit(0);
		 }
	   status = CheckBook(tempbooknumber);
	   if(status)
	   {
		bookno=tempbooknumber;
	    cout<<"\n Enter Book Title    :";
		cin.ignore();
	    gets_s(title);
		ChangeToUpper(title);
	    if(!cin)
		  {
			 cout<<"\n\n Input Failed, Can't continue......Exiting Program, Sorry !!!! ";
			 Sleep(1000);
			 exit(0);
		 }
	    cout<<"\n Enter Book Author   :";
		gets_s(author);
		ChangeToUpper(author);
		cout<<"\n Enter Book Publisher:";
		gets_s(publisher);
		cout<<"\n Book Price          :";
		cin>>price;
		PrintCategory();
	    cout<<"\n Category Number     :";
	    cin>>shelf;
	    availability=0;
	    current_holder=0;
	    _beginthread(SaveBook,0,(void*)12);
		SaveLog(bookno,title);
	   }
	   else
		   cout<<"\n\n Returning.....";
     }
	int GetBookNumber()
	{
		return bookno;
	}
	void PrintBook()
	{
		cout<<"\n Book Title       :"<<title;
		cout<<"\n Author/Publisher :"<<author;
		cout<<"\n Book Number      :"<<bookno;
		cout<<"\n Price            :"<<price;
		cout<<"\n Category         :";Category(shelf);
		cout<<"\n Shelf Number     :"<<shelf;
	}
	void PrintBook2()
	{
		cout<<"\n Author/Publisher   :"<<author;
		cout<<"\n Book Title         :"<<title;
		cout<<"\n Book Number        :"<<bookno;
		cout<<"\n Price              :"<<price;
		cout<<"\n Category           :";Category(shelf);
		cout<<"\n Shelf Number       :"<<shelf;
		cout<<"\n Book Availability  :";
		(availability==0)?cout<<"AVALABLE IN LIBRARY\n":cout<<"CURRENTLY NOT AVAILABLE\n";
	    if(availability)
		{
	    cout<<"\n BOOK HOLDER DETAILS :\n";
		int tm;
		tm=getnoofstudents();
		for(int w=0; w<tm; ++w)
		{
			if(current_holder==stu[w].roll&&stu[w].CurrentBookNumber==bookno)
			{
				stu[w].PrintStudent();
			}
		}
		}
	cout<<"-----------------------------------------------------------------";
	}
	void PrintBookTable()
	{
		if(!bookno)
			goto terminate;
       length=strlen(title);
	   if(length<=7)
	   {
		   cout<<"\n\t"<<title<<"\t\t\t\t"<<bookno<<"\t ";(availability==0)?cout<<"\t     YES\t":cout<<"\t NOT AVAILABLE\t";cout<<price<<endl;
	   }
	   else if(length<=12)
	   {
	   
		   cout<<"\n\t"<<title<<"\t\t\t"<<bookno<<"\t ";(availability==0)?cout<<"\t     YES\t":cout<<"\t NOT AVAILABLE\t";cout<<price<<endl;
	   }
	   else if(length<16&&length>12)
	   {
		  cout<<"\n\t"<<title<<"\t\t\t"<<bookno<<"\t ";(availability==0)?cout<<"\t     YES\t":cout<<"\t NOT AVAILABLE\t";cout<<price<<endl;
	   }
	   else if(length>=16)
	   {
		    cout<<"\n\t";cout.write(title, 15)<<"...\t\t"<<bookno<<"\t ";(availability==0)?cout<<"\t     YES\t":cout<<"\t NOT AVAILABLE\t";cout<<price<<endl;
	   }
	   terminate:;
	}
    void PrintBookToFile()
	{
       length=strlen(title);
	   if(length<7)
	   {
		   tout<<"\n\t"<<title<<"\t\t\t\t\t\t"<<bookno<<"\t ";(availability==0)?tout<<"\t     YES\t":tout<<"\t NOT AVAILABLE\t";tout<<price<<endl;
	   }
	   if(length<12)
	   {
	   
		   tout<<"\n\t"<<title<<"\t\t\t\t\t"<<bookno<<"\t ";(availability==0)?tout<<"\t     YES\t":tout<<"\t NOT AVAILABLE\t";tout<<price<<endl;
	   }
	   else if(length<=15)
	   {
		  tout<<"\n\t"<<title<<"\t\t\t\t"<<bookno<<"\t ";(availability==0)?tout<<"\t     YES\t":tout<<"\t NOT AVAILABLE\t";tout<<price<<endl;
	   }
	   else if(length<=19)
	   {
		    tout<<"\n\t"<<title<<"\t\t\t"<<bookno<<"\t ";(availability==0)?tout<<"\t     YES\t":tout<<"\t NOT AVAILABLE\t";tout<<price<<endl;
	   }
	   else if(length >21)
	 {
		 tout<<"\n\t";tout.write(title,19);tout<<"..\t\t"<<bookno<<"\t ";(availability==0)?tout<<"\t     YES\t":tout<<"\t NOT AVAILABLE\t";tout<<price<<endl;
	   }
	}
	void giveitaway(int r)
	{
		availability=1;
		current_holder=r;     // r = roll number of the student who takes the book; Storing details of the current book holder 
	}
	void takeit(int r)
	{
		availability=0;
		current_holder=0;    
	}
	void PrintForRead()
	{
		ofstream jout;
		jout.open("data.txt", ios::out|ios::app);
		jout<<(bookno);
		jout<<(title);jout<<"|";
		jout<<(author);jout<<"|";
		//jout<<(publisher);jout<<"|";
		jout<<(price);jout<<"|"<<"\n";
		jout.close();
	}
	void ReadFromFile(int u)
	{
		if(u)
		{
			ein.seekg(+2, ios::cur);
		}
		ein>>bookno;
		ein.seekg(+1, ios::cur);
		ein.getline(title, 100, '\t');
		ein.seekg(+2, ios::cur);
		ein.getline(author, 100, '|');
		ein.seekg(+1, ios::cur);
		ein>>price;
		availability=0;
	    current_holder=0;
		void SaveBook(void *arg);
	    _beginthread(SaveBook,0,(void*)12);
	}
	void Edit()
	{

		int ch,temp,state;
		char ans;
		cout<<"\n\n\t 1. CHANGE BOOK ID \t\t 2. CHANGE BOOK TITLE \n\t 3. CHANGE AUTHOR \t\t 4. CHANGE PRICE \n\t 5. RETURN \n\n Enter Coice :";
		ch = _getch();
		switch(ch)
		{
		case 49:cout<<"\n Enter New Book ID :";
			   cin>>temp;
			   state = CheckBook(temp);
			   if(state)
			   {
				   bookno = temp;
			   }
			   cout<<"\n UPDATED DATA :-";
			   PrintBook();
			   cout<<"\n Do you want to save this (y/n) :";
			   ans = _getch();
			   if(ans=='y'||ans=='Y')
			   {
				   _beginthread(SaveNow,0,(void*)1);
			   }
			   break;
		case 50:cout<<"\n Enter New Title :";
			cin.ignore();
			    gets_s(title);
			    cout<<"\n UPDATED DATA :-";
			    PrintBook();
			    cout<<"\n Do you want to save this (y/n) :";
			    ans = _getch();
			    if(ans=='y'||ans=='Y')
			    {
				   _beginthread(SaveNow,0,(void*)1);
			    }
				break;
		case 51 : cout<<"\n Enter New Author :";
			cin.ignore();
			      gets_s(author);
				 cout<<"\n UPDATED DATA :-";
			    PrintBook();
			    cout<<"\n Do you want to save this (y/n) :";
			    ans = _getch();
			    if(ans=='y'||ans=='Y')
			    {
				   _beginthread(SaveNow,0,(void*)1);
			    }
				break;
		case 52:cout<<"\n Enter New Price :";
			    cin>>price;
				cout<<"\n UPDATED DATA :-";
			    PrintBook();
			    cout<<"\n Do you want to save this (y/n) :";
			    ans = _getch();
			    if(ans=='y'||ans=='Y')
			    {
				   _beginthread(SaveNow,0,(void*)1);
			    }
				break;
		case 53 :break;
		default :cout<<" Invalid Choice !";
		        break; 
		}
	}
	void Delete()
	{
		bookno = -2;
	}

}book[4000];
void menudisplay()   //Founction to design main function
{
start:

	Analysis();
second:
	system("CLS");
	cout<<"\n\t\t\t\t\t\t**************************************\n";
    cout<<"\t\t\t\t\t\t\t   MAIN MENU:-";getclass(currentclass);cout<<"\n";
	cout<<"\t\t\t\t\t\t**************************************\n";
	cout<<"\n \t\t\t 1. BOOK ISSUE \t\t\t\t\t 2. BOOK SUBMISSION \n\n\t\t\t 3. VIEW ISSUED BOOKS \t\t\t\t 4. SEARCH FOR BOOK \n\n\t\t\t 5. CLASS REGISTER \t\t\t\t 6. SEARCH FOR STUDENT \n\n\t\t\t 7. CHANGE CLASS\t\t\t\t 8. ADMINISTRATOR'S MENU \n\n\t\t     [ESC]. EXIT"<<"\n\n Enter Choice :";
	choice = _getch();
    switch(choice)
	{
	  case 49:GiveABook();
				 goto second;
	  case 50 :SubmitABook(); 
				 goto second;
	  case 51 :ViewBookTakedStudents(); 
		       if(_getch())
				   goto second;
	  case 52:Search();
				goto second;
	  case 53:ViewAllStudents();
				 goto second;
	  case 54:ViewAStudent();
				 goto second;
	 case 55 : SelectClass();
			   goto start;
	  case 56:AdminMenu();
			  goto second;
	  case 27: endmenu();
		       break;
	  default :cout<<"\n\n\a Invalid Choice !\t Try Again !"   ;
		       Sleep(500);
			   goto second;
	}
}
void SelectClass()
{   post:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
 	system("CLS");   
	int rq;
	cout<<"______________________________________________________________________________________________________________________________";
	cout<<"\n\n FIRST YEAR CLASSES : - ";
	cout<<"\n______________________________________________________________________________________________________________________________\n\n";
	cout<<"\t1. CSE1\t\t2. ECE1\t\t3. ME1\t\t4. EE1";
	cout<<"\n______________________________________________________________________________________________________________________________\n\n";
    cout<<" SECOND YEAR CLASSES : - ";
	cout<<"\n______________________________________________________________________________________________________________________________\n\n";
	cout<<" \t5. CSE2\t\t6. ECE2\t\t7. ME2\t\t8. EE2";
	cout<<"\n______________________________________________________________________________________________________________________________\n\n";
    cout<<" THIRD YEAR CLASSES : - ";
	cout<<"\n______________________________________________________________________________________________________________________________\n\n";
	cout<<" \t9. CSE3\t\t10. ECE3\t\t11. ME3\t\t12. EE3";
	cout<<"\n______________________________________________________________________________________________________________________________\n\n";
    cout<<" Fourth YEAR CLASSES : - ";
	cout<<"\n______________________________________________________________________________________________________________________________\n\n";
	cout<<" \t13. CSE4\t\t14. ECE4\t\t15. ME4\t\t16. EE4\n\n\t17. TEACHERS";
	cout<<"\n\n\n\n\t\t\t\t\t\tSelect Your Class : ";
	cin>>rq;
	if(rq>17)
	{
		cout<<"\n\n\a Sorry.... Please Select a number between 1 and 17 ";
		Sleep(500);
		goto post;
	}
	currentclass=rq;
	
}
void main()
{
	Boot2(); 
	SelectClass();
	menudisplay();
}
void GiveABook()     //function_to_give_a_book_to_a_student
{
	readfiles();
	system("CLS");
	cout<<"\t\t\t\t\t\t**************************************\n";
    cout<<"\t\t\t\t\t\t\t     ISSUE A BOOK\n";
	cout<<"\t\t\t\t\t\t**************************************\n";
	cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
	ShowImp("\n TIP : DOUBLE CHECK YOUR INPUT WHEN USING BARCODE READER. ALWAYS CHECK THE BOOK TITLE");
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
first:
    i=0;
	int r=i, pos=0;
	int flag1=0, flag2=0,flag3=1;
	int bn;
	cout<<"\n\n ENTER BOOK ID :";
	cin>>bn;
	while(book[i].GetBookNumber())
	{
		if(bn==book[i].GetBookNumber())
		{
			if(book[i].current_holder)   //availability is true when value is zero//when not available
			{
				int user, countit;
				user=book[i].current_holder;
				countit=getnoofstudents();
				while(countit>=0)
				{
					if(stu[countit].roll==user)
						{
						if(stu[countit].CurrentBookNumber==bn)
							{
							   cout<<"\n THIS BOOK IS CURRENTLY ISSUED FOR :-\n ";
							   stu[countit].PrintStudent2();
							}
							else
								goto stop;
					        
							countit--;
							flag3=0;
					        goto first;
					    }
						countit--;
			      }
				
			}
			book[i].PrintBook();
			flag1=1;
		}
	i++;
	}
	if (!flag1)
	{
		cout<<"\n\n NO BOOK WITH BOOK NO ["<<bn<<"] DETECTED. TRY AGAIN !";
		goto first;
	}

	// HANDLING STUDENT DATA//

	cout<<"\n\n ENTER STUDENT'S ADMISSION / REGISTER NO :";
	cin>>r;
	i=0;
	while(stu[i].roll)
	{
		if(stu[i].regno==r&&flag2==0&&currentclass==stu[i].currentc)
		{
            stu[i].PrintStudent();
		    pos=i;
			flag2=1;
		}
    i++;
	}
	if (!flag2)
	{
		cout<<"\n\n NO STUDENT ON THE REGISTER NUMBER IS FOUND. CHECK AGAIN !\n ";
		_getch();
		goto stop;
	}
	if(stu[pos].CurrentBookNumber)
	{
		int cbn=stu[pos].CurrentBookNumber,i=0;
		cout<<"\n\n ";cout<<stu[pos].name<<" HAS ALREADY A BOOK!!!!";
		cout<<"\n BOOK NUMBER :"<<cbn;
		cout<<"\n\n BOOK DETAILS :-\n\n";
		while(book[i].bookno)
		{
			if(book[i].bookno==cbn)
			{
				book[i].PrintBook();
				cout<<"\n\n PROCESS ABORTED !";
				_getch();
				goto stop;
			}
				i++;
		}
	}
	cout<<"\n\t ARE YOU SURE WANT TO GIVE THIS BOOK TO ";cout<<(stu[pos].name)<<"? (Y/N) :";
	cin>>ans;
	i=0;
	if(ans=='y'||ans=='Y')
	{
		int roll_org = stu[pos].roll;
		stu[pos].CurrentBookNumber=bn;
		stu[pos].total_books_used++;  //Counting total book usage of the student 
		while(book[i].GetBookNumber())
	     {
		    if(bn==book[i].GetBookNumber())
		      {
				  book[i].giveitaway(roll_org);  // Sending Student's roll number to save details, making the book avalability to "NOT AVAILABLE";
		      }
	          i++;
	    }
		cout<<"\n THANK YOU";
		stu[pos].SetDate();
		_beginthread(SaveNow,0,(void*)12);
		SaveLog(stu[pos].CurrentBookNumber,stu[pos].name,stu[pos].currentc);
	}
	else
		cout<<"\n\n\n PROCESS ABORTED... RETURNING NOW\n ";
	MessageIssued();
stop:;

}

void ViewAStudent()
{   
	system("CLS");
	cout<<"\t\t\t\t\t\t**************************************\n";
	cout<<"\t\t\t\t\t\t      VIEW A STUDENT'S PROFILE :";getclass(currentclass);
	cout<<"\n\t\t\t\t\t\t**************************************\n";
	cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
	ShowImp("\n TIP : IF ANY UNKNOWN ERROR OCCURS, CLOSE THE WINDOW (alt+F4) IMMEDIETLY IN ORDER TO PROTECT DATA");
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
	i=0;
	int flag=0;
    int r;
	cout<<"\n\n ENTER ADMISSION / REGISTER NO:";
	cin>>r;
	while(stu[i].roll)
	{
		if(stu[i].regno==r&&stu[i].currentc==currentclass)
		{
            stu[i].PrintStudent();
			flag=1;
		}
    i++;
	}

	if(!flag)
	{
		cout<<"\n\n NO STUDENT WITH ROLL NUMBER "<<r<<" IS PRESENT!, TRY AGAIN.....";
	}
 _getch();
}
void SaveStudentData()
{
	int p=::count;
	fout.open("studentdata.bhsbiet", ios::app|ios::binary|ios::out);
	fout.write((char*)&stu[p], sizeof(student));	
	::count++;
	fout.close();
}
void readfiles()      //function to read files during every execution
{
	fflush(0);
	::count=0;
	fin.close();
	fout.close();
	fin.open("studentdata.bhsbiet", ios::binary|ios::app);
	while(fin)
	{
		fin.read((char*)&stu[::count],sizeof(student));
	    ::count++;
		numberofstudents++;
		globalstudentcounter++;
	}
	ctr2=::count;
	students=ctr;
	fin.close();
	fout.close();
	int bookcounter=0;
	personalcounter=0;   //for multifunctions and accurate book numbers;
	bin.open("bookdata.bhsbiet", ios::binary|ios::app);
	while(bin)
	{
		bin.read((char*)&book[bookcounter],sizeof(Book));
		bookcounter++;
		personalcounter++;
	}
	ctr=bookcounter;
	bin.close();
}
void SaveBook(void *arg)
{
	bout.close();
	int p=bookcounter;
	bout.open("bookdata.bhsbiet", ios::binary|ios::app);
	while(p<=bookcounter)
	{
		bout.write((char*)&book[p],sizeof(Book));
		p++;
	}
	bookcounter++;
	acbooks=bookcounter;
	MessageIssued();
	bout.close();
	readfiles();
}
void ViewAllBooks(void *arg)
{
	int tem2=getnoofbooks(); i=0;
	readfiles();
	tout.open("bfile.txt", ios::out);
	tout<<"\n\n\n\n------------------------------------BOOK DATA---------------------------------"<<"\n\n";;
	tout<<"Total no.of Books = "<<tem2;
	tout<<"\n________________________________________________________________________________";
	tout<<"\n\t    Title\t\t    Book Number\t\t Availability";
	tout<<"\n________________________________________________________________________________\n";
	
	while(tem2)
	{
		book[i].PrintBookToFile();
	    tem2--;
		i++;
	}
	tout.close();
	system("bfile.txt");
}
void SaveNow(void *arg)
{
	int a=0, b=0;
	a=ctr2-2;
	b=ctr-1;
	fin.close();bin.close();
	fout.close();bout.close();
	fout.open("studentdata.bhsbiet", ios::binary);
	while(a>=0)
	{
		fout.write((char *)&stu[a], sizeof(student));
		a--;
	}
	fout.close();
	fin.close();
	fout.open("bookdata.bhsbiet", ios::binary);
	while(b>=0)
	{
		if(book[b].bookno<=0)
			{
				b--;
				continue;
		}
		fout.write((char *)&book[b], sizeof(Book));
		b--;
	}
	fout.close();
}
void endmenu()
{ 
    PrintToFile();
	SaveLog("L.A CLOSED");
	system("CLS");
	char end[100] = {"\n\n\n\n\t\t\t\t\t\t THANKS FROM BHSBIET LIBRARY ASISTANT - V -  1.0 -\n\n\n\n\n\n\n"};
    int ln = strlen(end);
	for(int i=0; i<ln; ++i)
	{
		cout<<end[i];
		Sleep(10);
	}
	Sleep(500);
	exit(0);
}
void getclass(int x)
{
	switch (x)
	{
	case 1:cout<<"CSE1";
	       break;
	case 2:cout<<"ECE1";
		    break;
	case 3:cout<<"ME1";
		    break;
	case 4:cout<<"EE1";
		    break;
	case 5:cout<<"CSE2";
		    break;
	case 6:cout<<"ECE2";
		    break;
    case 7:cout<<"ME2";
		    break;
	case 8:cout<<"EE2";
	       break;
	case 9:cout<<"CSE3";
		    break;
	case 10:cout<<"ECE3";
		    break;
	case 11:cout<<"ME3";
		    break;
	case 12:cout<<"EE3";
		    break;
	case 13:cout<<"CSE4";
		    break;
    case 14:cout<<"ECE4";
		    break;
    case 15:cout<<"ME4";
		    break;
	case 16:cout<<"EE4";
	       break;
	case 17:cout<<"TEACHERS";
		   break;
	}
}
void reset() 
{
	const long int password=2641995;
	long int pass;
	system("CLS");
	system("Color 1a");
	cout<<"\n\n\n You are going to reset everything about your library, Enter Pass Word :";
	cin>>pass;
	if(pass==password)
	{
      fout.open("studentdata.bhsbiet",ios::binary);fout.close();
      fout.open("bookdata.bhsbiet", ios::binary);fout.close();
    }
	else 
	cout<<"\n\n Sorry ! Wrong password...\n\n \t\t\t RESET ABORTED !\n\n\n\n\n ";
	system("pause");
	readfiles();
}
void SubmitABook()     //function_to_give_a_book_to_a_student
{
	void SaveNow(void*);
	system("CLS");
	cout<<"\t\t\t\t\t\t**************************************\n";
    cout<<"\t\t\t\t\t\t     	      BOOK SUBMISSION\n";
	cout<<"\t\t\t\t\t\t**************************************\n";
    i=0;
	int r=i, pos=0;
	int flag1=0, flag2=0, flagx=1;
	int bn;
	cout<<"\n\n Enter Book ID :";
	cin>>bn;
	while(book[i].GetBookNumber())
	{
		if(bn==book[i].GetBookNumber())
		{
			if(!book[i].availability)
			{
		       cout<<"\n\n This Book is already available in library !";
			   flagx=0;
			   if(_getch())
			     goto lat;
            }
			book[i].PrintBook();
			flag1=1;
			r=book[i].current_holder;
		}
	i++;
	}
	if (!flag1)
	{
		cout<<"\n\n No Such Book Found....Try Again !";
		_getch();
		goto lat;
	}	
	i=0;
	cout<<"\n\n THE BOOK HOLDER DETAILS :-";
	while(stu[i].roll)
	{
		if(stu[i].roll==r&&flag2==0&&currentclass==stu[i].currentc)
		{
            stu[i].PrintStudent();
		    pos=i;
		}
    i++;
	}
	cout<<"\n ARE YOU SURE WANT TO SUBMIT BACK TO LIBRARY,  Mr/Ms. ";cout<<(stu[pos].name)<<"? (y/n) :";
	cin>>ans;
	i=0;
	if(ans=='y'||ans=='Y')
	{
	    stu[pos].CurrentBookNumber=0;
		while(book[i].GetBookNumber())
	     {
		    if(bn==book[i].GetBookNumber())
		      {
				  book[i].takeit(r);  // Sending Student's roll number to save details, making the book avalability to "NOT AVAILABLE";
		      }
	          i++;
	    }
		MessageIssued();
		stu[pos].DeleteDate();
		_beginthread(SaveNow,0,(void*)12);
		SaveLog(stu[pos].name,bn,stu[pos].currentc,10);
	}
	else
	 cout<<"\n\n\n\a Process Aborted !.... Returning\n ";
	
	lat:;
}
int getnoofstudents()
{
	int k=0, stuno=0;
	while(stu[k].roll)
	{
		k++;
	    stuno++;
	}
return stuno;
}
int getnoofbooks()
{
	int k=0;
	while(book[k].bookno)
	{
		k++;
	}
return k;
}	  
void PrintToFile()
{
	system("CLS");
	cout<<"\n\n\n Saving Student Informations to BHSBIET_LIBRARY file.........";
    tout.open("BHSBIET_LIBRARY.txt", ios::out);
	cout<<"\n Saving Book informations .........";
	tout<<"\n\n\n\n------------------------------------BOOK DATA---------------------------------"<<"\n\n";;
	tout<<"\n________________________________________________________________________________";
	tout<<"\n\t    Title\t\t    Book Number\t\t Availability\tPrice";
	tout<<"\n________________________________________________________________________________\n";
	int tem2=getnoofbooks(); i=0;
	while(tem2)
	{
		book[i].PrintBookToFile();
	    tem2--;
		i++;
	}
	tout<<"\t\t\n\n************************* B.H.S.B.I.E.T : BHSBIET LIBRARY ASSISTANT 1.0:*****************************\n\n\n";
	tout<<"\t\t\n\n-------------------------------STUDENT DATA---------------------------------\n";
	tout<<"\n_______________________________________________________________________________\n";
    tout<<"\t    Name\t\tRoll\t    Reg       Book No. \t     Date";
	tout<<"\n_______________________________________________________________________________\n";
	int tem=::count, i=0;
	cout<<"\n\a Saving Accomplished ..........";
	int tempclass=1;
	while(tempclass<=16)
	{
	for(int y=0; y<tem; ++y)
		{
			if(stu[y].currentc==tempclass)
		       stu[y].PrintStudentToFile();
		}
	 tempclass++;
	}
	tout<<"\n\n\n\n\n DEVELOPED BY : RAM KRISHNA, SHUBHAM & SAHIL Students of CSE Batch-2015";
	MessageIssued();
}
void putclass(int u)
{

switch (u)
	{
	case 1:tout<<"CSE1";
	       break;
	case 2:tout<<"ECE1";
		    break;
	case 3:tout<<"ME1";
		    break;
	case 4:tout<<"EE1";
		    break;
	case 5:tout<<"CSE2";
		    break;
	case 6:tout<<"ECE2";
		    break;
    case 7:tout<<"ME2";
		    break;
	case 8:tout<<"EE2";
	       break;
	case 9:tout<<"CSE3";
		    break;
	case 10:tout<<"ECE3";
		    break;
	case 11:tout<<"ME3";
		    break;
	case 12:tout<<"EE3";
		    break;
	case 13:tout<<"CSE4";
		    break;
    case 14:tout<<"ECE4";
		    break;
    case 15:tout<<"ME4";
		    break;
	case 16:tout<<"EE4";
	       break;
	}
}
void ViewAllStudents()
{	
	system("CLS");
	COORD dim = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));    //Aquiring Largest Possible windows size according to screen resolution  
    dim.Y =500;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),dim);
	cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
	getclass(currentclass);cout<<"\n\t    NAME\t\tROLL\t    REG.NO     BOOK NO \t   ISSUE DATE";
	cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";
	readfiles();
	int temp=::count-1, i=0;
	while(temp)
	{
		if(stu[i].currentc==currentclass)
		   stu[i].PrintTable();
		temp--;i++;
	}
    _getch();
    dim = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));    //Aquiring Largest Possible windows size according to screen resolution  
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),dim);
}
void getsize()  //just for debugging
{
	system("color f0");
	system("CLS");
	int stud=sizeof(student);
	int buk=sizeof(Book);
	int ttbook,ttstudent;
	ttbook=(buk*4000)/1024;
	ttstudent=(stud*2000)/1024;
	cout<<"\n\n\n Size of class students = "<<stud<<" bytes ";
	cout<<"\n\n Max Memory Required for Students = "<<(stud*1000)<<" bytes ="<<ttstudent<<" KB";
	cout<<"\n\n Size of class Books = "<<buk<<" bytes "<<endl;
	cout<<"\n\n Max Memory Required for BOOKS    = "<<buk*4000<<" bytes ="<<ttbook<<" KB\n\n";
	cout<<"\n\n Maximum Memory Usage = "<<(ttbook+ttstudent)<<" KB\n\n";
    _getch();
}
void About()
{
	system("CLS"); 
	cout<<"\n\n\n----------------------DEVELOPER INFO------------------------\n";
	cout<<"\n Created By : RAM KRISHNA KUMAR, SHUBHAM BRIJWASI & SAHIL MEHTA ";
	  cout<<"\n\n-----------------------------------------------------------\n\n";
	  cout<<"\n Current Version   : 1.0";
	  cout<<"\n Max:Memory Use    : 1.4 MB";
	  cout<<"\n Student Data base : studentdata.bhsbiet(binary mode)";
	  cout<<"\n Book Data base    : bookdata.bhsbiet(binary mode)";
}
void Settings()
{
first: 
	system("CLS");
	cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t    SETTINGS";
	cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n\n\t\t\t\t 1. DEVELOPER MODE \t\t\t 2. RESET EVERYTHING\n\n\t\t\t\t 3. ABOUT BHSBIET L.A 1.0\t\t\t 4. CHANGE LOCK STATUS\n\n\t\t\t     [ESC]. RETURN";
	cout<<"\n\n\n\t\t Enter Your Choice :";
    choice = _getch();
	switch(choice)
	{

	     case 49:DeveloperMode();
				goto first;
		case 50 :reset();
			    if(_getch())
					goto first;
		case 51:About();
					if(_getch())
						goto first;
		case 52 :SetLock();
		        goto first;
		case 27 :break;
		default : cout<<"\n\n\n Wrong Choice !!! Try Again !";
		        goto first;
	}
}
int CheckStudent(int rn)
{
	int x=getnoofstudents();
	int status=1;
	for(int j=0; j<x ; ++j)
	{
		if(stu[j].roll==rn&&stu[j].currentc==currentclass)
		{
			status=0;
			cout<<"\n\n A Student with this roll number is already present.....\n\n ";
			stu[j].PrintStudent();
			cout<<"\n\n\n PROCESS ABORTED !";
			if(_getch())
				break;
		}
	}
	return status;
}
int CheckBook(int no)
{
	int tmp=getnoofbooks();
	int s=1;
	for(int j=0; j<tmp; ++j)
	{
		if(book[j].bookno==no)
		{

			cout<<"\n\n A book with this number ("<<no<<") is already present......\n\n ";
			book[j].PrintBook();
			s=0;
		}
	}
	return s;
}
void ShowDate()
{
	cout<<"\n\n Current Date Is : ";
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
	int year=now->tm_year + 1900;
	int month=now->tm_mon + 1;
	int day=now->tm_mday;
	cout<<day<<" - "<<month<<" - "<<year;
}
void ViewBookTakedStudents()
{
	system("CLS");
	int limit;
    cout<<"\n Enter How many days  :";
	cin>>limit;
	  cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t ROLL\t\tREG.NO\t\tBOOK.C\t\tDATE\t      DAYS";
	  cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
	int st=getnoofstudents();
	for(int j=0; j<st ; ++j)
	{
		if(stu[j].CurrentBookNumber&&stu[j].currentc==currentclass)
		{
			if(stu[j].Countnoofdays()>=limit)
				stu[j].PrintTable3();
		}
	}
}
void BackUp()
{
	int pass;
	cout<<"\n\n Enter Password :";
	cin>>pass;
	if(pass==2641995)
	{
	system("CLS");
	cout<<"\n\n\n Saving Student Informations to PPM_HSS_LIBRARY file.........";
	Sleep(100);
    tout.open("backupfile.txt", ios::out);
	tout<<"\t\t\n\n*************************B.H.S.B.I.E.T : BHSBIET LIBRARY ASSISTANT 1.0:*****************************\n\n\n";
	tout<<"\t\t\n\n-------------------------------STUDENT DATA---------------------------------\n";
	tout<<"\n_______________________________________________________________________________\n";
    tout<<"\t    Name\t\tRoll\t    Reg       Book No. \t     Date";
	tout<<"\n_______________________________________________________________________________\n";
	int tem=getnoofstudents(), i=0;
	cout<<"\n\a Saving Accomplished ..........";
	int tempclass=1;
	while(tempclass<=16)
	{
	for(int y=0; y<tem; ++y)
		{
			if(stu[y].currentc==tempclass)
		       stu[y].PrintStudentToFile();
		}
	 tempclass++;
	}
	cout<<"\n Saving Book informations .........";
	int tem2=getnoofbooks(); i=0;
	tout<<"\n\n\n\n------------------------------------BOOK DATA---------------------------------"<<"\n\n";;
	tout<<"\n________________________________________________________________________________";
	tout<<"\n\t    Title\t\t    Book Number\t\t Availability";
	tout<<"\n________________________________________________________________________________\n";
	while(tem2)
	{
		book[i].PrintBookToFile();
	    tem2--;
		i++;
	}
	tout<<"\n\n\n\n\n DEVELOPED BY : CSE4th yr STUDENTS 2015-2019 BATCH";
	cout<<"\n\n Back-up Success !";
	}
	else
		cout<<"\n\n Wrong Password !";
}
void AdminMenu()
{
	Start:
	if(lock_status)
	{
	  BOOL logic = Protection();
	   if(logic==false)
	    {
		  system("CLS");
	      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t WRONG PASSWORD";
		  Sleep(500);
		  goto Start;
	    }
	}
	int ch;
boot:
    system("CLS");
	cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
    cout<<"\t\t\t\t\t\t\t\t     ADMININSTRATOR'S MENU:-";getclass(currentclass);
	cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n\t\t\t\t 1. ADD NEW STUDENT \t\t\t 2. ADD NEW BOOK \n\n\t\t\t\t 3. SETTINGS \t\t\t\t 4. SAVE TO FILE \n\n\t\t\t\t 5. CREATE BARCODE \t\t\t 6. EDIT A BOOK \n\n\t\t\t\t 7. DELETE A BOOK \t\t\t 8. EDIT A STUDENT     \n\n\t\t\t\t 9. EDIT BOOK CATEGORY \t\t      [ESC]. RETURN "<<"\n\n\t\t Enter Choice :";
	ch=_getch();
	switch(ch)
	{
	case 49:stu[::count].AddStudent();
		      Sleep(100);
				 goto boot;
	  case 50:book[bookcounter].AddBook();
		      if(_getch())
				 goto boot;
	  case 51:Settings();
				  goto boot;
	  case 52: PrintToFile();
		  	  cout<<"\n\n\n Opening Saved File..... Please Wait......";
	          tout.close();
	          _beginthread(OpenBackup,1,(void*)12);
				 goto boot;
	  case 53:void OpenBMaker(void *arg);
		     _beginthread(OpenBMaker,1,(void*)12);
		     break;
	  case 54:void EditBookData();
		      EditBookData();
			  goto boot;
	  case 55: 
		  DeleteBook();
		  goto boot;
	  case 56:EditStudentData();
		      _getch();
			  goto boot;
	  case 57:EditCategory();
		     goto boot;
	  case 27:return;
	  default :cout<<"\n\n Invalid Choice !";
		       break;

	}
	
} 
void CombineFiles()
{
	system("CLS");
	cout<<"_______________________________________________________________________________";
    cout<<"\n\n\t\t\t\t    COMBINE MULTIPLE FILES (STUDENT DATA ) \n";
	cout<<"_______________________________________________________________________________";
	cout<<"\n\n GENERAL INSTRUCTIONS :\n\n\n 1 . RENAME THE FIRST FILE TO BE COMBINED AS \"stutmp.bhsbiet\"\n 2 . RENAME THE SECOND FILE AS \"alldata.bhsbiet\" \n 3 . YOUR OUTPUT FILE WILL BE \"alldata-2.bhsbiet\"";
	ofstream gout;
	ifstream win,gin;
	int current=0; //Shows no of students in all data file;
	int nreaded=0; //New student data that has to be copied to all data.afsal file;
	gin.open("alldata.bhsbiet", ios::app|ios::binary);
	while(gin)
	{
		gin.read((char*)&stu[current], sizeof(student));
		current++;
	}
	current--;   //VC 2010++ returns 1 when even no studentdata found !
	cout<<"\n\n Base Reading Success !\n\n Total "<<current<<" students detected !\n\n Now reading new file";
	Sleep(2000);
	win.open("stutmp.bhsbiet", ios::binary|ios::app);
	while(win)
	{
		win.read((char*)&stu[current], sizeof(student));
		current++;
		nreaded++;
	}
	nreaded--;
	current--;
	cout<<"\n\n "<<nreaded<<" students added !\n\n Current Status is "<<current<<" students\n\n Now Saving !";
	_getch();
	 Sleep(900);
	gin.close();
	win.close();
	gout.open("alldata.bhsbiet", ios::binary|ios::out);
	for(int p=0; p<current; ++p)
	{
		gout.write((char*)&stu[p], sizeof(student));
	}
	cout<<"\n\n File Saving Accomplished!\n\n Check Files........";
	gout.close();
	_getch();
	cout<<"\n\n Reading All Data File.........";
	cout<<"\n*******************************************************************************\n";
	cout<<"\t    Name\t\tRoll\t    Reg       Book No. \t     Date";
	cout<<"\n*******************************************************************************\n";
	for(int k=0;k<current;++k)
	{
		stu[k].PrintTable();
	}
	_getch();
}
void DeveloperMode()
{
	int pass;
	int cho;
	system("color f0");
	cout<<"\n\n Password :";
	cin>>pass;
	if(pass!=2641995)
	{
		cout<<"Wrong !";cout<<"\n\n";
		system("pause");
		goto end;
	}
base:
	system("CLS");
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t    DEVELOPER MODE\n";
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\t\t 1. COMBINE STUDENT FILES \t\t 2. GET SIZES\n\n\t\t 3. BACK UP\n\n\t\t 4. COMBINE BOOK FILES \t\t 5.RETURN";
	cout<<"\n\n\n Enter Your Choice :";
	cin>>cho;
	switch(cho)
	{
	case 1: CombineFiles();
		    goto base;
	case 2:getsize();
		   goto base;
	case 3:BackUp();
		   goto base;
	case 4:void CombineBookFiles();
		   CombineBookFiles();
		   goto base;
	
	case 5: return;
	default: cout<<"\n\n Invalid Choice !";
		     break;
	}

end: ; //To return when wrong password entered
}
void CombineBookFiles()
{
  ifstream qin,pwin;
  int nbookreaded=0, ndetected=0;
  ofstream qout;
  qin.open("booktmp.bhsbiet", ios::app|ios::binary);
  while(qin)
  {
	  qin.read((char *)&book[nbookreaded], sizeof(Book));
	  nbookreaded++;
  }
  nbookreaded--;
  cout<<"\n Total "<<(nbookreaded)<<" Books found in Booktmp.bhsbiet. ";
  qin.close();
  pwin.open("alldata.bhsbiet", ios::binary|ios::app);
  while(pwin)
  {
	 pwin.read((char*)&book[nbookreaded], sizeof(Book));
	 nbookreaded++;
	 ndetected++;
  }
  nbookreaded--;
  ndetected--;
  cout<<"\n\n"<<(ndetected)<<" books are already in data base !\n\n Now Total = "<<nbookreaded;
  _getch();
  cout<<"\n\n Combining Files .....";
  pwin.close();
  qout.open("alldata-2.bhsbiet", ios::binary|ios::out);
  for(int yr=0; yr<nbookreaded; ++yr)
  {
	  qout.write((char*)&book[yr], sizeof(Book));  
  }
  cout<<"\n\n File Successfully Saved !";
  _getch();
}
void Boot2()
{
Start:
	ReadLock();
	readfiles();
	if(lock_status)
	{
	  BOOL logic = Protection();
	   if(logic==false)
	    {
		  system("CLS");
	      cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t WRONG PASSWORD";
		  Sleep(500);
		  goto Start;
	    }
	}
	TCHAR title[MAX_PATH];
	SMALL_RECT Rectangles;
	COORD dim = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));    //Aquiring Largest Possible windows size according to screen resolution  
	Rectangles.Top = 0;
	Rectangles.Left =0;
	Rectangles.Bottom = dim.Y-5;
	Rectangles.Right = dim.X-5;
	StringCchPrintf(title, MAX_PATH, L"BHSBIET LIBRARY ASSISTANT 1.0");    //Setting Program Title
	SetConsoleTitle(title);//Setting Program Title
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),dim);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE),TRUE,&Rectangles);
	Init();  //Initialising LOG file stream
	SaveLog("BHSBIET L.A STARTED");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t WELCOME TO BHSBIET LIBRARY ASSSITANT 1.0\n\n\n\n\n\n\n\n\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
	cout<<"\tLOADING..\t\t";
	Sleep(200);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
	system("CLS");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t WELCOME TO BHSBIET LIBRARY ASSSITANT 1.0\n\n\n\n\n\n\n\n\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
	cout<<"\tLOADING..\t\t\t\t\t\t\t\t\t";
	Sleep(250);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	system("CLS");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t WELCOME TO BHSBIET LIBRARY ASSSITANT 1.0\n\n\n\n\n\n\n\n\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY);
	cout<<"\tLOADING..\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
	Sleep(300);
}
void Analysis()
{
	system("CLS");
	int nstu=0 ,nbavailable(0),booktakers=0,ka;
	int u=0;
	ka = getnoofstudents();
	cout<<"---------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\t\t\t\t\t\t";getclass(currentclass);cout<<" : - A QUICK OVERVIEW ";
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------";
	for(int i=0; i<ka; ++i)
	{
	if(stu[i].currentc==currentclass)	{

		if(stu[u].CurrentBookNumber)
		{
			booktakers++;
		}
		nstu++;
		u++;
	}}
	int c=0,ko=0;
	while(book[ko].bookno)
	{
		ko++;
	}
	while(book[c].availability)
	{
		nbavailable++;
		c++;
	}
	int p=ko-nbavailable;
	cout<<"\n\n\t\t\t\t\t STUDENT STRENGTH OF ";getclass(currentclass);cout<<"\t    :"<<nstu;
	cout<<"\n\n\t\t\t\t\t NO.OF STUDENTS HAVING BOOK         :"<<booktakers;
	cout<<"\n\n\t\t\t\t\t TOTAL NO.OF BOOKS IN LIBRARY       :"<<ko;
	cout<<"\n\n\t\t\t\t\t NO.OF AVAILABLE BOOKS              :"<<p;
	cout<<"\n\n\n Press Any Key ..........";
	void WriteAll();
	WriteAll();
	_getch();
}
void Printing()
{
  int p=getnoofbooks();
  for(int u=0; u<p; u++)
  {
	  book[u].PrintForRead();
  }
}
void Reading()
{
	int n;
	ein.open("data.txt", ios::in|ios::app);
	cout<<"Enter How many books data are there in data.txt file :";
	cin>>n;
    for(int u=0; u<n; u++)
    {
		book[u].ReadFromFile(u);
    }
}
void StudentPrint()
{
	int num;
	sout.open("stud.txt", ios::app);
	num = getnoofstudents();
	for(int i=0; i<num; ++i)
	{
		stu[i].PrintForReading();
	}
	sout.close();
}
void ErrorCheck(){
    bout.close();
	int p=bookcounter;
	bout.open("bookdata.bhsbiet", ios::binary|ios::app);
	while(p<=bookcounter)
	{
		int lp = p - 1;
		if(book[p].bookno==book[lp].bookno)
		{
			cout<<"Occured!";
			p++;
			continue;
		}
		bout.write((char*)&book[p],sizeof(Book));
		p++;
	}
	bookcounter++;
	acbooks=bookcounter;
	cout<<"\nBook Saved !";
	bout.close();
	readfiles();
}
void Search()
{
	int ch,k=getnoofbooks(),bkn, flagx=0, j,flag_1=1,nos=0,i=0; ;
	system("CLS");
    cout<<"\t\t\t\t\t\t**************************************\n";
    cout<<"\t\t\t\t\t\t\t      SEARCH MENU\n";
	cout<<"\t\t\t\t\t\t**************************************\n";
	cout<<"\n\n\n\t\t\t\t 1. Search By Book ID \t\t 2. Search By Book Title \n\n\t Enter Your Choice :";
	ch = _getch();
	switch(ch)
	{
	  case 49 :
	   system("CLS");
	   cout<<"\t\t\t\t\t\t**************************************\n";
       cout<<"\t\t\t\t\t\t\t  SEARCH BY BOOK ID\n";
	   cout<<"\t\t\t\t\t\t**************************************\n";
   	   cout<<"\n\n Enter Book Number :" ;
	   cin>>bkn;
	   for(j=0; j<k; ++j)
			{
				if(bkn==book[j].bookno)
				{
					cout<<"\n\n  BOOK FOUND !";
					book[j].PrintBook2();
					flagx=1;
				}
			}
	   if(!flagx)
			{
				cout<<"\n\n Sorry... No Book with Number "<<bkn<<" found";
			}
	   _getch();
	   break;
	  case 50:void SeatchByBookTitle();
		  SeatchByBookTitle();
		  system("CLS");
		  break;
	  default : cout<<"\n Invalid Choice !";
	   
     } // End of switch
}// End of Search Function
void OpenBMaker(void *arg) //Multi Threaded
{
	system("bmaker.lnk");
}
void SeatchByBookTitle()
{
	COORD dim = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));    //Aquiring Largest Possible windows size according to screen resolution  
	dim.Y =1000;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),dim);
	cout<<"\n\n\n Start typing title :";
	var = _getch();
	if(var==13)
		goto Terminate;
	var = toupper(var);
	cout<<var;
	var1 = _getch();
	if(var1==13)
		goto Terminate;
	var1= toupper(var1);
	_beginthread(SearchWithThread2,0,(void*)12);
	system("CLS");
	var2 = _getch();
	if(var2==13)
		goto Terminate;
	var2 = toupper(var2);
	_beginthread(SearchWithThread3,0,(void*)12);	
	var3 = _getch();
	if(var3==13)
		goto Terminate;
	var3 = toupper(var3);
	_beginthread(SearchWithThread4,0,(void*)12);	
	var4 = _getch();
	if(var4==13)
		goto Terminate;
	var4 = toupper(var4);
	_beginthread(SearchWithThread5,0,(void*)12);
	var5 = _getch();
	if(var5==13)
		goto Terminate;
	var5 = toupper(var5);
	_beginthread(SearchWithThread6,0,(void*)12);
	var6 = _getch();
	if(var6==13)
		goto Terminate;
	var6 = toupper(var6);
	_beginthread(SearchWithThread7,0,(void*)12);
	var7 = _getch();
	if(var7==13)
		goto Terminate;
	var7 = toupper(var7);
	_beginthread(SearchWithThread8,0,(void*)12);
	var8 = _getch();
	if(var8==13)
		goto Terminate;
	var8 = toupper(var8);
	_beginthread(SearchWithThread9,0,(void*)12);
	_getch();
Terminate:;
    dim = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));    //Aquiring Largest Possible windows size according to screen resolution  
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),dim);
}
void SearchWithThread2(void *arg)
{
	while(book[nl].bookno)
	{
		nl++;
	} // No.of objects

  for(int p=0; p<nl;++p)
  {
	   g = book[p].title[0];
	   h = book[p].title[1];
	   if(g==var&&h==var1)
	   {
		   a++;
		   book[p].PrintBook();
		    cout<<"\n";
	   }
  }
  cout<<"\n\n ["<<a<< "] no.of books starting on "<<var<<var1<<"\n-------------------------------------------------------------\n";	
}
void SearchWithThread3(void *arg)
{
	system("CLS");
  for(int p=0; p<nl;++p)
  {
	   g = book[p].title[0];
	   h = book[p].title[1];
	   lg = book[p].title[2];
	   if(g==var&&h==var1&&lg==var2)
	   {
		   b++;
		   book[p].PrintBook();
		    cout<<"\n";
	   }
  }
  cout<<"\n\n ["<<b<< "] no.of books starting on "<<var<<var1<<var2<<"\n-------------------------------------------------------------\n";

}
void SearchWithThread4(void *arg)
{system("CLS");
  int c=0;
  for(int p=0; p<nl;++p)
  {
	   g = book[p].title[0];
	   h = book[p].title[1];
	   lg = book[p].title[2];
	   lo = book[p].title[3];
	   if(g==var&&h==var1&&lg==var2&&lo==var3)
	   {
		   c++;
		   book[p].PrintBook();
		   cout<<"\n";
	   }
  }
  cout<<"\n\n ["<<c<< "] no.of books starting on "<<var<<var1<<var2<<var3<<"\n-------------------------------------------------------------\n";
  	
}
void SearchWithThread5(void *arg)
{system("CLS");
  int lop=0;
  for(int p=0; p<nl;++p)
  {
	   g = book[p].title[0];
	   h = book[p].title[1];
	   lg = book[p].title[2];
	   lo = book[p].title[3];
	   m1 = book[p].title[4];
	   if(g==var&&h==var1&&lg==var2&&lo==var3&&m1==var4)
	   {
		   lop++;
		   book[p].PrintBook();
		   cout<<endl;
	   }
  }
  cout<<"\n\n ["<<lop<< "] no.of books starting on "<<var<<var1<<var2<<var3<<var4<<"\n------------------------------------------------------";
 
}
void SearchWithThread6(void *arg)
{system("CLS");
  int lop=0;
  for(int p=0; p<nl;++p)
  {
	   g = book[p].title[0];
	   h = book[p].title[1];
	   lg = book[p].title[2];
	   lo = book[p].title[3];
	   m1 = book[p].title[4];
	   q_1 = book[p].title[5];
	   if(g==var&&h==var1&&lg==var2&&lo==var3&&m1==var4&&q_1==var5)
	   {
		   lop++;
		   book[p].PrintBook();
		   cout<<endl;
	   }
  }
    cout<<"\n\n ["<<lop<< "] no.of books starting on "<<var<<var1<<var2<<var3<<var4<<var5<<"\n--------------------------------------------";
	
}
void SearchWithThread7(void *arg)
{system("CLS");
  int lop=0;
  for(int p=0; p<nl;++p)
  {
	   g = book[p].title[0];
	   h = book[p].title[1];
	   lg = book[p].title[2];
	   lo = book[p].title[3];
	   m1 = book[p].title[4];
	   q_1 = book[p].title[5];
	   q_2 = book[p].title[6];
	   if(g==var&&h==var1&&lg==var2&&lo==var3&&m1==var4&&q_1==var5&&q_2==var6)
	   {
		   lop++;
		   book[p].PrintBook();
		   cout<<endl;
	   }
  }
    cout<<"\n\n ["<<lop<<"] no.of books starting on "<<var<<var1<<var2<<var3<<var4<<var5<<var6<<"\n--------------------------------------------------------";
		
}
void SearchWithThread8(void *arg)
{system("CLS");
  int lop=0;
  for(int p=0; p<nl;++p)
  {
	   g = book[p].title[0];
	   h = book[p].title[1];
	   lg = book[p].title[2];
	   lo = book[p].title[3];
	   m1 = book[p].title[4];
	   q_1 = book[p].title[5];
	   q_2 = book[p].title[6];
	   q_3 = book[p].title[7];
	   if(g==var&&h==var1&&lg==var2&&lo==var3&&m1==var4&&q_1==var5&&q_2==var6&&q_3==var7)
	   {
		   lop++;
		   book[p].PrintBook();
		   cout<<endl;
	   }
  }
    cout<<"\n\n ["<<lop<< "] no.of books starting on "<<var<<var1<<var2<<var3<<var4<<var5<<var6<<var7<<"\n---------------------------------------------------------------------";
		
}
void SearchWithThread9(void *arg)
{system("CLS");
  int lop=0;
  for(int p=0; p<nl;++p)
  {
	   g = book[p].title[0];
	   h = book[p].title[1];
	   lg = book[p].title[2];
	   lo = book[p].title[3];
	   m1 = book[p].title[4];
	   q_1 = book[p].title[5];
	   q_2 = book[p].title[6];
	   q_3 = book[p].title[7];
	   q_4 = book[p].title[8];
	   if(g==var&&h==var1&&lg==var2&&lo==var3&&m1==var4&&q_1==var5&&q_2==var6&&q_3==var7&&q_4==var8)
	   {
		   lop++;
		   book[p].PrintBook();
		   cout<<endl;
	   }
  }
    cout<<"\n\n ["<<lop<< "] no.of books starting on "<<var<<var1<<var2<<var3<<var4<<var5<<var6<<var7<<var8<<"\n\n-----------Search Complete----------";
	_endthread();
}
void MessageIssued()
{
	system("CLS");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t CHANGES SAVED......";
	Sleep(800);

}
void EditBookData()
{
	BOOL flag = true;
	system("CLS");
	cout<<"\t\t\t\t\t\t**************************************\n";
    cout<<"\t\t\t\t\t\t\t     BOOK EDITOR\n";
	cout<<"\t\t\t\t\t\t**************************************\n";
	int bno,loc=0,lim=getnoofbooks();
	cout<<"\n ENTER CURRENT BOOK NUMBER : ";
	cin>>bno;
	for(int i=0; i<lim; ++i)
	{
		if(bno==book[i].bookno)
		{
			flag = false;
			book[i].PrintBook();
			book[i].Edit();
			MessageIssued();
		}
	}
	if(flag)
	{
		cout<<"\n NO BOOK DETECTED. PLEASE TRY TO ADD A NEW BOOK IN THIS NUMBER !";
		_getch();
	}
}
void DeleteBook()
{
	int temp, _c = getnoofbooks();
	BOOL flag = true;
	char answer;
	system("CLS");
	cout<<"\n\n\n Enter Book ID :";
	cin>>temp;
	for(int i=0; i<_c;++i)
	{
		if(book[i].bookno == temp)
		{
			cout<<"\n DID YOU MEAN THIS BOOK ? \n";
			book[i].PrintBook();
			ShowImp("\n\n\n\n\t\t\t\t\t DO YOU WANT TO DELETE THIS BOOK (Y/N) :");
			cin>>answer;
			if(answer=='y'||answer=='Y')
			{

				// if book is already out !
				if(book[i].availability)
				{
				  flag = false;
				  cout<<"\n\n\n\t\t\t\t Ooops... THIS BOOK IS CURRENTLY ISSUED FOR A STUDENT.";
	              cout<<"\n BOOK HOLDER DETAILS :\n";
		          int tm;
		          tm=getnoofstudents();
		          for(int w=0; w<tm; ++w)
		           {
					   if(book[i].current_holder==stu[w].roll&&stu[w].CurrentBookNumber==book[i].bookno)
			            {
			        	   stu[w].PrintStudent();
			            }
		            }
				  ShowImp("\n\n CAN'T DELETE THIS BOOK RIGHT NOW. PLEASE SUBMIT BACK THE BOOK TO LIBRARY AND TRY AGAIN !");
       		     _getch();
				  goto TERM;
		          }
				
				// Unsecure deletion has been prevented
				SaveLog(book[i].title,temp);
				book[i].Delete();
				cout<<"\n DELETED !";
				_beginthread(SaveNow,0,(void*)12);
				flag = false;
				Sleep(500);
				MessageIssued();
			}
			else   
				cout<<"\n DELETION ABORTED!\n ";
		}
	}

	 if(flag)  // If book search failed
	 {
			cout<<"\n NO BOOK WITH BOOK ID - "<<temp<<" - "<<" FOUND !";
			_getch();
	 }
	 TERM:;  // Function End from goto
}
void ShowImp(char msg[])
{
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	  cout.write(msg,strlen(msg));
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);		
}
BOOL Protection()
{
	char p1,p2,p3;
	system("CLS");
	cout<<"\n\n\n\t\t\t\t\t ---------- PASSWORD PROTECTION IS ON -----------";
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t ENTER PASSWORD :";
	p1 = toupper(_getch());
	cout<<"*";
	p2 = toupper(_getch());
	cout<<"*";
	p3 = toupper(_getch());
	cout<<"*";
	if(p1=='P'&&p2=='P'&&p3=='M')
	{
		return true;
	}
	else
		return false;
}
void ReadLock()
{
	ifstream win;
	win.open("default.bhsbiet",ios::binary|ios::app);
	while(win)
	{
	  win>>lock_status;
	}
	win.close();
}
void ShowBigMessage(char string[])
{
	system("CLS");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t";puts(string);
	Sleep(800);
}
void SetLock()
{
	ReadLock();
	if(lock_status)
	{
		cout<<"\n\n\n\n DO YOU WANT TO TURN OFF LOCK (Y/N):";
		if(toupper(_getch())==89)
		{
			lock_status=0;
			ofstream wout;
			wout.open("default.bhsbiet",ios::binary);
			wout<<lock_status;
			ShowBigMessage("LOCK DISABLED");
			wout.close();
		}
	}
	else if(!lock_status)
	{
		cout<<"\n\n\n\n DO YOU WANT TO TURN ON LOCK (Y/N) :";
		if(toupper(_getch())==89)
		{
			lock_status=1;
			ofstream wout;
			wout.open("default.bhsbiet",ios::binary);
			wout<<lock_status;
			ShowBigMessage("LOCK ENABLED");
			wout.close();
		}
	}
}
void OpenBackup(void* ARG)
{
	 system("BHSBIET_LIBRARY.txt");
}
void ChangeToUpper(char string[])
{
	for(int i=0; string[i]!='\0' ;++i)
	{
		string[i] = toupper(string[i]);
	}
}
void EditStudentData()
{
	long int reg;
	BOOL TRUTH = FALSE;
	int ct = getnoofstudents();
	cout<<"\n\n ENTER REGISTER NUMBER :";
	cin>>reg;
	for(int i=0; i<ct; ++i)
	{
		if(reg == stu[i].regno)
		{
			TRUTH = TRUE;
			stu[i].PrintStudent();
			stu[i].EditData();
		}
	}
	if(!TRUTH)
	{
		cout<<"\n\n SEARCH FAILED !\n\n PLEASE CHECK THE REGISTER NUMBER AGAIN";
	}
}
BOOL CheckStudentRegisterNumber(int reg)
{
	int x=getnoofstudents();
	BOOL status = true;
	for(int j=0; j<x ; ++j)
	{
		if(stu[j].regno==reg&&stu[j].currentc==currentclass)
		{
			status=false;
			cout<<"\n\n A Student with this register number is already present.....\n\n ";
			stu[j].PrintStudent();
			cout<<"\n\n\n PROCESS ABORTED !";
			if(_getch())
				break;
		}
	}
	return status;
}

//////////////////////////////////////////////////////////////////////

void PrintCategory()
{
	cout<<"\n\n CATEGORY LIST :-";
	cout<<"\n\n 1: REFERENCE \t 2 :STORY \t 3:NOVEL";   
}
void Category(int a)
{
	switch(a)
	{
	  case 1:cout<<"REFERENCE";
		     break;
	  case 2:cout<<"STORY";
		     break;
	  case 3:cout<<"NOVEL";
		     break;
	  
	  default :cout<<"NOT AVAILABLE!";
	}
}
void EditCategory()
{
	
	int id,op = getnoofbooks(), up;
	cout<<"\n\n\n\n\t\t\t ENTER CATEGORY NUMBER :";
	cin>>up;
	do{
	cout<<"\n\n ENTER BOOK ID :";
	cin>>id;
	for(int i=0; i<op; ++i)
	{
		if(book[i].bookno==id)
		{
			book[i].PrintBook();
			book[i].shelf = up;
		}
	}
	cout<<"n\n WANT TO EDIT MORE (Y/N) :";

	}while(toupper(_getch())==89);
	 
	//Updating whole book data 
	_beginthread(SaveNow,0,(void*)12);

}
void WriteAll()
{
	int n = getnoofbooks();
	ofstream Fout;
	Fout.open("datas.txt");
	for(int i=0; i<n ; ++i)
	{
		Fout<<book[i].title<<"\n"<<book[i].author<<"\n"<<book[i].price<<"\n"<<book[i].bookno<<"\n\n";
	}
}
