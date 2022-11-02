#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

//PROGRAM TESTS BILLING FUNCTIONS

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

/*int start()
{//func
gotoxy(32,1);
cout<<"CENTRAL PERK GROCERIES";
gotoxy(2,5);
cout<<"Access system records as\n1.Administrator\n2.Salesperson\n";
int op=0;
cin>>op;
switch(op)
{//switch
case 1: return 1; break;
case 2: return 2; break;
}//switch
}//func
*/

void addstock()
{//func
ofstream a("C:/^BILL/stock.dat",ios::binary|ios::app);
if(! a) {cout<<"error\n";return;}
stock z;
cout<<"Enter product number\n";
cin>>z.prdno;
cout<<"Enter product name\n";
gets(z.prdname);
cout<<"Enter product type code\n";
cin>>z.type;
cout<<"Enter price of 1 unit\n";
cin>>z.s_price;
cout<<"Enter number of units being stored\n";
cin>>z.s_qty;
a.write((char*)&z,sizeof(z));
a.close();
}//func

void deletestock()
{//func
ifstream d("C:/^BILL/stock.dat",ios::binary);
ofstream temp("C:/^BILL/temp_s.dat",ios::binary);
if(!d||!temp){cout<<"error\n"; return;}
stock z;
int pno;
cout<<"Enter product number whose complete details have to be erased\n";
cout<<"Warning:This can not be undone\n";
cin>>pno;
while(d.read((char*)&z,sizeof(z)))
{//while
if(z.prdno!=pno)
temp.write((char*)&z,sizeof(z));
}//while
d.close();
temp.close();
remove("stock.dat");
rename("temp_s","stock.dat");
}//func

void changestockqty()
{//func
fstream c("C:/^BILL/stock.dat",ios::binary|ios::in|ios::out);
if(!c){cout<<"error\n";return;}
stock z;
int pno,newqty;
cout<<"enter product number whose quantity needs to be changed\n";
cin>>pno;
cout<<"enter the new quantity\n";
cin>>newqty;
while(c.read((char*)&z,sizeof(z)))
{//while
if(z.prdno==pno)
{//if
z.s_qty=newqty;
c.seekg(c.tellg()-sizeof(z));
c.write((char*)&z,sizeof(z));
}//if
}//while
c.close();
}//func

void displaystock()
{//func
ifstream s("C:/^BILL/stock.dat",ios::binary);
if(!s) {cout<<"error\n"; return;}
cout<<"The stock details will be displayed as stored(as entered).\n";
stock z;
cout<<"PRD.NO\tPRD.NAME\t   TYPE\tPRICE\tQTY\n\n";
while(s.read((char*)&z,sizeof(z)))
{//while
cout<<z.prdno<<'\t'<<z.prdname<<"\t   "<<z.type<<'\t'<<z.s_price<<'\t'<<z.s_qty<<"\n";
}//while
s.close();
}//func


void main()
{
clrscr();
int op=0;
do
{
cout<<"1.add 2.delete 3.change 4.display all 5.exit\n";
cin>>op;
switch(op)
{
case 1: addstock(); break;
case 2: deletestock(); break;
case 3: changestockqty(); break;
case 4: displaystock(); break;
}}while(op!=5);
getch();
}

/*
void main()
{
clrscr();
int op=start();
*/