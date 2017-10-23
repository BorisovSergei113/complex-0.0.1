#include <iostream>
#include <sstream>
using namespace std;

struct complex_t {
    float real;
    float imag;
};


complex_t add( complex_t lhs, complex_t rhs ) {
    complex_t c;
    c.real = lhs.real + rhs.real;
    c.imag = lhs.imag + rhs.imag;
    return c;
}

complex_t sub ( complex_t lhs, complex_t rhs ) {
    complex_t c;
    c.real = lhs.real - rhs.real;
    c.imag = lhs.imag - rhs.imag;
    return c;
}

complex_t mul(complex_t lhs, complex_t rhs ) {
    complex_t c;
    c.real = lhs.real*rhs.real - lhs.imag*rhs.imag;
    c.imag = lhs.imag*rhs.real + lhs.real*rhs.imag;
    return c;

}

complex_t div(complex_t rhs, complex_t lhs ) {
    complex_t c;
    c.real = (rhs.real*lhs.real+rhs.imag*lhs.imag)/(lhs.real*lhs.real+lhs.imag*lhs.imag);
    c.imag = (rhs.imag*lhs.real-rhs.real*lhs.imag)/(lhs.real*lhs.real+lhs.imag*lhs.imag);
    return c;
}

istream & read( istream & stream, complex_t & complex ) {

    char symbol;
    float real, imag;

    if (stream >> symbol && symbol == '(' && stream >> real && stream >> symbol && symbol == ',' && stream >> imag && stream >> symbol && symbol == ')')
    {
        complex.real = real;
        complex.imag = imag;
    }
    else {
        stream.setstate(ios::failbit);
        if(_S_failbit){
            cout<< "An error has occured while reading input data";
        }
    }
}

ostream & write(ostream & stream, complex_t complex)
{
    stream<<"("<<complex.real<<","<<complex.imag<<")";
}


int main() {
    complex_t a;
    complex_t b;
    char op;
    string str;
    getline(cin,str);
    istringstream stream(str);
    read(stream,a);
    stream>>op;
    read(stream,b);
    switch(op) {
        case '+':
            write(cout, add(a, b));
            break;

        case '-':
            write(cout, sub(a, b));
            break;
        case '*':
            write(cout, mul(a, b));
            break;
        case '/':
            write(cout, div(a, b));
            break;
    }
    return 0;
}