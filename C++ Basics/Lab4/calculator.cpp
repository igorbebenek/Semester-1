#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>


using namespace std;

float a, b ,x ,y , w;
int opcja, c, d;
int main()
{
    for(;;){
        cout<<"wybierz opcje (+, -):1 "<<endl;
        cout<<"wybierz opcje (*, /, %):2 "<<endl;
        cout<<"pierw..(p):2 "<<endl;
        cout<<" pierw.. n stopnia(n):4 "<<endl;
        cout<<"oblicz miary kontów, cos(c), sin(s), tg(t):5 "<<endl;
        cout<<"potegowanie(^) i potegowanie n stopnia(n)"<<endl;
        cout<<"exit:7 "<<endl;
        cin>> opcja;
    switch (opcja)
        {
        
            case 1: 
            {
                cout<<"wybierz znak operacji aby ją wykonać"<<endl;
                char dodawanie = '+';
                cin>> dodawanie;
                cin>> a;
                cin>> b;
                if(dodawanie=='+')
                {
                     w = a + b;
                }
                if(dodawanie=='-')
                {
                    w = a - b;
                }
                 cout<< w <<" wynik";
            }break; 
            case 2: 
            {
                cout<<"wybierz znak operacji aby ją wykonać"<<endl;
                char dzialanie = '*';
                cin>> dzialanie;
            
                if(dzialanie=='*')
                {
                    cin>> a;
                    cin>> b;
                    w = a * b;
                }
                if(dzialanie=='/')
                {
                    cin>> a;
                    cin>> b;
                    if(b==0)
                        {
                        cout<<"error";
                        }
                    else{
                        w = a / b;
                    } 
                }
                if(dzialanie=='%')
                {
                    cin>> c;
                    cin>> d;
                    w = c % d;
                }
                cout<< w <<" wynik";
            
            }break;
            case 3: 
            {
                    cout <<"podaj wartość piewiastka ";
                    cin>>a;
                    x=sqrt(a);
                    cout<< x<< " wynik";
            }break;
            case 4:{    
                    cout<<"podaj wartość pierwiastka ";
                    cin>> a;
                    cout<<"podaj jego stopień ";
                    cin>> b;
                    y = pow(a, 1 / b);
                    cout<< y<< " wynik";
            }break;
            case 5:{
                char k;
                cin>>k;
                if(k=='s'){
                    cout<< "podaj wartość kąta ";
                    cin >> a;
                    x = sin(a * M_PI / 180);
                    cout<< x<< " wynik";
                }
                if(k=='c'){
                    cout<< "podaj wartość kąta ";
                    cin >> a;
                    x = cos(a * M_PI / 180);
                    cout << x<< " wynik";
                }
                if(k=='t'){
                    cout<< "podaj wartość kąta ";
                    cin >> a;
                    x = tan(a * M_PI / 180);
                    cout << x<< " wynik";
                }
            
            }break; 
            case 6:{
                char p;
                cout<<"podaj rodzaj potęgowania ";
                cin>> p;
                if(p=='^'){
                    cout<<"podaj wartosc a ";
                    cin>> c;
                    w=pow(c,2);
                    cout<< w<<" wynik";
                }
                if(p=='n'){
                    cout<<"podaj wartosc a ";
                    cin>> c;
                    cout<<"podaj stopien potengi ";
                    cin>> d;
                    w=pow(c,d);
                    cout<< w<<" wynik";
                }break;
            }
        
            case 7:{
                exit(0);
            }break;
            default:{ cout<< "nie ma takiej opcji";}
        }getchar();getchar();
    system("cls");
    
    }
} 