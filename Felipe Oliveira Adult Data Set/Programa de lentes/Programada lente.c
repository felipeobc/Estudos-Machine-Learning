#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Os dados são simplificados e para cada um dos 23 pacientes
há informações sobre a identificação do paciente (ID), a idade (categorizada em termos
oftalmológicos: jovem, pré-presbiópico e prebiópico), o diagnóstico oficial (míope ou
hipermetrope), a presença de astigmatismo (sim ou não), a produção lacrimal do paciente (normal
ou reduzida), e por fim, qual foi a lente prescrita (nenhuma, gelatinosa ou rígida).
*/

//
void Calcular (double Vetor[], double *Med, double *Dev){

    int i;

    *Med = 0.0;
    for(i = 0; i < 4; i++){
        printf("Digite a %d Medida: ", i + 1);
        scanf("%lf", &Medidas[i]);

         *Med += Medidas[i];
    }

   *Med = *Med / N;
   *Dev = 0.0;

   for(i = 0; i < N; i++){

        *Dev +=  pow(Medidas[i] - *Med, 2);
    }
    *Dev = sqrt(*Dev / N);

}
int Menu(){
    int R;
    volta:
    printf("Deja Fazer um Novo Calculo?\n");
    printf("(1)Sim!\n(2)Nao!\n");
    printf("Digite uma opcao: ");
    scanf("%d", &R);

    if((R != 1) && (R != 2)){
            printf("Numero incorreto !!\n");
            printf("Por Favor escolha (1) (2) ou (3)!!\n\n");
            goto volta;
        }
    return R;
}
//Calculadora: Tratamento Estático de Medidas.
int main () {

    double Jovem, PrePresbiopico, Prebiopico, Miope, Hipermetrope, R;
    int recomecar = 0;
    double Pesos[4], Media, Desvio_Padrao;
do{

    //Nuemero de Medidas
    printf("\n");
    printf("PROGRAMA PARA ESCOHA DE LENTES!!\n\n");
    printf("\n");

    volta:
    printf("Qual a sua idade\n");
    printf("(1)Jovem!\n(2)PrePresbiópico!\n(3)Presbiópico!\n");
    printf("Digite uma opcao: ");
    scanf("%d", &R);

    if((R != 1) && (R != 2) && (R != 3)){
            printf("Numero incorreto !!\n");
            printf("Por Favor escolha (1) ou (2)!!\n\n");
            goto volta;
        }
    if( R == 1){
        Pesos[0] = Jovem;
        R = 0;
    }
    if( R == 2){
        Pesos[0] = PrePresbiopico;
        R = 0;
    }
    if( R == 2){
        Pesos[0] = Presbiopico;
        R = 0;
    }

    volta1:
    printf("O Diagnóstico Oficial\n");
    printf("(1)Miope!\n(2)Hipermetrope!\n");
    printf("Digite uma opcao: ");
    scanf("%d", &R);

    if((R != 1) && (R != 2)){
            printf("Numero incorreto !!\n");
            printf("Por Favor escolha (1) ou (2)!!\n\n");
            goto volta1;
        }
    if( R == 1){
        Pesos[1] = Miope;
        R = 0;
    }
    if( R == 2){
        Pesos[1] = Hipermetrope;
        R = 0;
    }




   Calcular(*Pesos, &Media, &Desvio_Padrao);

    printf("\n");
    printf("Valor da Media = %f\n\n", Media);
    printf("\n");

    printf("Valor do Desvio Medio: %f\n", Desvio_Padrao);
    printf("Faixa de Confinca: %f +- %f\n\n", Media, Desvio_Padrao);
// Faixa Final.
    Faixa_Final = sqrt(pow(Desvio_Padrao,2) + pow(Fundo_Escala,2));
    printf("Valor a Considerar entre: %f +- %f\n\n", Media, Faixa_Final);
    free(Valor_Medidas);

    recomecar = Menu();

    } while(recomecar == 1);

    printf("Obrigado !!\n\n");

    system("pause");

}
