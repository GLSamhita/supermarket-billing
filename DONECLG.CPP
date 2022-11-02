#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

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
int type;
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

//FUNCTIONS
int start();
int ret1();
int ret2();
int ret3();
void logadmin();
void logsp();
void addstock();
void deletestock();
void displaystock();
void changestockqty();
void addbill();
void deletebill();
void displaybill();
void createadmin();
void createsp();

int start()
{//func
clrscr();
int op=0,q;
gotoxy(30,1);
cout<<"*CENTRAL PERK GROCERIES*";
gotoxy(30,2);
cout<<" ------- ---- ---------\n\n";
cout<<"Access system as -\n1.Administrator\n2.Salesperson\n3.Exit\n";
cin>>op;
if(op==1) q=ret1();
if(op==2) q=ret2();
if(op==3) q=ret3();
return q;
}//func

int ret1()
{return 1;}
int ret2()
{return 2;}
int ret3()
{return 3;}

void logadmin()
{//func
clrscr();
admin a,t;
int ct=0,op1=0,op2=0,op3=2;
cout<<"Enter user name\n";
cin>>a.a_un;
cout<<"Enter password (Warning:password not encrypted)\n";
cin>>a.a_p;
ifstream a_check("C:/^BILL/admin.dat",ios::binary);
if(!a_check) {cout<<"error\n"; return;}
while(a_check.read((char*)&t,sizeof(t)))
{//while
if(strcmpi(a.a_un,t.a_un)==0&&strcmpi(a.a_p,t.a_p)==0)
ct++;
}//while
if(ct!=1)
{//if
cout<<"Wrong information provided.\nAccess denied.\nPress any key to continue.\n";
getch();
clrscr();
return;
}//if
if(ct==1)
{//if
cout<<"\nUsername and password match.\nAccess granted.\nPress any key to continue\n";
getch();
clrscr();
do
{//do
clrscr();
cout<<"1.Stock \n2.Bill \n3.Add a new access account\n";
cin>>op1;
clrscr();
switch(op1)
{//switch
case 1:
cout<<"1.Add product to stock \n2.Delete product\n";
cout<<"3.Change quantity of a product \n4.Display complete stock\n";
cin>>op2;
switch(op2)
{//switch
case 1: addstock(); break;
case 2: deletestock(); break;
case 3: changestockqty(); break;
case 4: displaystock(); break;
}//switch
break;
case 2:
cout<<"1.Add bill \n2.Delete bill \n3.Display bill\n";
cin>>op2;
switch(op2)
{//switch
case 1: addbill(); break;
case 2: deletebill(); break;
case 3: displaybill(); break;
}//switch
break;
case 3:
cout<<"1.New admin\n2.New sales person\n";
cin>>op2;
switch(op2)
{//switch
case 1: createadmin(); break;
case 2: createsp(); break;
}//switch
break;
}//switch
cout<<"1.Logout 2.Continue\n";
cin>>op3;
}/*do*/while(op3==2);
}//if
}//func

void logsp()
{
clrscr();
sp a,t;
int op=0,ct=0,op1=0;
cout<<"Enter username\n";
cin>>a.sp_un;
cout<<"Enter password (Warning:password not encrypted)\n";
cin>>a.sp_p;
ifstream sp_check("C:/^BILL/sp.dat",ios::binary);
if(!sp_check) {cout<<"error\n"; return;}
while(sp_check.read((char*)&t,sizeof(t)))
{//while
if(strcmpi(a.sp_un,t.sp_un)==0&&strcmpi(a.sp_p,t.sp_p)==0)
ct++;
}//while
if(ct!=1)
{//if
cout<<"Wrong information provided.\nAccess denied.\nPress any key to continue.\n";
getch();
clrscr();
return;
}//if
if(ct==1)
{//if
cout<<"\nUsername and password match.\nAccess granted.\nPress any key to continue\n";
getch();
clrscr();
do
{//do
cout<<"1.Add bill 2.Delete bill 3.Display bill\n";
cin>>op;
switch(op)
{//switch
case 1: addbill(); break;
case 2: deletebill(); break;
case 3: displaybill(); break;
}//switch
cout<<"1.Logout 2.Continue\n";
cin>>op1;
}/*do*/while(op1==2);
}//if
}//func

void addstock()
{//func
clrscr();
ofstream a("C:/^BILL/stock.dat",ios::binary|ios::app);
if(!a) {cout<<"error\n"; return;}
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
cout<<"Press any key to continue\n";
getch();
clrscr();
}//func

void deletestock()
{//func
clrscr();
ifstream d("C:/^BILL/stock.dat",ios::binary);
ofstream temp("C:/^BILL/temp_s.dat",ios::binary);
if(!d||!temp) {cout<<"error\n"; return;}
stock z;
int pno;
cout<<"Enter product number whose complete details have to be erased (Warning:this can not be undone)\n";
cin>>pno;
while(d.read((char*)&z,sizeof(z)))
if(z.prdno!=pno)
temp.write((char*)&z,sizeof(z));
d.close();
temp.close();
remove("C:/^BILL/stock.dat");
rename("C:/^BILL/temp_s.dat","C:/^BILL/stock.dat");
cout<<"Press any key to continue\n";
getch();
clrscr();
}//func

