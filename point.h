//
//  point.h
//  point
//
//  Created by Bill Zeng on 2015-05-29.
//  Copyright (c) 2015 Bill Zeng. All rights reserved.
//
#include <iostream>
using namespace std;
#ifndef __point__point__
#define __point__point__

class point{
public:
    double x;
    double y;
    point();
    point(double xx, double xy);
    
    void getpoint();
    
    void changepoint(double xx, double yy);
};
class line{
public:
    double a;
    double b;
    double c;
    
    line();
    line(point x, point y);
    line(double x, double y);
    line(double x, double y, double z);
    
    void reduce(double a, double b, double c);
    double GCD(double a, double b, double c);
    
    void Xintercept(double a, double c);
    void Yintercept(double b,double c);
    
    void changeline(line temp);
    
    void equation();
    void equationslopeintercept();
};


#endif /* defined(__point__point__) */
