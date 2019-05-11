#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#include "arrayEmpleados.h"

int inicializarArray(char *nombres[]);

int buscarLibre (char lista[][56], int* pIndex, int cantidadPos);

int getString(char *pResult,char *pMsg,char *pMsgError,int min,int max,int intentos);

int validarLetra (char letras[]);

int isValidInt(int numero, int maximo, int minimo);

int getInt(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

int isValidFloat(float numero, float maximo, float minimo);

int getFloat(float *resultado,char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);

int isValidChar(char letra, char maximo, char minimo);

int getChar(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado);

#endif // UTN_H_INCLUDED
