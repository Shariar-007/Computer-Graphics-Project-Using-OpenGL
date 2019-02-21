#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<bits/stdc++.h>
#define PI 3.1416
using namespace std;
bool sim=false;
bool sorted=false;
int swapt=1;
float wait=0.00;

float a1=2.0,a2=20.0,a3=5.0,a4=20.0,a5=5.0,a6=5.0,a7=2.0,a8=5.0,a9=3.0,a10=5.5;
float b1=5.5,b2=16.0,b3=8.5,b4=16.0,b5=8.5,b6=5.0,b7=5.5,b8=5.0,b9=6.5,b10=5.5;
float c1=9.0,c2=18.0,c3=12.0,c4=18.0,c5=12.0,c6=5.0,c7=9.0,c8=5.0,c9=10.0,c10=5.5;
float d1=12.5,d2=12.0,d3=15.5,d4=12.0,d5=15.5,d6=5.0,d7=12.5,d8=5.0,d9=13.5,d10=5.5;
float e1=16.0,e2=10.0,e3=19.0,e4=10.0,e5=19.0,e6=5.0,e7=16.0,e8=5.0,e9=17.0,e10=5.5;
float f1=19.5,f2=22.0,f3=22.5,f4=22.0,f5=22.5,f6=5.0,f7=19.5,f8=5.0,f9=20.5,f10=5.5;

void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}


bool first=true;
bool second=false;
bool third=false;
bool forth=false;

float t1=6.75,t2=6.0,t3=7.5;
float x=3.50;
float y=18;

