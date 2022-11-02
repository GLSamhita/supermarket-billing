#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

//PROGRAM CREATES ACCESS ACCOUNTS

struct admin
{//admin
char a_un[20];
char a_p[10];
};//admin

struct sp
{//sp
char sp_un[20];
char sp_p[10];
};//sp

struct stock
{//stock
int prdno;
char prdname[20];
char type[20];
double s_price;
int s_qty;
};//stock

struct bill
{//bill
char date[15];
int prdno,billno;
char prdname[20];
int type;
int b_qty;
double b_price;
double b_prdrate;
};//bill

void createadmin()
{//func
admin z,x;
fstream a("C:/^BILL/admin.dat",ios::binary|ios::app|ios::in);
if(!a) {cout<<"error\n"; return;}
cout<<"Enter admin username\n";
cin>>z.a_un;
cout<<"Enter password (Warning:password is not encrypted)\n";
cin>>z.a_p;
a.write((char*)&z,sizeof(z));
cout<<"Account created\n";
a.close();
cout<<"Press any key to continue\n";
getch();
clrscr();
}//func

void createsp()
{//func
fstream s("C:/^BILL/sp.dat",ios::binary|ios::app|ios::in);
if(!s) {cout<<"error\n"; return;}
sp z;
cout<<"Enter sales person username\n";
cin>>z.sp_un;
cout<<"Enter password\nWarning:password is not encrypted\n";
cin>>z.sp_p;
s.write((char*)&z,sizeof(z));
cout<<"Account created\n";
}//func

void main()
{
clrscr();
createadmin();
createsp();
getch();
}