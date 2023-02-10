#include <iostream>
#include<string>
using namespace std;


template <typename T, typename V> 
class Pair{

    T x;
    V y;
    public : 
        void setData(T x,V y)
        {
            this->x=x;
            this->y=y;
        }
        T getDataX()
        {
            return x;
        }
        V  getDataY()
        {
            return y;
        }


};
int main()
{
    system("clear");
    Pair <Pair<int,int>, int>p;
    Pair <int,int>temp;
    temp.setData(5,6);
    p.setData(temp,7);
    cout<<p.getDataX().getDataX()<<" "<<p.getDataX().getDataY()<<" "<<p.getDataY()<<endl;
}