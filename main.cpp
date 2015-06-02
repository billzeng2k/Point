//
//  main.cpp
//  point
//
//  Created by Bill Zeng on 2015-05-29.
//  Copyright (c) 2015 Bill Zeng. All rights reserved.
//

#include <iostream>
#include "point.h"
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
void parallel(line x, line y)
{
    int parallel1 = x.a/(x.b*-1);
    int parallel2 = y.a/(y.b*-1);
    if(parallel1 == parallel2)
    {
        cout << "Parallel" << endl;
    }
    else
        cout << "Not Parallel" << endl;;
}
void coincident(line x, line y)
{
    if(x.a==y.a and x.b==y.b and x.c==y.c)
    {
        cout << "Coincident" << endl;
    }
    else
        cout << "Not Coincident" << endl;
}
double multiple(double x, double y)
{
    if(y>x)
    {
        double temp = y;
        y = x;
        x = temp;
    }
    return x/y;
}
void intersect(line x, line y)
{
    double a, b, c;
    double aa, bb, cc;
    double Yvalue;
    double Cvalue;
    double Xvalue;
    double multi = multiple(x.a, y.a);
    if(x.a > y.a)
    {
        a = y.a*multi;
        b = y.b*multi;
        c = y.c*multi;
        aa = x.a;
        bb = x.b;
        cc = x.c;
    }
    else
    {
        a = x.a*multi;
        b = x.b*multi;
        c = x.c*multi;
        aa = y.a;
        bb = y.b;
        cc = y.c;
    }
    Cvalue = (c-cc);
    Yvalue = Cvalue/(bb - b);
    Xvalue = ((x.b*Yvalue*-1)+(x.c*-1))/x.a;
    cout << "(" << Xvalue << "," << Yvalue << ")" << endl;
}
void addpoint(vector<point>& newpoint)
{
    double x, y;
    cout << "How many new points?" << endl;
    int pointsize;
    cin >> pointsize;
    
    for(int i = 0; i < pointsize; i++)
    {
        cout << "Point number " << i+1 << endl;
        cout << "X value:";
        cin >> x;
        cout << "Y value:";
        cin >> y;
        point newp(x,y);
        newpoint.push_back(newp);
    }
}
void addpointrand(vector<point>& newpoint)
{
    srand(time(NULL));
    bool decimals;
    int choice1;
    int choice;
    int range1x;
    int range2x;
    int range1y;
    int range2y;
    cout << "How many new points?" << endl;
    int pointsize;
    cin >> pointsize;
    cout << "What is the range for the X-Coordinate?" << endl;
    cout << "Starting Number:";
    cin >> range1x;
    cout << "Ending Number:";
    cin >> range2x;
    cout << "Do you wish to create a seperate range for the Y-Coordinate?" << endl << "1.Use the same range" << endl << "2.No, I want a different range" << endl;
    cin >> choice;
    if(choice == 1)
    {
        range1y = range1x;
        range2y = range2x;
    }
    else
    {
        cout << "What is the range for the Y-Coordinate?" << endl;
        cout << "Starting Number:";
        cin >> range1y;
        cout << "Ending Number:";
        cin >> range2y;
    }
    cout << "Include Decimals?" << endl << "1.Yes" << endl << "2.No" << endl;
    cin >> choice1;
    if(choice1==1)
    {
        decimals = true;
    }
    else
    {
        decimals = false;
    }
    for(int i = 0; i < pointsize; i++)
    {
        double rand1;
        double rand2;
        if(range1x>=0)
        {
            rand1 = rand()%(range2x+1-range1x)+range1x;
        }
        else
        {
            rand1 = (rand()%((range1x*-1)-(range2x*-1))*-1)+range2x;
        }
        if(range1y>=0)
        {
            rand2 = rand()%(range2y+1-range1y)+range1y;
        }
        else
        {
            rand2 = (rand()%((range1y*-1)-(range2y*-1))*-1)+range2y;;
        }
        point newp;
        if(decimals==false)
        {
            point p(rand1,rand2);
            newp.changepoint(p.x, p.y);
        }
        else
        {
            double dec = rand()%9;
            dec = dec/10;
            double dec1 = rand()%9;
            dec1 = dec1/10;
            point p(rand1,rand2);
            newp.changepoint(p.x+dec, p.y+dec1);
        }
        newpoint.push_back(newp);
    }
}
void addline1(vector<line>& newline, vector<point>& point)
{
    cout << "How many new lines?" << endl;
    int option;
    int option1;
    int linesize;
    cin >> linesize;
    for(int i = 0; i < linesize; i++)
    {
        cout << "Line number " << i+1 << endl;
        cout << "Which Point?" << endl << "First Point:" << endl;
        for(int i = 0; i < point.size();i++)
        {
            cout << i << ".";
            point[i].getpoint();
        }
        cin >> option;
        cout << "Which Point?" << endl << "Second Point:" << endl;
        for(int i = 0; i < point.size();i++)
        {
            if(option != i)
            {
                cout << i << ".";
                point[i].getpoint();
            }
        }
        cin >> option1;
        line newl(point[option], point[option1]);
        newline.push_back(newl);
    }
}
void addline2(vector<line>& newline)
{
    double m, b;
    cout << "How many new lines?" << endl;
    int linesize;
    cin >> linesize;
    
    for(int i = 0; i < linesize; i++)
    {
        cout << "Line number " << i+1 << endl;
        cout << "M value:";
        cin >> m;
        cout << "B value:";
        cin >> b;
        line newl(m,b);
        newline.push_back(newl);
    }
}
void addline3(vector<line>& newline)
{
    double a, b, c;
    cout << "How many new lines?" << endl;
    int linesize;
    cin >> linesize;
    
    for(int i = 0; i < linesize; i++)
    {
        cout << "Line number " << i+1 << endl;
        cout << "A value:";
        cin >> a;
        cout << "B value:";
        cin >> b;
        cout << "C value:";
        cin >> c;
        line newl(a,b,c);
        newline.push_back(newl);
    }
}
void addlinerand(vector<line>& newline)
{
    srand(time(NULL));
    int choice;
    int choice1;
    int range1a;
    int range2a;
    int range1b;
    int range2b;
    int range1c;
    int range2c;
    cout << "How many new lines?" << endl;
    int pointsize;
    cin >> pointsize;
    cout << "What is the range for the A-Value" << endl;
    cout << "Starting Number:";
    cin >> range1a;
    cout << "Ending Number:";
    cin >> range2a;
    cout << "Do you wish to create a seperate range for the B-Value?" << endl << "1.Use the same range" << endl << "2.No, I want a different range" << endl;
    cin >> choice;
    if(choice == 1)
    {
        range1b = range1a;
        range2b = range2a;
    }
    else
    {
        cout << "What is the range for the B-Value?" << endl;
        cout << "Starting Number:";
        cin >> range1b;
        cout << "Ending Number:";
        cin >> range2b;
    }
    cout << "Do you wish to create a seperate range for the C-Value?" << endl << "1.Use the same range and the range for the A-Value" << endl << "2.Use the same range and the range for the B-Value" << endl << "3.No, I want a different range" << endl;
    cin >> choice1;
    if(choice1 == 1)
    {
        range1c = range1a;
        range2c = range2a;
    }
    else if(choice1 == 2)
    {
        range1c = range1b;
        range2c = range2b;
    }
    else
    {
        cout << "What is the range for the C-Value?" << endl;
        cout << "Starting Number:";
        cin >> range1c;
        cout << "Ending Number:";
        cin >> range2c;
    }
    for(int i = 0; i < pointsize; i++)
    {
        int rand1;
        int rand2;
        int rand3;
        if(range1a>=0)
        {
            rand1 = rand()%(range2a+1-range1a)+range1a;
        }
        else
        {
            rand1 = (rand()%((range1a*-1)-(range2a*-1))*-1)+range2a;
        }
        if(range1b>=0)
        {
            rand2 = rand()%(range2b+1-range1b)+range1b;
        }
        else
        {
            rand2 = (rand()%((range1b*-1)-(range2b*-1))*-1)+range2b;
        }
        if(range1c>=0)
        {
            rand3 = rand()%(range2c+1-range1c)+range1c;
        }
        else
        {
            rand3 = (rand()%((range1c*-1)-(range2c*-1))*-1)+range2c;
        }
        line newl(rand1,rand2,rand3);
        newline.push_back(newl);
    }
}
int main()
{
    bool slopeintercept = false;
    vector <point> p;
    vector <line> l;
    while(1)
    {
        int choice;
        cout << "0.Create Point" << endl << "1.Create Line" << endl << "2.Change Point" << endl << "3.Change Line"  << endl << "4.Find X-Intercept" << endl << "5.Find Y-Intercept" << endl << "6.Determine if lines are coincident" << endl << "7.Determine if lines are parallel" << endl << "8.Determine Intersection" << endl << "9.Show all points" << endl << "10.Show all lines" << endl << "11.Delete Points" << endl << "12.Delete Lines" << endl;
        if(slopeintercept == true)
        {
            cout << "13.Change to Standard form" << endl;
        }
        if(slopeintercept == false)
        {
            cout << "13.Change to Slope-Intercept form" << endl;
        }
        cin >> choice;
        if(choice == 2)
        {
            if(p.size() > 0)
            {
                int option;
                double x;
                double y;
                cout << "Which Point" << endl;
                for(int i = 0; i < p.size(); i++)
                {
                    cout << i << ".";
                    p[i].getpoint();
                }
                cin >> option;
                cout << "Enter new X-Coordinate:";
                cin >> x;
                cout << "Enter new Y-Coordinate:";
                cin >> y;
                p[option].changepoint(x, y);
            }
            else
            {
                cout << "You must create a point first" << endl;
            }
        
        }
        if(choice == 3)
        {
            if(l.size()>0)
            {
                int option;
                cout << "Which line?" << endl;
                if(slopeintercept==false)
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equation();
                    }
                }
                else
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equationslopeintercept();
                    }
                }
                cin >> option;
                int option1;
                cout << "How?" << endl << "1.Two Points" << endl << "2.Enter m and b" << endl << "3.Enter A, B  and C" << endl;
                cin >> option1;
                if(option1 == 1)
                {
                    if(p.size()>1)
                    {
                        int option2;
                        cout << "Which two points?" << endl << "First Point:" << endl;
                        for(int i = 0; i < p.size(); i++)
                        {
                            cout << i << ".";
                            p[i].getpoint();
                        }
                        cin >> option2;
                        cout << "Second Point:" << endl;
                        int option3;
                        for(int i = 0; i < p.size(); i++)
                        {
                            if(option2 != i)
                            {
                                cout << i << ".";
                                p[i].getpoint();
                            }
                        }
                        cin >> option3;
                        line temp(p[option2],p[option3]);
                        l[option].changeline(temp);
                    }
                    else
                    {
                         cout << "You must create two or more points first" << endl;
                    }
                }
                if(option1 == 2)
                {
                    double m;
                    double b;
                    cout << "Enter m:";
                    cin >> m;
                    cout << "Enter b:";
                    cin >> b;
                    line temp(m,b);
                    l[option].changeline(temp);
                }
                if(option1 == 3)
                {
                    double a;
                    double b;
                    double c;
                    cout << "Enter A:";
                    cin >> a;
                    cout << "Enter B:";
                    cin >> b;
                    cout << "Enter C:";
                    cin >> c;
                    line temp(a,b,c);
                    l[option].changeline(temp);
                }
            }
            else
            {
                cout << "You must create a line first" << endl;
            }
        }
        if(choice==0)
        {
            int option;
            cout << "1.Intialize your own points" << endl << "2.Get Random Points" << endl;
            cin >> option;
            if(option==1)
            {
                addpoint(p);
            }
            if(option==2)
            {
                addpointrand(p);
            }
        }
        if(choice==1)
        {
            int option;
            cout << "How?" << endl << "1.Two Points" << endl << "2.Enter m and b" << endl << "3.Enter A, B and C" << endl << "4.Get Random lines" << endl;
            cin >> option;
            if(option==1)
            {
                if(p.size()>1)
                {
                    addline1(l,p);
                }
                else
                {
                    cout << "You must create two or more points first" << endl;
                }
            }
            if(option==2)
            {
                addline2(l);
            }
            if(option==3)
            {
                addline3(l);
            }
            if(option==4)
            {
                addlinerand(l);
            }
        }
        if(choice==4)
        {
            if(l.size()>0)
            {
                int option;
                cout << "Which line?" << endl;
                if(slopeintercept==false)
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equation();
                    }
                }
                else
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equationslopeintercept();
                    }
                }
                cin >> option;
                l[option].Xintercept(l[option].a, l[option].c);
            }
            else
            {
                cout << "You must create a line first" << endl;
            }
        }
        if(choice==5)
        {
            if(l.size()>0)
            {
                int option;
                cout << "Which line?" << endl;
                if(slopeintercept==false)
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equation();
                    }
                }
                else
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equationslopeintercept();
                    }
                }
                cin >> option;
                l[option].Yintercept(l[option].b, l[option].c);
            }
            else
            {
                  cout << "You must create a line first" << endl;
            }
        }
        if(choice==6)
        {
            if(l.size()>0)
            {
                int option;
                cout << "Which lines?" << endl;
                cout << "First line:" << endl;
                if(slopeintercept==false)
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equation();
                    }
                }
                else
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equationslopeintercept();
                    }
                }
                cin >> option;
                int option1;
                cout << "Second line:" << endl;
                if(slopeintercept==false)
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        if(option != i)
                        {
                            cout << i << ".";
                            l[i].equation();
                        }
                    }
                }
                else
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        if(option != i)
                        {
                            cout << i << ".";
                            l[i].equationslopeintercept();
                        }
                    }
                }
                
                cin >> option1;
                coincident(l[option], l[option1]);
            }
            else
            {
                cout << "You must create a line first" << endl;
            }
        }
        if(choice==7)
        {
            if(l.size()>0)
            {
                int option;
                cout << "Which lines?" << endl;
                cout << "First line:" << endl;
                if(slopeintercept==false)
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equation();
                    }
                }
                else
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equationslopeintercept();
                    }
                }
                cin >> option;
                int option1;
                cout << "Second line:" << endl;
                if(slopeintercept==false)
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        if(option != i)
                        {
                            cout << i << ".";
                            l[i].equation();
                        }
                    }
                }
                else
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        if(option != i)
                        {
                            cout << i << ".";
                            l[i].equationslopeintercept();
                        }
                    }
                }
                cin >> option1;
                parallel(l[option], l[option1]);
            }
            else
            {
                cout << "You must create a line first" << endl;
            }
        }
        if(choice==10)
        {
            if(l.size()>0)
            {
                if(slopeintercept==false)
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equation();
                    }
                }
                else
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equationslopeintercept();
                    }
                }
            }
            else
            {
                cout << "You must create a line first" << endl;
            }
        }
        if(choice==9)
        {
            if(p.size()>0)
            {
                for(int i = 0; i < p.size(); i++)
                {
                    cout << i << ".";
                    p[i].getpoint();
                }
            }
            else
            {
                cout << "You must create a point first" << endl;
            }
        }
        if(choice==13)
        {
            if(slopeintercept==true)
            {
                slopeintercept=false;
            }
            else
            {
                slopeintercept=true;
            }
        }
        if(choice==11)
        {
            if(p.size()>0)
            {
                int option;
                cout << "How?" << endl << "1.Individually" << endl << "2.By a range" << endl << "3.Delete all duplicates" << endl;
                cin >> option;
                if(option==1 or option==2)
                {
                    for(int i = 0; i < p.size(); i++)
                    {
                        cout << i << ".";
                        p[i].getpoint();
                    }
                }
                if(option==1)
                {
                    int Delete;
                    cout << "Which point do u want to delete?" << endl;
                    cin >> Delete;
                    p.erase(p.begin()+Delete);
                }
                if(option==2)
                {
                    int range1;
                    int range2;
                    cout << "What is the range that you want to delete?" << endl;
                    cout << "Starting number:";
                    cin >> range1;
                    cout << "Ending number:";
                    cin >> range2;
                    p.erase(p.begin()+range1, p.begin()+range2);
                }
                if(option==3)
                {
                    for(int i=0;i<p.size();i++)
                    {
                        for(int j=0;j<p.size();j++)
                        {
                            if(i!=j)
                            {
                                if(p[i].x==p[j].x and p[i].y==p[j].y)
                                {
                                    p.erase(p.begin()+i);
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                cout << "You must create a point first" << endl;
            }
        }
        if(choice==12)
        {
            if(l.size()>0)
            {
                int option;
                cout << "How?" << endl << "1.Individually" << endl << "2.By a range" << endl << "3.Delete all duplicates" << endl;
                cin >> option;
                if(option==1 or option==2)
                {
                    if(slopeintercept==false)
                    {
                        for(int i = 0; i < l.size(); i++)
                        {
                            cout << i << ".";
                            l[i].equation();
                        }
                    }
                    else
                    {
                        for(int i = 0; i < l.size(); i++)
                        {
                            cout << i << ".";
                            l[i].equationslopeintercept();
                        }
                    }
                }
                if(option==1)
                {
                    int Delete;
                    cout << "Which line do u want to delete?" << endl;
                    cin >> Delete;
                    l.erase(l.begin()+Delete);
                }
                if(option==2)
                {
                    int range1;
                    int range2;
                    cout << "What is the range that you want to delete?" << endl;
                    cout << "Starting number:";
                    cin >> range1;
                    cout << "Ending number:";
                    cin >> range2;
                    l.erase(l.begin()+range1, l.begin()+range2);
                }
                if(option==3)
                {
                    for(int i=0;i<l.size();i++)
                    {
                        for(int j=0;j<l.size();j++)
                        {
                            if(i!=j)
                            {
                                if(l[i].a==l[j].a and l[i].b==l[j].b and l[i].c==l[j].c)
                                {
                                    l.erase(l.begin()+i);
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                cout << "You must create a line first" << endl;
            }
        }
        if(choice==8)
        {
            if(l.size()>0)
            {
                int option;
                cout << "Which lines?" << endl;
                cout << "First line:" << endl;
                if(slopeintercept==false)
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equation();
                    }
                }
                else
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        cout << i << ".";
                        l[i].equationslopeintercept();
                    }
                }
                cin >> option;
                int option1;
                cout << "Second line:" << endl;
                if(slopeintercept==false)
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        if(option != i)
                        {
                            cout << i << ".";
                            l[i].equation();
                        }
                    }
                }
                else
                {
                    for(int i = 0; i < l.size(); i++)
                    {
                        if(option != i)
                        {
                            cout << i << ".";
                            l[i].equationslopeintercept();
                        }
                    }
                }
                cin >> option1;
                intersect(l[option], l[option1]);
            }
            else
            {
                cout << "You must create a line first" << endl;
            }
        }
    }
}

