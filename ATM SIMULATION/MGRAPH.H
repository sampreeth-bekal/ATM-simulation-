  int mx,my;
  void border()
  {
   mx=getmaxx();
   my=getmaxy();
   setcolor(GREEN);
   rectangle(2,2,mx-2,my-2);
   setcolor(RED);
   rectangle(4,4,mx-4,my-4);
   setcolor(GREEN);
   rectangle(6,6,mx-6,my-6);
  }

   void outer_function_screen(char *str)
   {
	cleardevice();
	hidemouseptr();
	border();
	setcolor(GREEN);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(100,40,str);
	showmouseptr();
   }

 void inner_function_screen(char *str)
 {
   outer_function_screen(str);
   hidemouseptr();
   setcolor(LIGHTGRAY);
   rectangle(78,108,552,402);
   setcolor(DARKGRAY);
   rectangle(80,110,550,400);
   showmouseptr();
 }

  void show_tran_window()
  {
	hidemouseptr();
	setcolor(GREEN);
	settextstyle(10,HORIZ_DIR,3);
	outtextxy(70,20,"TRANSACTIONS ENQUIRY");
	setcolor(WHITE);
	settextstyle(1,HORIZ_DIR,3);
	outtextxy(10,110,"Acc.No.");
	outtextxy(100,110,"Amount");
	outtextxy(230,110,"Date");
	outtextxy(330,110,"Time");
	outtextxy(430,110,"Transaction no.");
  }

   void draw_button(int x1,int y1,int x2,int y2,int csize,char *str)
   {
	int bxsize=x2-x1;
	int bysize=y2-y1;
	setcolor(WHITE);
	rectangle(x1,y1,x2,y2);
	setfillstyle(1,LIGHTGRAY);
	floodfill(x1+1,y1+1,WHITE);
	settextstyle(3,0,csize);
	setcolor(DARKGRAY);
	line(x1,y2,x2,y2);
	line(x2,y1,x2,y2);
	setcolor(BLACK);
	outtextxy(x1+((bxsize-textwidth(str))/2),y1+((bysize-textheight(str))/3),str);
   }


  void show_err(char *str)
   {
		 cleardevice();
		 border();
		 setcolor(RED);
		 settextstyle(3,0,4);
		 outtextxy(75,100,str);
		 settextstyle(1,0,4);
		 setcolor(WHITE);
		 outtextxy(75,350,"Press any key to try again");
		 getch();
   }
