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


class Item_info{
public:
  // インターフェース
  Item_info();
  Item_info( std::istream& );
  string id() const { return ID; } ;
  string name() const { return Name; } ;
  string date() const { return Date; } ;
  string junle() const { return Genre; };
  int num() const{return Num};
  vector<string>position()const{return Position;};
  bool valid() const { return !Positon.empty(); };
  std::istream& read(std::istream&);
  

private:
  string ID;//商品番号（バーコード）
  string Name;//商品名
  string Date;//廃棄日程
  string Genre;//ジャンル
  int Num;//在庫数
  vector<string> Positon;//演習のvector
};
