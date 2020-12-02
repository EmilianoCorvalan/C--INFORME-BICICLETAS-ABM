#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[25];
    char sexo;

}eCliente;




#endif // CLIENTES_H_INCLUDED

/** \brief Muestra nombre de cliente
 *
 * \param vector cliente
 * \param tamaño de vector
 * \return
 *
 */

void mostrarCliente(eCliente clientes[], int tam);




/** \brief Recorre el array de clientes y cuando encuentra el Id se lo  copia a  la descripcion Nombre de cliente
 *
 * \param recibe cadena nombre
 * \param recibe id
 * \param  recibe array  de clientes
 * \param tamaño del vector clientes
 * \return 0 todo Ok,  1 si hay error
 *
 */

int cargarNombre(char nombre[], int id,eCliente clientes[],int tam);

int validarIdCliente(eCliente clientes[], int tam, int id);
