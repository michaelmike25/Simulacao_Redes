/*

Autor: Michael Douglas C A
O programa foi testado com os seguintes dados:
a=61->0011000001
b=62->0011000010
c=63->0011000011
d=64->0011000100
e=65->0011000101

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;


void vetresult_vetvaium(int vet_resultado[10],int vet_vaium[10], int auxiliar){ // Caso Overflow

    int i;

    for(i=9; i>=0; i--){
        if(vet_resultado[i] == 0 && vet_vaium[i] == 0 && auxiliar == 0){    // caso bit a mais na resultante da direita para a esquerda
            vet_resultado[i]=0;
            auxiliar = 0;
        } else if(vet_resultado[i] == 0 && vet_vaium[i] == 0 && auxiliar == 1){
            vet_resultado[i]=1;
            auxiliar = 0;
        } else if(vet_resultado[i] == 1 && vet_vaium[i] == 1 && auxiliar == 0){
            vet_resultado[i]=0;
            auxiliar = 1;
        } else if(vet_resultado[i] == 1 && vet_vaium[i] == 1 && auxiliar == 1){
            vet_resultado[i]=1;
            auxiliar = 1;
        } else if(vet_resultado[i] == 1 && vet_vaium[i] == 0 && auxiliar == 0){
            vet_resultado[i]=1;
            auxiliar = 0;
        } else if(vet_resultado[i] == 0 && vet_vaium[i] == 1 && auxiliar == 0){
            vet_resultado[i]=1;
            auxiliar = 0;
        } else if(vet_resultado[i] == 1 && vet_vaium[i] == 0 && auxiliar == 1){
            vet_resultado[i]=0;
            auxiliar = 1;
        } else if (vet_resultado[i] == 0 && vet_vaium[i] == 1 && auxiliar == 1){
            vet_resultado[i]=0;
            auxiliar = 1;
        }
        if(auxiliar==0){
            break;
        }
    }
}

void seqnum (int mat_dados[4][10]){ // sequencia de dado enviado
        int i;

    printf("Alice_Output..."); // Alice tem uma msg paraenviar
    printf("----------------TX--------------------");
    printf("\ndado1 Enviado:");
            for(i=0;i<10;i++){
                        printf("%d ",mat_dados[0][i]);
                    }

            printf("\ndado2 Enviado:");
            for(i=0;i<10;i++){
                        printf("%d ",mat_dados[1][i]);
                    }

            printf("\ndado3 Enviado:");
            for(i=0;i<10;i++){
                        printf("%d ",mat_dados[2][i]);
                    }

            printf("\ndado4 Enviado:");
            for(i=0;i<10;i++){
                        printf("%d ",mat_dados[3][i]);
                    }

            printf("\ndado5 Enviado:");
            for(i=0;i<10;i++){
                        printf("%d ",mat_dados[4][i]);
                    }

}

void ack(int ack_confirma){ //ACK

printf("\nAlice_Input..."); // sistema de Bob manda para Alice
    if (ack_confirma == 1){
        printf("\npacote enviado com sucesso\n");
    }else{
        printf("\npacote nao enviado\n ");
    }
}

void zeramatriz(int mat_dados[4][10]){ // zerar dados para reenvio
        int i;

        for(i=0;i<9;i++){
            mat_dados[0][i]=0;
            mat_dados[1][i]=0;
            mat_dados[2][i]=0;
            mat_dados[3][i]=0;
            mat_dados[4][i]=0;
        }
}

void Alice_Init(int mat_dados[4][10]){ // rotina chamada antes de qqr outra - preenche a matriz dados

     printf("informe o valor binario de um dado de 5byte com 10bits..\n");

            printf("\nDigite o primeiro dado enviado, com um espaco entre os bits: \n");// declaração das palavras
            scanf("%d%d%d%d%d%d%d%d%d%d", &mat_dados[0][0],&mat_dados[0][1],&mat_dados[0][2],&mat_dados[0][3],&mat_dados[0][4],&mat_dados[0][5],&mat_dados[0][6],&mat_dados[0][7],&mat_dados[0][8],&mat_dados[0][9]);

            printf("\nDigite o segundo dado enviado, com um espaco entre os bits: \n");
            scanf("%d%d%d%d%d%d%d%d%d%d", &mat_dados[1][0],&mat_dados[1][1],&mat_dados[1][2],&mat_dados[1][3],&mat_dados[1][4],&mat_dados[1][5],&mat_dados[1][6],&mat_dados[1][7],&mat_dados[1][8],&mat_dados[1][9]);

            printf("\nDigite o terceiro dado enviado, com um espaco entre os bits: \n");
            scanf("%d%d%d%d%d%d%d%d%d%d", &mat_dados[2][0],&mat_dados[2][1],&mat_dados[2][2],&mat_dados[2][3],&mat_dados[2][4],&mat_dados[2][5],&mat_dados[2][6],&mat_dados[2][7],&mat_dados[2][8],&mat_dados[2][9]);

            printf("\nDigite o quarto dado enviado, com um espaco entre os bits: \n");
            scanf("%d%d%d%d%d%d%d%d%d%d", &mat_dados[3][0],&mat_dados[3][1],&mat_dados[3][2],&mat_dados[3][3],&mat_dados[3][4],&mat_dados[3][5],&mat_dados[3][6],&mat_dados[3][7],&mat_dados[3][8],&mat_dados[3][9]);

            printf("\nDigite o quinto dado enviado, com um espaco entre os bits: \n");
            scanf("%d%d%d%d%d%d%d%d%d%d", &mat_dados[4][0],&mat_dados[4][1],&mat_dados[4][2],&mat_dados[4][3],&mat_dados[4][4],&mat_dados[4][5],&mat_dados[4][6],&mat_dados[4][7],&mat_dados[4][8],&mat_dados[4][9]);

            system("cls");
}

void somadado(int mat_dados[4][10], int vai_um, int vet_resultado[10], int vet_EDC[10],int vet_vaium[10],int aux){ // somado CheckSum
    int i;
    for(i=9; i>=0; i--){
                    if(mat_dados[0][i] == 0 && mat_dados[1][i] == 0 && vai_um == 0){  // soma bit a bit da direita para a esquerda d1ed2
                        vet_resultado[i]=0;
                        vai_um = 0;
                    } else if(mat_dados[0][i] == 0 && mat_dados[1][i] == 0 && vai_um == 1){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if(mat_dados[0][i] == 1 && mat_dados[1][i] == 1 && vai_um == 0){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    } else if(mat_dados[0][i] == 1 && mat_dados[1][i] == 1 &&vai_um == 1){
                        vet_resultado[i]=1;
                        vai_um = 1;
                    } else if(mat_dados[0][i] == 1 && mat_dados[1][i] == 0 &&vai_um == 0){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if(mat_dados[0][i] == 0 && mat_dados[1][i] == 1 && vai_um == 0){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if(mat_dados[0][i] == 1 && mat_dados[1][i] == 0 && vai_um == 1){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    } else if (mat_dados[0][i] == 0 && mat_dados[1][i] == 1 && vai_um == 1){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    }

                }

                if(vai_um == 1){ // caso a soma do d1ed2 tenha o bit a mais (vai um)

                    vetresult_vetvaium(vet_resultado,vet_vaium,aux);
                }

            {
                vai_um = 0;
                aux = 0;

                for(i=9; i>=0; i--){
                    if(vet_resultado[i] == 0 && mat_dados[2][i] == 0 && vai_um == 0){ // d1d2ed3
                        vet_resultado[i]=0;
                        vai_um = 0;
                    } else if(vet_resultado[i] == 0 && mat_dados[2][i] == 0 && vai_um == 1){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if(vet_resultado[i] == 1 && mat_dados[2][i] == 1 && vai_um == 0){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    } else if(vet_resultado[i] == 1 && mat_dados[2][i] == 1 && vai_um == 1){
                        vet_resultado[i]=1;
                        vai_um = 1;
                    } else if(vet_resultado[i] == 1 && mat_dados[2][i] == 0 && vai_um == 0){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if (vet_resultado[i] == 0 && mat_dados[2][i] == 1 && vai_um == 0){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if(vet_resultado[i] == 1 && mat_dados[2][i] == 0 && vai_um == 1){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    } else if (vet_resultado[i] == 0 && mat_dados[2][i] == 1 && vai_um == 1){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    }
                }

                if(vai_um == 1){ // caso a soma do d1d2ed3 tenha o bit a mais (vai um)

                    vetresult_vetvaium(vet_resultado,vet_vaium,aux);
                }

            }

            {
                vai_um = 0;
                aux = 0;

                for(i=9; i>=0; i--){
                    if(vet_resultado[i] == 0 && mat_dados[3][i] == 0 && vai_um == 0){ // d1d2d3ed4
                        vet_resultado[i]=0;
                        vai_um = 0;
                    } else if(vet_resultado[i] == 0 && mat_dados[3][i] == 0 && vai_um == 1){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if(vet_resultado[i] == 1 && mat_dados[3][i] == 1 && vai_um == 0){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    } else if(vet_resultado[i] == 1 && mat_dados[3][i] == 1 && vai_um == 1){
                        vet_resultado[i]=1;
                        vai_um = 1;
                    } else if(vet_resultado[i] == 1 && mat_dados[3][i] == 0 && vai_um == 0){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if (vet_resultado[i] == 0 && mat_dados[3][i] == 1 && vai_um == 0){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if(vet_resultado[i] == 1 && mat_dados[3][i] == 0 && vai_um == 1){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    } else if (vet_resultado[i] == 0 && mat_dados[3][i] == 1 && vai_um == 1){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    }
                }

                if(vai_um == 1){ // caso a soma do d1d2d3ed4 tenha o bit a mais (vai um)

                    vetresult_vetvaium(vet_resultado,vet_vaium,aux);
                }
            }

            {
                vai_um = 0;
                aux = 0;

                for(i=9; i>=0; i--){
                    if(vet_resultado[i] == 0 && mat_dados[4][i] == 0 && vai_um == 0){ //d1d2d3d4+d5
                        vet_resultado[i]=0;
                        vai_um = 0;
                    } else if(vet_resultado[i] == 0 && mat_dados[4][i] == 0 && vai_um == 1){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if(vet_resultado[i] == 1 && mat_dados[4][i] == 1 && vai_um == 0){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    } else if(vet_resultado[i] == 1 && mat_dados[4][i] == 1 && vai_um == 1){
                        vet_resultado[i]=1;
                        vai_um = 1;
                    } else if(vet_resultado[i] == 1 && mat_dados[4][i] == 0 && vai_um == 0){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if (vet_resultado[i] == 0 && mat_dados[4][i] == 1 && vai_um == 0){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if(vet_resultado[i] == 1 && mat_dados[4][i] == 0 && vai_um == 1){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    } else if (vet_resultado[i] == 0 && mat_dados[4][i] == 1 && vai_um == 1){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    }
                }

                if(vai_um == 1){ // caso a soma do d1d2d3ed4ed5 tenha o bit a mais (vai um)

                    vetresult_vetvaium(vet_resultado,vet_vaium,aux);
                }
            }
             //   --------------------------EDC-------------------------
            { //complemento de 2 ou inversão da mensagem enviada
                for(i=0; i<10; i++){
                    vet_EDC[i]=!vet_resultado[i];
                }
            }
}

int main(){


        int mat_dados[4][10]={0},i ,vet_resultado[10]={0}, vai_um=0, vet_vaium[10]={0,0,0,0,0,0,0,0,0,1}, aux=0, vet_EDC[10]={0}, ack_confirma=0, erro;
    do{
       do{  Alice_Init(mat_dados);
            seqnum(mat_dados);

                    printf("\n\n");

        somadado(mat_dados,vai_um,vet_resultado,vet_EDC,vet_vaium,aux); // soma binaria / checksum


        printf("---------------------RX--------------------------\n");

        printf("Rx -> flag para -> Tx confirmando recebimento de dados");
        printf("informe ack 0/1: ");
        scanf("%d",&ack_confirma);

        if (ack_confirma ==0){
            ack(ack_confirma);
            zeramatriz(mat_dados);
        }
        }while(ack_confirma == 0);

          printf("\ndado1 recebido->");
            for(i=0;i<10;i++){
                        printf("%d ",mat_dados[0][i]);
                    }

            printf("\ndado2 recebido->");
            for(i=0;i<10;i++){
                        printf("%d ",mat_dados[1][i]);
                    }

            printf("\ndado3 recebido->");
            for(i=0;i<10;i++){
                        printf("%d ",mat_dados[2][i]);
                    }

            printf("\ndado4 recebido->");
            for(i=0;i<10;i++){
                        printf("%d ",mat_dados[3][i]);
                    }

            printf("\ndado5 recebido->");
            for(i=0;i<10;i++){
                   // mat_dados[4][5] = 1; //caso injeção de erro
                        printf("%d ",mat_dados[4][i]);
            }



    printf("\n--------------------EDC GERADO---------------------------");

            printf("\nEDC:"); // printa EDC na tela
            for(i=0;i<10;i++){
               printf("%d ",vet_EDC[i]);
            }

            {
                vai_um = 0;
                aux = 0;

                    // Injeção de erro no dado
                   // vet_resultado[5] = 1;

                for(i=9; i>=0; i--){        //Rx = Soma do dado resultante com EDC para confirmar dados recebidos
                    if(vet_resultado[i] == 0 && vet_EDC[i] == 0 && vai_um == 0){
                        vet_resultado[i]=0;
                        vai_um = 0;
                    } else if(vet_resultado[i] == 0 && vet_EDC[i] == 0 && vai_um == 1){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if(vet_resultado[i] == 1 && vet_EDC[i] == 1 && vai_um == 0){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    } else if(vet_resultado[i] == 1 && vet_EDC[i] == 1 && vai_um == 1){
                        vet_resultado[i]=1;
                        vai_um = 1;
                    } else if(vet_resultado[i] == 1 && vet_EDC[i] == 0 && vai_um == 0){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if (vet_resultado[i] == 0 && vet_EDC[i] == 1 && vai_um == 0){
                        vet_resultado[i]=1;
                        vai_um = 0;
                    } else if(vet_resultado[i] == 1 && vet_EDC[i] == 0 && vai_um == 1){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    } else if (vet_resultado[i] == 0 && vet_EDC[i] == 1 && vai_um == 1){
                        vet_resultado[i]=0;
                        vai_um = 1;
                    }
                }

                if(vai_um == 1){ // caso resultado tenha overflow

                    vetresult_vetvaium(vet_resultado,vet_vaium,aux);
                }
            }

printf("\n-----------------------------------------------");
       erro=0; // para confirmação da existencia de erro caso a mensagem esteja zerada ou nao .

            printf("\n\nVERIFICANDO ERRO DE DADOS...\n");
            for(i=0; i<10; i++){
                printf("%d ", vet_resultado[i]);
                if(vet_resultado[i]==0){
                    erro=1;
                }
            }

            if(erro == 1){ // empressão da mensagem de erro

                printf("\n\nPACOTE CONTEM ERRO\n\n");
                printf("envie novamente...");
            } else {

                printf("\n\nPACOTE NAO CONTEM ERRO\n\n");
            }
            }while(erro==1);

    return 0;
}


//0 0 1 1 0 0 0 0 0 1
