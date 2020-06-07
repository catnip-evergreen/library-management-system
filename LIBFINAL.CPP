//FINAL LIBRARY MANAGEMENT PROJECT 12-A BY PRERNA AND STUTI

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<bios.h>
#include<fstream.h>

//prottotype of various functions
void member1();
void book1();
void mainpage();






void introscreen() // function for the introduction screen of the library management system

 {

     setfillstyle(SOLID_FILL,11);
    floodfill(100,100,11);

	settextstyle(10,0,6);
	setcolor(1);
	outtextxy(170,50,"LIBRARY");
	delay(400);


	settextstyle(10,0,4);
	setcolor(9);
	outtextxy(165,170,"MANAGEMENT");
	delay(400);


	settextstyle(10,0,4);
	setcolor(1);
	outtextxy(240,250,"SYSTEM");
	delay(400);



	settextstyle(3,0,2);
	setcolor(9);
	outtextxy(450,430,"By-Stuti & Prerna");
	delay(1500);



       cleardevice();



 }




////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

//DEFINITION OF THE CLASS MEMBER AND ITS VARIOUS MEMBER FUNCTIONS



class member //class definng the details of the member of the library

 {


     char name[20];//name of the member
     char add[30]; //address of the member
     char num[10]; //phone no. pf the member
     char email[20];//email id of the member



  public:

    int status; //status explains whether the member has issued a book or not
    char code[10];//code of the member
    char date_is[12];//date of issueing for the member
    char date_rt[12];//date for returning for the member

    void getdata();//to input member details
    void display();//to display member details
    void search();//to search for a member
    void addition();// to add a new record
    void del();//to delet exsisting record
    void modify();//to modify an existing record
    void displayall();//to display all the records entered inside the member

 } ;

member obj;//defines that the object used for member is obj


void member::search() //to search file for a particular member

 {
     clrscr();
     fstream fin;
     char name[20];
     char code[10];
     int key4=0;



  do

   {

      int count=0;

      clrscr();


      cout<<"SEARCH MENU";
      cout<<"WHAT DO YOU WANT TO SEARCH BY"<<'\n';
      cout<<"1.SEARCH BY NAME"<<'\n';
      cout<<"2.SEARCH BY CODE"<<'\n';
      cout<<"3.EXIT TO MEMBER MANAGEMENT"<<'\n';
      cout<<"ENTER YOUR CHOICE"<<'\n';



      key4=bioskey(0);


      switch(key4)

	{


	     case  561://bioskey for option 1


			clrscr();
			cout<<"Enter the name to be searched :";
			gets(name);
			fin.open("member.txt",ios::in);
			fin.seekg(0,ios::beg);//set file pointer to the beginning
			fin.read((char*)&obj,sizeof(obj));//read first record
			count=0;
			while(!fin.eof())//search whole file

			    {
				if(strcmp(obj.name,name)==0)

				    {
					   count++;
					   obj.display();

				    }
				fin.read((char*)&obj,sizeof(obj));//read next record

			    }
			fin.close();//close file
			if(count>0)
			cout<<"MEMBER EXISTS";
			else
			cout<<"MEMBER DOESNT EXIST";
			getch();
			break;





	     case 818 : //key for 2



			clrscr();


			cout<<"Enter the code to be searched :";
			gets(code);
			fin.open("member.txt",ios::in);
			fin.seekg(0,ios::beg);//set file pointer to the beginning
			fin.read((char*)&obj,sizeof(obj));//read first record
			count=0;

			while(!fin.eof())//search whole file

			  {

			       if(strcmp(obj.code,code)==0)

				   {
					 count++;
					 obj.display();

				   }
			       fin.read((char*)&obj,sizeof(obj));//read next record
			  }
			fin.close();//close file
			if(count>0)
			cout<<"MEMBER EXISTS";
			else
			cout<<"MEMBER DOESNT EXIST";
			getch();
			break;



	       case 1075: //key for 3
			 clrscr();
			 member1();
			 break;

	   }

}
while(key4!=1075);

}


