#include<graphics.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h> 
#include "hostel.cpp"
#include"walking_man_project.cpp"
#include"walking_man_project_towards.cpp"
#include<iostream>


int n,c=0,i=0,id1,y,f=0;
int pin1[4]={2,5,8,8};
int pin[4];
void call(int i);

char maintext0[][10]={"0","1","2","3","4","5","6","7","8","9"};
char maintext[][20]={"Add Student","Search Student","Modify Student","Display Student","Delete Student","Exit"};
char maintext2[][20]={"Add Room","Delete Room","Display","Exit"};
char maintext3[][20]={"Room Operation","Student Operation","Exit"};
void call2(int );
void callmain(int );
void call(int );
void access(int );
int pinverify();
void normalvideo(int x,int y,char *c)
{
    setbkcolor(11);
    setcolor(0);
    outtextxy(x,y,c);
}
void reversevideo(int x,int y,char *c)
{
    setbkcolor(9);
    setcolor(0);
    outtextxy(x,y,c);
    setcolor(15);
    //setbkcolor(4); 
}
void access(int x)
{
	setfillstyle(SOLID_FILL,0);
	floodfill(2,2,0);
	setbkcolor(0);
	setcolor(10);
	setlinestyle(SOLID_LINE,0,5);
	setcolor(10);
	if(x==0)
	{
		rectangle(243,317,1241,417);
		outtextxy(250,320,"ACCESS DENIED");
		delay(3000);
		exit(1);
		setbkcolor(11);
	}
	else
	{
		setcolor(10);
		setcolor(10);
		rectangle(243,317,1317,467);
		outtextxy(250,320,"ACCESS GRANTED");
	}	
	
}
void inicolor(int x,int y,int a)
{
	setfillstyle(SOLID_FILL,a);
	floodfill(x,y,0);
}
void load2()
{
cleardevice();
setfillstyle(SOLID_FILL,11);
floodfill(1,1,11);
setfillstyle(SOLID_FILL,9);
setcolor(0);
settextstyle(10,0,5);
outtextxy(650,300,"Verifying...");
setlinestyle(SOLID_LINE,0,1);
rectangle(700,400,738,438);
floodfill(703,403,0);
rectangle(740,400,778,438);
floodfill(743,403,0);
rectangle(780,400,818,438);
floodfill(783,403,0);
rectangle(820,400,858,438);
floodfill(823,403,0);
rectangle(700,440,738,478);
floodfill(703,443,0);
rectangle(700,480,738,518);
floodfill(703,483,0);
rectangle(820,440,858,478);
floodfill(823,443,0);
rectangle(820,480,858,518);
floodfill(823,483,0);
rectangle(700,520,738,558);
floodfill(703,523,0);
rectangle(740,520,778,558);
floodfill(743,523,0);
rectangle(780,520,818,558);
floodfill(783,523,0);
rectangle(820,520,858,558);
floodfill(822,522,0);
for(int j=0;j<2;j++)
{
for(int i=1;i<13;i++)
{

	if(i==1)
	{
		inicolor(703,403,11);
		delay(300);
		inicolor(703,403,9);
	}
	else if(i==2)
	{
		inicolor(743,403,11);
		delay(300);
		inicolor(743,403,9);
	}
	else if(i==3)
	{
		inicolor(783,403,11);
		delay(300);
		inicolor(783,403,9);
	}
	else if(i==4)
	{
		inicolor(823,403,11);
		delay(300);
		inicolor(823,403,9);
	}
	else if(i==5)
	{
		inicolor(823,443,11);
		delay(300);
		inicolor(823,443,9);
	}
	else if(i==6)
	{
		inicolor(823,483,11);
		delay(300);
		inicolor(823,483,9);
	}
	else if(i==7)
	{
		inicolor(822,522,11);
		delay(300);
		inicolor(822,522,9);
	}
	else if(i==8)
	{
		inicolor(783,523,11);
		delay(300);
		inicolor(783,523,9);
	}
	else if(i==9)
	{
		inicolor(743,523,11);
		delay(300);
		inicolor(743,523,9);
	}
	else if(i==10)
	{
		inicolor(703,523,11);
		delay(300);
		inicolor(703,523,9);
	}
	else if(i==11)
	{
		inicolor(703,483,11);
		delay(300);
		inicolor(703,483,9);
	}
	else if(i==12)
	{
		inicolor(703,443,11);
		delay(300);
		inicolor(703,443,9);
	}
	
}
}
cleardevice();
setfillstyle(SOLID_FILL,11);
floodfill(1,1,11);
settextstyle(6,0,8);
}

