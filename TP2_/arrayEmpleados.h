#ifndef ARRAYEMPLEADOS_H_INCLUDED
#define ARRAYEMPLEADOS_H_INCLUDED

typedef struct
{   int isEmpty; // lleno=0 ; vacio=1
    int idEmpleado; //autoincremental
    char nombre[50];
    char apellido[50];
    float salario;
    int sector;
}Empleado;


#endif // ARRAYEMPLEADOS_H_INCLUDED

int emp_InicializarArray(Empleado* eEmpleado, int cantidad);
int emp_buscarLibre(Empleado* eEmpleado, int cantidad, int* devuelve);
int emp_altaEmpleado(Empleado* eEmpleado, int cantidad, int posLibre);
void emp_mostrarArray(Empleado* eEmpleado, int cantidad);
int emp_buscarPosicionId(Empleado* eEmpleado, int cantidad, int* empleadoEncontrado);
int emp_buscarPorId (Empleado* eEmpleado, int limite, int idE);
int emp_bajaEmpleado(Empleado* eEmpleado, int cantidad);
int emp_modificar(Empleado* eEmpleado, int limite,char* mensajeError,int intentos);
int emp_ordenarPorId(Empleado* eEmpleado,int limite);
int emp_ordenarPorDoble(Empleado* eEmpleado,int limite);
int emp_promedioSalario (Empleado* eEmpleado, int limite, float *promedioSalarios, float *totalSalarios);
int emp_salariosMayoresAlPromedio (Empleado* eEmpleado, int limite, int* SuperanSalarioPromedio);