void member::modify()
{ clrscr();
  fstream fin;
  int n1,z=0,f=0,status1=0,key4=0;
  char nm1[20],id1[20],add2[20],num1[10];
  char code[10];
  char ch='y';

  while (ch=='y')
	{
	 fin.open("member.txt",ios::in|ios::out);
	 cout<<"ENTER THE MEMBER CODE FOR WHICH YOU WANT TO MODIFY ";
	 gets(code);
	 while(!fin.eof())
		  {  f=0;
		   n1=fin.tellg();
		   fin.read((char*)&obj,sizeof(obj));

		   if(strcmp(obj.code,code)==0)
			   { f=1;
			    cout<<"ENTER THE UPDATED INFORMATION\n";
			    cout<<"ENTER NEW MEMBER NAME\n";
			    gets(nm1);
			    cout<<"ENTER NEW MEMBER ADDERESS \n";
			    gets(add2);
			    cout<<"ENTER NEW MEMBER PHONE NUMBER \n";
			    gets(num1);
			    cout<<"ENTER NEW MEMBER EMAIL ID \n";
			    gets(id1);
			    cout<<"ENTER NEW MEMBER STATUS (0=AVAILABLE, 1=UNAVALIABLE)\n";
			    cin>>status1;
			    strcpy(name,nm1);
			    strcpy(add,add2);
			    strcpy(num,num1);
			    strcpy(email,id1);
			    status=status1;
			    fin.seekg(n1);
			    fin.write((char*)&obj,sizeof(obj));//write modified data in the file

			    break;
			    }


		  }
       if(f==0)
	   {
	   cout<<'\n';
	    cout<<"No record stored for this code. Please proceed to add" <<'\n';
	  }
	    fin.seekg(0);
	    fin.close();
   cout<<"Any more records to be modified<<y/n>>----> :";
   cin>>ch;

  }
  cout<<"\nWHERE DO YOU WANT TO PROCEED?\n1. ADD \n2. MEMBER MANAGEMENT \n3. MAIN MENU ";
  key4=bioskey(0);
  switch (key4)
	    { case 561:
	      obj.addition();
	      break;

	      case 818:
	      member1();
	      break;

	      case 1075:
	      mainpage();
	      break;

	      default :
	      exit(0);

	     }
  }





void member::getdata()
{
clrscr();
cout<<"REENTER MEMBER CODE: ";
cin>>code;
cout<<"ENTER MEMBER NAME: ";
cin>>name;
cout<<"ENTER MEMBER ADDERESS: ";
cin>>add;
cout<<"ENTER MEMBER PHONE NUMBER: ";
cin>>num;
cout<<"ENTER MEMBER EMAIL ADDERESS: ";
cin>>email;
cout<<"ENTER MEMBER STATUS(0=AVAILABLE, 1=UNAVAILABLE): ";
cin>>status;


}

void member::addition()// to add new record
{
clrscr();
char code1[10];
fstream fio;
char ch='y';


       while (ch=='y')
	     {
	       cout<<"ENTER MEMBER CODE: ";
	       gets(code1);
	       fstream fin;
	       //checking if code is available for new entry
	       fin.open("member.txt",ios::in);
	       fin.seekg(0,ios::beg);//set file pointer to the beginning
	       fin.read((char*)&obj,sizeof(obj));//read first record
	       int count=0;
		      while(!fin.eof())//search whole file
			       {
			       if (strcmp(obj.code,code1)==0)
				  {
				      count++;
				       break;

				  }
				  else
				      fin.read((char*)&obj,sizeof(obj));//read next record
				}
	       fin.close();//close file
		      if(count==0)
			     {
			     fio.open("member.txt",ios::app);//open file in append mode
			     getdata(); //new code
			     fio.write((char*)&obj,sizeof(obj));//write the data in file
			     fio.close();//close file

			     }
		      else
			     {
			      cout<<"THIS CODE IS NOT AVALAIBLE FOR NEW ENTRY" ;
			      break;
			     }
	       cout<<"Any more records <<y/n>>----> :";
	       cin>>ch;


	      }
     if(ch=='n')
     { member1();
     }


 }




