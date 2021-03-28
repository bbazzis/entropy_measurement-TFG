using namespace std;
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include "zxcvbn2/zxcvbn.h"
const char *UsrDict[] =
{
    "Onename.Twoname@example.com", "Onename", "Twoname", "example.com", "example",
    0
};
void calcPass(const char *Pwd){
    double e;
        /* Output the details of how the entropy figure was calculated */
        int Len, ChkLen;
        struct timeval t1, t2;
        ZxcMatch_t *Info, *p;
        double m = 0.0;

        gettimeofday(&t1, 0);
        e = ZxcvbnMatch(Pwd, UsrDict, &Info);
        gettimeofday(&t2, 0);
        for(p = Info; p; p = p->Next)
            m += p->Entrpy;

        Len = strlen(Pwd);
        m = e - m;

        //IMPRIMIR INFORMACION SOBRE LA CONTRASEÑA INTRODUCIDA
        printf("Contraseña introducida: %s\n", Pwd);
        sleep(1);
        printf("Tamaño de la contraseña: %d\n", Len);
        sleep(1);
        printf("Nivel de entropia en bits: %.3f\n", e);
        sleep(1);
        printf("Nivel de entropia log10: %.3f\n", e * 0.301029996);
        sleep(1);
        //INFORMACION SOBRE NIVELES 
        if(e<0){
			printf("El nivel de la contraseña es muy insegura\n");
		}
		else if(e>100){
			printf("El nivel de la contraseña es muy segura\n");
		}
		else if(e>65){
			printf("El nivel de la contraseña es segura");
		}
		else if(e>40){
			printf("El nivel de la contraseña es de seguridad media");
		}
		else{
			printf("El nivel de la contraseña es insegura");
		}
        sleep(1);
        p = Info;
        ChkLen = 0;
        //INFORMACION SOBRE TIPO DE VULNERABILIDAD FRENTE A X ATAQUE
        while(p)
        {
            int n;
            switch((int)p->Type)
            {
                case BRUTE_MATCH:                     printf("  Type: Bruteforce     ");   break;
                case DICTIONARY_MATCH:                printf("  Type: Dictionary     ");   break;
                case DICT_LEET_MATCH:                 printf("  Type: Dict+Leet      ");   break;
                case USER_MATCH:                      printf("  Type: User Words     ");   break;
                case USER_LEET_MATCH:                 printf("  Type: User+Leet      ");   break;
                case REPEATS_MATCH:                   printf("  Type: Repeated       ");   break;
                case SEQUENCE_MATCH:                  printf("  Type: Sequence       ");   break;
                case SPATIAL_MATCH:                   printf("  Type: Spatial        ");   break;
                case DATE_MATCH:                      printf("  Type: Date           ");   break;
                case BRUTE_MATCH+MULTIPLE_MATCH:      printf("  Type: Bruteforce(Rep)");   break;
                case DICTIONARY_MATCH+MULTIPLE_MATCH: printf("  Type: Dictionary(Rep)");   break;
                case DICT_LEET_MATCH+MULTIPLE_MATCH:  printf("  Type: Dict+Leet(Rep) ");   break;
                case USER_MATCH+MULTIPLE_MATCH:       printf("  Type: User Words(Rep)");   break;
                case USER_LEET_MATCH+MULTIPLE_MATCH:  printf("  Type: User+Leet(Rep) ");   break;
                case REPEATS_MATCH+MULTIPLE_MATCH:    printf("  Type: Repeated(Rep)  ");   break;
                case SEQUENCE_MATCH+MULTIPLE_MATCH:   printf("  Type: Sequence(Rep)  ");   break;
                case SPATIAL_MATCH+MULTIPLE_MATCH:    printf("  Type: Spatial(Rep)   ");   break;
                case DATE_MATCH+MULTIPLE_MATCH:       printf("  Type: Date(Rep)      ");   break;

                default:                printf("  Type: Unknown%d ", p->Type);   break;
            }
            ChkLen += p->Length;
            for(n = 0; n < p->Length; ++n, ++Pwd)
                printf("%c", *Pwd);
            printf("\n");
            p = p->Next;
        }
        ZxcvbnFreeInfo(Info);
        t2.tv_sec -= t1.tv_sec;
        t2.tv_usec -= t1.tv_usec;
        t2.tv_usec += t2.tv_sec * 1000000; 
        //TIEMPO MINIMO NECESARIO
        printf("    Calculation Time %.2fms\n", t2.tv_usec/1000.0);
        if (ChkLen != Len)
            printf("*** Password length (%d) != sum of length of parts (%d) ***\n", Len, ChkLen);
    
}
int main(){
	char input[]="";
	bool cond = true;
	char *fuera;
	while(cond){
		cout << "Introduce la contraseña: ";
		cin >> input;
        cout << "\n";
        calcPass(input);
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