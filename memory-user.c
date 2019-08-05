#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[]) {
    clock_t timer = clock();

    if(argc == 1) {
    printf("ERROR!!!. Modo de uso: ./memory-user.out tam <tiempo> \n");
        }
    else if (argc == 2) {
        // Solo tamaño
        int tam = atoi(argv[1]);
        tam *= 1e6;
        //printf("Tamaño: %d\n", tam);
        int *p = malloc(tam);
    while(1) {
        for(int i = 0; i < tam/sizeof(int);i++) {
        *(p + i) = 0;
        printf("%d\n",i);
                }
            }
        }
        else {
        printf("empleando el tiempo \n");
        int tam = atoi(argv[1]);
        tam *= 1e6;
        int *p = malloc(tam);
            while ((clock() -timer)/CLOCKS_PER_SEC < atoi(argv[2])){
                    for(int i = 0; i < tam/sizeof(int);i++) {
                        *(p + i) = 0;
                        printf("%d\n",i);                       
                }
            }
        }
        return 0;
}