void member::displayall()//to display all the data entered//PLEASE MAKE IT IN A TABULAR FORM
{
clrscr();
fstream f("member.txt",ios::in);
f.seekg(0);
f.read((char*)&obj,sizeof(obj));
       while (!f.eof())
	     {
	      cout<<"MEMBER INFORMATION IS AS FOLLOWS: ";
	      cout<<'\n';
	      cout<<"MEMBER CODE: ";
	      puts(code);
	      cout<<'\n';
	      cout<<"MEMBER NAME: ";
	      puts(name);
	      cout<<'\n';
	      cout<<"MEMBER ADDERESS: ";
	      puts(add);
	      cout<<'\n';
	      cout<<"MEMBER PHONE NUMBER: ";
	      puts(num);
	      cout<<'\n';
	      cout<<"MEMBER EMAIL ADDERESS: ";
	      puts(email);
	      cout<<'\n';
	      cout<<"STATUS: ";
	      if(status==0)
		      cout<<"AVAILABLE";
	      else
		      cout<<"UNAVAILABLE";
	      cout<<'\n'<<'\n';
	      cout<<"DATE OF ISSUING: ";
	       {
	      if(strcmp(date_is,'\0')==0)
		       cout<<"THIS MEMBER HAS NOT ISSUED"<<'\n';
	      else
		       puts(date_is);
	      }
	      cout<<'\n';
	      cout<<"DATE OF RETURNING: ";
	      {
	       if(strcmp(date_rt,'\0')==0)
		       cout<<"THIS MEMBER HAS NOT RETURNED"<<'\n';
	       else
		       puts(date_rt);
	       }
	     f.read((char*)&obj,sizeof(obj));

	     cout<<'\n'<<'\n';

	 }
f.close();

getch();
member1();

}


void member::display()
{
clrscr();
cout<<"MEMBER INFORMATION IS AS FOLLOWS: ";
cout<<'\n';
cout<<"MEMBER NAME: ";
puts(name);
cout<<'\n';
cout<<"MEMBER ADDERESS: ";
puts(add);
cout<<'\n';
cout<<"MEMBER PHONE NUMBER: ";
puts(num);
cout<<'\n';
cout<<"MEMBER EMAIL ADDERESS: ";
puts(email);
cout<<'\n';
cout<<"MEMBER CODE: ";
puts(code);
cout<<'\n';
cout<<"STATUS: ";
if(status==0)
     cout<<"AVAILABLE";
else
     cout<<"UNAVALIABLE";
cout<<'\n';
cout<<"DATE OF ISSUING: ";
{
if(strcmp(date_is,'\0')==0)
      cout<<"THIS MEMBER HAS NOT ISSUED"<<'\n';
else
      puts(date_is);
}
cout<<'\n';
cout<<"DATE OF RETURNING: ";
{
if(strcmp(date_rt,'\0')==0)
      cout<<"THIS MEMBER HAS NOT RETURNED<<'\n'";
else
      puts(date_rt);
}

}




void member::del()//function to delete a record
{
clrscr();
char code1[10];
char ch='y';
fstream fin,fout;//initialise fstream
clrscr();
      while(ch=='y')
	    {
	    cout<<"ENTER CODE TO BE DELETED :";
	    gets(code1);
	    fin.open("member.txt",ios::in);//open file in input mode
	    fin.seekg(0);//set file pointer to the start
	    fout.open("temp.txt",ios::app);//open temporary file in append mode
	    fin.read((char*)&obj,sizeof(obj));//typecast object as char along with size

	    while(!fin.eof())
		 {
		 if(strcmp(obj.code,code1)!=0) //write all records that should nt be deleted in temp
		 fout.write((char*)&obj,sizeof(member));
		 fin.read((char*)&obj,sizeof(member));//rename temporary record
		 }
	    fin.close();
	    fout.close();
	    remove("member.txt");//delete old file
	    rename("temp.txt","member.txt");//renaming old file
	    cout<<"Delete any more records: ";
	    cout<<'\n';
	    cout<<"Enter y/n: ";
	    cin>>ch;

	}
if(ch=='n')
     {
      member1();
     }


}






