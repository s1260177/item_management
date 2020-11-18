/*
item.cc
概要：商品管理のプログラム
Author:Yuki Sakurai
Date:2020-11
*/

#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
#include<iomanip>// 書式設定を利用するときに必要
#include<map>//map
#include<list>

#include<fstream>//infile outfile

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::vector;
using std::list;
using std::istream;
using std::setw;


class Student_info{
public:
  // インターフェース
  Student_info();
  Student_info( std::istream& );
  string first_name() const { return First_name; } ;
  string last_name() const { return Last_name; } ;
  string id() const { return ID; } ;
  double midterm() const { return Midterm; };
  double final() const { return Final; };
  double ex() const { return Ex; };
  double total() const { return Total; };
  vector<double>execise()const{return Execise;};
  bool valid() const { return !Execise.empty(); };
  std::istream& read(std::istream&);
  double grade();

  string judge();

private:
  string ID;//学籍番号
  string First_name;//名
  string Last_name;//姓
  double Midterm;//中間テスト
  double Final;//期末テスト
  double Ex,Total;
  vector<double> Execise;//演習のvector
};