void display(void)
{
     glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

//
    if(sim==true)
    {
        if(swapt==1)
        {
             glColor3f(0.0, 0.0, 1.0);
             renderBitmapString(10.0,22.0,GLUT_BITMAP_TIMES_ROMAN_24,"Iteration 1");
             if(first)
             {
                    if(b2>=-2.0 && b4 >=-2.0 && b6>=-13.0 && b8>=-13.0 && b10>=-12.5){
                            // deduct y, from b2,b4,b6,b8,b10
                        b2=b2-0.04;
                        b4=b4-0.04;
                        b6=b6-0.04;                //2nd Down
                        b8=b8-0.04;
                        b10=b10-0.04;
                    }else{
                        second=true;
                        first=false;
                    }
             }
             if(second)
             {
                    if(a1 <=5.5 && a3<=8.5  && a5<=8.5  &&  a7<=5.5  &&  a9<=6.5)
                    {
                        a1=a1+0.04;
                        a3=a3+0.04;
                        a5=a5+0.04;                //1st right
                        a7=a7+0.04;
                        a9=a9+0.04;

                    }else{
                         third=true;
                         second=false;
                    }
             }
             if(third)
             {
                 if(b1>=2.0 && b3>= 5.0 && b5>=5.0 && b7>=2.0 && b9>=3.0)
                 {
                    b1=b1-0.04;
                    b3=b3-0.04;                    //2nd left
                    b5=b5-0.04;
                    b7=b7-0.04;
                    b9=b9-0.04;
                 }else{
                    forth=true;
                    third=false;

                 }

             }
             if(forth)
             {
                if(b2<=16.0 && b4<=16.0 && b6<= 5.0 && b8<=5.0 && b10<=5.5)
                {
                    b2=b2+0.04;
                    b4=b4+0.04;
                    b6=b6+0.04;                //2nd up
                    b8=b8+0.04;
                    b10=b10+0.04;
                }else
                {
                    first=true;
                    forth=false;
                    swapt++;
                    Sleep(500);
                    t1=t1+3.5;
                    t2=t2+3.5;
                    t3=t3+3.5;
                }
             }
        }

        if(swapt==2)
        {
            glColor3f(0.0, 0.0, 1.0);
            renderBitmapString(10.0,22.0,GLUT_BITMAP_TIMES_ROMAN_24,"Iteration 2");

            if(first)
            {
                if(c2>=0.0 && c4 >=0.0 && c6>=-13.0 && c8>=-13.0 && c10>=-12.5)
                {
                    c2=c2-0.04;
                    c4=c4-0.04;
                    c6=c6-0.04;                    //3rd down
                    c8=c8-0.04;
                    c10=c10-0.04;
                }else
                {
                    second=true;
                    first=false;
                }

            }
            if(second)
            {
                if(a1<=9.0 && a3<=12.0 && a5<=12.0 && a7<=9.0 && a9<=10.0)
                {
                    a1=a1+0.04;
                    a3=a3+0.04;                        //1st right
                    a5=a5+0.04;
                    a7=a7+0.04;
                    a9=a9+0.04;
                }else{
                    third=true;
                    second=false;

                }
            }
            if(third)
            {
                if(c1>=5.5 && c3 >=8.5 && c5>=8.5 && c7>=5.5 && c9>=6.5)
                {
                    c1=c1-0.04;
                    c3=c3-0.04;
                    c5=c5-0.04;                    //3rd left
                    c7=c7-0.04;
                    c9=c9-0.04;
                }else
                {
                    forth=true;
                    third=false;
                }
            }
            if(forth)
            {
                if(c2<=18.0 && c4<=18.0 && c6<= 5.0 && c8<=5.0 && c10 <=5.5)
                {
                    c2=c2+0.04;
                    c4=c4+0.04;
                    c6=c6+0.04;                    //3rd up
                    c8=c8+0.04;
                    c10=c10+0.04;
                }else{
                    first=true;
                    forth=false;
                    swapt++;
                    Sleep(500);
                    t1=t1+3.5;
                    t2=t2+3.5;
                    t3=t3+3.5;
                }
            }

        }
        if(swapt==3)
        {

            glColor3f(0.0, 0.0, 1.0);
            renderBitmapString(10.0,22.0,GLUT_BITMAP_TIMES_ROMAN_24,"Iteration 3");
            if(first)
            {
                if(d2 >=-6.0 && d4>=-6.0 && d6>=-13.0 && d8>=-13.0 && d10>=-12.5)
                {
                   d2=d2-0.04;
                   d4=d4-0.04;
                   d6=d6-0.04;
                   d8=d8-0.04;
                   d10=d10-0.04;
                }else{
                    second=true;
                    first=false;
                }
            }
            if(second)
            {
                if(a1<=12.5 && a3<=15.5 && a5<=15.5 && a7<=12.5 && a9<=13.5)
                {
                   a1=a1+0.04;
                   a3=a3+0.04;
                   a5=a5+0.04;
                   a7=a7+0.04;
                   a9=a9+0.04;
                }else{
                    third=true;
                    second=false;
                }
            }
            if(third)
            {
                if(d1>=9.0 && d3>=12.0 && d5>=12.0 && d7>=9.0 && d9>=10.0)
                {
                   d1=d1-0.04;
                   d3=d3-0.04;
                   d5=d5-0.04;
                   d7=d7-0.04;
                   d9=d9-0.04;
                }else{
                    forth=true;
                    third=false;
                }
            }
            if(forth)
            {
                if(d2<=12.0 && d4<=12.0 && d6<=5.0 && d8<=5.0 && d10<=5.5)
                {
                   d2=d2+0.04;
                   d4=d4+0.04;
                   d6=d6+0.04;
                   d8=d8+0.04;
                   d10=d10+0.04;
                }else{
                    first=true;
                    forth=false;
                    swapt++;
                    Sleep(500);
                    t1=t1-3.5;
                    t2=t2-3.5;
                    t3=t3-3.5;
                }
            }
        }
        if(swapt==4)
        {
            glColor3f(0.0, 0.0, 1.0);
            renderBitmapString(10.0,22.0,GLUT_BITMAP_TIMES_ROMAN_24,"Iteration 3");
            if(first)
            {
                if(d2 >=-6.0 && d4>=-6.0 && d6>=-13.0 && d8>=-13.0 && d10>=-12.5)
                {
                   d2=d2-0.04;
                   d4=d4-0.04;
                   d6=d6-0.04;
                   d8=d8-0.04;
                   d10=d10-0.04;
                }else{
                    second=true;
                    first=false;
                }
            }
            if(second)
            {
                if(c1<=9.0 && c3<=12.0 && c5<=12.0 && c7<=9.0 && c9<=10.0)
                {
                   c1=c1+0.04;
                   c3=c3+0.04;
                   c5=c5+0.04;
                   c7=c7+0.04;
                   c9=c9+0.04;
                }else{
                    third=true;
                    second=false;
                }
            }
            if(third)
            {
                if(d1>=5.5 && d3>=8.5 && d5>=8.5 && d7>=5.5 && d9>=6.5)
                {
                   d1=d1-0.04;
                   d3=d3-0.04;
                   d5=d5-0.04;
                   d7=d7-0.04;
                   d9=d9-0.04;
                }else{
                    forth=true;
                    third=false;
                }
            }
            if(forth)
            {
                if(d2<=12.0 && d4<=12.0 && d6<=5.0 && d8<=5.0 && d10<=5.5)
                {
                   d2=d2+0.04;
                   d4=d4+0.04;
                   d6=d6+0.04;
                   d8=d8+0.04;
                   d10=d10+0.04;
                }else{
                    first=true;
                    forth=false;
                    swapt++;
                    Sleep(500);
                    t1=t1-3.5;
                    t2=t2-3.5;
                    t3=t3-3.5;
                }
            }
        }
        if(swapt==5)
        {

            glColor3f(0.0, 0.0, 1.0);
            renderBitmapString(10.0,22.0,GLUT_BITMAP_TIMES_ROMAN_24,"Iteration 3");
            if(first)
            {
                if(d2 >=-6.0 && d4>=-6.0 && d6>=-13.0 && d8>=-13.0 && d10>=-12.5)
                {
                   d2=d2-0.04;
                   d4=d4-0.04;
                   d6=d6-0.04;
                   d8=d8-0.04;
                   d10=d10-0.04;
                }else{
                    second=true;
                    first=false;
                }
            }
            if(second)
            {
                if(b1<=5.5 && b3<=8.5 && b5<=8.5&& b7<=5.5 && b9<=6.5)
                {
                   b1=b1+0.04;
                   b3=b3+0.04;
                   b5=b5+0.04;
                   b7=b7+0.04;
                   b9=b9+0.04;
                }else{
                    third=true;
                    second=false;
                }
            }
            if(third)
            {
                if(d1>=2.0 && d3>=5.0 && d5>=5.0 && d7>=2.0 && d9>=3.0)
                {
                   d1=d1-0.04;
                   d3=d3-0.04;
                   d5=d5-0.04;
                   d7=d7-0.04;
                   d9=d9-0.04;
                }else{
                    forth=true;
                    third=false;
                }
            }
            if(forth)
            {
                if(d2<=12.0 && d4<=12.0 && d6<=5.0 && d8<=5.0 && d10<=5.5)
                {
                   d2=d2+0.04;
                   d4=d4+0.04;
                   d6=d6+0.04;
                   d8=d8+0.04;
                   d10=d10+0.04;
                }else{
                    first=true;
                    forth=false;
                    swapt++;
                    Sleep(500);
                    t1=t1+10.5;
                    t2=t2+10.5;
                    t3=t3+10.5;
                }
            }
        }
        if(swapt==6)
        {
            glColor3f(0.0, 0.0, 1.0);
            renderBitmapString(10.0,22.0,GLUT_BITMAP_TIMES_ROMAN_24,"Iteration 4");
            if(first)
            {
                if(e2 >=-6.0 && e4>=-6.0 && e6>=-13.0 && e8>=-13.0 && e10>=-12.5)
                {
                   e2=e2-0.04;
                   e4=e4-0.04;
                   e6=e6-0.04;
                   e8=e8-0.04;
                   e10=e10-0.04;
                }else{
                    second=true;
                    first=false;
                }
            }
            if(second)
            {
                if(a1<=16.0 && a3<=19.0 && a5<=19.0 && a7<=16.0 && a9<=17.0)
                {
                   a1=a1+0.04;
                   a3=a3+0.04;
                   a5=a5+0.04;
                   a7=a7+0.04;
                   a9=a9+0.04;
                }else{
                    third=true;
                    second=false;
                }
            }
            if(third)
            {
                if(e1>=12.5 && e3>=15.5 && e5>=15.5 && e7>=12.5 && e9>=13.5)
                {
                   e1=e1-0.04;
                   e3=e3-0.04;
                   e5=e5-0.04;
                   e7=e7-0.04;
                   e9=e9-0.04;
                }else{
                    forth=true;
                    third=false;
                }
            }
            if(forth)
            {
                if(e2<=12.0 && e4<=12.0 && e6<=5.0 && e8<=5.0 && e10<=5.5)
                {
                   e2=e2+0.04;
                   e4=e4+0.04;
                   e6=e6+0.04;
                   e8=e8+0.04;
                   e10=e10+0.04;
                }else{
                    first=true;
                    forth=false;
                    swapt++;
                    Sleep(500);
                    t1=t1-3.5;
                    t2=t2-3.5;
                    t3=t3-3.5;
                }
            }
        }
        if(swapt==7)
        {
            glColor3f(0.0, 0.0, 1.0);
            renderBitmapString(10.0,22.0,GLUT_BITMAP_TIMES_ROMAN_24,"Iteration 4");
            if(first)
            {
                if(e2 >=-6.0 && e4>=-6.0 && e6>=-13.0 && e8>=-13.0 && e10>=-12.5)
                {
                   e2=e2-0.04;
                   e4=e4-0.04;
                   e6=e6-0.04;
                   e8=e8-0.04;
                   e10=e10-0.04;
                }else{
                    second=true;
                    first=false;
                }
            }
            if(second)
            {
                if(c1<=12.5 && c3<=15.5 && c5<=15.5 && c7<=12.5 && c9<=13.5)
                {
                   c1=c1+0.04;
                   c3=c3+0.04;
                   c5=c5+0.04;
                   c7=c7+0.04;
                   c9=c9+0.04;
                }else{
                    third=true;
                    second=false;
                }
            }
            if(third)
            {
                if(e1>=9.0 && e3>=12.0 && e5>=12.0 && e7>=9.0 && e9>=10.0)
                {
                   e1=e1-0.04;
                   e3=e3-0.04;
                   e5=e5-0.04;
                   e7=e7-0.04;
                   e9=e9-0.04;
                }else{
                    forth=true;
                    third=false;
                }
            }
            if(forth)
            {
                if(e2<=12.0 && e4<=12.0 && e6<=5.0 && e8<=5.0 && e10<=5.5)
                {
                   e2=e2+0.04;
                   e4=e4+0.04;
                   e6=e6+0.04;
                   e8=e8+0.04;
                   e10=e10+0.04;
                }else{
                    first=true;
                    forth=false;
                    swapt++;
                    Sleep(500);
                    t1=t1-3.5;
                    t2=t2-3.5;
                    t3=t3-3.5;
                }
            }
        }
        if(swapt==8)
        {
            glColor3f(0.0, 0.0, 1.0);
            renderBitmapString(10.0,22.0,GLUT_BITMAP_TIMES_ROMAN_24,"Iteration 4");
            if(first)
            {
                if(e2 >=-6.0 && e4>=-6.0 && e6>=-13.0 && e8>=-13.0 && e10>=-12.5)
                {
                   e2=e2-0.04;
                   e4=e4-0.04;
                   e6=e6-0.04;
                   e8=e8-0.04;
                   e10=e10-0.04;
                }else{
                    second=true;
                    first=false;
                }
            }
            if(second)
            {
                if(b1<=9.0 && b3<=12.0 && b5<=12.0 && b7<=9.0 && b9<=10.0)
                {
                   b1=b1+0.04;
                   b3=b3+0.04;
                   b5=b5+0.04;
                   b7=b7+0.04;
                   b9=b9+0.04;
                }else{
                    third=true;
                    second=false;
                }
            }
            if(third)
            {
                if(e1>=5.5 && e3>=8.5 && e5>=8.5 && e7>=5.5 && e9>=6.5)
                {
                   e1=e1-0.04;
                   e3=e3-0.04;
                   e5=e5-0.04;
                   e7=e7-0.04;
                   e9=e9-0.04;
                }else{
                    forth=true;
                    third=false;
                }
            }
            if(forth)
            {
                if(e2<=12.0 && e4<=12.0 && e6<=5.0 && e8<=5.0 && e10<=5.5)
                {
                   e2=e2+0.04;
                   e4=e4+0.04;
                   e6=e6+0.04;
                   e8=e8+0.04;
                   e10=e10+0.04;
                }else{
                    first=true;
                    forth=false;
                    swapt++;
                    Sleep(500);
                    t1=t1-3.5;
                    t2=t2-3.5;
                    t3=t3-3.5;
                }
            }
        }

       if(swapt==9)
        {
            glColor3f(0.0, 0.0, 1.0);
            renderBitmapString(10.0,22.0,GLUT_BITMAP_TIMES_ROMAN_24,"Iteration 4");
            if(first)
            {
                if(e2 >=-6.0 && e4>=-6.0 && e6>=-13.0 && e8>=-13.0 && e10>=-12.5)
                {
                   e2=e2-0.04;
                   e4=e4-0.04;
                   e6=e6-0.04;
                   e8=e8-0.04;
                   e10=e10-0.04;
                }else{
                    second=true;
                    first=false;
                }
            }
            if(second)
            {
                if(d1<=5.5 && d3<=8.5 && d5<=8.5 && d7<=5.5 && d9<=6.5)
                {
                   d1=d1+0.04;
                   d3=d3+0.04;
                   d5=d5+0.04;
                   d7=d7+0.04;
                   d9=d9+0.04;
                }else{
                    third=true;
                    second=false;
                }
            }
            if(third)
            {
                if(e1>=2.0 && e3>=5.0 && e5>=5.0 && e7>=2.0 && e9>=3.0)
                {
                   e1=e1-0.04;
                   e3=e3-0.04;
                   e5=e5-0.04;
                   e7=e7-0.04;
                   e9=e9-0.04;
                }else{
                    forth=true;
                    third=false;
                }
            }
            if(forth)
            {
                if(e2<=12.0 && e4<=12.0 && e6<=5.0 && e8<=5.0 && e10<=5.5)
                {
                   e2=e2+0.04;
                   e4=e4+0.04;
                   e6=e6+0.04;
                   e8=e8+0.04;
                   e10=e10+0.04;
                }else{
                    first=true;
                    forth=false;
                    swapt++;
                    Sleep(500);
                    t1=t1+14;
                    t2=t2+14;
                    t3=t3+14;
                }
            }
        }
        if(swapt==10)
        {
            glColor3f(0.0, 0.0, 1.0);
            renderBitmapString(10.0,22.0,GLUT_BITMAP_TIMES_ROMAN_24,"Iteration 5");
            if(first)
            {
                if(f2 >=4.0 && f4>=4.0 && f6>=-13.0 && f8>=-13.0 && f10>=-12.5)
                {
                   f2=f2-0.04;
                   f4=f4-0.04;
                   f6=f6-0.04;
                   f8=f8-0.04;
                   f10=f10-0.04;
                }else{
                    second=true;
                    first=false;
                }
            }
            if(second)
            {
                if(wait<=10)
                {
                    wait=wait+0.05;
                }
                else
                {
                    if(f2<=22.0 && f4<=22.0 && f6<=5.0 && f8<=5.0 && f10<=5.5)
                    {
                       f2=f2+0.04;
                       f4=f4+0.04;
                       f6=f6+0.04;
                       f8=f8+0.04;
                       f10=f10+0.04;
                    }else{
                        first=true;
                        second=false;
                        swapt++;
                        Sleep(500);
                        sorted=true;
                    }
                }
            }
        }
//=====================================================================

    }


     if(sorted)
     {
        glColor3f(0.0, 0.0, 1.0);

        renderBitmapString(-10.0,-2.0,GLUT_BITMAP_TIMES_ROMAN_24,"Sorting Complete");
        renderBitmapString(-10.0,-4.0,GLUT_BITMAP_TIMES_ROMAN_24,"Press R to restart Simulation");

     }


      glutPostRedisplay();


        glPushMatrix();


        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_TRIANGLES);
            glVertex2f(t1, 2.5);
            glVertex2f(t2, 1.5);
            glVertex2f(t3, 1.5);
        glEnd();

        glColor3f(0.0,1.2323,1.0);
            glBegin(GL_POLYGON);
                glVertex2f(a1,a2);  // a1,a2
                glVertex2f(a3,a4);  // a3,a2
                glVertex2f(a5,a6);   // a3,a3
                glVertex2f(a7,a8);   // a1,a3
            glEnd();
        glColor3f(1.0, 0.0, 0.0);       //a4,a5
        renderBitmapString(a9,a10,GLUT_BITMAP_TIMES_ROMAN_24,"30");


        glColor3f(0.0,1.2323,1.0);
            glBegin(GL_POLYGON);
                glVertex2f(b1,b2);    //b1,b2
                glVertex2f(b3,b4);   //b3,b2
                glVertex2f(b5,b6);    //b3,b4
                glVertex2f(b7,b8);    //b1,b4
            glEnd();
        glColor3f(1.0, 0.0, 0.0);       //b5,b1
        renderBitmapString(b9,b10,GLUT_BITMAP_TIMES_ROMAN_24,"13");

        glColor3f(0.0,1.2323,1.0);
            glBegin(GL_POLYGON);
                glVertex2f(c1,c2);   //c1,c2
                glVertex2f(c3,c4);   //c3,c2
                glVertex2f(c5,c6);   //c3,c4
                glVertex2f(c7,c8);     //c1,c4
            glEnd();
        glColor3f(1.0, 0.0, 0.0);       //c5,c6
        renderBitmapString(c9,c10,GLUT_BITMAP_TIMES_ROMAN_24,"20");
    //    }

        glColor3f(0.0,1.2323,1.0);
            glBegin(GL_POLYGON);
                glVertex2f(d1,d2);  //d1,d2
                glVertex2f(d3,d4);  //d3,d2
                glVertex2f(d5,d6);   //d3,d4
                glVertex2f(d7,d8);   //d1,d4
            glEnd();
        glColor3f(1.0, 0.0, 0.0);       //d5,d6
        renderBitmapString(d9,d10,GLUT_BITMAP_TIMES_ROMAN_24,"8");


        glColor3f(0.0,1.2323,1.0);
            glBegin(GL_POLYGON);
                glVertex2f(e1,e2);
                glVertex2f(e3,e4);
                glVertex2f(e5,e6);
                glVertex2f(e7,e8);
            glEnd();
        glColor3f(1.0, 0.0, 0.0);
        renderBitmapString(e9,e10,GLUT_BITMAP_TIMES_ROMAN_24,"6");


         glColor3f(0.0,1.2323,1.0);
            glBegin(GL_POLYGON);
                glVertex2f(f1,f2);
                glVertex2f(f3,f4);
                glVertex2f(f5,f6);
                glVertex2f(f7,f8);
            glEnd();
        glColor3f(1.0, 0.0, 0.0);
        renderBitmapString(f9,f10,GLUT_BITMAP_TIMES_ROMAN_24,"35");


     glColor3f(0.0, 0.0, 1.0);
     renderBitmapString(-23.0,23.0,GLUT_BITMAP_TIMES_ROMAN_24,"Simulation of Intertion sort Algorithm");

     glPopMatrix();
     //##################################################################################################################

     glColor3f(0.0, 0.0, 1.0);
     glRasterPos2f(3.0,3.5);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'0');


     glColor3f(0.0, 0.0, 1.0);
     glRasterPos2f(6.5,3.5);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'1');

     glColor3f(0.0, 0.0, 1.0);
     glRasterPos2f(10.0,3.5);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'2');


     glColor3f(0.0, 0.0, 1.0);
     glRasterPos2f(13.5,3.5);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'3');


     glColor3f(0.0, 0.0, 1.0);
     glRasterPos2f(17.0,3.5);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'4');



     glColor3f(0.0, 0.0, 1.0);
     glRasterPos2f(20.5,3.5);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'5');


    glColor3f(0.0, 0.0, 1.0);
    renderBitmapString(-3.0,3.5,GLUT_BITMAP_TIMES_ROMAN_24,"Index ==>>");



