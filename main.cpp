#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<dos.h>
#include<graphics.h>
  void add_stock();
  void search_stock();
  void delete_stock();
  void mod_com_name();
  void mod_mod_name();
  void ser_com_name();
  void ser_mod_name();
  void page1();
  void page2();
  void main_menu();
  void display_stocks();
  void display();
  void generate_bill();
  void modify_stock();
  void modify_stocks();

//*****************************************************

class bill
{
char company_name[50];
char model_name[50];
char colour[20];
float price;
float tprice;
int qty;
public:
  char* getcomp()
  {
    return company_name;
  }
  char* getmod()
  {
    return model_name;
  }
  int getqty()
  {
   return qty;
  }
  float getpri()
  {
   return price;
  }
  void getdata()
  {
  cout<<"\nENTER COMPANY NAME\t\t\t";
  gets(company_name);
  cout<<"ENTER MODEL NAME\t\t\t";
  gets(model_name);
  cout<<"ENTER COLOUR\t\t\t\t";
  gets(colour);
  cout<<"ENTER QUANTITY\t\t\t\t";
  cin>>qty;
  cout<<"ENTER PRICE OF EACH MOBILE\t\t";
  cin>>price;
}
  void putdata()
  {
  cout<<"\n\n\n COMPANY NAME\t\t\t";
  puts(company_name);
  cout<<" MODEL NAME  \t\t\t";
  puts(model_name);
  cout<<" COLOUR      \t\t\t";
  puts(colour);
  cout<<" QUNTITY     \t\t\t";
  cout<<qty;
  cout<<"\n PRICE OF EACH MOBILE\t\t";
  cout<<price;
  tprice=price*qty;
  cout<<"\n TOTAL PRICE  OF STOCK  \t"<<tprice;
  }
  void calc_price();

};


//**************************************************************
void main()
  {
    clrscr();

  page1();
  page2();
  main_menu();


  getch();
  }

  //**********************************************************************


void add_stocks()
{
 clrscr();
  textbackground(5);
  textcolor(15);
 bill wd;      char ch;
  cout<<"\n\n\t\t\t###################";
 cout<<"\n\t\t\t#   ADD STOCK     #";
 cout<<"\n\t\t\t###################\n";
 do{
    ofstream ofs("mobile_stocks.dat",ios::in|ios::binary|ios::app);
    wd.getdata();
    ofs.write((char*)&wd,sizeof(wd));
    cout<<"\n\n\tDO YOU WANT TO ENTER MORE :\t";
    cin>>ch;
    }while(ch=='y');
main_menu();
}

  void bill::calc_price()
  {
   bill bomb;
   int s;
   ifstream ifs("mobile_stocks.dat",ios::in|ios::binary);
   while(!ifs.eof())
   {
    s=strcmp(bomb.model_name,model_name);
   if(s==0)
  {
   price=bomb.price;
  }
  ifs.close();
  tprice=price*qty;

  }

  }
