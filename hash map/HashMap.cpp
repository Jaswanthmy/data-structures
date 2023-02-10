#include <iostream>
#include <unordered_map>
#include <utility>
using namespace std;
//Map(BST) and Unordered Map(Hash Table)
int main()
{
    system("clear");
    pair<string, int> P[2];// pairs 
    P[0]=make_pair("hi",1);
    P[1]=make_pair("hello",2);
    cout<<P[0].first<<endl;
    P[0].swap(P[1]);
    cout<<P[0].first<<endl;

    unordered_map<string, int> mymap;// unordered map(stores key values in form of pair)
    mymap.insert(P[0]);// 1st method 
    mymap["def"]=3;// 2nd method
    // 2nd method is more useful no need to use pairs
    cout<<mymap["def"]<<endl;// Access the value(if key not present pushes key with value 0 into map and gives 0)
    cout<<mymap.at("def")<<endl;//Gives error if key not present


    // Check if key present in map or not
    cout<<mymap.count("hi")<<endl;
    // update key
    mymap["hello"]=4;
    mymap["cgi"]=10;
    cout<<mymap.count("hello")<<endl;
    cout<<mymap.count("def")<<endl;
    cout<<mymap["hello"]<<endl;
    cout<<mymap["cgi"]<<endl;
    cout<<mymap.size()<<endl;
    
    //Erase one key
    mymap.erase("cgi");
    cout<<mymap.count("hello")<<endl;
    cout<<mymap.count("def")<<endl;
    cout<<mymap["hello"]<<endl;
    cout<<mymap["cgi"]<<endl;
    cout<<mymap.size()<<endl;

}