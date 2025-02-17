#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

class MyComplex
{
private:
  double re{};
  double im{};
public:
  //Ввод и вывод
  friend istream& operator>>(istream& o, MyComplex& b);
  friend ostream& operator<<(ostream& o, MyComplex b);
  //Арифметические операции
  MyComplex& operator+(const MyComplex& d);
  MyComplex& operator-(const MyComplex& d);
  MyComplex& operator*(const MyComplex& d);
  MyComplex& operator/(const MyComplex& d);
  //Геттеры
  double get_re()
  {
    return this->re;
  }
  double get_im()
  {
    return this->im;
  }
  //Сеттеры
  void set_re(double a)
  {
    this->re = a;
  }
  void set_im(double a)
  {
    this->im = a;
  }
  //Модуль и аргумент
  double abs(MyComplex a)
  {
    return(sqrt(a.get_re() * a.get_re() + a.get_im() * a.get_im()));
  }
  double arg(MyComplex a)
  {
    return(atan(a.get_im() / a.get_re()) * 180 / M_PI);
  }
  //Возведение в степень
  MyComplex pow(MyComplex a, int n);
  //Сравнение
  //friend bool operator==(const MyComplex a,const MyComplex b);
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

MyComplex& MyComplex::operator*(const MyComplex& d)
{
  MyComplex c;
  c.re = re * d.re - im * d.im;
  c.im = re * d.im + im * d.re;
  return c;
}

MyComplex& MyComplex::operator/(const MyComplex& d)
{
  MyComplex c;
  c.re = (re * d.re + im * d.im) / (d.re * d.re + d.im * d.im);
  c.im = (im * d.re - re * d.im) / (d.re * d.re + d.im * d.im);
  return c;
}

MyComplex pow(MyComplex a, int n)
{
  MyComplex c;
  c.set_re(pow(a.abs(a), n) * cos(n * atan(a.get_im() / a.get_re())));
  c.set_re(pow(a.abs(a), n) * sin(n * atan(a.get_im() / a.get_re())));
  return c;
}

ostream& operator<<(ostream& o, MyComplex b)
{
  o << b.re << "+" << b.im << "i";
  return o;
}


istream& operator>>(istream& o, MyComplex& b)
{
  o >> b.re >> b.im;
  return o;
}

/*
bool operator==(const MyComplex a,const MyComplex b)
{
  return (a.re==b.re && a.im==b.im)
}
*/

void main()
{
  MyComplex c,f;
  cin >> c;
  cin >> f;
  cout << pow(c, 4) << endl;
  cout << f * f;
}