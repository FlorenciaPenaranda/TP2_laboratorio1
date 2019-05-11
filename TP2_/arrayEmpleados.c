#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "arrayEmpleados.h"

static int generarId(void)
{
    static int idE=0;
    return idE++;
}

int emp_InicializarArray(Empleado* eEmpleado, int cantidad)
{
    int ret;
    for (int i=0; i<cantidad; i++)
    {
        eEmpleado[i].isEmpty=1;
        ret=0;
    }
    return ret;
}

int emp_buscarLibre(Empleado* eEmpleado, int cantidad, int* devuelve)
{
    int ret;
    for (int i=0; i<cantidad; i++)
    {
        if (eEmpleado[i].isEmpty==1)
        {
            *devuelve=i;
            ret=0;
            break;
        }
        ret=1;
    }
    return ret;
}

int emp_altaEmpleado(Empleado* eEmpleado, int cantidad, int posLibre)
{
    int ret=-1;
    if (!getString(eEmpleado[posLibre].nombre,"Ingrese un nombre: ","error, vuelva a ingresar\n\n",2,20,2) &&
            !getString(eEmpleado[posLibre].apellido,"Ingrese el apellido:","error, vuelva a intentar\n\n",2,20,2) &&
            !getFloat(&eEmpleado[posLibre].salario,"Ingrese salario: ","error, vuelva a intentar\n\n",0,100000,2) &&
            !getInt(&eEmpleado[posLibre].sector, "Ingrese sector: ", "error, vuelva a intentar\n\n",0,20,2))
    {
        eEmpleado[posLibre].idEmpleado = generarId();
        eEmpleado[posLibre].isEmpty=0;
        ret=0;
    }
    else
    {
        ret=1;
    }
    return ret;
}

int emp_modificar(Empleado* eEmpleado, int limite,char* mensajeError,int intentos)
{
    int ret=-1;
    int auxId;
    int posIdEnc;
    int opcion;

    if(eEmpleado!=NULL && limite>0)
    {
        emp_buscarPosicionId(eEmpleado, limite, &posIdEnc);
        auxId = eEmpleado[posIdEnc].idEmpleado;//valor
        //printf("ID a modificar es: %d\n\n", auxId);
        if(auxId>=0 && posIdEnc!=-1)
        {

            do
            {
                system("cls");
                printf("1- Modificar nombre\n");
                printf("2- Modificar apellido\n");
                printf("3- Modificar salario\n");
                printf("4- Modificar sector\n");
                getInt(&opcion,"\n\nIngrese el campo a modificar: ", "Error. Ingrese una opcion valida",1,4,1);

            }
            while (opcion<1 || opcion>5);
            fflush( stdin ); //LIMPIA BUFFER WINDOWS
            //__fpurge(stdin); //LIMPIA BUFFER LINUX
            switch(opcion)
            {
            case 1:
                if(!getString(eEmpleado[posIdEnc].nombre,"Ingrese un nombre: ","error, ingrese un nombre valido\n\n",2,20,2))
                {
                    ret = 0;
                    printf("\nNombre modificado correctamente.\n\n");
                    break;
                }
                else
                {
                    printf("No se pudo modificar el nombre\n\n");
                    break;
                }
            case 2:
                if(!getString(eEmpleado[posIdEnc].apellido,"Ingrese el apellido:","error, ingrese un apellido valido\n\n",2,20,2))
                {
                    ret = 0;
                    printf("\nApellido modificado correctamente.\n\n");
                    break;
                }
                else
                {
                    printf("No se pudo modificar el apellido\n\n");
                    break;
                }
            case 3:
                if(!getFloat(&eEmpleado[posIdEnc].salario,"Ingrese salario: ","error, ingrese un salario valido\n\n",0,100000,2))
                {
                    ret = 0;
                    printf("\nSalario modificado correctamente.\n\n");
                    break;
                }
                else
                {
                    printf("No se pudo modificar el salario\n\n");
                    break;
                }
            case 4:
                if(!getInt(&eEmpleado[posIdEnc].sector, "Ingrese sector: ", "error, vuelva a intentar\n\n",0,20,2))
                {
                    ret = 0;
                    printf("\nSector modificado correctamente.\n\n");
                    break;
                }
                else
                {
                    printf("No se pudo modificar el salario\n\n");
                    break;
                }
            }
        }
        else
        {
            printf("\n\nNo se encontro el ID!\n");
        }
    }
    return ret;
}

void emp_mostrarArray(Empleado* eEmpleado, int cantidad)
{
    for (int i=0; i<cantidad; i++)
    {
        if(eEmpleado[i].isEmpty==0)
        {
            fflush(stdin);
            printf("ID : %d\n", eEmpleado[i].idEmpleado);
            printf("Nombre: %s\n", eEmpleado[i].nombre);
            printf("Apellido: %s\n", eEmpleado[i].apellido);
            printf("Salario: %f\n", eEmpleado[i].salario);
            printf("Sector: %d\n\n", eEmpleado[i].sector);
        }
        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }
}

