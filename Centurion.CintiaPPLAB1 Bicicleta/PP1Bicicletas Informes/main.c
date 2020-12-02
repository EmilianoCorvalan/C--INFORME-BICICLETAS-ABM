#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "color.h"
#include "tipo.h"
#include "bicicleta.h"
#include "fecha.h"
#include "trabajo.h"
#include "servicio.h"
#include "informes.h"
#include "clientes.h"



#define TAM 100
#define TAM_CLIE 10
#define TAM_T 4
#define TAM_C 5
#define TAM_TRA 100
#define TAM_SER 4

#define ORDEN 1




char menu();

int main()
{


    char seguir = 's';
    char confirma;
    int rta;

    int flag1 = 0;



    eBici lista [TAM];
    eTipo listaTipos [TAM_T]= {{1000,"Rutera"},{1001,"Carrera"},{1002,"Mountain"},{1003,"Bmx"}};
    eColor listaColores [TAM_C]= {{5000,"Gris"},{5001,"Negro"},{5002,"Blanco"},{5003,"Azul"},{5004,"Rojo"}};
    eTrabajo listaTrabajo[TAM_TRA];
    eServicio listaServicio[TAM_SER] = {{20000,"Limpieza",205},{20001,"Parche",300},{20002,"Centrado",400},{20003,"Cadena",350}};
    eCliente listaClientes[TAM_CLIE] ={{500,"Maria"},{501, "Sofia"},{502,"Daniel"},{503, "Tomas"},{504,"Susana"},{505, "Soledad"} ,{506,"Norma"},{507, "Cintia"} ,{508,"Luis"},{509, "Teresa"}};


    int proximoId = 100;
    int proximoIdTrabajo =30000;
    inicializarBicicletas(lista, TAM);
    inicializarTrabajo(listaTrabajo, TAM_TRA);
    proximoId += harcodearBicicletas(lista, TAM, 10);



  listaTrabajo[0] = (eTrabajo) {30001,100,20003, {16,03,2020},0};
  listaTrabajo[1] = (eTrabajo) {30006,100,20003, {16,03,2020},0};
  listaTrabajo[2] = (eTrabajo) {30002,102,20001, {16,05,2020},0};
  listaTrabajo[3] = (eTrabajo) {30005,103,20002, {30,12,2019},0};
  listaTrabajo[4] = (eTrabajo) {30004,104,20001, {10,04,2020},0};
  listaTrabajo[5] = (eTrabajo) {30009,100,20000, {22,07,2020},0};
  listaTrabajo[6] = (eTrabajo) {30007,106,20000, {02,06,2020},0};
  listaTrabajo[7] = (eTrabajo) {30005,107,20000, {12,03,2020},0};
  listaTrabajo[8] = (eTrabajo) {30003,107,20000, {12,10,2020},0};

  proximoIdTrabajo +=9;


    do
    {

        switch(menu())
        {

        case 'a':

            if(altaBicicletas(lista, TAM, listaColores, TAM_C, listaTipos, TAM_T, proximoId, listaClientes,TAM_CLIE)==0)
            {
                proximoId ++;
                printf("\n\nAlta exitosa!!!\n\n");
                mostrarBicicletas(lista,TAM, listaTipos, TAM_T, listaColores, TAM_C, listaClientes, TAM_CLIE);
                printf("\n\n");
            }
            else
            {
                printf("Problema para realizar el alta\n\n");
            }


            flag1=1;

            break;


        case 'b':

            if(flag1)
            {
                rta = modificarBicicleta(lista,TAM,listaTipos,TAM_T, listaColores, TAM_C, listaClientes, TAM_CLIE);
                if(rta == 0)
                {
                    printf("Se ha modificado con exito!!\n\n");
                }
                else if(rta ==2)
                {
                    printf("Modificacion Cancelada!!\n\n");

                }
                else
                {

                    printf("Hubo un problema al intentar realizar la modificacion!!\n\n");
                }
            }
            else
            {

                printf("Primero debe ingresar una Bicicleta opcion: ALTA \n");

            }

            break;


        case 'c':

            if(flag1)
            {
                rta = bajaBicicleta(lista,TAM,listaTipos,TAM_T,listaColores,TAM_C, listaClientes, TAM_CLIE);
                if(rta == 0)
                {
                    printf("Se ha realizado la baja con exito!!\n\n");
                }
                else if(rta ==2)
                {
                    printf("Baja cancelada!!\n\n");

                }
                else
                {
                    printf("Hubo un problema al realizar la baja!!\n\n");

                }

            }
            else
            {
                printf("Primero debe ingresar una Bicicleta opcion: ALTA \n");

            }

            break;


        case 'd':

            if(flag1)
            {
                if( ordenarBicicletas(lista, TAM,ORDEN)==0)  //orden ASC
                {
                    printf("\nSe ordeno el vector!!\n\n");
                    mostrarBicicletas(lista,TAM, listaTipos, TAM_T, listaColores, TAM_C, listaClientes, TAM_CLIE);
                    printf("\n\n");
                }
                else
                {
                    printf("Problema al ordenar vector\n\n");
                }
            }
            else
            {

                printf("Primero debe ingresar una Bicicleta opcion: ALTA \n");

            }


            break;


        case 'e':

            system("cls");
            mostrarTipos(listaTipos, TAM_T);

            break;


        case 'f':

            system("cls");
            mostrarColores(listaColores, TAM_T);


            break;


      case 'g':

            system("cls");
            mostrarServicios(listaServicio, TAM_SER);

            break;




        case 'h':

            if (altaTrabajo(proximoIdTrabajo, listaTrabajo,TAM_TRA, lista, TAM, listaTipos, TAM_T, listaColores, TAM_C, listaServicio, TAM_SER, listaClientes, TAM_CLIE))
            {
                proximoIdTrabajo++;
            }
            break;


        case 'i':

         mostrarTrabajos(listaTrabajo, TAM_TRA, listaServicio, TAM_SER,lista,TAM);

            break;

        case 'j':

         informes(lista,TAM, listaColores, TAM_C, listaTipos, TAM_T, listaTrabajo, TAM_TRA, listaServicio, TAM_SER, listaClientes, TAM_CLIE);

            break;


        case 'z':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');


    return 0;
}


char menu()
{
    char opcion;
    system("cls");


    printf("***********************SISTEMA DE GESTION DE BICICLETAS*************************\n");
    printf("--------------------------------MENU ABM---------------------------------------\n\n");
    printf("a Alta Bicicleta\n");
    printf("b Modificar Bicicleta\n");
    printf("c Baja Bicicleta\n");
    printf("d Listar Bicicletas Ordenamiento\n");
    printf("e Listar Tipo de bicicletas\n");
    printf("f Listar Colores de bicicletas\n");
    printf("g Listar Servicios\n");
    printf("h Alta Trabajo\n");
    printf("i Listar Trabajo\n");
    printf("j Informes\n");
    printf("z Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());



    return opcion;
}