int pinverify()
{ 
	setfillstyle(SOLID_FILL,11);
	floodfill(2,2,11);
	setbkcolor(11);
	settextstyle(10,0,5);
	setcolor(0);
	outtextxy(500,200,"PLEASE ENTER PIN No......");
	int x=100,y=100,i,j,flag;
	settextstyle(10,0,8);
    setcolor(0);
    setlinestyle(SOLID_LINE,10,5);
    line(595,345,905,345);
    line(595,345,595,655);
    line(905,345,905,655);
    line(595,655,905,655);
    setlinestyle(DASHED_LINE,10,1);
    line(590,340,910,340);
    line(590,340,590,660);
    line(910,340,910,660);
    line(590,660,910,660);
    line(600,350,900,350);
    line(600,450,900,450);
    line(600,550,900,550);
    line(600,650,900,650);
    line(600,350,600,650);
    line(700,350,700,650);
    line(800,350,800,650);
    line(900,350,900,650);
    settextstyle(6,0,8);
    for(i=0;i<3;i++)
    {
    	for(j=0;j<3;j++)
    	{
        	normalvideo(620+(j*y),(i*x)+355,maintext0[(3*i)+(j+1)]);
        }
    }
    int done=0;
    i=0,j=0;
    reversevideo(620+(j*y),(i*x)+355,maintext0[(3*i)+(j+1)]);
    do
        {
    int k=getch();
    switch(k)
    {
        case 00:
        k=getch();
        switch(k)
        {
        case 72:
            normalvideo(620+(j*y),(i*x)+355,maintext0[(3*i)+(j+1)]);
            --i;
            if(i==-1)
            {
                i=2;
            }
            reversevideo(620+(j*y),(i*x)+355,maintext0[(3*i)+(j+1)]);
            break;
        case 80:
            normalvideo(620+(j*y),(i*x)+355,maintext0[(3*i)+(j+1)]);
            ++i;
            if(i==3)
            {
                i=0;
            }
            reversevideo(620+(j*y),(i*x)+355,maintext0[(3*i)+(j+1)]);
            break;
        case 77:
            normalvideo(620+(j*y),(i*x)+355,maintext0[(3*i)+(j+1)]);
            ++j;
            if(j==3)
            {
                j=0;
            }
            reversevideo(620+(j*y),(i*x)+355,maintext0[(3*i)+(j+1)]);
            break;
        case 75:
            normalvideo(620+(j*y),(i*x)+355,maintext0[(3*i)+(j+1)]);
            --j;
            if(j==-1)
            {
                j=2;
            }
            reversevideo(620+(j*y),(i*x)+355,maintext0[(3*i)+(j+1)]);
            break;
        }
        break;
        case 13:
            done=done+1;
            if(i==0)
            {
            	if(j==0)
            	{
            		pin[done-1]=1;	
				}
				else if(j==1)
				{
					pin[done-1]=2;
				}
				else if(j==2)
				{
					pin[done-1]=3;
				}		
			}
			else if(i==1)
			{
				if(j==0)
            	{
            		pin[done-1]=4;	
				}
				else if(j==1)
				{
					pin[done-1]=5;
				}
				else if(j==2)
				{
					pin[done-1]=6;
				}	
			}
			else if(i==2)
			{
				if(j==0)
            	{
            		pin[done-1]=7;	
				}
				else if(j==1)
				{
					pin[done-1]=8;
				}
				else if(j==2)
				{
					pin[done-1]=9;
				}	
			}
		}
	}
	while(done!=4);
		cleardevice();
		for(int p=0;p<4;p++)
		{
			if(pin[p]!=pin1[p])
			{
				flag=0;
				break;
			}
			else
			{
				flag=1;
			}
		}
		setbkcolor(11);
		return flag;
}

