// Lab6_operators.cpp
// This program provides a few examples about operators in C++
// Study the code, run it, pay attention to the comments and questions
// posted, and use the ideas to complete the assignments described in
// the lab 6 guide.
// Reference: zyBook, Section 7.10

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
//                 OR: -std=c++0x
// Example:  g++ Lab6_operators.cpp -o Lab6_operators -std=c++11
//      or:  g++ Lab6_operators.cpp -o Lab6_operators -std=c++0x
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <vector>

using namespace std;

class Lab6
{
public:
	vector<int> a; // could be private, but methods would be needed to access this member.
	
	// operators as member functions: 'this' is bound to the left hand operand
	bool operator>(const Lab6 &rhs) const;	// const emphasizes that 'this' won't change 
	void operator+(const Lab6 &rhs);
	void operator*(int rhs_factor);
	void operator=(const Lab6 &rhs);        //added operator for bottom part of this program
	void Printvals();
	// constructor(s)
	Lab6(){a.resize(2);}
	// destructor
};

// --------------- Member functions ---------------------------------
bool Lab6::operator>(const Lab6 &rhs) const
{
	if ((a[0] > rhs.a[0]) & (a[1] > rhs.a[1]))
		return 1;
	else
		return 0;
}

void Lab6::operator+(const Lab6 &rhs)
{
	a[0] += rhs.a[0];
	a[1] += rhs.a[1];
}

void Lab6::operator*(int rhs_factor)
{
	a[0] *= rhs_factor;
	a[1] *= rhs_factor;
}

void Lab6::Printvals()
{
	cout << "\na[0] = " << a[0] << ", a[1] = " << a[1] << endl;
}

void Lab6::operator=(const Lab6 &rhs)  //added for operator= created 
{
	a[0] = rhs.a[0];
	a[1] = rhs.a[1];
}

// -------- Operators can be Non-member functions -------------------
Lab6 operator+(const Lab6 &lhs, const Lab6 &rhs)
{
	Lab6 sum;
	sum.a[0] = lhs.a[0] + rhs.a[0];
	sum.a[1] = lhs.a[1] + rhs.a[1];
	
	return sum;
}

// Main function. Shows a few examples about using the operators.
int main()
{
	Lab6 obj1, obj2, obj3;
	int f = 10;
	
	obj1.a[0] = 1; obj1.a[1] = 5;
	obj2.a[0] = 10; obj2.a[1] = 20;
	
	if(obj1 > obj2)	// normal expression. Which operator is being called?        Answer: the member function operator >
		cout << "\nObject 1 is bigger than object 2" << endl;
	else
		cout << "\nObject 1 is not bigger than object 2" << endl;
	
	 if(obj1.operator>(obj2))	// equivalent function call (eq. to obj1 > obj2)
		cout << "\nObject 1 is bigger than object 2" << endl;
	else
		cout << "\nObject 1 is not bigger than object 2" << endl;
	
	
	if(obj2 > obj1)	// Which operator is being called?                            Answer: the member function operator >
		cout << "\nObject 2 is bigger than object 1" << endl;
	else
		cout << "\nObject 2 is not bigger than object 1" << endl;
	
	if(obj2.operator>(obj1))	// explicit function call, equivalent to the previous
		cout << "\nObject 2 is bigger than object 1" << endl;
	else
		cout << "\nObject 2 is not bigger than object 1" << endl;
	
	cout << "------------------------------------------------------------------" << endl;
	obj1.Printvals();
	obj2.Printvals();
	
	obj1 + obj2;	// normal expression. Which operator is being called?               Answer: the member function operator +
	// obj1.operator+(obj2);	// equivalent, try it out
	obj1.Printvals();
	obj2.Printvals();
	
	obj2 + obj1;	// normal expression. Which operator is being called?               Answer: the member function operator +
	// obj2.operator+(obj1);	// equivalent, try it out
	obj1.Printvals();
	obj2.Printvals();

	cout << "------------------------------------------------------------------" << endl;
	obj1*2;		// Would 2*obj1 work? Give it a try.                                    Answer:  no, because the order it is called does matter
	obj2*f;		// Would f*obj2 work? Give it a try.                                    Answer:  no, because the order it is called does matter
	//2*obj1;
	//f*obj2;
	obj1.Printvals();
	obj2.Printvals();
	
	cout << "------------------------------------------------------------------" << endl;
	// Which operator is being called next?                                              Answer: the non-member function operator +
	obj3 = operator+(obj1, obj2);	// Would  obj3 = obj2 + obj1; work?                  Answer: no, because there is no operator=
	//obj3.operator=(operator+(obj2, obj1));
	obj1.Printvals();				// If not, how could you make it work?               Answer: a define operator = needs to be created
	obj2.Printvals();
	obj3.Printvals();
	
	obj3 = operator+(obj2, obj1);	// is this the same as before?                       Answer: yes, this is the same as obj3 = operator+(obj1, obj2)
	obj1.Printvals();                                                                    //because order does not matter for this function 
	obj2.Printvals();
	obj3.Printvals();
	
	return 0;
}