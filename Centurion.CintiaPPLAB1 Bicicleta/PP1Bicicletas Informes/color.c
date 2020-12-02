#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"
#include "tipo.h"
#include "informes.h"

void mostrarColores(eColor colores[], int tam)
{



    printf("\n\n");
    printf("              Lista de colores\n");
    printf("*************************************************\n\n");


    printf("           Id           Color \n");
    printf("--------------------------------------------------\n\n");
    for (int i =0; i < tam; i ++)
    {
        printf("       %d            %s     \n", colores[i].id, colores[i].nombreColor);
    }
    printf("\n\n");

}


int validarIdColor(eColor colores[], int tam, int id)
{
    int esValido = 0;

    for(int i=0; i < tam; i ++){
        if(colores[i].id == id){
            esValido = 1;
            break;
        }
    }


   return esValido;
}

int cargarDescripcionColor(char nombreColor[],int id, eColor colores[], int tam){

    int todoOk = 0;

    for(int i =0; i < tam; i++)
    {

        if(colores[i].id == id )
        {
            strcpy(nombreColor,colores[i].nombreColor);

            todoOk = 1;
        }

    }

    return todoOk;
}