void initialbk()
{
	int flag;
	floodfill(2,2,11);
	setbkcolor(11);
	settextstyle(10,0,20);
	outtextxy(400,100,"BVM HOSTEL");
	settextstyle(10,0,5);
	outtextxy(400,300,"Prepared By:-");
	outtextxy(400,400,"19CP034 :- Pratik Kher");
	outtextxy(400,500,"19CP025 :- Jay Kava");
	outtextxy(400,600,"19CP040 :- Kevin Patel");
	delay(3000);
	cleardevice();
	setfillstyle(SOLID_FILL,0);
	flag=pinverify();
	load2();
	access(flag);
	delay(3000);
	cleardevice();
	setfillstyle(SOLID_FILL,11);
	floodfill(1,1,11);
	settextstyle(10,0,3);
}

int mainmenu()
{ 
	setfillstyle(SOLID_FILL,11);
	floodfill(2,2,11);
	setbkcolor(11);
	settextstyle(10,0,7);
	setcolor(0);
	outtextxy(450,125,"Welcome, Admin");
	outtextxy(375,215,"Please select option");
	int x=40,i;
	settextstyle(10,0,3);
    setcolor(0);
    setlinestyle(SOLID_LINE,10,5);
    line(595,345,905,345);
    line(595,475,905,475);
    line(595,345,595,475);
    line(905,345,905,475);
    setlinestyle(DASHED_LINE,10,1);
    line(600,350,900,350);
    line(600,390,900,390);
    line(600,430,900,430);
    line(600,470,900,470);
    line(600,350,600,470);
    line(900,350,900,470);
    
    for(i=0;i<3;i++)
    {
        normalvideo(645,(i*x)+358,maintext3[i]);
    }
    int done=0;
    i=0;
    reversevideo(645,(i*x)+358,maintext3[0]);
    do
        {
    int k=getch();
    switch(k)
    {
        case 00:
        k=getch();
        switch(k)
        {
        case 72:
            normalvideo(645,(i*x)+358,maintext3[i]);
            --i;
            if(i==-1)
            {
                i=2;
            }
            reversevideo(645,(i*x)+358,maintext3[i]);
            break;
        case 80:
            normalvideo(645,(i*x)+358,maintext3[i]);
            ++i;
            if(i==3)
            {
                i=0;
            }
            reversevideo(645,(i*x)+358,maintext3[i]);
            break;
        }
        break;
        case 13:
            done=1;
		}
	}
	while(done!=1);
		cleardevice();
		setbkcolor(11);
        callmain(i);
        return i;
}
int menu2()
{ 
	setfillstyle(SOLID_FILL,11);
	floodfill(2,2,11);
	setbkcolor(11);
	settextstyle(10,0,5);
	setcolor(0);
	outtextxy(200,200,"SELECT ROOM OPERATION");
	int x=40,i;
	settextstyle(10,0,3);
    setcolor(0);
    setlinestyle(SOLID_LINE,10,5);
    line(595,345,905,345);
    line(595,515,905,515);
    line(595,345,595,515);
    line(905,345,905,515);
    setlinestyle(DASHED_LINE,10,1);
    line(600,350,900,350);
    line(600,390,900,390);
    line(600,430,900,430);
    line(600,470,900,470);
    line(600,510,900,510);
    line(600,350,600,510);
    line(900,350,900,510);
    
    for(i=0;i<4;i++)
    {
        normalvideo(645,(i*x)+358,maintext2[i]);
    }
    int done=0;
    i=0;
    reversevideo(645,(i*x)+358,maintext2[0]);
    do
        {
    int k=getch();
    switch(k)
    {
        case 00:
        k=getch();
        switch(k)
        {
        case 72:
            normalvideo(645,(i*x)+358,maintext2[i]);
            --i;
            if(i==-1)
            {
                i=3;
            }
            reversevideo(645,(i*x)+358,maintext2[i]);
            break;
        case 80:
            normalvideo(645,(i*x)+358,maintext2[i]);
            ++i;
            if(i==4)
            {
                i=0;
            }
            reversevideo(645,(i*x)+358,maintext2[i]);
            break;
        }
        break;
        case 13:
            done=1;
		}
	}
	while(done!=1);
		cleardevice();
        call2(i);
        return i;
}
void menu()
{
	floodfill(2,2,11);
	setbkcolor(11);
	settextstyle(10,0,5);
	setcolor(0);
	outtextxy(200,200,"SELECT STUDENT OPERATION");
    int x=40,i;
    settextstyle(10,0,3);
    setcolor(0);
    setlinestyle(SOLID_LINE,10,5);
    line(595,345,595,595);
    line(595,345,905,345);
    line(905,345,905,595);
    line(595,595,905,595);
    setlinestyle(DASHED_LINE,10,1);
    line(600,350,600,590); //vertical line
    line(600,350,900,350);
    line(600,510,900,510);
    line(900,350,900,590);
    line(600,390,900,390);
    line(600,430,900,430);
    line(600,470,900,470);
    line(600,550,900,550);
    line(600,550,900,550);
    line(600,590,900,590);
    
    for(i=0;i<6;i++)
    {
        normalvideo(645,(i*x)+358,maintext[i]);
    }
    int done=0;
    i=0;
    reversevideo(645,(i*x)+358,maintext[0]);
    do
    {
    int k=getch();
    switch(k)
    {
        case 00:
        k=getch();
        switch(k)
        {
        case 72:
            normalvideo(645,(i*x)+358,maintext[i]);
            --i;
            if(i==-1)
            {
                i=5;
            }
            reversevideo(645,(i*x)+358,maintext[i]);
            break;
        case 80:
            normalvideo(645,(i*x)+358,maintext[i]);
            ++i;
            if(i==6)
            {
                i=0;
            }
            reversevideo(645,(i*x)+358,maintext[i]);
            break;
        }
        break;
        case 13:
            done=1;
    }
    }
        while(done!=1);
        cleardevice();
        call(i);
}
void loading()
        {
        	setfillstyle(SOLID_FILL,11);
        	floodfill(2,2,11);
        	setbkcolor(11);
            int x=500,i;
            settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
            setcolor(0);
            setlinestyle(SOLID_LINE,10,1);
            rectangle(500,400,1000,420);
            outtextxy(600,350,"LOADING,PLEASE WAIT");
            for(i=0;i<500;++i)
            {
                delay(10);
                line(x,400,x,420);
                x++;
                if(x<800)
                {
                	outtextxy(600,460,"Fetching File ....");
				}
				else if(x>800)
				{
					outtextxy(600,460,"Reading Data ....");
				}
            }
            cleardevice();
        }