void changestockqty()
{//func
clrscr();
fstream c("C:/^BILL/stock.dat",ios::binary|ios::in|ios::out);
if(!c) {cout<<"error\n"; return;}
stock z;
int pno,newqty;
cout<<"Enter product number whose quantity needs to be changed\n";
cin>>pno;
cout<<"Enter the new quantity\n";
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
cout<<"Press any key to continue\n";
getch();
clrscr();
}//func

void displaystock()
{//func
ifstream s("C:/^BILL/stock.dat",ios::binary);
if(!s) {cout<<"error\n"; return;}
stock z;
int ct=0;
clrscr();
cout<<"The stock details will be displayed as stored(as entered).\n";
gotoxy(1,3);
cout<<"PRD.NO.";
gotoxy(9,3);
cout<<"PRD.NAME";
gotoxy(24,3);
cout<<"TYPE";
gotoxy(30,3);
cout<<"QTY";
gotoxy(35,3);
cout<<"MRP";
while(s.read((char*)&z,sizeof(z)))
{//while
ct++;
gotoxy(1,ct+1+3);
cout<<z.prdno;
gotoxy(9,ct+1+3);
cout<<z.prdname;
gotoxy(24,ct+1+3);
cout<<z.type;
gotoxy(30,ct+1+3);
cout<<z.s_qty;
gotoxy(35,ct+1+3);
cout<<z.s_price;
}//while
s.close();
cout<<"\n\nPress any key to continue\n";
getch();
clrscr();
}//func

void addbill()
{//func
clrscr();
bill z,c,v;
stock a;
int op=1;
do
{//do
cout<<"Enter bill number\n";
cin>>z.billno;
cout<<"Enter product number\n";
cin>>z.prdno;
fstream st("C:/^BILL/stock.dat",ios::binary|ios::in|ios::out);
fstream bi("C:/^BILL/bills.dat",ios::binary|ios::app|ios::in);
if(!st||!bi) {cout<<"error\n"; return;}
while(st.read((char*)&a,sizeof(a)))
{//while
if(a.prdno==z.prdno)
{//if
strcpy(z.prdname,a.prdname);
z.type=a.type;
z.b_price=a.s_price;
}//if
}//while
cout<<"enter quantity\n";
cin>>z.b_qty;
z.b_prdrate=z.b_qty*z.b_price;
a.s_qty=a.s_qty-z.b_qty;
st.seekg(st.tellg()-sizeof(a),ios::beg);
st.write((char*)&a,sizeof(a));
bi.write((char*)&z,sizeof(z));
cout<<"Add another item to this bill - 1.Yes 2.No\n";
cin>>op;
}while(op==1);
cout<<"Press any key to continue\n";
getch();
clrscr();
}//func

void deletebill()
{//func
clrscr();
bill z;
int bno;
cout<<"Enter the bill number of the bill to be deleted (Warning:this can not be undone)";
cin>>bno;
ifstream b_in("C:/^BILL/bills.dat",ios::binary);
ofstream b_out("C:/^BILL/temp_b.dat",ios::binary|ios::app);
if(!b_in||!b_out) {cout<<"error\n"; return;}
while(b_in.read((char*)&z,sizeof(z)))
{//while
if(z.billno==bno);
else
b_out.write((char*)&z,sizeof(z));
}//while
b_in.close();
b_out.close();
remove("C:/^BILL/bills.dat");
rename("C:/^BILL/temp_b.dat","C:/^BILL/bills.dat");
cout<<"Press any key to continue\n";
getch();
clrscr();
}//func

void displaybill()
{
bill z;
int bno,ct=0;
cout<<"Enter bill number to be displayed\n";
cin>>bno;
ifstream a("C:/^BILL/bills.dat",ios::binary);
if(!a) {cout<<"error\n"; return;}
clrscr();
gotoxy(1,3);
cout<<"BILL NO."<<bno;
gotoxy(1,5);
cout<<"PRD.NO.";
gotoxy(9,5);
cout<<"PRD.NAME";
gotoxy(24,5);
cout<<"TYPE";
gotoxy(30,5);
cout<<"QTY";
gotoxy(35,5);
cout<<"MRP";
gotoxy(42,5);
cout<<"PRICE";
while(a.read((char*)&z,sizeof(z)))
{//while
if(z.billno==bno)
{//if
ct++;
gotoxy(1,ct+1+5);
cout<<z.prdno;
gotoxy(9,ct+1+5);
cout<<z.prdname;
gotoxy(24,ct+1+5);
cout<<z.type;
gotoxy(30,ct+1+5);
cout<<z.b_qty;
gotoxy(35,ct+1+5);
cout<<z.b_price;
gotoxy(42,ct+1+5);
cout<<z.b_prdrate;
}//if
}//while
a.close();
cout<<"\n\nPress any key to continue\n";
getch();
clrscr();
}//func

void createadmin()
{//func
clrscr();
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
clrscr();
fstream s("C:/^BILL/sp.dat",ios::binary|ios::app|ios::in);
if(!s) {cout<<"error\n"; return;}
sp z;
cout<<"Enter sales person username\n";
cin>>z.sp_un;
cout<<"Enter password (Warning:password is not encrypted)\n";
cin>>z.sp_p;
s.write((char*)&z,sizeof(z));
cout<<"Account created\n";
s.close();
cout<<"Press any key to continue\n";
getch();
clrscr();
}//func

void main()
{//main
clrscr();
int op=0;
do
{//do
op=start();
switch(op)
{//switch
case 1: logadmin(); break;
case 2: logsp(); break;
}//switch
}/*do*/while(op!=3);
getch();
}//main