//-------------------------------------------------------------
     glColor3f(0.0,0.0,0.0);
     glRectf(-25,22.0,1.0,5.0);


     glColor3f(0.981,0.974,0.981);
     glRectf(-24.5,21.0,0.5,5.5);



     glColor3f(0.0, 0.0, 0.0);

    renderBitmapString(-23.0,20.0,GLUT_BITMAP_9_BY_15,"***Insertion Sort Algorithm***");

    renderBitmapString(-23.0,18.0,GLUT_BITMAP_8_BY_13,"void insertionSort(int a[], int N) {");

    renderBitmapString(-22.0,17.0,GLUT_BITMAP_8_BY_13,"for (int i = 1; i < N; i++) { // O(N)");

    renderBitmapString(-21.0,16.0,GLUT_BITMAP_8_BY_13,"X = a[i]; // X is the item to be inserted");

    renderBitmapString(-21.0,15.0,GLUT_BITMAP_8_BY_13,"for (j = i-1; j >= 0 && a[j] > X; j--) // can be fast or slow");

    renderBitmapString(-20.0,14.0,GLUT_BITMAP_8_BY_13,"a[j+1] = a[j]; // make a place for X");

    renderBitmapString(-21.0,13.0,GLUT_BITMAP_8_BY_13,"a[j+1] = X; // index j+1 is the insertion point");

    renderBitmapString(-22.0,12.0,GLUT_BITMAP_8_BY_13,"}");

    renderBitmapString(-23.0,11.0,GLUT_BITMAP_8_BY_13,"}");

    renderBitmapString(-23.0,9.0,GLUT_BITMAP_8_BY_13,"Input:");

    renderBitmapString(-23.0,7.0,GLUT_BITMAP_8_BY_13,"N=6");

    renderBitmapString(-23.0,6.0,GLUT_BITMAP_8_BY_13,"Array= 30 13 20 8 6 35");


    if(sim==false)
    {

    glColor3f(0.0, 0.0, 1.0);
    renderBitmapString(-20.0,0.0,GLUT_BITMAP_TIMES_ROMAN_24,"PRESS    TO START SIMULATION");
     glColor3f(1.0, 0.0, 0.0);
     glRasterPos2f(-16.8,0.0);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'S');
    }



    glFlush();
}


