
#include "bicicleta.h"
#include "tipo.h"
#include "servicio.h"
#include "trabajo.h"
#include "color.h"
#include "clientes.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

void informes(eBici vec[], int tam,eColor colores[], int tamC, eTipo tipos[], int tamT, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ, eCliente clientes[], int tamClie);

void informarBicicletasXTipo(eBici vec[], int tam,eColor colores[], int tamC, eTipo tipos[], int tamT, eCliente clientes[], int tamClie);
void informarMayorRodado(eBici vec[], int tam,eColor colores[], int tamC, eTipo tipos[], int tamT, eCliente clientes[], int tamClie);
void mostrarBicicletasXtipo(eBici vec[], int tam,eColor colores[], int tamC, eTipo tipos[], int tamT, eCliente clientes[], int tamClie);
int contartTipoColorBicicleta(eBici vec[], int tam,eColor colores[], int tamC, eTipo tipos[], int tamT, eCliente clientes[], int tamClie);
int colorFavorito(eBici vec[], int tam,eColor colores[], int tamC, eTipo tipos[], int tamT, eCliente clientes[], int tamClie);

int mostrarTrabajosBicicleta(eBici vec[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente cliente[], int tamClie);
int mostrarImporteTotalServicios(eBici vec[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamClie);
int mostrarServicioXfecha(eBici vec[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ);
int InformafechaDeServicios(eBici vec[], int tam, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ);

void informarBicicletasXColor(eBici vec[], int tam,eColor colores[], int tamC, eTipo tipos[], int tamT, eCliente clientes[], int tamClie);