void loading1()
        {
        	setfillstyle(SOLID_FILL,11);
        	floodfill(2,2,11);
        	setbkcolor(11);
            int x=500,i;
            settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
            setcolor(0);
            setlinestyle(SOLID_LINE,10,1);
            rectangle(500,400,1000,420);
            outtextxy(600,350,"LOADING,PLEASE WAIT");
            for(i=0;i<500;++i)
            {
                delay(10);
                line(x,400,x,420);
                x++;
                settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
                if(x<800)
                {
                	outtextxy(600,460,"Fetching Data File ....");
				}
				else if(x>800)
				{
					outtextxy(600,460,"Reading Data File ....");
				}
            }
            cleardevice();
        }


void callmain(int i) //main menu
  {
        if(i==0)
        {   
            loading();
        	menu2();
        }
        else if(i==1)
        {
        	loading();
        	menu();
		}
        else
        {
            exit(1);
        }
  }
void call2(int i) //menu for room operation
  {
        if(i==0)
        {   
            loading1();
            addroom();
        }
        else if(i==1)
        {
        	loading1();
        	deleteroom();
		}
        else if(i==2)
        {
        	loading1();
        	displayroom();
        }
        else if(i==3)
        {
        	exit(1);
		}
  }
void call(int i) //menu for student operation
  {
        if(i==0)
        {   
            loading1();
            walktowards();
        	AddStudent();	
        }
        else if(i==1)
        {
        	loading1();
        	SearchByStud_no();
		}
        else if(i==2)
        {
        	loading1();
        	ModifyStudent();
        }
        else if(i==3)
        {
        	loading1();
        	DisplayByroom_no();
		}
		else if(i==4)
        {
        	loading1();
        	deletegraphic();
        	DeleteStudent();
		}
		else if(i==5)
        {
        	exit(1);
		}
		
  }

int main()
{   
    int gd=DETECT,gm;
    initwindow(1900,1000,"");
    setfillstyle(SOLID_FILL,11);
    setcolor(0);
    initialbk();
    loading();
    mainmenu(); 
	return 0;  
}