///////////////////////////////////////////////////////////////////////////
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
class book //class for book management
{

char title1[40];
char author1[50];
char publisher1[50];



public:
char code1[20];//code of the book
int status;//staus whether book is available or not
int genre1;//genre of the book
void getdata1();//to input data into the file
void display1(); //to present data already entered
void read1();//to read member details from file
void search1();//to search for a member
void add1();// to add a new record
void del1();//to delete exsisting record
void modify1();//to modify the existing book records
void displayall1();//function to display all the records entered


} novel;

void book::displayall1()//to display all the data entered//PLEASE MAKE IT IN A TABULAR FORM
{
  clrscr();
  fstream f("book.txt",ios::in);
  f.seekg(0);
  f.read((char*)&novel,sizeof(novel));
  while (!f.eof())
    {
      cout<<"BOOK CODE: ";
      puts(code1);
      cout<<'\n';
      cout<<"NAME OF THE BOOK: ";
      puts(title1);
      cout<<'\n';
      cout<<"AUTHOR OF THE BOOK: ";
      puts(author1);
      cout<<'\n';
      cout<<"PUBLISHER OF THE BOOK: ";
      puts(publisher1);
      cout<<'\n';
      cout<<"GENRE OF THE BOOK: ";
	 {
	   if(genre1==1)
	   cout<<"ROMANCE";
	   else if(genre1==2)
	   cout<<"CRIME/THRILLER";
	   else if(genre1==3)
	   cout<<"ADVENTURE";
	   else if(genre1==4)
	   cout<<"PHILOSOPHY";
	   else if(genre1==5)
	   cout<<"NON FICTION";
	   else if(genre1==6)
	   cout<<"BIOGRAPHY/AUTOBIOGRAPHY";
	   else if(genre1==7)
	   cout<<"SCI FI";
	   else if(genre1==8)
	   cout<<"EDUCATION";
	   else
	   cout<<"OTHER";

	 }
      cout<<'\n';

      cout<<"STATUS: ";
      if(status==0)
      cout<<"AVAILABLE";
      else
      cout<<"UNAVAILABLE";
      cout<<'\n';

      f.read((char*)&novel,sizeof(novel));

      }
      f.close();

      getch();
      book1();

}


void book::modify1()
{

clrscr();
fstream fin;
int f=0,n2,z=0,status1=0,genre;
char title[20],author[20],publisher[50];
char code1[10];
char ch='y';

while (ch=='y')
{

  fin.open("book.txt",ios::in|ios::out);
  cout<<"ENTER THE BOOK CODE FOR WHICH YOU WANT TO MODIFY";
  gets(code1);
  while(!fin.eof())
   {
    n2=fin.tellg();
    fin.read((char*)&novel,sizeof(novel));
    if(strcmp(novel.code1,code1)==0)
	 {
	  cout<<"ENTER THE UPDATED INFORMATION\n";
	  cout<<"ENTER NEW BOOK NAME\n";
	  gets(title);
	  cout<<"ENTER AUTHOR \n";
	  gets(author);
	  cout<<"ENTER NEW PUBLISHER \n";
	  gets(publisher);
	  cout<<"ENTER GENRE NUMBER FROM THE FOLLOWING"<<'\t';
	  cout<<"\n1.ROMANCE";
	  cout<<"\n2.CRIME/THRILLER";
	  cout<<"\n3.ADVENTURE";
	  cout<<"\n4.PHILOSOPHY";
	  cout<<"\n5.NON FICTION";
	  cout<<"\n6.BIOGRAPHY/AUTOBIOGRAPHY";
	  cout<<"\n7.SCI FI";
	  cout<<"\n8.EDUCATION";
	  cin>>genre;
	  cout<<"ENTER NEW STATUS( 0=AVAILABLE, 1=UNAVALIBLE)   ";
	  cin>>status1;
	  strcpy(title1,title);
	  strcpy(author1,author);
	  strcpy(publisher1,publisher);
	  genre1=genre;
	  status=status1;
	  fin.seekg(n2);
	  fin.write((char*)&novel,sizeof(novel));//write modified data in the file
	  fin.flush();
	  f=1;
	  break;
  }

}
  if(f==0)
  cout<<"\n No record stored for this code. Please proceed to add\n";
  fin.seekg(0);
  getch();
  fin.close();

  cout<<"Any more records <<y/n>>----> : ";
  cin>>ch;
}

 cout<<"\nWHERE DO YOU WANT TO PROCEED?\n1. ADD\n2. BOOK MANAGEMENT \n3. MAIN MENU ";
 int key4=0;
 key4=bioskey(0);
 switch (key4)
 { case 561:
	     novel.add1();
	     break;
   case 818:
	     book1();
	     break;
   case 1075:
	     mainpage();
	     break;
   default:
	     exit(0);

   }



}











