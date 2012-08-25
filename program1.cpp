/*
Interpreter
by Ana B.
*/
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main(){
    int numCasosPrueba = 0;
    cin>>numCasosPrueba;

    string bLine;
    getline(cin,bLine);
    do{
        getline(cin,bLine);
    }while(bLine.length()>0);

    for(int casoPrueba=1; casoPrueba<=numCasosPrueba; casoPrueba++){
        int registros[10];
        int ram[1000];

        string linea;
        int iRam = 0;
        int i = 0;
        do{
            getline(cin,linea);
            iRam = atoi(linea.c_str());
            ram[i] = iRam;
            i++;
        }while(linea.length()>0);

        int total = 0;
        int locacion = 0;
        int sizeRAM = sizeof ram/sizeof(int);

        while(locacion<sizeRAM){
            total++;
            int instruccion = ram[locacion];

            if(instruccion==100){
                break;
            }

            int d1 = instruccion / 100;
            int d2 = (instruccion / 10) % 10;
            int d3 = instruccion % 10;

            locacion++;

            if(d1 == 2)
                registros[d2] = d3;
            else if(d1 == 3)
                registros[d2] = (registros[d2] + d3) % 1000;
            else if(d1 == 4)
                registros[d2] = (registros[d2] * d3) % 1000;
            else if(d1 == 5)
                registros[d2] = registros[d3];
            else if(d1 == 6)
                registros[d2] = (registros[d2] + registros[d3]) % 1000;
            else if(d1 == 7)
                registros[d2] = (registros[d2] * registros[d3]) % 1000;
            else if(d1 == 8)
                registros[d2] = ram[registros[d3]];
            else if(d1 == 9)
                ram[registros[d3]] = registros[d2];
            else if(d1 == 0 && registros[d3] != 0)
                locacion = registros[d2];


        }
            cout<<total<<endl;

    }


 return 0;
}