void init(void)
{
	glClearColor (1.2258, 1.3935, 1.5032, 0.0);
	glOrtho(-25.0, 25.0, -25.0, 25.0, -25.0, 25.0);
}

void simulate()
{
    sim=true;
    glutPostRedisplay();


}
reinitialize()
{
//    p1=-14.0,q1=-6.0,p2=-8.0,q2=-6.0,p3=-2.0,q3=-6.0,p4=4.0,q4=-6.0,p5=10.0,q5=-6.0,t1=-14,t2=-15,t3=-13;
    sim=false;
    sorted=false;
    first=true;
    second=false;
    third=false;
    swapt=1;

    t1=6.75,t2=6.0,t3=7.5;

    //--------------------------------------------------------------------------------------
    a1=2.0,a2=20.0,a3=5.0,a4=20.0,a5=5.0,a6=5.0,a7=2.0,a8=5.0,a9=3.0,a10=5.5;
    b1=5.5,b2=16.0,b3=8.5,b4=16.0,b5=8.5,b6=5.0,b7=5.5,b8=5.0,b9=6.5,b10=5.5;
    c1=9.0,c2=18.0,c3=12.0,c4=18.0,c5=12.0,c6=5.0,c7=9.0,c8=5.0,c9=10.0,c10=5.5;
    d1=12.5,d2=12.0,d3=15.5,d4=12.0,d5=15.5,d6=5.0,d7=12.5,d8=5.0,d9=13.5,d10=5.5;
    e1=16.0,e2=10.0,e3=19.0,e4=10.0,e5=19.0,e6=5.0,e7=16.0,e8=5.0,e9=17.0,e10=5.5;
    f1=19.5,f2=22.0,f3=22.5,f4=22.0,f5=22.5,f6=5.0,f7=19.5,f8=5.0,f9=20.5,f10=5.5;
    //--------------------------------------------------------------------------------------
    glutPostRedisplay();

}

void keyboard(unsigned char key, int x, int y)
{

	switch (key) {

      case 's':
				simulate();
				break;
      case 'S':
				simulate();
				break;
	  case 'r':
                reinitialize();
				break;
      case 'R':
               reinitialize();
               break;

	  default:
			break;
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1200, 800);
	glutInitWindowPosition (100, 0);
	glutCreateWindow ("Insertion sort Algorithm Simulation ");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