void book::getdata1()
{
clrscr();

cout<<"REENTER BOOK CODE: ";
gets(code1);
cout<<'\n';

cout<<"ENTER THE NAME OF THE BOOK: ";
gets(title1);
cout<<'\n';
cout<<"ENTER THE AUTHOR OF THE BOOK: ";
gets(author1);
cout<<'\n';
cout<<"ENTER THE PUBLISHER OF THE BOOK: ";
gets(publisher1);
cout<<'\n';
cout<<"ENTER THE GENRE NUMBER OF THE BOOK FROM THE FOLLOWING: ";

cout<<"\n1.ROMANCE";
cout<<"\n2.CRIME/THRILLER";
cout<<"\n3.ADVENTURE";
cout<<"\n4.PHILOSOPHY";
cout<<"\n5.NON FICTION";
cout<<"\n6.BIOGRAPHY/AUTOBIOGRAPHY";
cout<<"\n7.SCI FI";
cout<<"\n8.EDUCATION";

cout<<'\n';
cin>>genre1;


cout<<"ENTER THE STATUS(0=avaiable,1=unavalible): ";
cin>>status;
 }

void book::display1()
{
cout<<"NAME OF THE BOOK: ";
puts(title1);
cout<<'\n';
cout<<"AUTHOR OF THE BOOK: ";
puts(author1);
cout<<'\n';
cout<<"PUBLISHER OF THE BOOK: ";
puts(publisher1);
cout<<'\n';
cout<<"GENRE OF THE BOOK: ";
if(genre1==1)
cout<<"ROMANCE";
else if(genre1==2)
cout<<"CRIME/THRILLER";
else if(genre1==3)
cout<<"ADVENTURE";
else if(genre1==4)
cout<<"PHILOSOPHY";
else if(genre1==5)
cout<<"NON FICTION";
else if(genre1==6)
cout<<"BIOGRAPHY/AUTOBIOGRAPHY";
else if(genre1==7)
cout<<"SCI FI";
else if(genre1==8)
cout<<"EDUCATION";
else
cout<<"OTHER";


cout<<'\n';

cout<<"STATUS OF THE BOOK: ";
if(status==0)
cout<<"BOOK AVAILABLE";
else
cout<<"BOOK UNAVAILABLE";

cout<<'\n';


}





  void book::add1()// to add new records into the book
{
clrscr();
char code2[10];
fstream fio;
char ch='y';


     while (ch=='y'|| ch=='Y')
	     {
	       cout<<"ENTER BOOK CODE :";
	       gets(code2);
	       fstream fin;
	       //checking if code is available for new entry
	       fin.open("book.txt",ios::in);
	       fin.seekg(0,ios::beg);//set file pointer to the beginning
	       fin.read((char*)&novel,sizeof(novel));//read first record
	       int count=0;
		      while(!fin.eof())//search whole file
			       {
				  if (strcmp(novel.code1,code2)==0)
				  {count++;
				  break;

				  }
				  else
				  fin.read((char*)&novel,sizeof(novel));//read next record

				}
	       fin.close();//close file
		      if(count==0)
			     {
			     fio.open("book.txt",ios::app);//open file in append mode

			      getdata1();
				   //new code
			      fio.write((char*)&novel,sizeof(novel));//write the data in file
			      fio.close();//close file

			      }
		      else
			      {
			      cout<<"THIS CODE IS NOT AVALAIBLE FOR NEW ENTRY" ;
			      //break;
			      }
	       cout<<"\nAny more records <<y/n>>----> :";
	       cin>>ch;

	      }

if(ch=='n'|| ch=='N')
     { book1();
     }

 }