int emp_buscarPosicionId(Empleado* eEmpleado, int limite, int* empleadoEncontrado)
{
    int ret=1;
    Empleado auxEmpleado;


    if (getInt(&auxEmpleado.idEmpleado,"ingrese el ID del empleado: ","Vuelva a ingresar",0,20,3)==0)
    {
        //auxEmpleados.nombre=tolower(auxEmpleados.nombre);
        ret=-1;
        for(int i=0; i<limite; i++)
        {
            //empleados[i].nombre=tolower(empleados[i].nombre);
            if (eEmpleado[i].idEmpleado == auxEmpleado.idEmpleado)
            {
                *empleadoEncontrado=i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}

int emp_buscarPorId (Empleado* eEmpleado, int limite, int idE)
{
    int i;
    int ret=-1;
    for(i=0; i<limite; i++)
    {
        if(eEmpleado[i].idEmpleado==idE)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int emp_bajaEmpleado(Empleado* eEmpleado, int cantidad)
{
    int posEmpleado;
    switch (emp_buscarPosicionId(eEmpleado, cantidad,&posEmpleado))
    {
    case 0:
        if (eEmpleado[posEmpleado].isEmpty==0)
        {
            printf("hubo coincidencia\n\n");
            eEmpleado[posEmpleado].isEmpty=1;
            printf("El empleado borrado es: %d\n\n",eEmpleado[posEmpleado].idEmpleado);
        }
        break;
    case 1:
        printf("no se encontro el nombre y no entro al if");
        break;

    default:
        printf("ingreso al if pero no encontro el nombre");
        break;
    }
    return 1;
}

int emp_ordenarPorId(Empleado* eEmpleado,int limite)
{
    int ret= -1;
    int i;
    Empleado aux;
    int flagSwap;
    do
    {
        // RECORRER PARA ORDENAR SOLO LOS isEmpty llenos = 0
        for(i=0; i<limite-1; i++)
        {
            flagSwap =0;
            ret = 1;
            if(eEmpleado[i].idEmpleado > eEmpleado[i+1].idEmpleado)//preg por una entidad
            {
                aux = eEmpleado[i];
                eEmpleado[i] = eEmpleado[i+1];// el swap es de la entidad completa.
                eEmpleado[i+1] = aux;
                flagSwap = 1;
                ret =0;
            }
            /* ELSE if(eEmpleado[i].precio == eEmpleado[i+1].precio)// si son iguales usamos otro criterio como el de abajo
            {
                if(strncmp(eEmpleado[i].nombre, eEmpleado[i+1].nombre,50)>0)
                // ordena por un segundo criterio y podriamos seguir anidando if con distintos criterios.
                    //>0 1 es mayor que 2
                    //<0 1 es menos que 2
                    //=0 1 es igual a 2
                {
                    aux = eEmpleado[i];
                    eEmpleado[i] = eEmpleado[i+1];
                    eEmpleado[i+1] = aux;
                    flagSwap = 1;
                    ret =0;
                }

            }*/
        }
    }
    while(flagSwap);

    return ret;
}

int emp_ordenarPorDoble(Empleado* eEmpleado,int limite)
{
    int ret= -1;
    int i;
    Empleado aux;
    int flagSwap;
    do
    {
        for(i=0; i<limite-1; i++)
        {
            if(eEmpleado[i].isEmpty ==0)
            {
                flagSwap =0;
                ret = 1;
                if(strncmp(eEmpleado[i].apellido, eEmpleado[i+1].apellido,50)>0)//preg por una entidad
                {
                    aux = eEmpleado[i];
                    eEmpleado[i] = eEmpleado[i+1];// el swap es de la entidad completa.
                    eEmpleado[i+1] = aux;
                    flagSwap = 1;
                    ret =0;
                }
                else if(strncmp(eEmpleado[i].apellido, eEmpleado[i+1].apellido,50)==0)// si son iguales usamos otro criterio como el de abajo
                {
                    if(eEmpleado[i].sector > eEmpleado[i+1].sector)

                    {
                        aux = eEmpleado[i];
                        eEmpleado[i] = eEmpleado[i+1];
                        eEmpleado[i+1] = aux;
                        flagSwap = 1;

                    }

                }
                ret =0;
            }
        }

    }
    while(flagSwap);
    return ret;
}

int emp_promedioSalario (Empleado* eEmpleado, int limite, float *promedioSalarios, float *totalSalarios)
{
    int ret = 1;
    float sumaSalarios =0;
    float cantidadSalarios = 0;

    if(eEmpleado != NULL && limite>0)
    {
        for(int i =0; i<limite ; i++)
        {
            if(eEmpleado[i].isEmpty==0)
            {
                sumaSalarios += eEmpleado[i].salario;
                cantidadSalarios ++;

            }

        }
        *totalSalarios = sumaSalarios;
        *promedioSalarios = sumaSalarios / cantidadSalarios;
        ret = 0;
    }
    return ret;
}

int emp_salariosMayoresAlPromedio (Empleado* eEmpleado, int limite, int* SuperanSalarioPromedio)
{
    int ret = 1;
    int contadorAux =0;
    float auxTotal;
    float auxpromedio;

    emp_promedioSalario(eEmpleado, limite, &auxpromedio, &auxTotal);

    if(eEmpleado != NULL && limite>0)
    {
        for(int i =0; i<limite ; i++)
        {
            if(eEmpleado[i].isEmpty==0)
            {
                if(eEmpleado[i].salario > auxpromedio)
                {
                    contadorAux++;
                }

            }

        }
        *SuperanSalarioPromedio = contadorAux;
        ret = 0;
    }
    return ret;
}
