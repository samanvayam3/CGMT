#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int x,y,h,k,r;
char A[15];
float p;

void getcoordinates()
{ delay(500);
  outtextxy(20,70,"# Enter coordinates of center :-");
  setlinestyle(0,0,1);
  delay(500);
  line(20,85,270,85);
  delay(500);
  outtextxy(20,105,"-> Input x=450, y=320 & r=100 for refrence.");
  delay(500);
  outtextxy(20,132,"Enter x - coordinate (h) : ");
  gotoxy(30,9);
  scanf("%d",&h);
  outtextxy(20,148,"Enter y - coordinate (k) : ");
  gotoxy(30,10);
  scanf("%d",&k);
  outtextxy(20,180,"Enter radius (r) : ");
  gotoxy(22,12);
  scanf("%d",&r);
  setlinestyle(1,0,1);
  delay(500);
  line(20,205,320,205);
}

void midpointcircle()
{ setcolor(7);
  setlinestyle(2,0,1);
  delay(100);
  line(h,k,h+r+30,k);
  delay(100);
  line(h,k,h+r,k+r);
  delay(100);
  line(h,k,h,k+r+30);
  delay(100);
  line(h,k,h-r,k+r);
  delay(100);
  line(h,k,h-r-30,k);
  delay(100);
  line(h,k,h-r,k-r);
  delay(100);
  line(h,k,h,k-r-30);
  delay(100);
  line(h,k,h+r,k-r);
  setcolor(15);
  y=r;
  p=1.25-r;
  for(x=0;x<=y;x++)
  { delay(23);
    putpixel(h+y,k+x,2); //octant-1
    putpixel(h+x,k+y,1); //octant-2
    putpixel(h-x,k+y,4); //octand-3
    putpixel(h-y,k+x,3); //octant-4
    putpixel(h-y,k-x,6); //Octant-5
    putpixel(h-x,k-y,5); //Octant-6
    putpixel(h+x,k-y,9); //Octant-7
    putpixel(h+y,k-x,7); //Octant-8
    if(p<0)
    { p=p+2*x+3;
    }
    else
    { y--;
      p=p+2*(x-y)+5;
    }
  }
  circle(h,k,1);
}

void mpcircle()
{ y=r;
  p=1.25-r;
  for(x=0;x<=y;x++)
  { delay(23);
    putpixel(h+y,k+x,15); //octant-1
    putpixel(h+x,k+y,15); //octant-2
    putpixel(h-x,k+y,15); //octand-3
    putpixel(h-y,k+x,15); //octant-4
    putpixel(h-y,k-x,15); //Octant-5
    putpixel(h-x,k-y,15); //Octant-6
    putpixel(h+x,k-y,15); //Octant-7
    putpixel(h+y,k-x,15); //Octant-8
    if(p<0)
    { p=p+2*x+3;
    }
    else
    { y--;
      p=p+2*(x-y)+5;
    }
  }
  circle(h,k,1);
}

void frame()
{ line(0,0,getmaxx(),0);
  line(0,0,0,getmaxy());
  line(getmaxx(),0,getmaxx(),getmaxy());
  line(0,getmaxy(),getmaxx(),getmaxy());
}

void details()
{ setlinestyle(1,0,1);
  delay(500);
  line(390,80,390,150);
  delay(500);
  line(400,160,600,160);
  delay(500);
  outtextxy(460,85,"# Details :-");
  setlinestyle(0,0,1);
  delay(500);
  line(460,100,550,100);
  sprintf(A,"C(%d,%d)",h,k);
  delay(500);
  outtextxy(410,115,"-> Centre : ");
  outtextxy(510,115,A);
  delay(500);
  outtextxy(465,310,A);
  delay(500);
  outtextxy(410,135,"-> Radius : ");
  sprintf(A,"%d",r);
  outtextxy(510,135,A);
  delay(500);
  outtextxy(20,225,"# Coordinates by 8-way symmetry :-");
  setlinestyle(0,0,1);
  delay(500);
  line(20,240,290,240);
  delay(500);
  outtextxy(550,360,"Octant-1");
  delay(500);
  outtextxy(20,260,"Octant-1 : (x,y)");
  delay(500);
  outtextxy(470,425,"Octant-2");
  delay(500);
  outtextxy(20,280,"Octant-2 : (y,x)");
  delay(500);
  outtextxy(370,425,"Octant-3");
  delay(500);
  outtextxy(20,300,"Octant-3 : (-x,y)");
  delay(500);
  outtextxy(285,360,"Octant-4");
  delay(500);
  outtextxy(20,320,"Octant-4 : (-y,x)");
  delay(500);
  outtextxy(285,280,"Octant-5");
  delay(500);
  outtextxy(20,340,"Octant-5 : (-y,-x)");
  delay(500);
  outtextxy(370,210,"Octant-6");
  delay(500);
  outtextxy(20,360,"Octant-6 : (-x,-y)");
  delay(500);
  outtextxy(470,210,"Octant-7");
  delay(500);
  outtextxy(20,380,"Octant-7 : (x,-y)");
  delay(500);
  outtextxy(550,275,"Octant-8");
  delay(500);
  outtextxy(20,400,"Octant-8 : (y,-x)");
  setlinestyle(1,0,1);
  delay(500);
  line(200,255,200,410);
}

void main()
{ int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
  frame();
  delay(200);
  outtextxy(120,20,"-: Circle (Mid-Point Circle drawimg algorithm) :-");
  delay(200);
  line(143,33,485,33);
  setlinestyle(3,0,1);
  delay(200);
  line(40,50,600,50);
  delay(200);
  getcoordinates();
  delay(200);
  if((h==450)&&(k==320)&&(r==100))
  { midpointcircle();
    delay(200);
    details();
    delay(200);
    line(20,430,300,430);
  }
  else
  { mpcircle(); }
  delay(200);
  outtextxy(20,450,"Press any key to EXIT ...");
  getch();
  closegraph();
}
