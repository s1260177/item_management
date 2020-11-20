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
//  vector<string>position()const{return Position;};
  string position() const {return Position;};
  bool valid() const { return !Position.empty();};
  istream& read(istream&);


private:
  string Id;//商品番号（バーコード）
  string Name;//商品名
  string Date;//廃棄日程
  string Price;//価格
  int Num;//在庫数
  //vector<string> Position;//商品の売り場の位置のvector
  string Position;//商品の売り場の位置
};

// メンバ関数の定義
Item_info::Item_info(){}
Item_info::Item_info( istream& is) { read(is); }

/*
istream& read_position(istream& is, vector<string>v){
  if( is ) {
  string x; // 毎回の商品の売り場の位置
  v.clear();
  while( is >> x ){
  v.push_back( x );
    }
  is.clear();
}
return is;
}
*/

istream& Item_info::read(istream& is ){
  is >> Id >> Name >> Date >> Price >> Num >>Position;

  //read_position(is, Position);

  return is;
}

istream& Item_info::output(Item_info v){
  outfile<<Id<<Name<<Date<<Price<<Num<<Position;

  return v;
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
    if(menu_select==1){//1.商品情報の追加
      string judge;

      cout<<"登録したい商品情報を入力してください"<<endl;
      cout<<"ex) 00000000 item 2020/12/31 1000 10 A1" <<endl;
      while(judge!="OK"){
        record.read(cin);
        cout<<"入力内容"<<endl;//日本語にsetwは効かない。。。
        cout<<"商品番号　　　"<<record.id()<<endl<<"商品名　　　　"<<record.name()<<endl;
        cout<<"廃棄日　　　　"<<record.date()<<endl;
        cout<<"価格　　　　　"<<record.price() <<endl<<"在庫数　　　　"<<record.num()<<endl;

        cout<<"売り場の位置　"<<record.position()<<endl;


          while(judge!="OK"){
            cout<<"この内容を登録してもよろしいでしょうか？ OK or NO"<<endl;
            cin>>judge;
            if(judge=="OK"){
              items.push_back(record);
              cout<<"登録しました"<<endl;
              break;
            }
            else if(judge=="NO"){
              cout<<"もう一度入力し直してください"<<endl;
              break;
            }
            else{
              cout<<"OK or NOで答えてください ";
            }
          //}
        }
      }
    }else if(menu_select==2){

    }else if (menu_select==3){

    }else if(menu_select==4){

    }else cout<<"メニュー番号を入力してください。"<<endl;
  }

  //終了動作
  cout<<"ファイル更新中"<<endl;
  for(vector<Item_info>size_type:: i=0;i!=items.size();i++){
    record=items[i];
    record.output(record);
  }
  //outfile<<;

  cout<<"完了しました。終了します"<<endl;

  return 0;
}
