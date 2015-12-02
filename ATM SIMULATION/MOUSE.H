int initmouse();
void showmouseptr();
void restrictmouseptr(int ,int ,int ,int );
void getmousepos(int *,int *,int *);

union REGS in,o;

  int initmouse()
	 {
	   in.x.ax=0;
	   int86(0x33,&in,&o);
	   return(o.x.ax);
	 }

   void showmouseptr()
	 {
	   in.x.ax=1;
	   int86(0x33,&in,&o);
	 }

   void restrictmouseptr(int x1,int y1,int x2,int y2)
	 { in.x.ax=7;
	   in.x.cx=x1;
	   in.x.dx=x2;
	   int86(0x33,&in,&o);
	   in.x.ax=8;
	   in.x.cx=y1;
	   in.x.dx=y2;
	   int86(0x33,&in,&o);
	 }

	 void getmousepos(int* button,int *x,int *y)
	  {
	   in.x.ax=3;
	   int86(0x33,&in,&o);
	   *button=o.x.bx;
	   *x=o.x.cx;
	   *y=o.x.dx;
	  }

	 void hidemouseptr()
	  {
		_AX=2;
		geninterrupt(0x33);
	  }