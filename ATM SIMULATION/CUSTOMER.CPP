#include<graphics.h>
#include<iostream.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<alloc.h>
#include<stdlib.h>
#include<mouse.h>
#include<mgraph.h>
#include<declare.h>
#include<getinfo.c>
#include<login.c>


 unsigned int al_money,al_status=0,accountno=10001;
 unsigned long money;
 int w,p,l;

int  check_id();
void displaydata();
void show_next_form();
int  get_id();
void floppy();
void show_menu();
void getpasswd();

void withdrawl()
{
 char *acc;
 inner_function_screen(" MONEY WITHDRAWL");
 settextstyle(3,0,2);
 outtextxy(125,150,"Enter amount: Rs. ");
 gotoxy(41,11);
 cin>>money;

 f1=fopen("cust.dat","rb+");
 fseek(f1,0,SEEK_SET);

 while(fread(&cust,sizeof(cust),1,f1))
 {
   if(cust.acc_no==accountno)
	 break;
 }
 if(cust.balance>500)
 {
   if(cust.balance<(money+500))
	{
			 cleardevice();
			 border();
			 setcolor(RED);
			 settextstyle(3,0,4);
			 outtextxy(175,100,"Not sufficient Balance");
			 settextstyle(1,0,4);
			 setcolor(WHITE);
			 outtextxy(75,350,"Press Enter to try again");
			 return;
	}
   gotoxy(22,19);
   printf("%lu",money);
   setcolor(WHITE);
   settextstyle(3,0,3);
   outtextxy(120,278," Rs.    has been withdrawn ");
   cust.balance-=money;
   itoa(cust.acc_no,acc,10);
   ac=fopen(acc,"ab+");
   ft=fopen("transactions","rb+");
   df=fopen("data.dat","rb+");
   fseek(ac,0,SEEK_END);
   fseek(ft,0,SEEK_END);
   fseek(df,0,SEEK_SET);

   trans.acc_no=cust.acc_no;
   _strdate(cur_date);
   _strtime(cur_time);
   strcpy(trans.date,cur_date);
   strcpy(trans.time,cur_time);
   trans.amount=money;
   fread(&data,sizeof(data),1,df);
   trans.tran_no=data.tran_no;
   data.tran_no++;
   trans.tran_no++;
   fseek(df,0,SEEK_SET);
   fwrite(&data,sizeof(data),1,df);    //Update transaction no in data file
   fwrite(&trans,sizeof(trans),1,ft);  //write transaction to global transaction file
   fwrite(&trans,sizeof(trans),1,ac);  //write transaction to customer's transaction file
   long back=sizeof(cust);
   fseek(f1,-back,SEEK_CUR);
   fwrite(&cust,sizeof(cust),1,f1);
   flushall();
   fcloseall();
   settextstyle(1,0,4);
   outtextxy(40,410,"Press any key to go to MAIN MENU");
   getch();
 }
}

 void bal_enquiry()
 {
  gotoxy(25,10);
  inner_function_screen("   Balance Enquiry");
  f1=fopen("cust.dat","rb+");
  fseek(f1,0,SEEK_SET);
  while(fread(&cust,sizeof(cust),1,f1))
  {
   if(cust.acc_no==accountno)
	{
	 printf("The balance is :%d",cust.balance);
	 settextstyle(1,0,4);
	 outtextxy(40,410,"Press any key to go to MAIN MENU");
	 fclose(f1);
	 return;
	}
  }
  fclose(f1);
 }

 void showusermenu()
 {
  delay(50);
  hidemouseptr();
  cleardevice();
  border();
  settextjustify(1,1);
  settextstyle(3,0,5);
  setcolor(GREEN);
  outtextxy(290,80,"M A I N  M E N U");
  setcolor(WHITE);
  rectangle(210,205,420,235);
  rectangle(210,255,420,285);
  rectangle(210,305,420,335);
  rectangle(210,355,420,385);
  rectangle(210,405,420,435);
  setfillstyle(1,LIGHTGRAY);
  for(i=0;i<5;i++)
	floodfill(212,207+50*i,WHITE);
  for(i=0;i<5;i++)
   {
	setcolor(DARKGRAY);
	line(210,235+50*i,420,235+50*i);
	line(420,205+50*i,420,235+50*i);
   }
  settextjustify(LEFT_TEXT,TOP_TEXT);
  settextstyle(3,0,1);
  setcolor(BLACK);
  outtextxy(235,205,"Withdrawl");
  outtextxy(230,255,"Balance Enquiry");
  outtextxy(225,305,"Transactions Enquiry");
  outtextxy(230,355,"Change Password");
  outtextxy(290,405,"Exit");

  showmouseptr();
  while(1)
  {
   showmouseptr();
   getmousepos(&button,&corx,&cory);
   if((button&1)==1)
   {
	if((corx>210&&corx<420)&&(cory>205&&cory<235))
	   {
		   hidemouseptr();
		   withdrawl();
		   return;
	   }
	if((corx>210&&corx<420)&&(cory>255&&cory<285))
	   {
		   hidemouseptr();
		   bal_enquiry();
		   return;
	   }
	if((corx>210&&corx<420)&&(cory>305&&cory<335))
	   {
		   hidemouseptr();
		   tran_enquiry(cust.acc_no);
		   return;
	   }
	if((corx>210&&corx<420)&&(cory>355&&cory<385))
	 {
		   hidemouseptr();
		   ch_pass(1);
		   return;
	 }
	if((corx>210&&corx<420)&&(cory>405&&cory<435))
	   {
		   hidemouseptr();
		   closegraph();
		   exit(0);
	   }
   }
  }
 }

