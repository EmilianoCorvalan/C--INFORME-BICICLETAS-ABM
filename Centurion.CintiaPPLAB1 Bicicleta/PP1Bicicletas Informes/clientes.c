#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



#include "clientes.h"



int cargarNombre(char nombre[], int id,eCliente clientes[],int tam)
{
    int error =1;

    if(clientes!=NULL && tam > 0 && id >0 && nombre !=NULL)
     {
         for(int i=0; i < tam; i ++)
         {
             if(clientes[i].id == id)
             {
                 strcpy(nombre, clientes[i].nombre);
                 error =0;
                 break;
             }
         }
     }

return error;
}



void mostrarCliente(eCliente clientes[], int tam)
{

    printf("\n\n");
    printf("              Lista de clientes\n");
    printf("*************************************************\n\n");


    printf("    Id Clientes              Clientes \n");
    printf("--------------------------------------------------\n\n");
    for (int i =0; i < tam; i ++)
    {
        printf("       %d                   %s     \n", clientes[i].id, clientes[i].nombre);
    }
    printf("\n\n");

}


int validarIdCliente(eCliente clientes[], int tam, int id)
{
    int esValido = 0;

    for(int i=0; i < tam; i ++){
        if(clientes[i].id == id){
            esValido = 1;
            break;
        }
    }


   return esValido;
}






