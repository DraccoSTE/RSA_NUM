#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <NTL/ZZ.h>


using namespace std;
using namespace NTL;

ZZ modulo(ZZ a, ZZ b){
    ZZ r;
    r = a - b * (a / b);
    r = r + (r < 0) * b;
    return r;
    }
	//algoritmo base
	ZZ Euclides(ZZ x,ZZ y){
    	ZZ aux=x-((x/y*y));
    	while (aux!= 0){
       		x=y;
       		y=aux;
       		aux= x-((x/y)*y);
    	}
    	return y;
	}
	//algoritmo extendido
	vector<ZZ> extMcd(ZZ a, ZZ b){
    vector<ZZ> temp;
    ZZ q = a / b;
    ZZ res = a - (q * b);

    ZZ s1;
    s1 = 1;
    ZZ s2;
    s2 = 0;
    ZZ s = s1 - (q * s2);

    ZZ t1;
    t1 = 0;
    ZZ t2;
    t2 = 1;
    ZZ t = t1 - (q * t2);

    while (res > 0)
    {
        a = b;
        b = res;
        q = a / b;
        res = a - (q * b);

        s1 = s2;
        s2 = s;
        s = s1 - (q * s2);

        t1 = t2;
        t2 = t;
        t = t1 - (q * t2);

    }
    temp.push_back(b);
    temp.push_back(s2);
    temp.push_back(t2);

    return temp;
    }
    ZZ inverse (ZZ a, ZZ b)
    {
        if (Euclides(a, b) == 1) {
            return extMcd(a, b).at(1);
        }
        else
            return ZZ();
    }
    main(){
        ZZ e1 = conv<ZZ>("7");
        ZZ e2 = conv<ZZ>("11");
        ZZ n = conv<ZZ>("35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516111204504060317568667");
        ZZ c1 = conv<ZZ>("35794234179725868774991807832568455403003778024228226193532908190484670252364677411513516052471686245831933544");
        ZZ c2 = conv<ZZ>("35794234179725868774991807832568455403003778024228226193532908190484670252364665786748759822531352444533388184");
        if(Euclides(e1, e2)==1){
            cout<<"ambas claves son coprimos"<<endl;
        }
        if(Euclides(c1, n)==1 && Euclides(c2, n)==1){
            cout<<"ambos son coprimos con n"<<endl;
        }
        vector<ZZ> ext = extMcd(e1, e2);
        ZZ cinverse = inverse(c1, n);
        cout << "inversa1: " << ext.at(1);
        cout<<endl<<"inversa2: "<<ext.at(2)<<endl;
        ZZ m = modulo(PowerMod(cinverse, (-1) * ext.at(1), n) * PowerMod(c2, ext.at(2), n), n);
        cout<< "valor de m es: " << m <<endl;
    }
