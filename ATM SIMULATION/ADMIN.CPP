// ATM SIMULATION

#include<graphics.h>
#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<ctype.h>
#include<alloc.h>
#include<stdlib.h>
#include<mouse.h>
#include<mgraph.h>
#include<declare.h>
#include<getinfo.c>
#include<login.c>



 int changepassword()
 {
	cleardevice();
	outer_function_screen("CHANGE PASSWORD");
	draw_button(225,225,395,255,1,"Administrator");
	draw_button(225,285,395,315,1,"Customer");
	draw_button(225,345,395,375,1,"Exit");
	showmouseptr();
	while(1)
	{
	 showmouseptr();
	 getmousepos(&button,&corx,&cory);
	 if((button&1)==1)
	  {
	   if((corx>225&&corx<395)&&(cory>225&&cory<255))
		{
		 hidemouseptr();
		 return(ch_pass(0));
		}
	   if((corx>225&&corx<395)&&(cory>285&&cory<315))
		{
		 hidemouseptr();
		 return(ch_pass(1));
		}
	   if((corx>225&&corx<395)&&(cory>345&&cory<375))
		{
		 hidemouseptr();
		 closegraph();
		 exit(0);
		}
	  }
	}
 }

 void rm_menu()
 {
   unsigned int ac,acc_no;
   char acc[5];
   inner_function_screen("   REMOVE ACCOUNT");
   settextstyle(3,0,2);
   setcolor(8);
   outtextxy(120,130,"Enter Account no.");
   gotoxy(43,10);
   cin>>ac;

   itoa(ac,acc,10);

   if((df=fopen(acc,"r+"))==NULL)
	{
		cleardevice();
		border();
		setcolor(RED);
		settextstyle(3,0,4);
		outtextxy(75,100,"Account doesn't exist");
		settextstyle(1,0,4);
		setcolor(WHITE);
		outtextxy(75,350,"Press any key to try again");
		getch();
		rem_account();
	}
	fclose(df);

	setcolor(GREEN);

	f1=fopen("Rem_acc.dat","rb+");
	fseek(f1,0L,SEEK_END);
	fwrite(&ac,sizeof(int),1,f1);

	 remove(acc);
	 outtextxy(120,295,"Account Successfully Removed");
	 fflush(f1);
	 fclose(f1);
	 getch();
 }

 void rem_account()
 {
   cleardevice();
   outer_function_screen("REMOVE ACCOUNT");
   draw_button(220,225,425,255,1,"Remove Account");
   draw_button(220,285,425,315,1,"  EXIT");

   showmouseptr();
	while(1)
	{
	 getmousepos(&button,&corx,&cory);
	 if((button&1)==1)
	  {
	   if((corx>220&&corx<425)&&(cory>225&&cory<255))
		{
		 hidemouseptr();
		 rm_menu();
		 return;
		}
	   if((corx>220&&corx<425)&&(cory>285&&cory<315))
		{
		 hidemouseptr();
		 showadminmenu();
		 exit(0);
		}
	  }
	}
 }

 void displaydata()
 {
	char *c;
	cleardevice();
	hidemouseptr();
	cleardevice();
	border();
	setcolor(GREEN);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(70,20,"LIST OF ACCOUNTS IN BANK");
	setcolor(LIGHTGRAY);
	line(8,95,getmaxx()-8,95);
	line(8,100,getmaxx()-8,100);
	settextstyle(1,HORIZ_DIR,1);
	outtextxy(15,120,"Acc.No.");
	outtextxy(150,120,"Name");
	outtextxy(300,120,"Address");
	outtextxy(500,120,"Balance");
 }

 void list_of_accounts()
  {
	int l,ct=0,i=0,j=0,fl=0,acc_no,k=0;
	static int acc_list[50];
	displaydata();

	f1=fopen("Rem_acc.dat","rb+");
	 rewind(f1);
	while(fread(&acc_no,sizeof(int),1,f1))
	  {
		acc_list[k++]=acc_no;
	  }
	fclose(f1);

	fp=fopen("cust.dat","rb+");
	rewind(fp);
	i=10;
	while(fread(&cust,sizeof(cust),1,fp))
	 {
	  fl=0;
	  for(j=0;j<k;j++)
	   {
		if(cust.acc_no==acc_list[j])
		 {
		  fl=1;
		  break;
		 }
	   }
	  if(fl==1)
		continue;
	   ct=0;
	   gotoxy(5,i);
	   printf("%d",cust.acc_no);
	   gotoxy(20,i);
	   puts(cust.fname);
	   if(strlen(cust.address.add1)>0)
	   {
		gotoxy(35,i);
		printf("%s",cust.address.add1);
		ct++;
	   }
	   if(strlen(cust.address.add2)>0)
	   {
		gotoxy(35,i+ct);
		printf("%s",cust.address.add2);
		ct++;
	   }
	   if(strlen(cust.address.add3)>0  && strcmpi(cust.address.add2,cust.address.add2)!=0)
	   {
		gotoxy(35,i+ct);
		printf("%s",cust.address.add3);
		ct++;
	   }
	   if(strlen(cust.address.city)>0 || strlen(cust.address.state)>0)
	   {
		gotoxy(35,i+ct);
		printf("%s %s",cust.address.city,cust.address.state);
		ct++;
	   }
	   gotoxy(65,i);
	   printf("%lu",cust.balance);
	   i=i+ct;
	  }
	 fclose(fp);
	 settextstyle(1,0,4);
	 outtextxy(40,410,"Press any key to go to MAIN MENU");
	 getch();
   }


 void show_transactions()
   {
	unsigned int l,ac;
	char acc[5];
	inner_function_screen("TRANSACTIONS");
	settextstyle(3,0,2);
	setcolor(8);
	outtextxy(120,130,"Enter Account no.");
	gotoxy(42,10);
	cin>>ac;

	itoa(ac,acc,10);
	if((fp=fopen(acc,"rb+"))==NULL)
	 {
	  show_err("Sorry! Account doesn't exist");
	  settextstyle(1,0,4);
	  setcolor(WHITE);
	  outtextxy(75,350,"Press any key to try again");
	  return;
	 }
	fclose(fp);
	tran_enquiry(ac);
   }

 void showadminmenu()
 {
  delay(250);
  cleardevice();
  hidemouseptr();
  border();

  settextjustify(1,1);
  settextstyle(3,0,5);
  setcolor(GREEN);
  outtextxy(290,80,"M A I N  M E N U");
  setcolor(WHITE);
  rectangle(210,155,450,185);
  rectangle(210,205,450,235);
  rectangle(210,255,450,285);
  rectangle(210,305,450,335);
  rectangle(210,355,450,385);
  rectangle(210,405,450,435);
  setfillstyle(1,LIGHTGRAY);
  for(i=0;i<=5;i++)
	floodfill(212,157+50*i,WHITE);
  for(i=0;i<=5;i++)
   {
	setcolor(DARKGRAY);
	line(210,185+50*i,450,185+50*i);
	line(450,155+50*i,450,185+50*i);
   }
  settextjustify(LEFT_TEXT,TOP_TEXT);
  settextstyle(3,0,1);
  setcolor(WHITE);
  outtextxy(225,155,"Create New Account");
  outtextxy(230,205,"Change Password");
  outtextxy(230,255,"Remove Account");
  outtextxy(225,305,"Transactions Enquiry");
  outtextxy(230,355,"List of Accounts");
  outtextxy(290,405,"Exit");

  showmouseptr();
  while(1)
  {
   showmouseptr();
   getmousepos(&button,&corx,&cory);
   if((button&1)==1)
   {
	if((corx>210&&corx<450)&&(cory>155&&cory<185))
	   {
	       hidemouseptr();
	       createaccount();
	       return;
	   }
	if((corx>210&&corx<450)&&(cory>205&&cory<235))
	   {
		   hidemouseptr();
		   delay(250);
		   while(!changepassword());
		   return;
	   }
	if((corx>210&&corx<450)&&(cory>255&&cory<285))
	   {
		   hidemouseptr();
		   delay(250);
		   rem_account();
		   return;
	   }
	if((corx>210&&corx<450)&&(cory>305&&cory<335))
	   {
		   hidemouseptr();
		   show_transactions();
		   return;
	   }
	if((corx>210&&corx<450)&&(cory>355&&cory<385))
	 {
		   hidemouseptr();
		   list_of_accounts();
		   return;
	 }
	if((corx>210&&corx<450)&&(cory>405&&cory<435))
	   {
		 hidemouseptr();
		 closegraph();
		 exit(0);
	   }
   }
  }
 }

 void show_close_button()
 {
  rectangle(580,8,630,20);
  line(618,8,618,20);
  settextstyle(2,0,4);
  outtextxy(583,9,"CLOSE");
  outtextxy(622,8,"x");
 }

  void enter()
  {
   while(1)
	{
	 if(successfullogin==1)
	   break;
	 show_close_button();
	 showmouseptr();
	 getmousepos(&button,&x,&y);
	  if((button&1)==1)
	  { corx=x;
		cory=y;
		if((corx>170&&corx<280)&&(cory>250&&cory<290))
		 {
			setcolor(WHITE);
			line(170,290,280,290);
			line(280,250,280,290);
			setcolor(DARKGRAY);
			line(170,250,280,250);
			line(170,250,170,290);
			delay(125);
			hidemouseptr();
			resetloginform();
			login();
		 }
		else if((corx>310&&corx<430)&&(cory>250&&cory<290))
		 {
			hidemouseptr();
			setcolor(WHITE);
			line(310,290,430,290);
			line(430,250,430,290);
			setcolor(DARKGRAY);
			line(310,250,430,250);
			line(310,250,310,290);
			delay(125);
			f1=fopen("admin","r");
			rewind(f1);
			fread(&admin,sizeof(admin),1,f1);
			if((strcmp(admin.loginid,loginid)==0) && (strcmp(admin.password,password)==0))
			 {
			  successfullogin=1;
			  return;
			 }
			else
			{
			 show_err("Wrong LoginID or Password");
			 resetloginform();
			 login();
			}
		 }
		else if((corx>618&&corx<630)&&(cory>8&&cory<20))
		{
		  show_exit_message();
		  delay(500);
		  exit(0);
		}
	  }
	}
  }

  void show_next_form()
  {
	 cleardevice();
	 hidemouseptr();
     cleardevice();
     setcolor(GREEN);
     settextstyle(10,HORIZ_DIR,3);
     outtextxy(70,20,"OPENING A NEW ACCOUNT");
     setcolor(LIGHTGRAY);
	 line(80,110,550,110);
     line(80,110,80,400);
	 setcolor(DARKGRAY);
	 line(550,110,550,400);
	 line(80,400,550,400);
	 settextstyle(1,HORIZ_DIR,1);
	 outtextxy(90,120,"Enter Floppy and press enter : ");
	 getch();
  }

 int read_card_id()
  {
   int sector=4;
   char id[2];
   int acc;
   if (absread(0, 1, sector, &fl_code) != 0)
	{
	  cleardevice();
	  perror("Disk not found");
	  getch();
	  show_next_form();
	  read_card_id();
	}
   if(strlen(fl_code.id)>0)
	{
	  gotoxy(15,10);
	  printf("Enter another floppy");
	  getch();
	  show_next_form();
	  read_card_id();
	}
   return(1);
  }

  int check_next_button()
  {
	showmouseptr();
	while(1)
	{
	 getmousepos(&button,&x,&y);
	 if((button&1)==1)
	   {
			if(((x>400)&&(x<465))&&((y>410)&&(y<440)))
			 {
			  hidemouseptr();
			  return 0;
			 }
			if(((x>475)&&(x<540))&&((y>410)&&(y<440)))
			  {
			   hidemouseptr();
			   return 1;
			  }
		}
	 }
  }

  void getdata()
   {
	cleardevice();
	hidemouseptr();
	cleardevice();
	setcolor(GREEN);
	settextstyle(10,0,3);
	outtextxy(70,20,"OPENING A NEW ACCOUNT");
	get_user_info();
	showmouseptr();
	draw_button(400,410,465,440,1,"BACK");
	draw_button(475,410,540,440,1,"NEXT");
	if(check_next_button()==0)
	   return;
	hidemouseptr();
	cleardevice();
	getbalance();
	draw_button(400,410,465,440,1,"BACK");
	draw_button(475,410,540,440,1,"NEXT");
	if(check_next_button()==0)
	   return;
	hidemouseptr();
	cleardevice();
	show_next_form();
	read_card_id();

	cleardevice();
	fl_code.id[0]=cust.fname[0];
	fl_code.id[1]=cust.lname[0];
	fl_code.acc_no=cust.acc_no;
	abswrite(0,1,4,&fl_code);

	 passwd.code=fl_code;
	 randomize();
	 passwd.pass=random(9999)+1;
	 gotoxy(35,10);
	 printf("****%.4d****",passwd.pass);
	 border();
	 settextstyle(1,0,5);
	 outtextxy(75,50,"Your PIN number is");

	 ft=fopen("password.dat","rb+");
	 fseek(ft,0,SEEK_END);
	 fwrite(&passwd,sizeof(passwd),1,ft);

	 fp=fopen("cust.dat","rb+");
	 fseek(fp,0,SEEK_END);
	 fwrite(&cust,sizeof(cust),1,fp);

	 df=fopen("data.dat","rb+");
	 fseek(df,0,SEEK_SET);
	 fread(&data,sizeof(data),1,df);
	 data.acc_no=cust.acc_no+1;
	 fseek(df,0,SEEK_SET);
	 fwrite(&data,sizeof(data),1,df);

	 flushall();
	 fcloseall();
	 getch();
	 return;
  }

   void createaccount()
   {
	  getdata();
   }

   void login()
   {
	showloginform();
	getloginid();
	getpassword();
	enter();
   }

   void graphics()
   {
	d=DETECT;
	initgraph(&d,&m,"c:\\tc\\");
	initmouse();
	mx=getmaxx();
	my=getmaxy();
   }

   void init()
   {
	graphics();
	border();
	settextstyle(4,0,5);
	outtextxy(100,40,"ATM SIMULATION");
	setcolor(YELLOW);
	line(100,88,520,88);
	setcolor(RED);
	line(100,90,520,90);
   }

   void start()
   {
	  i=0;
	  init();
	  setcolor(WHITE);
	  settextstyle(1,0,4);
	  outtextxy(100,400,"Press any key to Continue");

	 if((f1=fopen("firstrun","r"))==NULL)
	  {
	   f1=fopen("firstrun","w+");
	   border();
	   while(!kbhit())
	   {
		if(i%2==0)
		 setcolor(GREEN);
		else
		 setcolor(BLACK);
		settextstyle(1,0,3);
		outtextxy(75,300,"Program is running for the first time");
		delay(500);
		i++;
	   }
	   f2=fopen("Admin","wb+");
	   f3=fopen("data.dat","wb+");
	   f5=fopen("rem_acc.dat","wb+");
	   f6=fopen("password.dat","wb+");
	   df=fopen("cust.dat","wb+");
	   ft=fopen("transactions","wb+");
	   strcpy(admin.loginid,"admin");
	   strcpy(admin.password,"password");
	   fwrite(&admin,sizeof(admin),1,f2);
	   data.acc_no=10001;
	   data.tran_no=1000000;
	   fwrite(&data,sizeof(data),1,f3);
	   flushall();
	   fcloseall();
	  }
	  getch();
   }

   void main()
   {
	 start();
	 login();
	 welcomeuser(0,"ADMINISTRATOR");
	 showadminmenu();
	 cleardevice();
	 showmouseptr();

	 while(1)
	 {
	  showadminmenu();
	  getch();
	 }
   }

