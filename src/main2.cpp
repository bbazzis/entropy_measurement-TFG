using namespace std;
#include <cstring>
#include <iostream>
#include <unistd.h>
#include "zxcvbn2/zxcvbn.h"
const char *UsrDict[] =
{
    "Onename.Twoname@example.com", "Onename", "Twoname", "example.com", "example",
    0
};
// void calcPass(const char *Pwd){
//     double e;
//         /* Output the details of how the entropy figure was calculated */
//         int Len, ChkLen;
//         struct timeval t1, t2;
//         ZxcMatch_t *Info, *p;
//         double m = 0.0;

//         //gettimeofday(&t1, 0);
//         e = ZxcvbnMatch(Pwd, UsrDict, &Info);
//         //gettimeofday(&t2, 0);
//         for(p = Info; p; p = p->Next)
//             m += p->Entrpy;

//         Len = strlen(Pwd);
//         m = e - m;
//         printf("Pass %s \tLength %d\tEntropy bits=%.3f log10=%.3f\tMulti-word extra bits=%.1f\n", Pwd, Len, e, e * 0.301029996, m);
//         p = Info;
//         ChkLen = 0;
//         while(p)
//         {
//             int n;
//             switch((int)p->Type)
//             {
//                 case BRUTE_MATCH:                     printf("  Type: Bruteforce     ");   break;
//                 case DICTIONARY_MATCH:                printf("  Type: Dictionary     ");   break;
//                 case DICT_LEET_MATCH:                 printf("  Type: Dict+Leet      ");   break;
//                 case USER_MATCH:                      printf("  Type: User Words     ");   break;
//                 case USER_LEET_MATCH:                 printf("  Type: User+Leet      ");   break;
//                 case REPEATS_MATCH:                   printf("  Type: Repeated       ");   break;
//                 case SEQUENCE_MATCH:                  printf("  Type: Sequence       ");   break;
//                 case SPATIAL_MATCH:                   printf("  Type: Spatial        ");   break;
//                 case DATE_MATCH:                      printf("  Type: Date           ");   break;
//                 case BRUTE_MATCH+MULTIPLE_MATCH:      printf("  Type: Bruteforce(Rep)");   break;
//                 case DICTIONARY_MATCH+MULTIPLE_MATCH: printf("  Type: Dictionary(Rep)");   break;
//                 case DICT_LEET_MATCH+MULTIPLE_MATCH:  printf("  Type: Dict+Leet(Rep) ");   break;
//                 case USER_MATCH+MULTIPLE_MATCH:       printf("  Type: User Words(Rep)");   break;
//                 case USER_LEET_MATCH+MULTIPLE_MATCH:  printf("  Type: User+Leet(Rep) ");   break;
//                 case REPEATS_MATCH+MULTIPLE_MATCH:    printf("  Type: Repeated(Rep)  ");   break;
//                 case SEQUENCE_MATCH+MULTIPLE_MATCH:   printf("  Type: Sequence(Rep)  ");   break;
//                 case SPATIAL_MATCH+MULTIPLE_MATCH:    printf("  Type: Spatial(Rep)   ");   break;
//                 case DATE_MATCH+MULTIPLE_MATCH:       printf("  Type: Date(Rep)      ");   break;

//                 default:                printf("  Type: Unknown%d ", p->Type);   break;
//             }
//             ChkLen += p->Length;
//             printf("  Length %d  Entropy %6.3f (%.2f) ", p->Length, p->Entrpy, p->Entrpy * 0.301029996);
//             for(n = 0; n < p->Length; ++n, ++Pwd)
//                 printf("%c", *Pwd);
//             printf("\n");
//             p = p->Next;
//         }
//         ZxcvbnFreeInfo(Info);
//         t2.tv_sec -= t1.tv_sec;
//         t2.tv_usec -= t1.tv_usec;
//         t2.tv_usec += t2.tv_sec * 1000000;
//         printf("    Calculation Time %.2fms\n", t2.tv_usec/1000.0);
//         if (ChkLen != Len)
//             printf("*** Password length (%d) != sum of length of parts (%d) ***\n", Len, ChkLen);
    
// }
int main(){
	char input[]="";
	bool cond = true;
	char *fuera;
	while(cond){
		cout << "Introduce la contraseña: ";
		cin >> input;
		//cout <<" Salgo";
		//ouble entropy = ZxcvbnMatch(input, nullptr, nullptr);
        //calcPass(input);
        char *Pwd = input;
		double e;
        /* Output the details of how the entropy figure was calculated */
        int Len, ChkLen;
        struct timeval t1, t2;
        ZxcMatch_t *Info, *p;
        double m = 0.0;

        //gettimeofday(&t1, 0);
        e = ZxcvbnMatch(Pwd, UsrDict, &Info);
        //gettimeofday(&t2, 0);
        for(p = Info; p; p = p->Next)
            m += p->Entrpy;

        Len = strlen(Pwd);
        m = e - m;
        printf("Pass %s \tLength %d\tEntropy bits=%.3f log10=%.3f\tMulti-word extra bits=%.1f\n", Pwd, Len, e, e * 0.301029996, m);
        p = Info;
        ChkLen = 0;
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
            printf("  Length %d  Entropy %6.3f (%.2f) ", p->Length, p->Entrpy, p->Entrpy * 0.301029996);
            for(n = 0; n < p->Length; ++n, ++Pwd)
                printf("%c", *Pwd);
            printf("\n");
            p = p->Next;
        }
        ZxcvbnFreeInfo(Info);
        t2.tv_sec -= t1.tv_sec;
        t2.tv_usec -= t1.tv_usec;
        t2.tv_usec += t2.tv_sec * 1000000;
        printf("    Calculation Time %.2fms\n", t2.tv_usec/1000.0);
        if (ChkLen != Len)
            printf("*** Password length (%d) != sum of length of parts (%d) ***\n", Len, ChkLen);
    
	}
	return 0;
	}