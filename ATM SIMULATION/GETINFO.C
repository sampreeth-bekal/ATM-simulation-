//File of ATM Simulation Program

 int q=0;

 //Function to show error in the form
  void show_error(char *err)
  {
   void *ptr;
   unsigned size=imagesize(mx/2-50,my/2-25,mx/2+50,my/2+25);
   ptr=malloc(size);
   getimage(mx/2-50,my/2-25,mx/2+50,my/2+25,ptr);
   setcolor(DARKGRAY);
   rectangle(mx/2-50,my/2-25,mx/2+50,my/2+25);
   line(mx/2-50,my/2-10,mx/2+50,my/2-10);
   setfillstyle(1,LIGHTGRAY);
   floodfill(mx/2-45,my/2-20,DARKGRAY);
   settextjustify(0,1);
   settextstyle(2,0,5);
   outtextxy(mx/2-40,my/2-20,"ERROR");
   setfillstyle(1,BLACK);
   floodfill(mx/2-45,my/2+20,DARKGRAY);
   settextjustify(0,1);
   settextstyle(2,0,4);
   outtextxy(mx/2-45,my/2,err);
   setcolor(WHITE);
   rectangle(mx/2-7,my/2+8,mx/2+12,my/2+24);
   setlinestyle(1,0,1);
   rectangle(mx/2-5,my/2+10,mx/2+10,my/2+22);
   outtextxy(mx/2-3,my/2+15,"OK");
   setlinestyle(0,0,1);
   while(1)
	{
	 showmouseptr();
	 getmousepos(&button,&x,&y);
	  if((button&1)==1)
	   {
		 if((x>(mx/2-5) && x<(mx/2+10)) && (y>(my/2+10) && y<(my/2+22)))
		   {
			hidemouseptr();
			putimage(mx/2-50,my/2-25,ptr,COPY_PUT);
			return ;
		   }
	   }
	}
  }

  void getfname()
  {
	settextstyle(3,0,2);
	setusercharsize(2,3,2,3);
	settextjustify(0,2);
	setcolor(3);
	outtextxy(148,153,"First Name  :");
	gotoxy(38,11);
	gets(cust.fname);
	 if(strlen(cust.fname)!=0)
	   {
		form_fill_bit[0]=1;
		q++;
	   }
	setcolor(8);
	outtextxy(148,153,"First Name  :");
  }

  void getlname()
  {
	settextstyle(3,0,2);
	setusercharsize(2,3,2,3);
	settextjustify(0,2);
	setcolor(3);
	outtextxy(148,184,"Last Name  :");
	gotoxy(38,13);
	gets(cust.lname);
	if(strlen(cust.lname)!=0)
	 {
	  form_fill_bit[1]=1;
	  q++;
	 }
	setcolor(8);
	outtextxy(148,184,"Last Name  :");
  }

  void getaddress()
  {
	settextstyle(3,0,2);
	setusercharsize(2,3,2,3);
	settextjustify(0,2);
	setcolor(3);
	outtextxy(148,215,"Address    :");
	gotoxy(38,15);
	gets(cust.address.add1);
	gotoxy(38,16);
	gets(cust.address.add2);
	gotoxy(38,17);
	gets(cust.address.add3);
	if(strlen(cust.address.add1)!=0 || strlen(cust.address.add2)!=0 || strlen(cust.address.add3)!=0)
	 {
	  form_fill_bit[2]=1;
	  q++;
	 }
	setcolor(8);
	outtextxy(148,215,"Address    :");
  }

  void getcity()
  {
	settextstyle(3,0,2);
	setusercharsize(2,3,2,3);
	setcolor(3);
	settextjustify(0,2);
	outtextxy(148,265,"City         :");
	gotoxy(38,18);
	gets(cust.address.city);
	if(strlen(cust.address.city)!=0)
	 {
	  form_fill_bit[3]=1;
	  q++;
	 }
	setcolor(8);
	outtextxy(148,265,"City         :");
  }

  void getstate()
  {
	settextstyle(3,0,2);
	setusercharsize(2,3,2,3);
	setcolor(3);
	settextjustify(0,2);
	outtextxy(148,297,"State       :");
	gotoxy(38,20);
	gets(cust.address.state);
	if(strlen(cust.address.state)!=0)
	 {
	  form_fill_bit[4]=1;
	  q++;
	 }
	setcolor(8);
	outtextxy(148,297,"State       :");
  }

  void getemailid()
  {
	settextstyle(3,0,2);
	setusercharsize(2,3,2,3);
	setcolor(3);
	settextjustify(0,2);
	outtextxy(148,328,"Email ID     :");
	gotoxy(38,22);
	gets(cust.emailid);
	if(strlen(cust.emailid)!=0)
	  form_fill_bit[5]=1;
	setcolor(8);
	outtextxy(148,328,"Email ID     :");
  }

  void getphoneno()
  {
	settextstyle(3,0,2);
	setusercharsize(2,3,2,3);
	setcolor(3);
	outtextxy(148,359,"Phone no.   :");
	gotoxy(38,24);
	cin>>cust.phoneno;
	setcolor(8);
	outtextxy(148,359,"Phone no.   :");
	if(cust.phoneno<=0)
	   cust.phoneno=0;
  }

  void get_user_info()
  {
	static char account[5];
	setcolor(LIGHTGRAY);
	rectangle(78,108,552,402);
	setcolor(DARKGRAY);
	rectangle(80,110,550,400);
	settextstyle(3,0,2);
	settextjustify(0,2);
	setcolor(8);
	setusercharsize(2,3,2,3);
	outtextxy(148,120,"Account No. :");
	outtextxy(148,153,"First Name  :");
	outtextxy(148,184,"Last Name  :");
	outtextxy(148,215,"Address    :");
	outtextxy(148,265,"City         :");
	outtextxy(148,297,"State       :");
	outtextxy(148,328,"Email ID     :");
	outtextxy(148,359,"Phone no.   :");
	setcolor(RED);
	settextstyle(3,0,1);
	outtextxy(265,153,"*");
	outtextxy(260,184,"*");
	outtextxy(252,215,"*");
	outtextxy(240,265,"*");
	outtextxy(250,297,"*");
	outtextxy(255,359,"*");
	outtextxy(55,420,"*");
	setcolor(DARKGRAY);
	outtextxy(60,420," fields are compulsory");
	settextstyle(3,0,2);
	setcolor(WHITE);
	fflush(stdin);
	gotoxy(30,9);

	FILE *df;
	df=fopen("data.dat","rb+");
	{
	 fseek(df,0,SEEK_SET);
	 fread(&data,sizeof(data),1,df);
	}
	fclose(df);
	cust.acc_no=data.acc_no;
	itoa(data.acc_no,account,10);
	ac=fopen(account,"w+");
	fclose(ac);

	setcolor(RED);
	outtextxy(290,120,account);
	setcolor(WHITE);

	fflush(stdin);
	getfname();
	getlname();
	fflush(stdin);
	getaddress();
	fflush(stdin);
	getcity();
	getstate();
	fflush(stdin);
	getemailid();
	fflush(stdin);
	getphoneno();

   settextstyle(3,0,2);
   for(;q<=6;q++)
	{
	  while(form_fill_bit[0]==0)
		  {
		   show_error("Enter First name");
		   getfname();
		  }
	  while(form_fill_bit[1]==0)
		  {
		   show_error("Enter Last name");
		   getlname();
		  }
	  while(form_fill_bit[2]==0)
		  {
		   show_error("Enter Address");
		   getaddress();
		  }
	  while(form_fill_bit[3]==0)
		  {
		   show_error("Enter City");
		   getcity();
		  }
	  while(form_fill_bit[4]==0)
		  {
		   show_error("Enter State");
		   getstate();
		  }
	  if(form_fill_bit[5]==0)
		  getemailid();
	}
  }

  void getbalance()
  {
	inner_function_screen("     NEW ACCOUNT");
	settextstyle(3,0,2);
	setcolor(8);
	outtextxy(120,130,"Enter Balance:");
	gotoxy(42,10);
	cin>>cust.balance;
	if(cust.balance<0)
	  cust.balance=0;
	showmouseptr();
  }

  int ifblocked(int ac)
  {
	 int acc_no;
	 f2=fopen("Blockacc.dat","rb+");
	  rewind(f2);
	  while(fread(&acc_no,sizeof(acc_no),1,f2))
	   {
		if(ac==acc_no)
		 {
		  printf("Account Blocked. Contact Administrator.");
		  fclose(f2);
		  getch();
		  return 1;
		 }
	   }
	  return 0;
  }


 int ch_pass(int t)
 {
   char p1[16],p2[16],p3[16],*pass,*acc;
   unsigned int ac,flag=0,pin=0;
   inner_function_screen("CHANGE PASSWORD");
   settextstyle(3,0,2);
   setcolor(8);

	if(t==1)                 //CUSTOMER
	 {
	  outtextxy(120,134,"Enter Account no.");
	  gotoxy(42,10);
	  cin>>ac;
	 }
	  cleardevice();
	  inner_function_screen("CHANGE PASSWORD");
	  settextstyle(1,0,3);

	  setcolor(GREEN);
	  outtextxy(110,130,"Enter Old PIN/Password:");
	  gotoxy(55,10);
	  gets(p1);
	  border();
	  setcolor(LIGHTGRAY);
	  outtextxy(110,130,"Enter Old PIN/Password:");

	  setcolor(GREEN);
	  outtextxy(110,180,"Enter New PIN/Password:");
	  pass=getpass(" ");
	  strcpy(p2,pass);

	  gotoxy(55,13);
	  for(i=0;i<strlen(p2);i++)
	   printf("*");
	  border();
	  setcolor(LIGHTGRAY);
	  outtextxy(110,180,"Enter New PIN/Password:");

	  setcolor(GREEN);
	  outtextxy(110,230,"Confirm New PIN/Password:");
	  pass=getpass(" ");
	  strcpy(p3,pass);

	  gotoxy(55,16);
	  for(i=0;i<strlen(p3);i++)
	   printf("*");
	  border();
	  setcolor(LIGHTGRAY);
	  outtextxy(110,230,"Confirm New PIN/Password:");
	  delay(100);

	  setcolor(GREEN);
	  if(strcmp(p2,p3)==0)
		flag=1;

	  if(flag==1)
	  {
		if(t==0)
		 {
		   f1=fopen("admin","rb+");
		   fseek(f1,0L,SEEK_SET);
		   fread(&admin,sizeof(admin),1,f1);
		   fseek(f1,0L,SEEK_SET);
		   if(strcmp(admin.password,p1)==0)
			{
			  strcpy(admin.password,p2);
			  fwrite(&admin,sizeof(admin),1,f1);
			}
		   else
		   {
			show_err("You have entered wrong Password");
			return 0;
		   }
		   fflush(f1);
		   fclose(f1);
		 }
		else if(t==1)
		 {
		  ifblocked(ac);
		  itoa(ac,acc,10);
		  if((f2=fopen(acc,"rb+"))==NULL)
		   {
			show_err("Wrong Account no. or Password");
			settextstyle(1,0,4);
			setcolor(WHITE);
			outtextxy(75,350,"Press any key to try again");
			return 0;
		   }

		  f3=fopen("password.dat","rb+");
		  fseek(f3,0L,SEEK_SET);
		  while(fread(&passwd,sizeof(passwd),1,f3))
		  {
		   if(passwd.code.acc_no==ac)
		   {
			if(passwd.pass!=atoi(p1))
			{
			  show_err("WRONG PASSWORD");
			  return 0;
			}
			pin=atoi(p2);
			passwd.pass=pin;
			long back=sizeof(passwd);
			fseek(f3,-1*back,SEEK_CUR);
			fwrite(&passwd,sizeof(passwd),1,f3);
			fflush(f3);
			fclose(f3);
			break;
		   }
		  }
		}
	  if(flag==1)
	  {
	   outtextxy(120,295,"Password Successfully changed");
	   getch();
	   return 1;
	  }
	}
	outtextxy(120,295,"Password not matched");
	getch();
	return 0;
 }

 //Function to show transactions of a particular account
  void tran_enquiry(int ac)
  {
	char *acc;
	outer_function_screen("TRANSACTION ENQUIRY");
	setcolor(WHITE);
	settextstyle(1,HORIZ_DIR,3);
	outtextxy(10,105,"Acc.No.");
	outtextxy(100,105,"Amount");
	outtextxy(230,105,"Date");
	outtextxy(330,105,"Time");
	outtextxy(430,105,"Transaction no.");

	itoa(ac,acc,10);
	if((fp=fopen(acc,"rb+"))==NULL)
	 {
	  inner_function_screen("TRANSACTION ENQUIRY");
	  gotoxy(25,15);
	  printf("No Transactions yet");
	  getch();
	  return;
	 }
	long size=10*sizeof(trans);
	fseek(fp,-size,SEEK_END);
	i=10;
	line(8,105,getmaxx()-8,105);
	line(8,135,getmaxx()-8,135);

	while(fread(&trans,sizeof(trans),1,fp) && i<21)
	 {
	   gotoxy(5,i);
	   printf("%d",ac);
	   gotoxy(18,i);
	   printf("%6d",trans.amount);
	   gotoxy(30,i);
	   puts(trans.date);
	   gotoxy(42,i);
	   puts(trans.time);
	   n=i;
	   gotoxy(60,i);
	   printf("%lu\n",trans.tran_no);
	   i++;
	 }
	settextstyle(1,0,4);
	outtextxy(40,410,"Press any key to go to MAIN MENU");
	fclose(fp);
	getch();
  }
