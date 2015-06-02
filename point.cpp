//
//  point.cpp
//  point
//
//  Created by Bill Zeng on 2015-05-29.
//  Copyright (c) 2015 Bill Zeng. All rights reserved.
//
#include "point.h"
#include <iostream>
using namespace std;
point::point()
{
    x = 0;
    y = 0;
}
point::point(double xx, double xy)
{
    x = xx;
    y = xy;
}
void point::getpoint()
{
    cout << "(" << x << "," << y << ")" << endl;
}
void point::changepoint(double xx, double yy)
{
    x = xx;
    y = yy;
}
line::line()
{
    a = 0;
    b = 0;
    c = 0;
}
line::line(point x, point y)
{
    double rise = x.y - y.y;
    double run = x.x - y.x;
    double slope = rise/run;
    a = slope;
    b = -1;
    c = (slope*-1)*x.x+x.y;
    reduce(a, b, c);
    reduce(a, b, c);
}
line::line(double x, double y)
{
    a = x;
    b = -1;
    c = y;
    reduce(a, b, c);
}
line::line(double x, double y, double z)
{
    a = x;
    b = y;
    c = z;
    reduce(a, b, c);
}
void line::reduce(double aa, double bb, double cc)
{
    double gcd = GCD(aa,bb,cc);
    a = aa/gcd;
    b = bb/gcd;
    c = cc/gcd;
    if(a<0)
    {
        a = a*-1;
        b = b*-1;
        c = c*-1;
    }
}
double line::GCD(double a, double b, double c)
{
    int tens = 1;
    if(a < 0)
    {
        a = a*-1;
    }
    if(b < 0)
    {
        b = b*-1;
    }
    if(c < 0)
    {
        c = c*-1;
    }
    int aa = a;
    int bb = b;
    int cc = c;
    while(a != aa or b != bb or c!= cc)
    {
        tens = tens*10;
        if(a != aa)
        {
            a = a*10;
            aa = a;
        }
        if(b != bb)
        {
            b = b*10;
            bb = b;
        }
        if(c != cc)
        {
            c = c*10;
            cc = c;
        }
    }
    double large;
    if(aa>bb)
    {
        large = aa;
    }
    if(bb > aa)
    {
        large = bb;
    }
    if(bb==aa and bb>cc)
    {
        large = bb;
    }
    if(large<cc)
    {
        large = cc;
    }
    for(int i=large; i>0; i--)
    {
        if(aa%i==0 and bb%i==0 and cc%i==0)
        {
            double ii = i;
            ii = ii/tens;
            return ii;
        }
    }
    return 1;
}
void line::Xintercept(double a,double c)
{
    int cc = c*-1;
    double xinter = cc/a;
    cout << "(" << xinter << ",0)" << endl;
}
void line::Yintercept(double b,double c)
{
    int cc = c*-1;
    double yinter = cc/b;
    cout << "(0," << yinter << ")" << endl;
}
void line::equation()
{
    cout << a << "x";
    if(b>=0)
    {
        cout << "+";
    }
    cout << b << "y";
    if(c>=0)
    {
        cout << "+";
    }
    cout << c << "=0" << endl;
}
void line::equationslopeintercept()
{
    int m = a/(b*-1);
    int B = c/(b*-1);
    cout << "y=" << m << "x";
    if(B>=0)
    {
        cout << "+";
    }
    cout << B << endl;
}
void line::changeline(line temp)
{
    a = temp.a;
    b = temp.b;
    c = temp.c;
}

