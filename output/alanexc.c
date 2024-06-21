
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float dist(float a1, float a2, float a3, float a4,
                         float b1, float b2, float b3, float b4) {
    return sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2) +
                (a3 - b3) * (a3 - b3) + (a4 - b4) * (a4 - b4));
}

int main () {
 FILE *teste=fopen("IrisTeste.txt", "r");
 FILE *treino=fopen("IrisTreino.txt", "r");

 float teste1, teste2, teste3, teste4,treino1, treino2, treino3, treino4, distancia, verifica;
 int classeRTeste, taxaAcerto = 0, classeRTreino, classe = -1, total = 0;

    while(fscanf(teste, "%f,%f,%f,%f,%d", &teste1, &teste2, &teste3, &teste4, &classeRTeste)!= EOF){
     float distMin = 10000;
     rewind(treino);

        while(fscanf(treino,"%f,%f,%f,%f,%d", &treino1, &treino2, &treino3, &treino4, &classeRTreino) != EOF){

        distancia = dist(teste1, teste2, teste3, teste4, treino1, treino2, treino3, treino4 );

         if (distancia<distMin){
          distMin = distancia;
          classe = classeRTreino;
         }

        }


        if (classe==classeRTeste){
           taxaAcerto++;
        }
        total++;
  }
  fclose(treino);
  fclose(teste);

  verifica = (float)taxaAcerto/total;
  printf("taxa de acerto eh %.2f \n", verifica*100);

  return 0;
  }
