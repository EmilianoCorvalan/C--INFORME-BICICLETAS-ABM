#include "tipo.h"
#include "color.h"
//#include "fecha.h"
#include "clientes.h"



#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{

    int id;
    char marca[20];
    float rodado;
    int idCliente;
    int idTipo;
    int idColor;
    int isEmpty;


} eBici;

#endif // BICICLETA_H_INCLUDED


/** \brief Recorre el array buscando el indice de la primer estructura que tenga el campo isEmpty en 1 o sea libre.
 *
 * \param Recibe el array de bicicletas
 * \param  recibe el tama�o del array
 * \return devuelve el indice de la primer estructura libre que encontro
 *
 */
int buscarLibre(eBici vec [], int tam);




/** \brief Recorre el array y pone el campo isEmpty en 1 si hay lugar en el array.
 *
 * \param array bicicleta
 * \param tama�o del array
 * \return 1 si hay error, 0 si esta todo OK.
 *
 */
int inicializarBicicletas(eBici vec[], int tam);



/** \brief Agrega en el array existente los valores recibidos como p�rametro en la primer posici�n libre.
 *
 * \param recibe id incremental
 * \param recibe vector bicicleta, vector tipo, vector colores, vector cliente.
 * \param tama�o de todos los vectores.
 * \return 0 si est� todo OK, -1 error
 *
 */
int altaBicicletas(eBici vec[], int tam, eColor colores[], int tamC, eTipo tipos[],int tamT, int id, eCliente clientes[], int tamClie);




/** \brief Funcion que buscara la bicicleta por el id que le paso y lo eliminara del listado
 *
 * \param Recibe el id
 * \param Recibe el array de bicicletas
 * \param recibe el tama�o del array
 * \return Devuelve el indice de la bicicleta o -1 si no existe el id que le pase id.
 *
 */

int buscarBicicletas(int id, eBici vec[], int tam);





/** \brief Muestra todas las bicicletas del vector con sus distintos campos
 *
 * \param estructura bicicleta eBici
 * \param Tama�o eBici
 * \param vector Tipo
 * \param Tama�o del vector tipo
 * \param vector colores
 * \param tama�o del vector colores
 * \param estructura clientes eCliente
 * \param tama�o del vector cliente
 * \return es void
 *
 */

void mostrarBicicletas(eBici vec[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamClie);


/** \brief Muestra vector de una bicicleta
 *
 * \param recibe una bicicleta
 * \param vector tipo
 * \param tama�o vector tipo
 * \param vector color
 * \param tama�o vector color
 * \param vecto clientes
 * \param ta�amo del vector cliente
 * \return
 *
 */
void mostrarBici(eBici x, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamClie);



/** \brief Recibe datos cargados y se lo copia asigna a los capos de la estructura
 *
 * \param recibe estructura bicicleta
 * \param recibe tama�a del vector
 * \param recibe cantidad
 * \return la cantidad que cargue.
 *
 */

int harcodearBicicletas(eBici vec[], int tam, int cant);






/** \brief Modifica el campo que desea el usuario a traves de la seleccion de ID
 *
 * \param vector bicicleta
 * \param tama�o del vector eBici
 * \param vector tipo
 * \param tama�o del vector etipo
 * \param vector colores
 * \param tama�o del vector colores
 * \param vector clientes
 * \param tama�o del vector clientes
 * \return 0 si la modificacion fue exitosa, 1 si hubo error, 2 si se cancelo la modificaci�n
 *
 */

int modificarBicicleta(eBici vec[], int tam,eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamClie);




/** \brief Elimina una bicicleta, mostrara un  mensaje de error si no se encuentra el Id.
 *
 * \param recibe vector bicicleta
 * \param recibe tama�o del vector bicicleta
 * \param recibe vector tipo
 * \param recibe tama�o del vector tipo
 * \param recibe vector color
 * \param recibe tama�o del vector color
 * \param recibe vector clientes
 * \param recibe tama�o del vector clientes
 * \return -1 error, 0 Baja exitosa, 2 cancelacion de baja
 *
 */
int bajaBicicleta(eBici vec[], int tam,eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamClie);




/** \brief ordena las bicicletas por el criterio solicitado (ID y TIPO)
 *
 * \param  recibe vector de bicicletas
 * \param tama�o del vector bicicletas
 * \param criterio de ordenamiento Ascendente
 * \return
 *
 */
int ordenarBicicletas(eBici vec[], int tam, int orden);
