#include <stdio.h>
#include <stdlib.h>
#define nrbiti_la_adresa(MSK) (((~0)>>(32-MSK))<<(32-MSK))

void print_binar(unsigned int x) {
    int i;
    for (i = 7; i >= 0; i--) {
        if (( x & (1<<i)) != 0) {
            printf("1");
        } else {
            printf("0");
        }
    }
}
int main() {
    unsigned int i,m;

    scanf("%u",&m);                                          
    for (i = 1; i <= m; i++) {                             
	    printf("%u\n", i);

    unsigned int MSK_1, MSK_2, IP_1, x1, x2, x3, x4;
    unsigned char Biti_MSK_2;
        scanf("%u.%u.%u.%u",&x1,&x2,&x3,&x4);                 
        MSK_1 = (x1 << 24) + (x2 << 16) + (x3 << 8) + x4;
        scanf("%hhu",&Biti_MSK_2);                           
        MSK_2 = nrbiti_la_adresa(Biti_MSK_2);    
        scanf("%u.%u.%u.%u",&x1,&x2,&x3,&x4);                
        IP_1 = (x1 << 24) + (x2 << 16) + (x3 << 8) + x4;

        printf("-0 %u.%u.%u.%u/%hhu\n", (IP_1 >> 24), (( IP_1 << 8) >> 24),
                    ((IP_1 << 16) >> 24),  ((IP_1 << 24) >> 24), Biti_MSK_2);

        printf("-1 %u.%u.%u.%u\n", (MSK_2 >> 24), ((MSK_2 << 8) >> 24),
                                 ((MSK_2 << 16) >> 24), ((MSK_2 << 24) >> 24));

        printf("-2 %o.%o.%o.%o", (MSK_1 >> 24), ((MSK_1 << 8) >> 24),
                                 ((MSK_1 << 16) >> 24), ((MSK_1 << 24) >> 24));

        printf(" %X.%X.%X.%X\n", (MSK_1 >> 24), ((MSK_1 << 8) >> 24),
                                 ((MSK_1 << 16) >> 24), ((MSK_1 << 24) >> 24));

    unsigned int a_retea_IP_1;
        a_retea_IP_1 = IP_1 & MSK_2;
        printf("-3 %u.%u.%u.%u\n", (a_retea_IP_1 >> 24),
                                  ((a_retea_IP_1 << 8) >> 24),
                                  ((a_retea_IP_1 << 16) >> 24),
                                  ((a_retea_IP_1 << 24) >> 24));

    unsigned int a_br_IP_1;
        a_br_IP_1 = IP_1 | (~MSK_2);
        printf("-4 %u.%u.%u.%u\n", (a_br_IP_1 >> 24), ((a_br_IP_1 << 8) >> 24),
                         ((a_br_IP_1 << 16) >> 24), ((a_br_IP_1 << 24) >> 24));

    unsigned int IP_2, a_retea_IP_2;
        scanf("%u.%u.%u.%u",&x1,&x2,&x3,&x4);
        IP_2 = (x1 << 24) + (x2 << 16) + (x3 << 8) + x4;
        a_retea_IP_2 = IP_2 & MSK_2;
        if (a_retea_IP_1 == a_retea_IP_2) {
           printf("-5 DA\n");
        } else {
           printf("-5 NU\n");
        }

    int q, first_zero = -1;
    for (q = 31; q >= 0; q--) {
        if ((MSK_1 & (1 << q)) == 0) {
            first_zero=q ;
        break;
        }
    }
    for (q = first_zero; q >= 0; q--) {
        if ((MSK_1 & (1 << q)) != 0) {
            printf("-6 NU\n");
            break;
        }
    }
    if (q < 0) {
        printf("-6 DA\n");
    }


    if (q < 0) {
        printf("-7 %u.%u.%u.%u\n", (MSK_1 >> 24), ((MSK_1 << 8) >> 24),
                         ((MSK_1 << 16) >> 24), ((MSK_1 << 24) >> 24));
    } else {
        MSK_1 = MSK_1 >> (first_zero);
        MSK_1 = MSK_1 << (first_zero);
        printf("-7 %u.%u.%u.%u\n", (MSK_1 >> 24), ((MSK_1 << 8) >> 24),
                         ((MSK_1 << 16) >> 24), ((MSK_1 << 24) >> 24));
    }

        printf("-8 ");
        print_binar(IP_1 >> 24);
        printf(".");
        print_binar((IP_1 << 8) >> 24);
        printf(".");
        print_binar((IP_1 << 16) >> 24);
        printf(".");
        print_binar((IP_1 << 24) >> 24);
        printf("\n");

    unsigned int j,N, Bin_MSK_a_retea, NET, a_retea_NET;
    unsigned char Biti_MSK_a_retea;
        printf("-9");
        scanf("%u",&N);
    for(j = 0; j < N; j++) {
        scanf("%u.%u.%u.%u/%hhu",&x1,&x2,&x3,&x4,&Biti_MSK_a_retea);
        NET = (x1 << 24) + (x2 << 16) + (x3 << 8) + x4;
        Bin_MSK_a_retea = nrbiti_la_adresa(Biti_MSK_a_retea);
        a_retea_NET = NET & Bin_MSK_a_retea;
        a_retea_IP_2 = IP_2 & Bin_MSK_a_retea;
        if (a_retea_IP_2 == a_retea_NET) {
            printf(" %u", j);
        }
    }
	    printf("\n");
    }
    return 0;
}