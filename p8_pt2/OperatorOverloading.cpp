//P8: Operator Overloading
//Cody Wall
//10 December 2019
//Type up the above ^^ example and get it to work.
//Overload the following operators:
//Relational operators ( >, <=, >= )
//Multiplication ( * ) operator
//Division ( / ) operator
//Subtraction ( - ) operator
//Test all your overloaded operators from the main ( )
//Submit the program test run using multiline comments /*   */ at the bottom of your code

#include <iostream>
using namespace std;

class Distance
{
private:
    int meter;
public:
    //constructor
    Distance (int m)    { meter = m; }
    //overload <
    bool operator < (const Distance d)  {return meter < d.meter; }
    // overload >
    bool operator > (const Distance d)  {return meter > d.meter; }
    // overload <=
    bool operator <= (const Distance d)  {return meter <= d.meter; }
    // overload >=
    bool operator >= (const Distance d)  {return meter >= d.meter; }
    //overload ==
    bool operator == (const Distance &d)  {return meter == d.meter; }
    // overload !=
    bool operator != (const Distance &d)  {return meter != d.meter; }
    //overload =
    void operator = (const Distance &d)  { meter = d.meter; }
    //overload +
    Distance operator + (const Distance &d)
    {
        Distance dist(0);
        dist.meter = this->meter + d.meter; // 'this'= d1; d = d2;
        return dist;
    }
    Distance operator - (const Distance &d)
    //overload -
    {
        Distance dist(0);
        dist.meter = this->meter - d.meter; // 'this'= d1; d = d2;
        return dist;
    }
    Distance operator * (const Distance &d)
    //overload *
    {
        Distance dist(0);
        dist.meter = this->meter * d.meter; // 'this'= d1; d = d2;
        return dist;
    }
    Distance operator / (const Distance &d)
    //overload /
    {
        Distance dist(0);
        dist.meter = this->meter / d.meter; // 'this'= d1; d = d2;
        return dist;
    }
    //overload <<
    friend ostream &operator << (ostream &output, const Distance &d)
    {
        output << d.meter << "m " << endl;
        return output;
    }
    //overload >>
    friend istream &operator >> ( istream &input, Distance &d )
    {
        input >> d.meter;
        return input;
    }
};
int main() {
    Distance d1(4), d2(2), d3(0), d4(4);
    cout << boolalpha;
    cout << "d1 = " << d1; // overload << for d1, d2, d3, d4
    cout << "d2 = " << d2;
    cout << "d3 = " << d3;
    cout << "d4 = " << d4;
    d4 = d1 + d2;
    cout << "d4 = d1 + d2 = " << d1 + d2; //overload +
    cout << "d2 - d1 = d4 = " << d2 - d1; //overload -
    cout << "d1 / d2 = d4 = " << d1 / d2; //overload +
    cout << "d1 * d2 = d4 = " << d1 * d2; //overload *

    cout << "(d1 < d2) is " << (d1 < d2) << endl; //overload <
    cout << "(d2 < d1) is " << (d2 < d1) << endl; //overload <
    cout << "(d1 <= d2) is " << (d1 <= d2) << endl; //overload <=
    cout << "(d1 >= d2) is " << (d1 >= d2) << endl; //overload >=
    cout << "(d2 == d1) is " << (d2 == d1) << endl; //overload ==
    cout << "(d1 != d2) is " << (d1 != d2) << endl; //overload !=
    cout << "Enter d4:";
    cin >> d4;                                  //overload >>
    cout << "d4 = " << d4;                      //overload <<


    return 0;
}

/*
/Users/cody/Desktop/fall19/data-structures/p8_pt2/cmake-build-debug/p8_pt2
        d1 = 4m
d2 = 2m
d3 = 0m
d4 = 4m
d4 = d1 + d2 = 6m
d2 - d1 = d4 = -2m
d1 / d2 = d4 = 2m
d1 * d2 = d4 = 8m
        (d1 < d2) is false
(d2 < d1) is true
(d1 <= d2) is false
(d1 >= d2) is true
(d2 == d1) is false
(d1 != d2) is true
Enter d4:33
d4 = 33m

Process finished with exit code 0
*/