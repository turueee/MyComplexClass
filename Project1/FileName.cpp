#include <iostream>

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
  //Сравнение
  friend bool operator==(const MyComplex a,const MyComplex b);
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

bool operator==(const MyComplex a,const MyComplex b)
{
  return (a.re==b.re && a.im==b.im)
}

void main()
{
  MyComplex c,f;
  cin >> c;
  cin >> f;
  cout << c==f;
}