void book::search1() //to search file for a particular book
{


 clrscr();
 fstream fin;

  char title1[40];
  char author1[50];
  char publisher1[50];
  int genre1;
  char code1[20];
  int ch;
  int key5=0;

do


  {



     int count=0;

     clrscr();
     cout<<"SEARCH OPTIONS\n";
     cout<<"1.SEARCH BY TITLE"<<'\n';
     cout<<"2.SEARCH BY CODE"<<'\n';
     cout<<"3.SEARCH BY GENRE"<<'\n';
     cout<<"4.EXIT TO BOOK MANAGEMENT"<<'\n';

     cout<<"\nCHOOSE REQUIRED OPTION";








key5=bioskey(0);
switch(key5)

{

 case  561:   //BIOSKEY FOR 1

	   clrscr();
	   cout<<"ENTER THE TITLE TO BE SERCHED FOR :";
	   gets(title1);
	   fin.open("book.txt",ios::in);
	   fin.seekg(0,ios::beg);//set file pointer to the beginning
	   fin.read((char*)&novel,sizeof(novel));//read first record
	   count=0;
	   while(!fin.eof())//search whole file
		{
		   if(strcmp(novel.title1,title1)==0)
			{
			   count++;
			   novel.display1();
			 }
		     fin.read((char*)&novel,sizeof(novel));//read next record
		  }
		  fin.close();//close file
	   if(count>0)
	  cout<<"NOVEL EXISTS";
	  else
	  cout<<"NOVEL DOESNT EXIST";
	  getch();


       break;



case 818:  //KEY FOR 2

  clrscr();
   cout<<"ENTER THE BOOK CODE TO BE SEARCHED :";
   gets(code1);
      fin.open("book.txt",ios::in);
      fin.seekg(0,ios::beg);//set file pointer to the beginning
      fin.read((char*)&novel,sizeof(novel));//read first record
	count=0;
       while(!fin.eof())//search whole file
	{
	 if(strcmp(novel.code1,code1)==0)
	 {
	  count++;
	  novel.display1();
	  }
	fin.read((char*)&novel,sizeof(novel));//read next record
      }
    fin.close();//close file
    if(count>0)
    cout<<"BOOK EXISTS";
    else
    cout<<"BOOK DOESNT EXIST";
    getch();
    break;




case 1075:
clrscr();

cout<<"ENTER FROM THE FOLLOWING GENRES NUMBER\n";

cout<<"\n1.ROMANCE\n";
cout<<"2.CRIME/THRILLER\n";
cout<<"3.ADVENTURE\n";
cout<<"4.PHILOSOPHY\n";
cout<<"5.NON FICTION\n";
cout<<"6.BIOGRAPHY/AUTOBIOGRAPHY\n";
cout<<"7.SCI FI\n";
cout<<"8.EDUCATION\n";


cin>>genre1;
fin.open ("book.txt",ios::in);
fin.seekg(0,ios::beg);//set file pointer to the begg
fin.read((char*)&novel, sizeof (novel));//read first record
count=0;
while(!fin.eof())// search wholoe file
{
    if (novel.genre1==genre1)
    {count ++;
     novel.display1();
     }
   fin.read((char*)&novel, sizeof (novel));//read next record
   }
   fin.close();
   if(count>0)
   cout<<" THE GENRE EXISTS";
   else
   cout<<"GENRE DOES NOT EXSIST ";
   getch();








case 1332:
 clrscr();
 book1();
 break;

}


}

while(key5!=1332);

}




void book::del1()//function to delete an existing record
{ clrscr();
char code2[10];
fstream fin,fout;//initialise fstream
char ch='y';
  while(ch=='y')

 {
    cout<<"ENTER CODE TO BE DELETED :";
    gets(code2);
    fin.open("book.txt",ios::in);//open file in input mode
    fin.seekg(0);//set file pointer to the start
    fout.open("temp.txt",ios::app);//open temporary file in append mode
    fin.read((char*)&novel,sizeof(novel));//typecast object as char along with size

    while(!fin.eof())
    {
     if(strcmp(novel.code1,code2)!=0) //write all records that should nt be deleted in temp
     fout.write((char*)&novel,sizeof(book));
     fin.read((char*)&novel,sizeof(book));//rename temporary record
     }

    fin.close();
    fout.close();
    remove("book.txt");//delete old file
    rename("temp.txt","book.txt");//renaming old file
    cout<<"Delete any more records? Please enter y/n  ";
    cin>>ch;

  }
if(ch=='n')
   {
    book1();
   }


}
















