#include <iostream>

using namespace std;

class MyComplex
{
public:
  double re{};
  double im{};

  MyComplex& operator+(const MyComplex& d);
  MyComplex& operator-(const MyComplex& d);
  MyComplex& operator*(const MyComplex& d);

};

MyComplex& MyComplex::operator+(const MyComplex& d)
{
  MyComplex c;
  c.im = im + d.im;
  c.re = re + d.re;
  return c;
}

MyComplex& MyComplex::operator-(const MyComplex& d)
{
  MyComplex c;
  c.im = im - d.im;
  c.re = re - d.re;
  return c;
}

ostream& operator<<(ostream& o, MyComplex b)
{
  o << b.re << "+i" << b.im;
  return o;
}


istream& operator>>(istream& o, MyComplex& b)
{
  o >> b.re >> b.im;
  return o;
}


void main()
{
  MyComplex c;
  cin >> c;
  cout << c-c;
}