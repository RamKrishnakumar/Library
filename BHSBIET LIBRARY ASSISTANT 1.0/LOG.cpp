#include<iostream>
#include<conio.h>
#include<time.h>
#include<fstream>
#include<direct.h>
#include<sstream>

using namespace std;

ofstream lout;
void ClassFind(int u)
{

switch (u)
	{
	case 1:lout<<"CSE1";
	       break;
	case 2:lout<<"ECE1";
		    break;
	case 3:lout<<"ME1";
		    break;
	case 4:lout<<"EE1";
		    break;
	case 5:lout<<"CSE2";
		    break;
	case 6:lout<<"ECE2";
		    break;
    case 7:lout<<"ME2";
		    break;
	case 8:lout<<"EE2";
	       break;
	case 9:lout<<"CSE3";
		    break;
	case 10:lout<<"ECE3";
		    break;
	case 11:lout<<"ME3";
		    break;
	case 12:lout<<"EE3";
		    break;
	case 13:lout<<"CSE4";
		    break;
    case 14:lout<<"ECE4";
		    break;
    case 15:lout<<"ME4";
		    break;
	case 16:lout<<"EE4";
	       break;
	case 17 :lout<<"TEACHER";
		    break;
	}
}
void Init()
{
	mkdir("\Log");
	lout.open("C:\LOG\\log.txt",ios::app);

}
void PrintTime()
{
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
	int year=now->tm_year + 1900;
	int month=now->tm_mon + 1;
	int day=now->tm_mday;
	int hr = now->tm_hour;
	int min = now->tm_min;
	int sec = now ->tm_sec;
	lout<<" on "<<day<<"/"<<month<<"/"<<year<<" at "<<hr<<":"<<min<<":"<<sec;
}
void SaveLog(char str[])   //Common
{
	lout<<"\n  "<<str;PrintTime();
}
void SaveLog(char name[], int c, int roll)  // New Student Added
{
	lout<<"\n  A NEW STUDENT "<<name<<" [CLASS :";ClassFind(c);lout<<" ROLL:"<<roll<<"] IS ADDED TO DATABASE";PrintTime();
}
void SaveLog(int bno, char name[],int c)  //BOOK ISSUE
{
	lout<<"\n  A BOOK "<<" [BOOK NO "<<bno<<"] IS ISSUED FOR "<<name<<" CLASS - ";ClassFind(c);PrintTime();
}
void SaveLog(char name[] , int bno, int c, int p)  //BOOK SUBMISSION
{
	lout<<"\n  "<<name<<" CLASS :";ClassFind(c);lout<<" RETURNED A BOOK [BOOK NO."<<bno<<"]";PrintTime();
}
void SaveLog(int bno,char name[])
{
	lout<<"\n  A NEW BOOK NAMED \""<<name<<"\" IS ADDED TO DATABASE. BOOK ID :"<<bno;PrintTime();
}
void SaveLog(char name[], int bno)
{
	lout<<"\n  THE BOOK NAMED \""<<name<<"\" HAS BEEN DELETED FROM THE DATABASE. BOOK ID :"<<bno;PrintTime();
}
void SaveLog(char name[],int roll,int a,int b, int c)
{
	lout<<"\n  THE STUDENT  \""<<name<<"\" HAS BEEN DELETED FROM THE DATABASE. ROLL NO :"<<roll;PrintTime();
}