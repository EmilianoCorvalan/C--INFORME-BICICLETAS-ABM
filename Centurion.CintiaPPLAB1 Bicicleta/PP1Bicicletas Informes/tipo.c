#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipo.h"
#include "color.h"
#include "informes.h"


void mostrarTipos(eTipo tipos[], int tam)
{
    printf("\n\n");
    printf("                         Tipo de Bicicletas\n");
    printf("***********************************************************************\n\n");


    printf("    Id           Tipos \n");
    printf("---------------------------\n\n");

    for (int i =0; i < tam; i ++)
    {
        printf("  %d         %s     \n", tipos[i].id, tipos[i].descripcion);
    }
 printf("\n\n");

}

int validarIdTipo(eTipo tipos[], int tam, int id)
{
    int esValido = 0;

    for(int i=0; i < tam; i ++){
        if(tipos[i].id == id){
            esValido = 1;
            break;
        }
    }


   return esValido;
}
int cargarDescripcionTipo(char descripcion[],int id, eTipo tipos[], int tam)
{


    int todoOk = 0;

    for(int i =0; i < tam; i++)
    {

        if(tipos[i].id == id )
        {
            strcpy(descripcion,tipos [i].descripcion);

            todoOk = 1;
        }

    }

    return todoOk;
}