void main()
{
 d=DETECT;
 initgraph(&d,&m,"c:\\tc\\bgi");
 df=fopen("cust.dat","rb+");
 initmouse();

 while(1)
 {
  cleardevice();
  floppy();
  w=check_id();
  if(w==1)
   break;
 }
 showusermenu();
 cleardevice();
 showmouseptr();
 while(1)
  {
	showusermenu();
	getch();
  }
}

 void getpasswd()
 {
   char *pa;
   hidemouseptr();
   cleardevice();
   setcolor(GREEN);
   settextstyle(1,0,3);
   settextjustify(LEFT_TEXT,CENTER_TEXT);
   outtextxy(70,50,"ENTER PIN");
   pa=getpass("");
   gotoxy(35,4);
   int p1=strlen(pa);
   for(i=0;i<p1;i++)
	  printf("*");
   p=atoi(pa);
   getch();
 }

 int check_id()
  {
	 int r;
	 char initials[2],*name;
	 int flag=0,flag2=0;

	 r=get_id();

	 if(r==1)
	 {
		int sector=4;
		absread(0,1,sector,&fl_code);
		accountno=fl_code.acc_no;

		getpasswd();
		passwd.code=fl_code;
		passwd.pass=p;

		fseek(df, 0L ,SEEK_SET);
		fread(&cust,sizeof(cust),1,df);
		do
		 {
		  fflush(df);
		  if(cust.acc_no==fl_code.acc_no)
		  {
			initials[0]=cust.fname[0];
			initials[1]=cust.lname[0];
			strcpy(name,cust.fname);
			strcat(name," ");
			strcat(name,cust.lname);
			flag=1;
			break;
		  }
		  fread(&cust,sizeof(cust),1,df);
		 }while(!feof(df));
		fclose(df);
		if(flag==0)
		 {
			gotoxy(5,10);
			printf("ERROR...INVALID CARD or WRONG PASSWORD");
			getch();
			return 0;
		 }
		fp=fopen("password.dat","rb+");
		rewind(fp);
		while(fread(&passwd,sizeof(passwd),1,fp))
		 {
		  if(passwd.code.id[0]==initials[0] && passwd.code.id[1]==initials[1] && passwd.pass==p)
		   {
			 showmouseptr();
			 accountno=cust.acc_no;
			 welcomeuser(1,name);
			 flag2=1;
			 break;
		   }
		   fflush(fp);
		 }
		if(flag2==0)
		  {
			 cleardevice();
			 border();
			 setcolor(RED);
			 settextstyle(3,0,4);
			 outtextxy(175,100,"Invalid PIN");
			 settextstyle(1,0,3);
			 setcolor(WHITE);
			 outtextxy(75,350,"Enter Card again and enter correct PIN");
			 getch();
			 exit(0);
		  }
		 fclose(fp);
		}
	   return 1;
  }


 void floppy()
 {
  setbkcolor(BLACK);
  setcolor(GREEN);
  settextstyle(10,HORIZ_DIR,3);
  settextjustify(0,2);
  outtextxy(170,100,"ENTER FLOPPY ");
  draw_button(250,410,350,450,1,"NEXT");
  showmouseptr();
  while(1)
  {
	setcolor(BLACK);
	line(300,270,300,320);
	line(300,270,275,290);
	line(300,270,325,290);

	setcolor(GREEN);
	line(300,300,300,350);
	line(300,300,275,320);
	line(300,300,325,320);

	getmousepos(&button,&x,&y);
	if((button&1)==1)
	 {
	  if((x>250 && x<350) && (y>410 && y<450))
		break;
	 }
	delay(500);
	setcolor(BLACK);
	line(300,300,300,350);
	line(300,300,275,320);
	line(300,300,325,320);

	setcolor(GREEN);
	line(300,270,300,320);
	line(300,270,275,290);
	line(300,270,325,290);
	delay(500);
  }
 }


 void show_menu()
 {
  hidemouseptr();
  cleardevice();
  setbkcolor(BLACK);
  settextjustify(LEFT_TEXT,CENTER_TEXT);
  rectangle(1,1,getmaxx()-1,getmaxy()-1);
  draw_button(200,100,400,150,1,"Transaction");
  draw_button(200,200,400,250,1,"Balance Enquiry");
  draw_button(200,300,400,350,1,"Change Password");
  draw_button(200,400,400,450,1," Exit");
  showmouseptr();
 }


int get_id()
{
  unsigned int sector,accno;
  sector = 4;
  if (absread(0, 1, sector, &fl_code) != 0)
	{
	 cleardevice();
	 gotoxy(10,8);
	 printf("Disk not detected. Either the diskette is damaged or corrupted.");
	 gotoxy(15,10);
	 printf("Enter floppy and press ENTER");
	 getch();
	 delay(50);
	 get_id();
	}

  if((f1=fopen("rem_acc.dat","rb+"))==NULL)
  {
   show_err("File rem_acc.dat Missing");
   exit(0);
  }
  while(fread(&accno,sizeof(unsigned int),1,f1))
  {
   if(accno==fl_code.acc_no)
   {
	show_err("Account Doesn't exist");
	fclose(f1);
	exit(0);
   }
  }
  fclose(f1);
  return(1);
}

 void displaydata()
  {
	 char *c;
	 cleardevice();
	 hidemouseptr();
	 cleardevice();
	 setcolor(GREEN);
	 settextstyle(10,HORIZ_DIR,3);
	 outtextxy(70,20,"LIST OF ACCOUNTS IN BANK");
	 setcolor(LIGHTGRAY);
	 line(0,90,getmaxx(),90);
	 line(0,100,getmaxx(),100);
	 settextstyle(1,HORIZ_DIR,1);
	 outtextxy(10,120,"Acc.No.");
	 outtextxy(150,120,"Name");
	 outtextxy(300,120,"Address");
	 outtextxy(500,120,"Balance");
  }
