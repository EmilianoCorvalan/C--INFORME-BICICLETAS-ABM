#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "servicio.h"
#include "informes.h"


void mostrarServicios(eServicio servicios[], int tamServ)
{
    printf("\n\n\n* * * * * Listado de Servicios * * * * * \n\n");
    printf(" Id         Service           Precio     \n\n");

    for (int i = 0; i < tamServ; i ++)
    {
        printf(" %d     %10s         %5.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
    }

    printf("\n\n");
}

int validarIdServicio(eServicio servicios[], int tam, int id)
{
    int esValido = 0;

    for(int i=0; i < tam; i ++){
        if(servicios[i].id == id){
            esValido = 1;
            break;
        }
    }


   return esValido;
}
