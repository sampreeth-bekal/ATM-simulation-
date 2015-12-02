 //WELCOMING THE USER
 void welcomeuser(int t, char *s)
 {
  hidemouseptr();
  cleardevice();
  setcolor(GREEN);
  fflush(stdout);
  border();
  settextjustify(CENTER_TEXT,LEFT_TEXT);
  settextstyle(3,0,8);
  setcolor(GREEN);
  outtextxy(mx/2,my/2-120,"WELCOME");
  setcolor(WHITE);
  settextstyle(1,0,7);
  if(t==0)
	strcpy(s,"ADMINISTRATOR");
  outtextxy(mx/2-40,my/2-20,s);
  setcolor(RED);
  settextstyle(5,0,4);
  outtextxy(mx/2,380,"\nPRESS ANY KEY TO CONTINUE");
  settextstyle(5,0,4);
  outtextxy(mx/2-1,380,"\nPRESS ANY KEY TO CONTINUE");
  settextstyle(5,0,4);
  outtextxy(mx/2+1,380,"\nPRESS ANY KEY TO CONTINUE");
  getch();
 }


 void show_exit_message()
 {
	 cleardevice();
	 border();
	 setcolor(RED);
	 settextstyle(3,0,4);
	 outtextxy(75,100,"Exiting the program...");
	 settextstyle(1,0,4);
	 setcolor(WHITE);
	 outtextxy(75,350,"Thanks for using the program");
 }

 void resetloginform()
 {
  count=countp=0;
  setcolor(BLACK);
  settextstyle(2,0,5);
  setusercharsize(3,1,3,1);
  outtextxy(290,80,loginid);
  settextstyle(1,0,4);
  outtextxy(290,155,"               ");
  strcpy(loginid,"                              ");
  strcpy(loginid,"\0");
  strcpy(password,"                ");
  strcpy(password,"\0");
  flushall();
 }


 void showloginform()
 {
  hidemouseptr();
  cleardevice();
  border();
  setcolor(WHITE);
  fflush(stdout);
  rectangle(280,80,500,120);
  rectangle(280,150,500,190);
  setcolor(WHITE);
  settextstyle(2,0,5);
  outtextxy(400,8,"Press * to exit anytime");
  settextstyle(3,0,4);
  outtextxy(80,80,"Login ID");
  outtextxy(80,150,"Password");
  draw_button(170,250,280,290,2,"RESET");
  draw_button(310,250,430,290,2,"SUBMIT");

  //PARTIONING LINE
  setcolor(WHITE);
  line(8,340,mx-8,340);
  line(8,341,mx-8,341);
  setcolor(GREEN);
  settextstyle(1,0,5);
  outtextxy(25,360,"  STUDENTS INTERNATIONAL");
  outtextxy(250,420,"BANK");
  showmouseptr();
 }

 void getloginid()
 {
  hidemouseptr();
  char ch[1];
  setcolor(GREEN);
  settextstyle(2,0,5);
  setusercharsize(3,1,3,1);
  while(count<=30)
  {
   ch[0]=getche();
   if(ch[0]=='\r')
   {
	if(count!=0)
	 {
	  loginid[count]='\0';
	  break;
	 }
   }
   else if(ch[0]==42)
   {
	 show_exit_message();
	 delay(500);
	 exit(0);
   }
   else if((ch[0]>=65 && ch[0]<=90)||(ch[0]>=97 && ch[0]<=122) || (ch[0]>=48 &&ch[0]<=57) ||(ch[0]==32))
   {
	loginid[count++]=ch[0];
	outtextxy(290,80,loginid);
	loginid[count]='\0';
   }
  }
 }

void getpassword()
{
 hidemouseptr();
 char ch[1];
 setcolor(GREEN);
 settextstyle(1,0,4);
 while(countp<=16)
 {
   fflush(stdout);
   ch[0]=getche();
   if(ch[0]=='\r')
   {
	if(countp!=0)
	 {
	  loginid[countp]='\0';
	  break;
	 }
   }
   else if(ch[0]==42)
   {
	 show_exit_message();
	 delay(500);
	 exit(0);
   }
   else if((ch[0]>=32 && ch[0]<127))
   {
	password[countp]=ch[0];
	outtextxy(290+countp*15,155,"*");
	password[++countp]='\0';
   }
  }
}

