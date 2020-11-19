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

using namespace std;


class Item_info{
public:
  // インターフェース
  Item_info();
  Item_info( istream& );
  string id() const { return Id; } ;
  string name() const { return Name; } ;
  string date() const { return Date; } ;
  string price() const { return Price; };
  int num() const{return Num;};
  vector<string>position()const{return Position;};
  bool valid() const { return !Position.empty();};
  istream& read(istream&);


private:
  string Id;//商品番号（バーコード）
  string Name;//商品名
  string Date;//廃棄日程
  string Price;//価格
  int Num;//在庫数
  vector<string> Position;//商品の売り場の位置のvector
};

// メンバ関数の定義
Item_info::Item_info(){}
Item_info::Item_info( istream& is) { read(is); }


istream& Item_info::read(istream& is ){

  return is;
}

int main(int argc, char* argv[]){
  //ファイル操作
  std::ifstream infile(argv[1]);
  std::ofstream outfile(argv[2]);
  if(argc!=3){
    std::cerr<<"Error"<<endl;
    return -1;
  }

  //入力
  vector<Item_info> items;
  Item_info record;

  while(record.read(infile)){
    items.push_back(record);
  }

  //入力完了表示
  cout<<"データ入力完了"<<endl;
  //売り場注意情報表示


  //メニュー表示
  cout<<"メニューを選んでください"<<endl;
  int menu_select=0;
  while(menu_select!=4){
    cout<<"1.商品情報の追加"<<endl<<"2.商品検索"<<endl<<"3.売り場検索"<<endl<<"4.終了（データ更新)"<<endl;
    cin>>menu_select;
    if(menu_select==1){

    }else if(menu_select==2){

    }else if (menu_select==3){

    }else if(menu_select==4){

    }else cout<<"メニュー番号を入力してください。"<<endl;
  }

  //終了動作
  cout<<"ファイル更新中"<<endl;
  //outfile<<;

  cout<<"完了しました。終了します"<<endl;

  return 0;
}
