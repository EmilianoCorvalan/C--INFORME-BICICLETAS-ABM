#include <stdio.h>
#include <stdlib.h>

#include "fecha.h"
#include "color.h"
#include "tipo.h"
#include "servicio.h"


void mostrarFecha(eFecha fecha)
{

    printf("%02d/%02d/%d\n", fecha.dia, fecha.mes,fecha.anio);

}