//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

//DEFINITION AF FUNCTIONS THAT ARE NOT MEMBER FUNCTIONS OF THE CLASSES BOOK AND MEMBER



void issue1()//function to issue a book

{
    clrscr();
    char c1[10],cbook[10];
    int n4,n3,f=0,k=0;

     // entering book modify function so that we can modify book information
    fstream fin;
    fin.open("book.txt",ios::in|ios::out);
    cout<<"ENTER BOOK CODE FOR ISSUEING: ";
    gets(cbook);


    while(!fin.eof())

      {


	  n3=fin.tellg();
	  fin.read((char*)&novel,sizeof(novel));
	  if(strcmp(novel.code1,cbook)==0 &&novel.status==0)
	       {
		    cout<<'\n';
		    novel.display1();
		    novel.status=1;
		    fin.seekg(n3);
		    fin.write((char*)&novel,sizeof(novel));//write in book file
		    fin.flush();
		    f=1;
		    break;
	       }
      }
    if(f==0)
    cout<<'\n'<<"THIS BOOK DOESNT EXIST IN THE LIBRARY OR IS NOT AVAILABLE FOR ISSUEING"<<'\n';
    fin.seekg(0);
    fin.close();// close book file
    //member issueing
    if(f==1)

	{

	   fin.open("member.txt",ios::in|ios::out);   //opening member file
	   cout<<"ENTER MEMBER CODE FOR ISSUEING: ";
	   gets(c1);
	   cout<<'\n';
	   while(!fin.eof())
		   {
			n4=fin.tellg();
			fin.read((char*)&obj,sizeof(obj));
			if(strcmp(obj.code,c1)==0 && obj.status==0)
			       {
				   obj.display();
				   obj.status=1;
				   cout<<"ENTER THE DATE FOR ISSUEING: ";
				   gets(obj.date_is);
				   fin.seekg(n4);
				   fin.write((char*)&obj,sizeof(obj));
				   fin.flush();
				   k=1;
				   break;

			       }

		   }
	   if(k==0)
	   cout<<'\n'<<"THIS MEMBER HAS ALREADY ISSUED OR IS NOT A MEMBER OF THE LIBRARY";


	   fin.close();


      }
  //close member file
  cout<<"PRESS ANY KEY TO GO TO THE MAIN PAGE"<<'\n';

    getch();
    mainpage();

 }




