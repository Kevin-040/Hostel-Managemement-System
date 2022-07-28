#include<graphics.h>
using namespace std;
int walk_last;
void walk_1(int x)
{
	setcolor(0);
    circle(600+x,500,40);
    circle(585+x,490,5);
    circle(615+x,490,5);
    arc(600+x,475,255,285,50);
    line(600+x,500,600+x,510);
    line(600+x,540,600+x,610);
    line(600+x,610,570+x,680);//for legs
    line(600+x,610,630+x,680);
    line(600+x,540,560+x,610);//for hands
    line(600+x,540,640+x,610);
}
void walk_3(int x)
{
	setcolor(0);
    circle(600+x,500,40);
    circle(585+x,490,5);
    circle(615+x,490,5);
    arc(600+x,475,255,285,50);
    line(600+x,500,600+x,510);
    line(600+x,540,600+x,610);
    line(600+x,610,585+x,680);//for legs
    line(600+x,610,615+x,680);
    line(600+x,540,585+x,610);//for hands
    line(600+x,540,615+x,610);
}
void walk_2(int x)
{
	setcolor(0);
    circle(600+x,500,40);
    circle(585+x,490,5);
    circle(615+x,490,5);
    arc(600+x,475,255,285,50);
    line(600+x,500,600+x,510);
    line(600+x,540,600+x,680);
}
void draw_door()
{
	setcolor(0);
    line(1200,680,1200,400);
    line(1210,680,1210,410);
    line(1300,680,1300,410);
    line(1310,680,1310,400);
    line(1200,400,1310,400);
    line(1210,410,1300,410);
    line(1200,400,1210,410);
    line(1300,410,1310,400);
    setlinestyle(3,0,2);
    line(560,680,1310,680);
    setlinestyle(0,0,1);

}
void draw_main()
{
	setcolor(0);
    draw_door();
    setcolor(0);
    line(1255,680,1255,410);
    circle(1245,545,4);
    circle(1265,545,4);
}
void draw_door_open1()
{
	setcolor(0);
    draw_door();
    setcolor(0);
    line(1245,660,1245,430);
    line(1265,660,1265,430);
    line(1245,430,1210,410);
    line(1245,660,1210,680);
    line(1265,430,1300,410);
    line(1265,660,1300,680);
    circle(1237,545,3);
    circle(1272,545,3);
}
void draw_door_open2()
{
	setcolor(0);
    draw_door();
    setcolor(0);
    line(1235,660,1235,430);
    line(1275,660,1275,430);
    line(1275,430,1300,410);
    line(1275,660,1300,680);
    line(1235,430,1210,410);
    line(1235,660,1210,680);
    circle(1230,545,2);
    circle(1280,545,2); 
}
void room_man()
{
	setcolor(0);
    circle(1255,520,20);
    circle(1245,517,3);
    circle(1265,517,3);
    arc(1255,480,265,275,50);
    line(1255,520,1255,527);
    line(1255,540,1255,610);
    line(1255,610,1245,680);//for legs
    line(1255,610,1265,680);
    line(1255,540,1245,610);//for hands
    line(1255,540,1265,610);
}
void knock()
{
	setcolor(0);
    circle(600+walk_last,500,40);
    circle(585+walk_last,490,5);
    circle(615+walk_last,490,5);
    arc(600+walk_last,475,255,285,50);
    line(600+walk_last,500,600+walk_last,510);
    line(600+walk_last,540,600+walk_last,610);
    line(600+walk_last,610,570+walk_last,680);//for legs
    line(600+walk_last,610,630+walk_last,680);
    line(600+walk_last,540,560+walk_last,610);//for hands
    line(600+walk_last,540,620+walk_last,580);
}
void knock1()
{
    knock();
    setcolor(0);
    line(620+walk_last,580,640+walk_last,540);
    delay(100);
}
void knock2()
{
    knock();
    setcolor(0);
    line(620+walk_last,580,650+walk_last,560);
    delay(100);
}
int walktowards()
{
    setfillstyle(SOLID_FILL,0);
    floodfill(2,2,0);
    int i,walk=0;
    setcolor(0);
    settextstyle(5,0,3);
    outtextxy(600,415,"Let me check for empty room");
    draw_main();
    walk_1(walk);
    delay(1000);
    
    for(i=0;i<35;i++)
    {
        cleardevice();
        walk+=5; 
        draw_main();
        walk_1(walk); 
        delay(200);
        walk+=5;
        cleardevice();
        draw_main();
        walk_2(walk);
        delay(200);
        walk+=5;
        cleardevice();
        draw_main();
        setcolor(WHITE);
        walk_3(walk);
        delay(200);
        walk_last=walk;
    }

    for(int count=1;count<4;count++)
    {   
        cleardevice();
        draw_main();
        knock1();
        delay(100);
        cleardevice();
        draw_main();
        knock2();
    }
    cleardevice();
    draw_door_open1();
    delay(200);
    cleardevice();
    draw_door_open2();
    delay(200);
    room_man();
    setcolor(WHITE);
    settextstyle(5,0,3);
    outtextxy(400+walk,415,"Hi,Room looks great");

    
    cleardevice();
    delay(3000);
    return 0;
}
