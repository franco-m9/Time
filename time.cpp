/* 
Name: Franco Marcoccia
Course: COP3330 Section 1
Assignment: Homework 3
Purpose: This cpp file contains the function definitions for class Time. These functions basically use operator overloading to store/update the amount of days,hours,minutes, and seconds on a clock.
*/

#include <iostream>
#include "time.h"
using namespace std;

Time::Time()													// sets variables to 0
{
	days=0, hours=0, minutes=0, seconds=0;
}

Time::Time(int sec)												// takes in seconds and increases other variables based off time logic
{
	if(sec<0)
	{
	days=0,hours=0,minutes=0,seconds=0;
	seconds=0;
	}

	else
	{
	seconds=(sec%60);
	sec=(sec/60);
	minutes=(sec%60);
	sec=(sec/60);
	hours=(sec%24);
	sec=(sec/24);
	days=sec;
	}
	
}

Time::Time(int d, int h, int m, int s)										// takes in all variables and changes others based off time logic
{
	if(d<0 || h<0 || m<0 || s<0)
	days=0,hours=0,minutes=0,seconds=0;

	else
	{
	days=d;
	hours=h;
	minutes=m;
	seconds=s;
	
		if(seconds>59)
		{
		minutes=(minutes+(seconds/60));
		seconds=(seconds%60);
		}
		if(minutes>59)
		{
		hours=(hours+(minutes/60));
		minutes=(minutes%60);
		}
		if(hours>23)
		{
		days=(days+(hours/24));
		hours=(hours%24);
		}
	}
}

ostream& operator<<(ostream& os, const Time& t)										// various output formats depending if single digit or not
{
if(t.hours>9 && t.minutes>9 && t.seconds>9) 
os << t.days << "~" << t.hours << ":" << t.minutes << ":" << t.seconds;
	
	else if(t.hours<10 && t.minutes>9 && t.seconds>9)
	os << t.days << "~0" << t.hours << ":" << t.minutes << ":" << t.seconds;
	else if(t.hours<10 && t.minutes<10 && t.seconds>9)
	os << t.days << "~0" << t.hours << ":0" << t.minutes << ":" << t.seconds;
	else if(t.hours<10 && t.minutes<10 && t.seconds<10)
	os << t.days << "~0" << t.hours << ":0" << t.minutes << ":0" << t.seconds;
	else if(t.hours<10 && t.minutes>9 && t.seconds<10)
	os << t.days << "~0" << t.hours << ":" << t.minutes << ":0" << t.seconds;
		
		else if(t.hours>9 && t.minutes<10 && t.seconds<10)
		os << t.days << "~" << t.hours << ":0" << t.minutes << ":0" << t.seconds;
		else if(t.hours>9 && t.minutes<10 && t.seconds>9)
		os << t.days << "~" << t.hours << ":0" << t.minutes << ":" << t.seconds;
			
			else if(t.hours>9 && t.minutes>9 && t.seconds<10)
			os << t.days << "~" << t.hours << ":" << t.minutes << ":0" << t.seconds;
}

istream& operator>>(istream& is, Time& t)										// first determins if input is logical and then stores into actual data
{
int dtemp,htemp,mtemp,stemp;
char useless;

is >> dtemp >> useless >> htemp >> useless >> mtemp >> useless >> stemp; 
	if(dtemp<0 || htemp<0 || mtemp<0 || stemp<0)
	{
	t.days=0;
	t.hours=0;
	t.minutes=0;
	t.seconds=0;
	}
	else
	{
	t.days=dtemp;
	t.hours=htemp;
	t.minutes=mtemp;
	t.seconds=stemp;
	}

		if(t.seconds>59)
                {
                t.minutes=(t.minutes+(t.seconds/60));
                t.seconds=(t.seconds%60);
                }
                if(t.minutes>59)
                {
                t.hours=(t.hours+(t.minutes/60));
                t.minutes=(t.minutes%60);
                }
                if(t.hours>23)
                {
                t.days=(t.days+(t.hours/24));
                t.hours=(t.hours%24);
                }
}

Time operator+(const Time& t1, const Time& t2)												//Arithmatic operators create new objects to store values
{																	
Time plus;																
plus.days=(t1.days+t2.days);
plus.hours=(t1.hours+t2.hours);
plus.minutes=(t1.minutes+t2.minutes);
plus.seconds=(t1.seconds+t2.seconds);
	
		if(plus.seconds>59)
		{
		plus.minutes=(plus.minutes+(plus.seconds/60));
		plus.seconds=(plus.seconds%60);
		}
		if(plus.minutes>59)
		{
		plus.hours=(plus.hours+(plus.minutes/60));
		plus.minutes=(plus.minutes%60);
		}
		if(plus.hours>23)
		{
		plus.days=(plus.days+(plus.hours/24));
		plus.hours=(plus.hours%24);
		}
return plus;
}