//***************************************************************


 void search_stock()
{l:

 clrscr();
  textbackground(5);
  textcolor(15);
 int ch;
  cout<<"\n\n\t\t\t###################";
 cout<<"\n\t\t\t#   SEARCH STOCK  #";
 cout<<"\n\t\t\t###################";
 cout<<"\n\n\n\t\t1. COMPANY NAME\n";
 cout<<"\t\t2. MODEL NAME ";

 cout<<"\n\t\tSEARCH WITH RESPECT TO  ";
 cin>>ch;
 clrscr();
 if(ch==1)
 {
  ser_com_name();
 }
 else if(ch==2)
 {
  ser_mod_name();
 }
 else
 {cout<<"\n\t\tNOT A VALID ENTERY!!\n\t\t ENTER CORRECT CHOICE";
  delay(400);
 goto l;
 }

getch();    main_menu();
}
//Searching with respect to company name
void ser_com_name()
{
 bill m;
 char com_name[50];
 int i=1;

  cout<<"\n\n\t\t\t###################";
 cout<<"\n\t\t\t#   SEARCH STOCK  #";
 cout<<"\n\t\t\t###################";
 cout<<"\n\nENTER COMPANY NAME WANT TO SEARCH  ";
 gets(com_name);
 ifstream ifs("mobile_stocks.dat",ios::in|ios::binary);
 while(ifs.read((char*)&m,sizeof(m)))
 {

  if(strcmp(m.getcomp(),com_name)==0)
  {
   m.putdata();
   i=0;
  }
 }
 if(i!=0)
 {
  cout<<"\nNO STOCK FOUND";
 }
 ifs.close();
}
//********************************************************************
//searching with respect to model name
void ser_mod_name()
{
 bill m;
 char mod_name[50];
 int i=1;
  cout<<"\n\n\t\t\t###################";
 cout<<"\n\t\t\t#   SEARCH STOCK  #";
 cout<<"\n\t\t\t###################";
 cout<<"\n\n\nENTER MODLE NAME WANT TO SEARCH  ";
 gets(mod_name);
 ifstream ifs("mobile_stocks.dat",ios::in|ios::binary);
 while(ifs.read((char*)&m,sizeof(m)))
 {

  if(strcmp(m.getmod(),mod_name)==0)
  {
   m.putdata();
   i=0;
  }
 }
 if(i!=0)
 {
  cout<<"\nNO STOCK FOUND";
 }
 ifs.close();
}
//**************************************************************
//GENERATE BILL FUNCTION
void generate_bill()
{ clrscr();
  textbackground(5);
  textcolor(15);
  char cname[50];     bill m;
  float p_discount,t;
  int d;
  char mobile_no[10];
   cout<<"\n\n\t\t\t###################";
 cout<<"\n\t\t\t#   GENERATE BILL #";
 cout<<"\n\t\t\t###################";
  cout<<"\n\nENTER CUSTOMER NAME\t\t";
  gets(cname);
  cout<<"ENTER CUSTOMER MOBILE NUMBER\t";
  gets(mobile_no);
  cout<<"\n\n\tENTER MOBILE DETAILS\n\n";
  m.getdata();
  clrscr();
  cout<<"===============================================================================";
 cout<<"=\t\t\t\t  INVOICE\t\t\t\t" ;
 cout<<"\n\n\t Shop 18, WTP, JLN road, Jaipur";
  cout<<"\n\t Mobile No.9875695647\n";
 cout<<"\n================================================================================";

  cout<<"\n\tCustomer Detail\n\n CUSTOMER NAME\t\t";
  puts(cname);
  cout<<"\n MOBILE NUMBER\t\t"<<mobile_no<<"\n\n\tMobile Details";
  m.putdata();
  t=m.getpri();
  d=m.getqty();
  cout<<"\n\n\t\tAMOUNT PAID\t\t"<<t*d;

  getch();
}
//**************************************************************
//INTRODUCTION PAGE OF PROJECT
  void page1()
  {
  textbackground(1);
  textcolor(15);
  clrscr();
 cout<<" ==============================================================================";
 cout<<"\n\t\t\t    WELCOME  TO  C++  PROJECT                                            ";
 cout<<"\n\n\n\n\t\t\t    MOBILE STOCK MANAGEMENT\n\n\n                                   ";
 cout<<"\n\tMADE BY         :  PALASH JAIN  &  PARUL SHANDILYA\n\n\n";
 cout<<"\tCLASS           :  XII - B\n\n\n     ";
 cout<<"   SCHOOL          :  MAHAVEER  PUBLIC  SCHOOL                                    ";
 cout<<"\n\n\tSUBMITTED  TO   :  Mrs. SUMAN  TANEJA                                           ";
 cout<<"\n\n\n ==============================================================================";
 cout<<"\n\t\tPRESS ENTER TO CONTINUE";
 getch();
  }

  //********************************************************
  //SECOND PAGE OF PROGRAM
  void page2()
  {

  textbackground(4);
  textcolor(15);
  clrscr();
  cout<<"================================================================================";
  cout<<"\n\n\n\n\n\n\n\t\t\t######################################\n\t\t\t#\t\t\t\t     #";
 cout<<"\n\t\t\t# \t       WELCOME\t\t     #\n\t\t\t#\t\t TO\t\t     #\n\t\t\t#\tSTORE STOCK MANAGEMENT\t     #\n\t\t        #\t\t\t\t     #";
 cout<<"\n\t\t\t######################################\n\n\n\n\n\n\n\n";
 cout<<"================================================================================";
 cout<<"\n\t\t\t\t Loading";
  for(int i=0;i<10;i++)
   {
    cout<<".";
   delay(300);
   }
  }
  //*******************************************************
  //MAIN MENU
  void main_menu()
  {  clrscr();
  textbackground(2);
  textcolor(15);
  int c;
  char ch;
  l: clrscr();
  cout<<"################################################################################";
cout<<"\n       \t\t\t\t  MAIN  MENU\t\t\t\t                                                                " ;
cout<<"\n################################################################################";
cout<<"\n================================================================================";
cout<<"\n\t\t\t1.\tGENERATE  BILL";
cout<<"\n\n\t\t\t2.\tADD      STOCK";
cout<<"\n\n\t\t\t3.\tMODIFY   STOCK";
cout<<"\n\n\t\t\t4.\tSEARCH   STOCK";
cout<<"\n\n\t\t\t5.\tDELETE   STOCK";
cout<<"\n\n\t\t\t6.\tDISPLAY  STOCK";
cout<<"\n\n\t\t\t7.\tEXIT \n";
cout<<"================================================================================";
cout<<"\n\t\tENTER  YOUR  CHOICE  :  ";
  cin>>c;

  if(c==1)
  {
   generate_bill();
  }
  else if(c==2)
  {
   add_stocks();
  }
  else if(c==3)
  {
   modify_stocks();
  }
  else if(c==4)
  {
   search_stock();
  }

  else if(c==5)
  {
   delete_stock();
  }
  else if(c==6)
  {
   display();
  }
  else if(c==7)
  {
   exit(0);
  }
  goto l;
}
//***********************************************************
 //TO DISPLAY STOCK
 void display()
 {
  textbackground(5);
  textcolor(15);
  clrscr();
  cout<<"\n\n\t\t\t###################";
  cout<<"\n\t\t\t#  DISPLAY STOCK  #";
  cout<<"\n\t\t\t###################";

   display_stocks();
  }
 void display_stocks()
 {

  bill wd;      char ch;

  ifstream ifs("mobile_stocks.dat",ios::in|ios::binary);

  while(ifs.read((char*)&wd,sizeof(wd)))
  {
  wd.putdata();
  }
  cout<<"\n\n";
  ifs.close();
  getch();
 }

 //*************************************************************
 //TO DELETE STOCK
