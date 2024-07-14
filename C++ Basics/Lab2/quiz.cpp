#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int a,b,c,w,z,x,i,pkt=0,miejsce,tmp;
    string pop,odp;
    char znak;
    
    srand(time(NULL));
    
    cout<<"Wybierz dzialanie(+,-,*,/,%)\n";
    cin>>znak;
    
    switch(znak){
        case '+' : { cout<<"dodawanie\n"; break;  }
        case '-' : { cout<<"odejmowanie\n"; break; }
        case '*' : { cout<<"mnozenie\n"; break; }
        case '/' : { cout<<"dzielenie\n"; break; }
        default : cout<<"zly znak";
    }
    
    for(i=1;i<=10;i++){

        c = 0;
        
        a=rand()%19+2;
        b=rand()%19+2;
        
        switch(znak){
            case '+' : { c=a+b; break;  }
            case '-' : { c=a-b; break; }
            case '*' : { c=a*b; break; }
            case '/' : { c=a*b;  tmp = a; a = c; c = tmp;  break; }
        }
        
        w=c-3;
        z=rand()%6+w;
        while(z==c){ 
            z=rand()%6+w;
        }
        x=rand()%6+w;
        while(x==c||x==z){
            x=rand()%6+w;
        }
        miejsce=rand()%7+3;
        
        cout<<i<<". "<<a<<znak<<b<<"="<<endl;
        
        switch(miejsce){
            case 1:
                cout<<"a. "<<c<<endl;
                cout<<"b. "<<z<<endl;
                cout<<"c. "<<x<<endl;
                pop="a";
                break;
            case 2:
                cout<<"a. "<<z<<endl;
                cout<<"b. "<<c<<endl;
                cout<<"c. "<<x<<endl;
                pop="b";
                break;
            case 3:
                cout<<"a. "<<x<<endl;
                cout<<"b. "<<z<<endl;
                cout<<"c. "<<c<<endl;
                pop="c";
        }
        
        cout<<"wpisz odpowiedz: ";
        cin>>odp;
        if(odp==pop){
            pkt++;
            cout<<endl;
            cout << endl << "OK" << endl;
        }
        
        
    }
    
    cout<<"liczba pkt: "<<pkt;

    return 0;
}
