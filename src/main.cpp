
using namespace std;
#include <cstring>
#include <iostream>
#include <unistd.h>
#include "zxcvbn/zxcvbn.h"
int main(){
	char input[]="";
	bool cond = true;
	char *fuera;
	while(cond){
		cout << "Introduce la contraseña: ";
		cin >> input;
		//cout <<" Salgo";
		double entropy = ZxcvbnMatch(input, nullptr, nullptr);
        sleep(1);
		cout << "Nivel de entropia = " << entropy << endl;
        sleep(1);
		if(entropy<0){
			cout << "El nivel de la contraseña es muy insegura" << endl;
		}
		else if(entropy>100){
			cout << "El nivel de la contraseña es muy segura" << endl;
		}
		else if(entropy>65){
			cout << "El nivel de la contraseña es segura"<< endl;
		}
		else if(entropy>40){
			cout << "El nivel de la contraseña es de seguridad media" << endl;
		}
		else{
			cout << "El nivel de la contraseña es insegura" << endl;
		}
        string input2 = input;
        int contar = input2.length();
        sleep(1);
        cout << "Tamaño de la contraseña = " << contar << endl;
        sleep(1);
        while(1){
            cout << "¿Quieres seguir probando con nuevas contraseñas(Y/N)?: ";
		    cin >> input;
		    if(strcmp(input, "n")==0){
			    cond = false;
                break;
		    }
            else if(strcmp(input,"y")==0){
                cout << endl;
                break;
            }
            else{
                cout << "ERROR: Introduzca un valor correcto" << endl;
            }
        }
		
	}
	return 0;
	}
