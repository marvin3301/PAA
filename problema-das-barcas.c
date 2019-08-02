#include<stdio.h>
#include<stdlib.h>

void main()
{

//Declaração (nem precisa fazer isso no pseudo-código -> Pseudo-código 1x0 Código)
    int i,j,k,X,Y,A,B;
    int M[6][31][31];
    int Z[6][31][31];
    int C[5];

//Não tem como enfeitar no pseudo-código -> Pseudo-código 2x0

    printf("\n----------------------------------------\n");
    printf("\n------- O problema das balsas ----------\n");
    printf("\n----------- UFC - Crateús --------------\n");
    printf("\n------------ PAA - 2017.2 --------------\n");
    printf("\n----------------------------------------\n");

//Preenchendo o tamanho dos carros
    for (i=0; i<=4; i++)
    {
        printf("\nTamanho do carro %d\n.: ", i+1); //Esse i+1 é só para não escrever Carro 0. Viu? Pseudo-código 3x0
        scanf("%d", &C[i]);
    }

//Como eu falei em sala, essa parte é apenas o "caso base"
    for (i=0; i<=30; i++)
    {
        for (j=0; j<=30; j++)
        {
            M[5][i][j] = 0;
        }
    }

//Vou alocar os carros do último até o primeiro, com todos as configurações de tamanho de balsas possíveis
    for (k=4; k>=0; k--) //Carros
    {
        for (i=0; i<=30; i++) //Tamanho da balsa 1
        {
            for (j=0; j<=30; j++) //Tamanho da balsa 2
            {
                X=0;
                Y=0;
                if (C[k] <= i)  //Se o k-ésimo carro cabe na balsa 1
                {
                    X = 1 + M[k+1][i-C[k]][j];
                }
                if (C[k] <= j) //Se o k-ésimo carro cabe na balsa 2
                {
                    Y= 1 + M[k+1][i][j-C[k]];
                }
                if (X==0 && Y==0) //Se não coube em nenhuma balsa
                {
                    M[k][i][j]=0;
                }
                else  //Se coube em alguma, vê em qual balsa você consegue o maior número de alocações
                {
                    if (X >= Y) //Se a alocação na balsa 1 rende um maior número de alocações, então...
                    {
                        M[k][i][j]=X;
                        Z[k][i][j]=1;
                    }//Essa parte é do rastreio
                    else
                    {
                        M[k][i][j]=Y;//Se a alocação na balsa 2 rende um maior número de alocações, então...
                        Z[k][i][j]=2;
                    }
                }//Essa parte é do rastreio
            }
        }
    }

    printf("\nO número máximo de carros possível para alocar é %d \n",M[0][30][30]);//Imprime o número máximo de carros possíveis de alocar

//Agora é a impressão da solução ótima
    printf("\nA alocação dos carros foi a seguinte:\n");
    A=30;//Tamanho total da balsa 1, porque no ínicio você tem toda balsa à disposição
    B=30;//Tamanho total da balsa 2, porque no ínicio você tem toda balsa à disposição
    for (i=0; i<=4; i++) //Vamos ver onde fica cada carro agora
    {
        printf("\nO carro %d foi para a balsa %d\n",i+1,Z[i][A][B]);//A matriz Z guardou a informação sobre em qual balsa é melhor alocar o k-ésimo
        if (Z[i][A][B]==1) //Se ele foi alocado na balsa 1, então...
        {
            A=A-C[i];
        }//...diminui o tamanho da balsa 1
        else
        {
            B=B-C[i];   //Caso contrário, ele foi alocado na balsa 2, então diminuímos o tamanho da balsa 2
        }
    }

}
