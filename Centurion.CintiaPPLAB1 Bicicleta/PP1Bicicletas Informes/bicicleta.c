#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "dataStore.h"
#include "informes.h"
#include "clientes.h"
#include "centurion.h"




void mostrarBici(eBici x, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamClie)
{
    char nombreColor[20];
    char descripcion[20];
    char nombre[20];

    cargarDescripcionColor(nombreColor, x.idColor, colores, tamC);
    cargarDescripcionTipo(descripcion, x.idTipo,tipos, tamT);

    cargarNombre(nombre, x.idCliente,clientes, tamClie);

    printf(" %d       %10s       %.2f        %10s          %10s         %d          %10s\n", x.id, x.marca, x.rodado,nombreColor, descripcion, x.idCliente,nombre);
}


void mostrarBicicletas(eBici vec[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamClie)
{

    int flag =0;

    system("cls");
    printf("\n\n");
    printf("                                         LISTADO DE BICICLETAS\n");
    printf("***************************************************************************************************************************\n\n");

    printf(" Id             Marca       Rodado            Color               Tipo       id Cliente         Cliente   \n");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n\n");

    for (int i =0; i < tam; i ++)
    {


        if(vec[i].isEmpty == 0)
        {

            mostrarBici(vec[i], tipos, tamT, colores, tamC, clientes, tamClie);

            flag = 1;
        }

    }
    if (flag ==0)
    {
        printf("No hay Bicicletas que mostrar\n\n");
    }
}


int inicializarBicicletas(eBici vec[], int tam)
{
    int error = 1;//hay error

    if(vec != NULL && tam > 0) //validar vector sea distinto de NULL
    {

        for(int i = 0; i < tam; i ++)
        {
            vec[i].isEmpty =1;
        }

        error =0;
    }
    return error;
}

int buscarLibre(eBici vec [], int tam)
{
    int indice = -1;

    for(int i = 0; i < tam; i ++ )
    {
        if( vec[i].isEmpty == 1 ) //Entro, significa que la estructura eta  vacia es igual a 1.
        {
            indice = i;
            break; // ya encontre la primer estructura que tenia el campo vacio
        }

    }

    return indice;
}

int buscarBicicletas(int id, eBici vec[], int tam)
{

    int indice = -1;

    for ( int i =0; i < tam ; i ++)
    {

        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaBicicletas(eBici vec[], int tam, eColor colores[], int tamC, eTipo tipos[],int tamT, int id, eCliente clientes[], int tamClie)
{
    int error = 1;
    int indice;
    int idColor;
    int idTipo;
    int idCliente;
    float rodados;
    int flag=0;

     eBici nuevaBici;


    char auxMarca[20];

    if(vec != NULL && tam > 0 && id > 0)
    {
        system("cls");
        printf("-----------------------------ALTA BICICLETA-----------------------------------\n");
        printf("--------------------------------------------------------------------------------\n");
        indice = buscarLibre(vec, tam);

        if(indice == -1)
        {
            printf("Sistema completo!!!\n");
        }
        else
        {
            nuevaBici.id = id;
            nuevaBici.isEmpty = 0; //ahora la estoy cargando a la persona

            mostrarCliente(clientes, tamClie);

          utn_getNumero(&idCliente, "\nIngrese numeros de Cliente: ", "Error, Ingrese Id Clientes\n", 500,509,100);

          nuevaBici.idCliente = idCliente;


           get_String("Ingrese un Marca: ", "Error ingrese un nombre valido: ", 20, auxMarca);
           strcpy(nuevaBici.marca, auxMarca);


            system("cls");
            printf("-----------------------------ALTA COLOR BICICLETA-----------------------------------\n");
            printf("------------------------------------------------------------------------------------\n");
            mostrarColores(colores, tamC);

          utn_getNumero(&idColor, "\nIngrese numeros ID Color: ", "Error, Ingrese Id Color\n", 5000,5004,100);

          nuevaBici.idColor = idColor;


            system("cls");
            printf("-----------------------------ALTA TIPO BICICLETA-----------------------------------\n");
            printf("-----------------------------------------------------------------------------------\n");
            mostrarTipos(tipos, tamT);

            utn_getNumero(&idTipo, "\nIngrese ID Tipo: ", "Error, Ingrese Tipo\n", 1000,1003,100);


            nuevaBici.idTipo = idTipo;


            system("cls");
            printf("-----------------------------ALTA RODADO BICICLETA-----------------------------------\n");
            printf("-----------------------------------------------------------------------------------\n");

            while(flag!=1)
            {
                printf("Ingrese un Rodado: 20,26,27.5,29: ");
                scanf("%f", &rodados);
                if(rodados ==20 || rodados ==26 || rodados ==29 || rodados == 27.5)
                {
                    printf("Alta rodado exitoso!!\n");
                    flag=1;
                }

                printf("Error ingrese un rodado!!\n");
            }
            nuevaBici.rodado = rodados;
            vec[indice] = nuevaBici;

            error = 0;
        }

    }
    return  error;
}


int harcodearBicicletas(eBici vec[], int tam, int cant)
{

    int retorno = -1; // si hay error retorna -1

    if(vec !=NULL && tam > 0 && cant <= tam)
    {
        retorno =0;
        for (int i =0; i < cant; i ++)
        {
            vec[i].id = ids[i];
            strcpy(vec[i].marca, marcas[i]);
            vec[i].idColor = idColores[i];
            vec[i].idTipo = idTipos[i];
            vec[i].rodado = rodados[i];
            vec[i].idCliente = idsClientes[i];

            vec[i].isEmpty = 0; //no vacio 0 - vacio 1
            retorno++; // devuelvo retorno que devuelva la cantidad que cargue
        }
    }
    return retorno;
}

int modificarBicicleta(eBici vec[], int tam,eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamClie)
{
    int error =1;
    int indice;
    int id;
    int nuevoTipo;
    float nuevoRodado;
    int flag=0;

    char confirma;

    int opcion;



    if(vec != NULL && tam > 0 )
    {

        system("cls");
        printf("-------------------------------------MODIFICAR BICICLETA-------------------------------------------------\n\n");
        printf("-----------------------------------------------------------------------------------------------------\n\n");

        mostrarBicicletas(vec, tam,tipos, tamT,colores, tamC, clientes, tamClie);
        printf("\n\n");
        printf("Ingrese el Id de la bicicleta a modificar: ");
        scanf("%d", &id);

        indice = buscarBicicletas(id,vec, tam);

        if( indice == -1)

        {
            printf("No existe una moto con ese Id\n\n");

        }
        else
        {

            do
            {
                system("cls");
                printf("-------------------------------------MENU MODIFICAR BICICLETA-------------------------------------------------\n\n");
                printf("MENU MODIFICAR CAMPO -------------------------------------------------------------------------------\n\n");
                printf("1.Tipo\n");
                printf("2.Rodado\n");


                printf("\n\nLa Bicicleta a modificar es :\n\n");
                mostrarBici(vec[indice], tipos, tamT, colores, tamC, clientes, tamClie);

                printf("Ingrese una opcion: ");

                utn_getNumero(&opcion, "\nIngrese un numero del submenu: ", "Error debe ingresar un numero valido\n", 1, 2,2);

                switch(opcion)
                {


                case 1:
                    printf("\nIngrese nuevo Tipo de Bicicleta: \n* 1000- Rutera \n* 1001- Carrera  \n* 1002- Mountain  \n* 1003- BMX \n\n");
                    scanf("%d",&nuevoTipo);
                    vec[indice].idTipo = nuevoTipo;

                    printf("Se ha actualizado Tipo de bicileta con exito\n\n");

                    break;



                case 2:

               while(flag!=1)
                {
                printf("Ingrese un Rodado: 20,26,27.5,29: ");
                scanf("%f", &nuevoRodado);
                if(nuevoRodado ==20 || nuevoRodado ==26 || nuevoRodado ==29 || nuevoRodado == 27.5)
                {
                    printf("Modificacion rodado exitosa!!\n");
                    flag=1;
                }

                printf("Error ingrese un rodado!!\n");

               }
                break;


            }

            mostrarBici(vec[indice], tipos, tamT, colores, tamC, clientes, tamClie);

            printf("\nSigue modificando? ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma== 's')
            {

                error =0;
            }
            else
            {
                error = 2;

            }

        }
        while(confirma =='s');

    }

}
return error;
}

int bajaBicicleta(eBici vec[], int tam,eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamClie)
{
    int error =1;
    int indice;
    int id;
    char confirma;


    if(vec != NULL && tam > 0)
    {
        system("cls");
        printf("------------------------------------- SISTEMA DE BAJA BICICLETA -------------------------------------------------\n\n");
        printf("----------------------------------------------------------------------------------------------------------------- \n\n");

        mostrarBicicletas(vec, tam, tipos, tamT, colores, tamC, clientes, tamClie);
        printf("\n\n");
        printf("Ingrese el Id a eliminar: ");
        scanf("%d", &id);

        indice = buscarBicicletas(id, vec, tam);

        if( indice == -1)
        {
            printf("No hay ninguna Bicicleta con ese Id\n\n");

        }
        else
        {
            mostrarBici(vec[indice], tipos, tamT, colores, tamC, clientes, tamClie);
            printf("\nConfirma baja de la Bicicleta? ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma== 's')
            {
                vec[indice].isEmpty =1;
                error =0;
            }
            else
            {
                error = 2;

            }
        }

    }
    return error;
}


int ordenarBicicletas(eBici vec[], int tam, int orden)
{
    int isOk = -1;
    eBici auxN;

    if(vec != NULL)
    {
        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i + 1; j < tam; j ++)
            {
                if(vec[i].isEmpty == 0 && vec[j].isEmpty == 0)
                {

                    if(orden == 1)
                    {
                        if(vec[i].idTipo > vec[j].idTipo || (vec[i].idTipo == vec[j].idTipo && vec[i].rodado > vec[j].rodado))
                        {
                            auxN = vec[i];
                            vec[i] = vec[j];
                            vec[j] = auxN;
                        }

                    }
                    else if(orden == 0)
                    {
                        if(vec[i].idTipo < vec[j].idTipo || (vec[i].idTipo == vec[j].idTipo && vec[i].rodado < vec[j].rodado))
                        {
                            auxN = vec[i];
                            vec[i] = vec[j];
                            vec[j] = auxN;
                        }

                    }
                }
            }
        }
        isOk = 0;
    }
    return isOk;
}



