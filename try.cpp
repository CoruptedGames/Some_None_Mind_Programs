#include <iostream>
#include <iomanip>
using namespace std;

void table(){
    cout<<"this is a table"<<endl;
    cout<<left<<setw(20)<<"Name "<<setw(2)<<"RN"<<endl; 
    cout<<left<<setw(20)<<"amit patel "<<setw(2)<<"45"<<endl;
    cout<<left<<setw(20)<<"srivan kumar "<<setw(2)<<"12"<<endl;
    cout<<left<<setw(20)<<"vaibhav "<<setw(2)<<"32"<<endl;
    cout<<left<<setw(20)<<"sarita "<<setw(2)<<"23"<<endl;
    

}
void persentage(){
    cout<<"Enter Mark of 3 subject out of 20"<<endl;
    float a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    int total  = a+b+c;
    cout<<"Total = "<<total<<endl;
    cout<<"Persentage :"<< (total/60)*100<<" %"<<endl;
}
void area(){
    float l,b;
    cout<<"Enter Length and breath :"<<endl;
    cin >> l >> b;
    cout<<"Area : "<<l*b<<endl;
}


int main(){

    //table();
    //persentage();
    // area();
    return 0;
}