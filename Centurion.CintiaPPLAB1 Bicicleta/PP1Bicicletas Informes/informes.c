#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "informes.h"
#include "bicicleta.h"
#include "servicio.h"
#include "trabajo.h"
#include "color.h"
#include "tipo.h"
#include "fecha.h"
#include "centurion.h"


int menuInformes()
{

    int opcion;

    system("cls");
    printf("************** Informe Bicicletas ********\n\n");
    printf("1. Mostrar Bicicletas por color \n");
    printf("2. Mostrar Bicicletas por tipo seleccion \n");
    printf("3. Informe Bicicletas menor Rodado \n");
    printf("4. Informe Bicicletas listadas por tipo\n");
    printf("5. Total tipo y Total color \n");
    printf("6. Colores mas elegidos \n");
    printf("7. Informe servicios a la bicicleta\n");
    printf("8. Total $ Servicios realizados a la Bicicleta \n");
    printf("9. Informar servicios segun fecha\n");
    printf("10. Informar por fecha de Servicios\n");
    printf("11. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}



void informes(eBici vec[], int tam,eColor colores[], int tamC, eTipo tipos[], int tamT, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ, eCliente clientes[], int tamClie)
{

    char seguir ='s';
    char confirma;

    system("cls");
    printf("**************** Informes Bicicletas *************\n\n");

    do
    {

        switch(menuInformes())
        {
        case 1:
            informarBicicletasXColor(vec, tam, colores, tamC, tipos, tamT, clientes, tamClie);
            break;

        case 2:
            informarBicicletasXTipo(vec, tam, colores, tamC, tipos, tamT, clientes, tamClie);
            break;

        case 3:
            informarMayorRodado(vec, tam, colores, tamC, tipos, tamT, clientes, tamClie);
            break;

        case 4:
            mostrarBicicletasXtipo(vec, tam, colores, tamC, tipos, tamT, clientes, tamClie);
            break;

        case 5:
            contartTipoColorBicicleta(vec, tam, colores, tamC, tipos, tamT, clientes, tamClie);
            break;

        case 6:
            colorFavorito(vec, tam, colores, tamC, tipos, tamT, clientes, tamClie);
            break;

        case 7:

             mostrarTrabajosBicicleta(vec,tam,trabajos, tamTrab, servicios,tamServ, tipos,tamT, colores,tamC, clientes, tamClie);

            break;


        case 8:

             mostrarImporteTotalServicios(vec,tam,trabajos, tamTrab, servicios,tamServ, tipos,tamT, colores,tamC,clientes,  tamClie);
            break;


        case 9:

          InformafechaDeServicios(vec,tam,trabajos, tamTrab, servicios,tamServ);


            break;

        case 10:

            mostrarServicioXfecha(vec,tam,trabajos, tamTrab, servicios,tamServ);

            break;


        case 11:
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
}

void informarBicicletasXColor(eBici vec[], int tam,eColor colores[], int tamC, eTipo tipos[], int tamT, eCliente clientes[], int tamClie)
{

    int idColor;
    int flag =0;

    system("cls");
    printf("******* Bicicletas por color ***********\n\n");

    mostrarColores(colores, tamC);
    utn_getNumero(&idColor, "\nIngrese numeros ID Color: ", "Error, Ingrese Id Color\n", 5000,5004,100);



    printf("\n");
    printf(" Id Bicicleta         Marca           Rodado               Color              Tipo          Id Cliente \n\n");
    printf("-----------------------------------------------------------------------------------------------------------\n");

    for (int i =0; i < tam; i ++)
    {

        if(vec[i].isEmpty == 0 && vec[i].idColor == idColor)
        {
            mostrarBici(vec[i],tipos, tamT,colores, tamC, clientes, tamClie);
            printf("\n");
            flag = 1;
        }
    }
    if (flag ==0)
    {
        printf("* * * * * No hay Bicicletas de ese color * * * * * \n\n");
    }

}


void informarBicicletasXTipo(eBici vec[], int tam,eColor colores[], int tamC, eTipo tipos[], int tamT, eCliente clientes[], int tamClie)
{

    int idTipo;
    int flag =0;

    system("cls");
    printf("******* Bicicletas por Tipo ***********\n\n");

    mostrarTipos(tipos, tamT);

     utn_getNumero(&idTipo, "\nIngrese ID Tipo: ", "Error, Ingrese Tipo\n", 1000,1003,100);

    printf("\n");
    printf(" Id         Marca         Rodado               Color              Tipo   \n\n");
    printf("--------------------------------------------------------------------------------\n");

    for (int i =0; i < tam; i ++)
    {

        if(vec[i].isEmpty == 0 && vec[i].idTipo == idTipo)
        {
            mostrarBici(vec[i],tipos, tamT,colores, tamC, clientes, tamClie);
            printf("\n");
            flag = 1;
        }
    }
    if (flag ==0)
    {
        printf("* * * * * No hay Bicicletas ese tipo de Bicicletas * * * * * \n\n");
    }

}

void informarMayorRodado(eBici vec[], int tam,eColor colores[], int tamC, eTipo tipos[], int tamT, eCliente clientes[], int tamClie)
{


    system("cls");
    printf("******* Bicicletas mayor Rodado ***********\n\n");



    printf("\n");
    printf(" Id         Marca         Rodado               Color              Tipo   \n\n");
    printf("--------------------------------------------------------------------------------\n");


    for (int i =0; i < tam; i ++)
    {
        {
            if(vec[i].isEmpty == 0 && (vec[i].rodado)<=20)
            {
                mostrarBici(vec[i],tipos, tamT,colores, tamC, clientes, tamClie);
                printf("\n");
                //flag = 1;
            }

        }
    }
}

void mostrarBicicletasXtipo(eBici vec[], int tam,eColor colores[], int tamC, eTipo tipos[], int tamT, eCliente clientes[], int tamClie)
{
    int flag;

    system("cls");
    printf("************** Informe Tipos de bicicletas ****************\n\n");

    //RECORRO LOS SECTORES INT S PARA RECORRER SECTORES (FOR EXTERIOR)
    for(int t =0; t < tamT ; t ++)
    {
        flag =0;
        printf("tipos: %s\n", tipos[t].descripcion);
        printf("--------\n\n");

        //RECORRO LOS SECTORES DE DONDE ESTOY POSC.
        for(int b =0; b < tam ; b ++)
        {
            if(vec[b].isEmpty == 0 && vec[b].idTipo == tipos[t].id)
            {
                mostrarBici(vec[b], tipos, tamT, colores, tamC, clientes, tamClie);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\n No existe este tipo de bicicletas\n\n");
        }
        printf("\n-----");
    }
}


int contartTipoColorBicicleta(eBici vec[], int tam,eColor colores[], int tamC, eTipo tipos[], int tamT, eCliente clientes[], int tamClie)
{
    int error=1;
    int idColor;
    int idTipo;
    char colorDesc[20];
    char tipoDesc[20];
    int contadorColor=0;
    int contadorTipo=0;


    if(vec !=NULL && tam  > 0 && tamC)
    {
        system("cls");
        printf("\n\n------------------------Cantidad de Bicicletas-----------------------------------\n\n");
        printf("---------------------------------------------------------------------------------\n\n");
        mostrarColores(colores, tamC);
        utn_getNumero(&idColor, "\nIngrese numeros ID Color: ", "Error, Ingrese Id Color\n", 5000,5004,100);


       // printf("Ingrese Colores: ");
        //scanf("%d", &idColor);

       // while(validarIdColor(colores, tamC,idColor)==0)
        //{
            //printf("Id Invalido.Reingrese Id Color: ");
            //scanf("%d", &idColor);
        //}

        cargarDescripcionColor(colorDesc, idColor, colores, tamC);


        mostrarTipos(tipos, tamT);

       utn_getNumero(&idTipo, "\nIngrese ID Tipo: ", "Error, Ingrese Tipo\n", 1000,1003,100);

      //  printf("Ingrese Tipos: ");
       // scanf("%d", &idTipo);

        //while(validarIdTipo(tipos, tamT,idTipo)==0)
        //{
            //printf("Id Invalido.Reingrese Id deporte: ");
            //scanf("%d", &idTipo);
        //}

        cargarDescripcionTipo(tipoDesc, idTipo, tipos, tamT);


        system("cls");
        mostrarBicicletas(vec, tam,tipos, tamT,colores, tamC, clientes, tamClie);

        for(int i=0; i < tam; i ++)
        {
            if(vec[i].isEmpty == 0 && vec[i].idColor == idColor)
            {
                contadorColor++;
            }

        }
        for(int i=0; i < tam; i ++)
        {

            if(vec[i].isEmpty == 0 && vec[i].idTipo == idTipo)
            {
                contadorTipo++;
            }

        }
        error=0;

        printf("\n\n------------------------Cantidad de Bicicletas---------------------------------------\n\n");
        printf("-------------------------------------------------------------------------------------\n\n");
        printf("Cantidad de Bicicletas de color %s: %d en total \n\n",colorDesc, contadorColor);
        printf("-------------------------------------------------------------------------------------\n\n");
        printf("Cantidad de Biciccletas de Tipo %s: %d en total \n\n\n",tipoDesc,contadorTipo);
    }

    return error;
}

int colorFavorito(eBici vec[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT, eCliente clientes[], int tamClie)
{

    int error=1;
    int contadores[tamC];//VECTOR DE CONTADORES DE COLORES
    int idBuscado;
    int mayor;
    int flag =0;

    if(vec !=NULL && colores != NULL && tam > 0 && tamC > 0)
    {
        for(int c=0; c < tamC; c++)
        {
            contadores[c] = 0;
        }

        for(int c=0; c < tamC; c++)
        {
            idBuscado = colores[c].id;

            for( int b=0; b <tam; b++)
            {
                if(vec[b].isEmpty ==0 && vec[b].idColor == idBuscado)
                {
                    contadores[c]++;
                }

            }
        }
        //BUSCO EL CONTADOR MAYOR
        for(int i=0; i < tamC; i++)
        {
            if(contadores[i] > mayor || flag == 0)
            {
                mayor= contadores[i];
                flag=1;
            }
        }

        system("cls");
        mostrarBicicletas(vec, tam,tipos, tamT,colores, tamC, clientes, tamClie);
        printf("\n\n-------------- Colores de bicicletas preferidos --------------------\n\n");
        printf("El o los colores con mas elegidos: ");

        for(int i=0; i < tamC; i++)
        {
            if(contadores[i] == mayor)
            {
                printf("%s\n", colores[i].nombreColor);
            }
        }

        printf("\n\n");



        error =0;
    }
    return error;
}


int mostrarTrabajosBicicleta(eBici vec[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamClie)
{
    int error =1;
    int idBici;




    system("cls");
    printf("---------------------- Informe total servicios Bicicleta --------------------------------\n\n");

    mostrarBicicletas(vec, tam,tipos, tamT, colores,tamC, clientes, tamClie);
    printf("\n\n");


    printf("Ingrese Id Bicicleta: ");
    scanf("%d", &idBici);

    for(int i=0; i < tamTrab; i ++)
    {

        if(trabajos[i].isEmpty ==0 && trabajos[i].idBicibleta ==idBici)
        {

            for(int j=0; j< tamServ; j++)
            {
                if(servicios[j].id == trabajos[i].idservicio)
                {
                    mostrarTrabajo(trabajos[i], servicios, tamServ, vec,tam);
                }
            }
        }

        error =0;
    }


    return error;
}

int mostrarImporteTotalServicios(eBici vec[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamClie)
{
    int error =1;
    int idBici;
    float total =0;

    if(vec !=NULL && servicios != NULL &&  trabajos != NULL && colores != NULL && tipos != NULL && tam > 0 && tamServ > 0 && tamTrab > 0 && tamT >0 && tamC >0)
    {

        system("cls");
        printf("---------------------- Informe total Importe servicios Bicicleta --------------------------------\n\n");

        mostrarBicicletas(vec, tam,tipos, tamT, colores,tamC, clientes, tamClie);
        printf("\n\n");
        printf("Ingrese Id Bicicleta: ");
        scanf("%d", &idBici);

        for(int i=0; i < tamTrab; i ++)
        {

            if(trabajos[i].isEmpty ==0 && trabajos[i].idBicibleta ==idBici)
            {

                for(int j=0; j< tamServ; j++)
                {
                    if(servicios[j].id == trabajos[i].idservicio)
                    {
                        total += servicios[j].precio;

                    }
                }
            }

        }
        system("cls");
        printf("\n\n");
        printf("----------------------------------------------------- \n\n");
        printf("Total a pagar bicicleta ID %d : $ %2.f\n\n", idBici,total);

        error =0;
    }


    return error;
}

int InformafechaDeServicios(eBici vec[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ)
{

    int error =1;

    int idServicio;
    char desServicio[20];

    system("cls");

     if(servicios !=NULL && tamServ  > 0 && tamTrab)
    {

        mostrarServicios(servicios, tamServ);
        printf("Ingrese ID de Servicio: ");
        scanf("%d", &idServicio);

        while(validarIdServicio(servicios, tamServ,idServicio)==0)
            {
                printf("Id Invalido.Reingrese Id Servicio: ");
                scanf("%d", &idServicio);
            }

       cargarDescripcionServicio(desServicio,idServicio, servicios , tamServ);


        printf("-----------------------------Lista de Servicios----------------------------------------------\n\n");
        printf("  Id Trabajo           Servicio         Id Bicicleta          Marca         Fecha de Ingreso  \n\n");
        for(int i=0; i < tamTrab; i ++)
        {

            if(trabajos[i].isEmpty ==0 && trabajos[i].idservicio == idServicio)

                for(int j=0; j< tamServ; j++)
                {
                    if(servicios[j].id == trabajos[i].idservicio)
                    {

                        mostrarTrabajo(trabajos[i], servicios, tamServ, vec,tam);

                        printf("\n");
                    }
                }
        }


    }




    return error;
}


int mostrarServicioXfecha(eBici vec[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ)
{

    int error =1;
    int dias;
    int meses;
    int anios;


    if( vec !=NULL && servicios !=NULL &&  trabajos != NULL  && tam >0 && tamServ >0 && tamTrab >0)
    {

        system("cls");
        printf("---------------------- Informe por Solicitud de fecha --------------------------------\n\n");

        mostrarTrabajos(trabajos,tam, servicios, tamServ, vec,tam);
        printf("\n\n");
        printf("Ingrese dia: ");
        scanf("%d", &dias);
        printf("Ingrese mes: ");
        scanf("%d", &meses);
        printf("Ingrese anio: ");
        scanf("%d", &anios);

        printf("\n------------------------------------Lista de Servicios----------------------------------------------\n\n");
        printf("  Id Trabajo           Servicio         Id Bicicleta          Marca         Fecha de Ingreso  \n\n");

        for(int i=0; i < tamTrab; i ++)
        {

            if(trabajos[i].isEmpty ==0 && trabajos[i].fechaIngreso.dia==dias && trabajos[i].fechaIngreso.mes==meses && trabajos[i].fechaIngreso.anio)
            {
                for(int j=0; j< tamServ; j++)
                {
                    if(servicios[j].id == trabajos[i].idservicio)
                    {
                     mostrarTrabajo(trabajos[i], servicios, tamServ, vec,tam);
                      printf("\n");
                    }
                }
            }
           error=0;

        }


    }

    return error;
}