Time operator-(const Time& t1, const Time& t2)
{
Time minus;
	
	if(t1.Convert()<t2.Convert())
	minus.days=0,minus.hours=0,minus.minutes=0,minus.seconds=0;

	else
	{
	minus.days=(t1.days-t2.days);
	minus.hours=(t1.hours-t2.hours);
	minus.minutes=(t1.minutes-t2.minutes);
	minus.seconds=(t1.seconds-t2.seconds);
	
		if(minus.seconds>59)
		{
		minus.minutes=(minus.minutes+(minus.seconds/60));
		minus.seconds=(minus.seconds%60);
		}
		if(minus.minutes>59)
		{
		minus.hours=(minus.hours+(minus.minutes/60));
		minus.minutes=(minus.minutes%60);
		}
		if(minus.hours>23)
		{
		minus.days=(minus.days+(minus.hours/24));
		minus.hours=(minus.hours%24);
		}
	}
return minus;		
}

Time operator*(const Time& t1, const Time& t2)
{
Time multiply;
multiply.days=(t1.days*t2.days);
multiply.hours=(t1.hours*t2.hours);
multiply.minutes=(t1.minutes*t2.minutes);
multiply.seconds=(t1.seconds*t2.seconds);
	
		if(multiply.seconds>59)
		{
		multiply.minutes=(multiply.minutes+(multiply.seconds/60));
		multiply.seconds=(multiply.seconds%60);
		}
		if(multiply.minutes>59)
		{
		multiply.hours=(multiply.hours+(multiply.minutes/60));
		multiply.minutes=(multiply.minutes%60);
		}
		if(multiply.hours>23)
		{
		multiply.days=(multiply.days+(multiply.hours/24));
		multiply.hours=(multiply.hours%24);
		}
return multiply;

}

bool operator<(const Time& t1, const Time& t2)									//Comparison operators use Convert function to compare values off seconds
{														
if(t1.Convert()<t2.Convert())											
return true;
else
return false;
}

bool operator>(const Time& t1, const Time& t2)
{
if(t1.Convert()>t2.Convert())
return true;
else
return false;
}

bool operator<=(const Time& t1, const Time& t2)
{
if(t1.Convert()<=t2.Convert())
return true;
else
return false;
}

bool operator>=(const Time& t1, const Time& t2)
{
if(t1.Convert()>=t2.Convert())
return true;
else
return false;
}

bool operator==(const Time& t1, const Time& t2)
{
if(t1.Convert()==t2.Convert())
return true;
else
return false;
}

bool operator!=(const Time& t1, const Time& t2)
{
if(t1.Convert()!=t2.Convert())
return true;
else
return false;
}

Time& Time::operator++()
{
seconds=seconds+1;

		if(seconds>59)
		{
		minutes=(minutes+(seconds/60));
		seconds=(seconds%60);
		}
		if(minutes>59)
		{
		hours=(hours+(minutes/60));
		minutes=(minutes%60);
		}
		if(hours>23)
		{
		days=(days+(hours/24));
		hours=(hours%24);
		}
return *this;
}

Time Time::operator++(int)
{
Time temp=*this;
seconds=seconds+1;

		if(seconds>59)
		{
		minutes=(minutes+(seconds/60));
		seconds=(seconds%60);
		}
		if(minutes>59)
		{
		hours=(hours+(minutes/60));
		minutes=(minutes%60);
		}
		if(hours>23)
		{
		days=(days+(hours/24));
		hours=(hours%24);
		}
return temp;
}

Time& Time::operator--()													// Takes into consideration if hours,minutes, or seconds are 0 and increases others before
{
	if(Convert()!=0)
	{
		if(seconds==0)
		{
			seconds=59;
				if(minutes>0)
				{
				minutes=minutes-1;
				return *this;
				}
				else if(minutes<1 && hours>0)
				{
				minutes=59;
				hours=hours-1;
				return *this;
				}
				else if(minutes<1&&hours<1)
				{
				days=days-1;
				hours=hours-1;
				minutes=minutes-1;
				return *this;
				}
		}
		else if(seconds>0)
		{
		seconds=seconds-1;
		return *this;
		}
	}
}

Time Time::operator--(int)
{
	if(Convert()!=0)
	{
		if(seconds>0)
		{
		Time temp=*this;
		seconds=seconds-1;
		return temp;
		}
		else if(seconds==0)
                {
		Time temp=*this;
                seconds=59;
                                if(minutes>0)
                                {
                                minutes=minutes-1;
                                return temp;
                                }
                                else if(minutes<1 && hours>0)
                                {
                                minutes=59;
                                hours=hours-1;
                                return temp;
                                }
                                else if(minutes<1&&hours<1)
                                {
                                days=days-1;
                                hours=hours-1;
                                minutes=minutes-1;
                                return temp;
                                }
                }
                

	}
}
int Time::Convert() const														// self-made function which converts total time to purely seconds
{
int totalconvert;
int dayconvert=days*86400;
int hourconvert=hours*3600;
int minuteconvert=minutes*60;
totalconvert=dayconvert+hourconvert+minuteconvert+seconds;
return totalconvert;
}
