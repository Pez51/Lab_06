#include <iostream> //Sobrecarga de operadores
#include <string>
#include <vector>

using namespace std;

        

class SumYRes{
    public:
        struct Vectores2d{
            int x;
            int y;
        };

        vector <Vectores2d> listaxy;
        static int contaObje;

        SumYRes(int x, int y){
            Vectores2d Vec;
            Vec.x = x;
            Vec.y = y;
            listaxy.push_back(Vec);
        };

        void AddElement(int A, int B){
            Vectores2d Vect;
            Vect.x = A;
            Vect.y = B;
            listaxy.push_back(Vect);
        }
};

SumYRes operator + (const SumYRes &p1,const SumYRes &p2){
    SumYRes New(p1.listaxy[0].x + p2.listaxy[0].x, p1.listaxy[0].y + p2.listaxy[0].y);
    for (int i = 1; i < p1.listaxy.size(); i++){
        New.AddElement(p1.listaxy[i].x + p2.listaxy[i].x, p1.listaxy[i].y + p2.listaxy[i].y);
    }
    return New;
}

SumYRes operator - (const SumYRes &p1,const SumYRes &p2){
    SumYRes New(p1.listaxy[0].x - p2.listaxy[0].x, p1.listaxy[0].y - p2.listaxy[0].y);
    for (int i = 1; i < p1.listaxy.size(); i++){
        New.AddElement(p1.listaxy[i].x - p2.listaxy[i].x, p1.listaxy[i].y - p2.listaxy[i].y);
    }
    return New;
}

ostream & operator << (ostream &o,const SumYRes &p3){
    o << "[";
    for (int i = 0; i < p3.listaxy.size(); i++){
        o << "[" << p3.listaxy[i].x <<", "<<p3.listaxy[i].y<< "]";
        if (i !=  p3.listaxy.size() - 1){
            o << ", ";
        }
    }
    o << "]";
    return o;
}


int main(){
    SumYRes A(50,75);
    A.AddElement(30,777);
    A.AddElement(10,10);
    A.AddElement(73,80);
    SumYRes B(150,175);
    B.AddElement(10,15);
    B.AddElement(10,10);
    B.AddElement(30,25);
    SumYRes C = A + B;
    cout<<"\nVectores de suma: "<<endl;
    cout << A<<endl;
    cout << B<<endl;
    cout << C<<endl;
    SumYRes D = A - B;
    cout<<"\nVectores de resta: "<<endl;
    cout << A<<endl;
    cout << B<<endl;
    cout << D<<endl;

    return 0;
}