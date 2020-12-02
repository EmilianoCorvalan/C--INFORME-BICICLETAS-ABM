#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;  // pk
    char descripcion[20];


} eTipo;


#endif // TIPO_H_INCLUDED


void mostrarTipos(eTipo tipos[], int tam);
int cargarDescripcionTipo(char descripcion[],int id, eTipo tipos[], int tam);
int validarIdTipo(eTipo tipos[], int tam, int id);
