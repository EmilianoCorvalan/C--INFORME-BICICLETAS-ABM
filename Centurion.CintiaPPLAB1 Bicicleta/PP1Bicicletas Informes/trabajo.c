#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "trabajo.h"
#include "servicio.h"
#include "bicicleta.h"
#include "fecha.h"
#include "centurion.h"


int inicializarTrabajo(eTrabajo vec[], int tam)
{
    int error = 1;//hay error

    if(vec != NULL && tam > 0) //validar vectores sea distinto de NULL
    {

        for(int i = 0; i < tam; i ++)
        {
            vec[i].isEmpty =1;
        }

        error =0;
    }
    return error;
}



int buscarLibreTrabajo(eTrabajo trabajos[], int tamTrab)
{
    int indice = -1; // esta precargado indice NO hace falta hacer un ELSE. (-1) ESTA LLENO NO HAY LUGAR.

    for(int i = 0; i < tamTrab; i ++ )
    {
        if( trabajos[i].isEmpty == 1 ) //Entro, significa que la estructura eta  vacia es igual a 1.
        {
            indice = i;
            break;
        }

    }

    return indice;
}


void mostrarTrabajo(eTrabajo x, eServicio servicios[], int tamServ,eBici bicicletas[], int tam)
{

    char desServicio[20];
    char descMarca[20];

    cargarDescripcionServicio(desServicio, x.idservicio, servicios , tamServ);

    cargarMarcaBici(descMarca,x.idBicibleta,bicicletas, tam);

    printf("   %d             %10s            %d            %10s              %d/%d/%d\n", x.id, desServicio,x.idBicibleta,descMarca, x.fechaIngreso.dia, x.fechaIngreso.mes, x.fechaIngreso.anio);
}

void mostrarTrabajos(eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamSer, eBici vec[], int tam)
{

    int flag =0;


    system("cls");
    printf("\n*********************************** Listado  Service ***************************************************\n\n\n");
    printf("  Id Trabajo           Servicio         Id Bicicleta          Marca         Fecha de Ingreso  \n");
    printf("\n*********************************************************************************************************\n\n\n");

    for (int i = 0; i < tamTrab; i ++)
    {
        if(trabajos[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajos[i], servicios, tamSer, vec,tam);

            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("No hay Trabajos que mostrar\n\n");
    }
    printf("\n");
}




int altaTrabajo(int idTrabajo, eTrabajo trabajos[],int tamTrab, eBici bicicletas[], int tam,eTipo tipos[], int tamT, eColor colores[],int tamC, eServicio servicios[], int tamServ, eCliente clientes[], int tamClie)
{
    int todoOk =0;
    eTrabajo nuevoTrabajo;
    int indice;


    system("cls");
    printf("--------------------------------------Alta Service---------------------------------\n\n");
    printf("--------------------------------------------------------------------------------------\n\n");


    indice = buscarLibreTrabajo(trabajos,tamTrab);

    if(indice == -1)
    {
        printf("Sistema completo no se puede dar Trabajos de alta \n");
    }
    else
    {


        mostrarBicicletas(bicicletas, tam, tipos, tamT, colores, tamC, clientes, tamClie);
        utn_getNumero(&nuevoTrabajo, "\nIngrese ID de Bicicleta: ", "Error, Ingrese bicicleta\n", 100,115,100);



        mostrarServicios(servicios, tamServ);
        utn_getNumero(&nuevoTrabajo, "\nIngrese ID de Servicio: ", "Error, Ingrese Servicio\n", 20000,20003,100);


        utn_getNumero(&nuevoTrabajo.fechaIngreso.dia, "\nIngrese dia: ", "Error, Ingrese dia\n", 1,31,100);
        utn_getNumero(&nuevoTrabajo.fechaIngreso.mes, "\nIngrese mes: ", "Error, Ingrese mes\n", 1,13,100);
        utn_getNumero(&nuevoTrabajo.fechaIngreso.anio, "\nIngrese anio: ", "Error, Ingrese mes\n",2000,2021,100);



        nuevoTrabajo.id = idTrabajo ;
        nuevoTrabajo.isEmpty =0;

        trabajos[indice] = nuevoTrabajo;

        todoOk = 1;

        printf("\n\n\nAlta Trabajo Exitoso!!!\n\n\n\n");

    }

    return todoOk;
}

int cargarDescripcionServicio(char descripcion[],int id, eServicio servicios[], int tamServ)
{

    int todoOk = 0;

    for(int i =0; i < tamServ; i++)
    {

        if(servicios[i].id== id )
        {
            strcpy(descripcion, servicios[i].descripcion);

            todoOk = 1;
        }

    }

    return todoOk;
}


int cargarMarcaBici(char marca[],int id, eBici bicicletas[], int tam)
{

    int todoOk = 0;

    for(int i =0; i < tam; i++)
    {

        if(bicicletas[i].id == id && bicicletas[i].isEmpty == 0)
        {
            strcpy(marca, bicicletas[i].marca);
            todoOk = 1;
        }

    }

    return todoOk;
}



