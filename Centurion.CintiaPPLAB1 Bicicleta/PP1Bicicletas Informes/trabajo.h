

#include "bicicleta.h"

#include "servicio.h"

#include "color.h"
#include "tipo.h"
#include "fecha.h"


#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idBicibleta;
    int idservicio;
    eFecha fechaIngreso;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED



/** \brief Recorre el array y pone el campo isEmpty en 1 si hay lugar en el array.
 *
 * \param array trabajos
 * \param tamaño del array trabajos
 * \return 1 si hay error, 0 si esta todo OK.
 *
 */
int inicializarTrabajo(eTrabajo trabajos[], int tamTrab);
int buscarLibreTrabajo(eTrabajo trabajos[], int tamTrab);
void mostrarTrabajos(eTrabajo trabajos[], int tamTrab,eServicio servicios[], int tamSer,eBici vec[],int tam);
void mostrarTrabajo(eTrabajo x, eServicio servicios[], int tamServ,eBici bicicletas[], int tam);

/** \brief Recorre el array de servicios y cuando encuentra el Id se lo  copia a  la descripcion servicios
 *
 * \param recibe cadena servicios
 * \param recibe id
 * \param  recibe array  de servicios
 * \param tamaño del vector servicios
 * \return 0 todo Ok,  1 si hay error
 *
 */

int cargarDescripcionServicio(char descripcion[],int id, eServicio servicios[], int tamServ);
int cargarMarcaBici(char marca[],int id, eBici bicicletas[], int tam);

int altaTrabajo(int idTrabajo, eTrabajo trabajos[],int tamTrab, eBici bicicletas[], int tam,eTipo tipos[], int tamT, eColor colores[],int tamC, eServicio servicios[], int tamServ, eCliente clientes[], int tamClie);