void delete_stock()
{
 textbackground(0);
  textcolor(15);
 char ch;
 bill st;  char comp[46];
 int flag=0;
 clrscr();

 do{

 cout<<"\n\t\t\t\t###################";
 cout<<"\n\t\t\t\t#   DELETE STOCK  #";
 cout<<"\n\t\t\t\t###################";
 display_stocks();
 cout<<"\n ENTER THE COMPANY NAME OF THE STOCK WANT TO DELETE:   ";
 gets(comp);
 fstream fp("mobile_stocks.dat",ios::in|ios::binary);
 ofstream fp2("to.dat",ios::out|ios::binary);
 fp.seekg(0,ios::beg);
 while(fp.read((char*)&st,sizeof(st)))
 {
   if(strcmp(comp,st.getcomp())!=0)
 {
 fp2.write((char*)&st,sizeof(st));
 }
 else
 {
 flag=1;
 }
 }
 fp2.close();
 fp.close();
 remove("mobile_stocks.dat");
 rename("to.dat","mobile_stocks.dat");
 if(flag==1)
 {
 cout<<"\n RECORD DELETED";
 }
 else
 {
 cout<<"\n RECORD NOT FOUND";
 }
 cout<<"\n DO YOU WANT TO DELETE MORE  ";
 cin>>ch;
 clrscr();
 }while(ch=='y');

}
//******************************************************************
//MODIFY WITH RESPECT TO COMPANY NAME

