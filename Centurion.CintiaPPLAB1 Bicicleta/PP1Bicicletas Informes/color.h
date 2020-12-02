#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;  // pk
    char nombreColor[20];


} eColor;


#endif // COLOR_H_INCLUDED

void mostrarColores(eColor colores[], int tam);
int validarIdColor(eColor colores[], int tam, int id);
int cargarDescripcionColor(char nombreColor[],int id, eColor colores[], int tam);
