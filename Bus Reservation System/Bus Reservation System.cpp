#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class college
{
static char n[20];
public :
void out()
{
cout<<"\t\t\tCOLLEGE NAME=\t"<<n<<endl;
}
};
char college::n[]="CHITKARA";
class teacher:public college
{
char tn[20],st[20];
public:
void in()
{
cout<<"\t\t\tENTER STUDENT NAME"<<endl;
cin.getline(tn,20);
cin.getline(tn,20);
cout<<"\t\t\tENTER ROUTE NO\n";
cin.getline(st,20);
}
void out()
{
cout<<"\t\t\tSTUDENT NAME=\t"<<tn<<endl;
cout<<"\t\t\tROUTE NO      =\t"<<st<<endl;
college::out();
cout<<"\t\t\t================================\n";
}
char*  gm()
{
return st;
}
char* gm1()
{
return tn;
}
};
class student:public college
{
char sn[20],id[20];
public:
void in()
{
cout<<"\t\t\tENTER DRIVER`S NAME"<<endl;
cin.getline(sn,20);
cin.getline(sn,20);
cout<<"\t\t\tENTER BUS NO.\n";
cin>>id;
}
void out()
{
cout<<"\t\t\tDRIVER`S NAME=\t"<<sn<<endl;
cout<<"\t\t\tBUS NO.  =\t"<<id<<endl;
college::out();
cout<<"\t\t\t================================\n";
}
};

int main()
{
while(1)
{
teacher t;
student s;
ifstream o;
ofstream ob;
int a;
cout<<"\n\t\t\t\t\t\t\t\t\t     *MAIN MENU*\n\t\t\t\t\t\t\t\t\t   ==============";
cout<<"\n\t\t\t\t\t\t\t\t   ****PRESS 1 TO INPUT DATA****\n\n"<<endl;
cout<<"\t\t\t\t\t\t\t\t   ****PRESS 2 TO DISPLAY DATA****\n\n"<<endl;
cout<<"\t\t\t\t\t\t\t\t   ****PRESS 3 FOR FOR EXIT****"<<endl;
cout<<"\n\t<<< Please Enter Required Option >>> : ";
cin>>a;
switch(a)
{
  case 1:
    cout<<"\n\n\n\t\t\t\t\t\t\t\t  ~~~~PRESS 1 FOR STUDENT DATA~~~~"<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t  ~~~~PRESS 2 FOR DRIVER DATA~~~~"<<endl;
    cout<<"\n\t<<< Please Enter Required Option >>> : ";
    cin>>a;
      switch(a)
       {
	 case 1:
	  char ch;
	  ob.open("student.cpp",ios::app);
	  do
	   {
	    t.in();
	    ob.write((char*)&t,sizeof(t));
	    cout<<"\n\n\n\t\t\t\t\t\t   ====PRESS Y/y FOR NEXT STUDENT OR ANY OTHER KEY TO DISPLAY MAIN MENU===="<<endl;
	     cout<<"\n\t<<< Please Enter Required Option >>> : ";
	     cin>>ch;
	   }while(ch=='y'||ch=='Y');
	    ob.close();

	break;


	case 2:
		  ob.open("driver1.cpp",ios::app);
	  do
	   {
	     s.in();
	      ob.write((char*)&s,sizeof(s));
	     cout<<"\n\n\n\t\t\t\t\t****PRESS Y/y FOR NEXT DRIVER OR ANY OTHER KEY TO DISPLAY MAIN MENU****"<<endl;
	      cout<<"\n\t<<< Please Enter Required Option >>> : ";
	     cin>>ch;
	   }
	     while(ch=='y'||ch=='Y');
	     ob.close();
	break;

      default:
      cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t!!!!INVALID OPTION!!!!\n";
      continue;
     }
    break;
case 2:
    cout<<"\n\n\n\t\t\t\t\t\t\t   ******PRESS 1 TO DISPLAY STUDENT DATA******";
    cout<<"\n\n\t\t\t\t\t\t\t   ******PRESS 2 TO DISPLAY DRIVER DATA******\n";
     cout<<"\n\t<<< Please Enter Required Option >>> : ";
    cin>>a;
      switch(a)
       {
	 case 1:
	  cout<<"\n\n\n\t\t\t\t\t\t\t     ~~~~PRESS 1 FOR FULL INFORMATION~~~~";
	  cout<<"\n\n\n\t\t\t\t\t\t      ~~~~~~PRESS 2 TO SEARCH ACCORDING TO ROUTE NO.~~~~~~\n";
	   cout<<"\n\t<<< Please Enter Required Option >>> : ";
	   cin >>a;
	    switch(a)
	     {
	       case 1:
	       cout<<"\n\n\n\n";
	       o.open("student.cpp");
	       o.seekg(0);
	       o.read((char*)&t,sizeof(t));
	       while(o.eof()==0)
		 {
		    t.out();
		    o.read((char*)&t,sizeof(t));
		  }
		    o.close();
		    break;
	  case 2:
	     o.open("student.cpp");
	       cout<<"\n\n\n\t\t\t\t\t\t\t    ====ENTER ROUTE NO. TO BE FOUND====\n";
	       char stream[20];
	        cout<<"\n\t<<< Please Enter Required Option >>> : ";
	       cin>>stream;
	       cout<<"\n\t\t\t\t\t\t\t*****NAMES OF STUDENTS WITH RPUTE NO. "<<stream<<"*****\n";
	       o.seekg(0);
	       o.read((char*)&t,sizeof(t));
	       int count=0;
		while(o.eof()==0)
		  {
		     if(strcmp(t.gm(),stream)==0)
		     {
		     	count++;
		     cout<<"\t\t\t\t\t\t\t\t\t~"<<t.gm1()<<"\n";
		     }
		     o.read((char*)&t,sizeof(t));
		  }
		  o.close();
		  if(count==0)
		  cout<<"\n\t\t\t\t\t\t\t      =====!!!!NOTHING TO SHOW!!!!=====\n\n";
		  break;
	       }

	  break;

       case 2:
	    cout<<"\n\n\n\n";
	     o.open("driver1.cpp");
	     o.seekg(0);
	     o.read((char*)&s,sizeof(s));
	     while(o.eof()==0)
	      {
		s.out();
		o.read((char*)&s,sizeof(s));
	      }
	       o.close();
	       break;
	   }
	break;
	case 3:
	exit(1);
	break;

default:
cout<<"\n\n\t\t\t\t\t\t\t\t     !!!!INVALID OPTION!!!!";
cout<<"\n\t\t\t\t\t\t\t\t      |||||ENTER AGAIN|||||\n\n\n";
continue;
break;
}
}
return 0;
}