void modify_stock1()
{
textbackground(5);
  textcolor(15);
 fstream fp;
 bill st;
 char comp[46];
 int found=0;
 clrscr();
 cout<<"\n\t\t\t  ###################";
 cout<<"\n\t\t\t  #   MODIFY STOCK  #";
 cout<<"\n\t\t\t  ###################";
 cout<<"\n\n\t ENTER THE COMPANY NAME WHOSE STOCK YOU WANT TO MODIFY\t";
 gets(comp);
 fp.open("mobile_stocks.dat",ios::in|ios::out|ios::binary);
 while(fp.read((char*)&st,sizeof(st)) && found==0)
 {
 if(!strcmp(comp,st.getcomp()))
 {
 st.putdata();
 cout<<"\n\nENTER THE NEW DETAILS OF THE STOCK"<<endl;
 st.getdata();
 int pos=-1*sizeof(st);
 fp.seekp(pos,ios::cur);
 fp.write((char*)&st,sizeof(st));
 cout<<"\n RECORD UPDATED!!";
 found=1;
 }
 }
 fp.close();
 if(found==0)
 cout<<"\n\n RECORD NOT FOUND!!";
 getch();
 }
//MODIFY WITH RESPECT TO MODEL NAME
void modify_stock2()
{
textbackground(5);
  textcolor(15);
 fstream fp;
 bill st;
 char mod[46];
 int found=0;
 clrscr();
 cout<<"\n\t\t\t\t  ###################";
 cout<<"\n\t\t\t\t  #   MODIFY STOCK  #";
 cout<<"\n\t\t\t\t  ###################";
 cout<<"\n\n\t ENTER THE MODEL NAME WHOSE RECORD WANT TO BE MODIFY\t";
 gets(mod);
 fp.open("mobile_stocks.dat",ios::in|ios::out|ios::binary);
 while(fp.read((char*)&st,sizeof(st)) && found==0)
 {
 if(!strcmp(mod,st.getmod()))
 {
 st.putdata();
 cout<<"\n\nENTER THE NEW DETAILS OF THE STOCK"<<endl;
 st.getdata();
 int pos=-1*sizeof(st);
 fp.seekp(pos,ios::cur);
 fp.write((char*)&st,sizeof(st));
 cout<<"\n RECORD UPDATED!!";
 found=1;
 }
 }
 fp.close();
 if(found==0)
 cout<<"\n\nSORRY RECORD NOT FOUND!!";
 getch();
 }
 //*********************************************
 //MODIFY STOCK
void modify_stocks()
{
textbackground(5);
  textcolor(15);
clrscr();
 int ch;
 cout<<"\n\t\t\t\t  ###################";
 cout<<"\n\t\t\t\t  #   MODIFY STOCK  #";
 cout<<"\n\t\t\t\t  ###################";
 cout<<"\n\n\n\t\t\t\t 1. COMPANY NAME\n";
 cout<<"\t\t\t\t 2. MODEL NAME ";
 l:
 cout<<"\n\n\t\t\tMODIFY WITH RESPECT TO  ";
 cin>>ch;
 clrscr();
 if(ch==1)
 {
  modify_stock1();
 }
else if(ch==2)
 {
  modify_stock2();
 }
 else
 {cout<<"NOT VALID ENTERY";goto l;}


}