void return1()//function to return the book
{

      clrscr();
      char c1[10],cbook[10];
      int n4,n3,f=0,k=0;

      // entering book modify function so that we can modify book information
      fstream fin;
      fin.open("book.txt",ios::in|ios::out);
      cout<<"ENTER BOOK CODE FOR RETURNING: ";
      gets(cbook);


      while(!fin.eof())
	 {
	       n3=fin.tellg();
	       fin.read((char*)&novel,sizeof(novel));
	       if(strcmp(novel.code1,cbook)==0 &&novel.status==1)
	       {
		   cout<<'\n';
		   novel.display1();
		   novel.status=0;
		   fin.seekg(n3);
		   fin.write((char*)&novel,sizeof(novel));//write in book file
		   fin.flush();
		   f=1;
		   break;
	       }
	 }
      if(f==0)
      cout<<'\n'<<"THIS BOOK DOESNT EXIST IN THE LIBRARY OR IS ALREADY RETURNED"<<'\n';
      cout<<'\n';
      fin.seekg(0);
      fin.close();// close book file
      //member returning
      if(f==1)

	  {
	     fin.open("member.txt",ios::in|ios::out);   //opening member file
	     cout<<"ENTER MEMBER CODE FOR RETURNING: ";
	     gets(c1);
	     while(!fin.eof())
		 {
		    n4=fin.tellg();
		    fin.read((char*)&obj,sizeof(obj));
		    if(strcmp(obj.code,c1)==0 && obj.status==1)
		     {
		       obj.display();
		       obj.status=0;
			cout<<"ENTER THE DATE OF RETURNING: ";
			gets(obj.date_rt);
			fin.seekg(n4);
			fin.write((char*)&obj,sizeof(obj));
			fin.flush();
			k=1;
			break;
		      }
		 }
	     if(k==0)
	     cout<<"THIS MEMBER HAS ALREADY RETURNED THE BOOK OR DOESNT EXIST AS THE MEMBER OF THE LIBRARY"<<'\n';


	     fin.close();}
	     //close member file
	     cout<<"PRESS ANY KEY TO GO TO THE MAIN MENU"<<'\n';

	     getch();
	     mainpage();


}







  void book1()//function for the main page of book management
 {
       clrscr();

       cout<<"\t\t\t\tBOOK MANAGMENT";
       cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t1.SEARCH";
       cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t2.ADD";
       cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t3.DELETE";
       cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t4.MODIFY";
       cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t5.DISPLAY ALL";
       cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t6.MAIN MENU";
       int key5=0;
       key5=bioskey(0);
       clrscr();
       if(key5==561)//bioskey for 1
	  {
	      novel.search1();
	  }
       else if(key5==818)//bioskey for 2
	  {
	      novel.add1();
	  }
       else if (key5==1075)//bioskey for 3
	  {
	      novel.del1();
	   }
       else if (key5==1332)//bioskey for 4
	  {
	      novel.modify1();
	  }
       else if (key5==1589)//bioskey for 5
	   {
	      novel.displayall1();
	   }


       else if (key5==1846)//bioskey for 6
	 {
	  mainpage();
	 }

	else
	exit(0);
 }







 void member1()//main page of book management
  {
      clrscr();
      cout<<"\t\t\t\tMEMBER MANAGMENT";
      cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t1.SEARCH";
      cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t2.ADD";
      cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t3.DELETE";
      cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t4.MODIFY";
      cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t5.DISPLAY";
      cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t6.MAIN MENU";
      int key5=0;
      key5=bioskey(0);
      clrscr();
      if(key5==561)//bioskey for 1

	  {
	      obj.search();
	    }
      else if(key5==818)//bioskey for 2
	 {
	     obj.addition();
	  }
      else if (key5==1075)//bioskey for 3
	 {
	    obj.del();
	  }
      else if (key5==1332)//bioskey for 4
	  {
	    obj.modify();
	   }
      else if (key5==1589)//bioskey for 5
	  {
	     obj.displayall();
	   }

      else if (key5==1846)//bioskey for 6
	  {
	     mainpage();
	   }

      else
	   {
	     exit(0);
	    }


}




void mainpage()
{
    clrscr();
    cout<<"\t\t\t\tM A I N  M E N U";
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t1.FIND A BOOK";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t2.ISSUE A BOOK";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t3.RETURN A BOOK";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t4.MEMBER MANAGEMENT";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t5.BOOK MANAGMENT";
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t6.EXIT";
    cout<<'\n';
    cout<<"\n Note: A fine of rupees 200 per week on any book submitted past one week of the date of issue."<<'\n';
    cout<<"\nWARNING:IF YOU PRESS ANY KEY OTHER THAN THE SPECIFIED YOU WILL GO IN A SITUATIONWITH NO WAY OUT!!!";

    int key2=0;
    key2=bioskey(0);
    clrscr();
    if(key2==561)//bioskey for 1
	 {
	     novel.search1();
	 }
    else if(key2==818)//bioskey for 2
	 {
	     issue1();
	 }
    else if (key2==1075)//bioskey for 3
	 {
	     return1();
	 }
    else if (key2==1332)//bioskey for 4
	 {
	     member1();
	 }
    else if (key2==1589)//bioskey for 5
	 {
	     book1();
	 }
    else if (key2==1846)//bioskey for 6
	 {
	     exit(0);
	 }



}











void main()//function of the main page

      {


       int gdriver = DETECT, gmode , errorcode;      //initialise graphics
       initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
       introscreen();
       delay(1000);
       closegraph();
       mainpage();





	getch();


   }


/////////////END OF PROJECT//////////////////////////////////////////////