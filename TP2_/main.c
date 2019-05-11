#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmpleados.h"
#include "utn.h"

#define CANT_EMPLEADOS 10
int main()
{
    char seguir='s'; //MENU
    int opcion; //MENU
    int incializarArray;
    int posLibre;
    int flag = 0;
    float auxPromedio;
    float auxSalariosTotales;
    int cantEmpMayorSalarioPromerio;

    /*buffer[strlen(buffer)-1]= "\0" saca el enter que se toma como caracter*/
    Empleado empleados[CANT_EMPLEADOS];
    incializarArray = emp_InicializarArray(empleados, CANT_EMPLEADOS);


    if (incializarArray==0)
    {
        printf("Pantalla inicializadas correctamente\n\n\n");
    }
    while (seguir=='s')
    {
        printf("\t\tMENU");
        printf("\n\n1-ALTAS");
        printf("\n\n2-MODIFICAR");
        printf("\n\n3-BORRAR");
        printf("\n\n4-INFORMAR\n");
        printf("\n\n5-SALIR\n");


        do
        {
            printf("\n\t\tingrese opcion: ");
            scanf("\n%d",&opcion);
            //system("cls"); //limpia la pantalla en windows
            //system("clear"); //limpia pantalla en linux

        }
        while (opcion<1 || opcion>5);

        switch (opcion)
        {
        case 1:
            if(emp_buscarLibre(empleados, CANT_EMPLEADOS, &posLibre)!=0)
            {
                printf("LLENO\n\n");
            }
            else
            {
                switch(emp_altaEmpleado(empleados, CANT_EMPLEADOS, posLibre))
                {
                case 0 :
                    flag = 1;
                    printf("Dato ingresado correctamente\n\n");
                    break;
                case 1:
                    printf("Dato ingresado incorrectamente\n\n");
                    break;
                }
            }
            break;

        case 2:
            if(flag != 0 )
            {
                emp_mostrarArray(empleados, CANT_EMPLEADOS);
                emp_modificar(empleados, CANT_EMPLEADOS, "Error al modificar. Reintente", 2);
            }
            else
            {
                printf("\nSe debe realizar el alta de empleados para poder operar.\n\n");
            }
            break;
        case 3:
            if(flag != 0 )
            {
                emp_bajaEmpleado(empleados, CANT_EMPLEADOS);
            }
            else
            {
                printf("\nSe debe realizar el alta de empleados para poder operar.\n\n");
            }
            break;

        case 4:
            if(flag != 0)
            {
                getInt(&opcion,"\n\n-------MENU INFORMES-------\n\n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector \n2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.  \n\n3.)Salir\nIngrese su opcion: ","\nError",1,2,1);

                switch(opcion)
                {
                case 1:
                    fflush(stdin);
                    emp_ordenarPorDoble(empleados, CANT_EMPLEADOS);
                    emp_mostrarArray(empleados, CANT_EMPLEADOS);
                    break;
                case 2:
                    //
                    emp_promedioSalario(empleados,CANT_EMPLEADOS,&auxPromedio,&auxSalariosTotales);
                    printf("El total de los salarios es: %f y el promedio de los mismos es: %f\n\n", auxSalariosTotales, auxPromedio);
                    emp_salariosMayoresAlPromedio(empleados, CANT_EMPLEADOS, &cantEmpMayorSalarioPromerio);
                    printf("La cantidad de empleados que superan el salario promedio son: %d\n\n", cantEmpMayorSalarioPromerio);
                    break;
                }
            }
            else
            {
                printf("\nSe debe realizar el alta de empleados para poder operar.\n\n");
                break;
            }
            break;
        case 5:
            seguir='n';
            break;
        }
    }
    return 0;
}
