#include <stdio.h>

int main(){
    int horas;
    float total = 5;
    printf("Digite o total de horas: ");
    scanf("%d",&horas);

    if(horas <= 0){
        printf("Número inválido");
        return 1;
    }else if (horas == 1){ 
      printf("Total a pagar 5 reias\n"); 
    }else if (horas > 1){
        for(int i = 1; i < horas; i++){
            total += 3;
        }
        if(horas > 10){
            total = total * 0.9;
        }    
    }

    printf("Total = %.2f", total);

    return 0;
}
