int d,m,button,x,y,corx,cory;
int i=0,j,k,count=0,countp=0,u=0,n=0,successfullogin=0;
int acc=10000;
int front=-1,rear=-1;
char *c;
static form_fill_bit[6];
char loginid[30],password[16];
char cur_date[9],cur_time[9];

FILE *fp,*ft,*df,*ac,*f1,*f2,*f3,*f4,*f5,*f6;

void login();
void createaccount();
void showadminmenu();
void rem_account();
int changepassword();
void inner_function_screen(char *str);
void draw_button(int,int,int,int,int,char *);

  typedef struct
  {
	char add1[25];
	char add2[25];
	char add3[25];
	char city[20];
	char state[20];
  }add;

  struct customer
  {
	unsigned int acc_no;
	char fname[25];
	char lname[20];
	add address;
	char emailid[30];
	unsigned long phoneno;
	long balance;
}cust;

struct header
{
 char id[2];
 unsigned int acc_no;
}fl_code;

struct passwor
{
	header code;
	int pass;
}passwd;

struct transaction
{
 unsigned int acc_no;
 unsigned long amount;
 char date[9];
 char time[9];
 unsigned long tran_no;
}trans;

struct miscdata
{
 unsigned int acc_no;
 unsigned long tran_no;
}data;

struct adminrec
{
 char loginid[30];
 char password[16];
}admin;