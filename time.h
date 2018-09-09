/* 
Name: Franco Marcoccia
Course: COP3330 Section 1
Assignment: Homework 3
Purpose: This header file contains the class Time which holds member/friend functions, constructors, and private information necessary to run cpp file.
*/

#include <iostream>
using namespace std;

class Time
{
	friend ostream& operator<<(ostream& os, const Time& t);								// Various friend functions for operators
	friend istream& operator>>(istream& is, Time& t);							
	friend Time operator+(const Time& t1, const Time& t2);							
	friend Time operator-(const Time& t1, const Time& t2);
	friend Time operator*(const Time& t1, const Time& t2);
	friend bool operator<(const Time& t1, const Time& t2);
	friend bool operator>(const Time& t1, const Time& t2);
	friend bool operator<=(const Time& t1, const Time& t2);
	friend bool operator>=(const Time& t1, const Time& t2);
	friend bool operator==(const Time& t1, const Time& t2);
	friend bool operator!=(const Time& t1, const Time& t2);

public:
	Time();														//Constructors with 0,1,4 parameters and increment/decrement operators
	Time(int sec);													
	Time(int d,int h,int m,int s);											
	Time& operator++();											
	Time operator++(int);
	Time& operator--();
	Time operator--(int);


private:
	int days;													//Variables to store time
	int hours;													
	int minutes;													
	int seconds;
	int Convert() const;												// self-made function to convert everything to seconds
};
