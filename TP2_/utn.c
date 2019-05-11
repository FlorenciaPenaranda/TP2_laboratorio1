#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"

int buscarLibre (char lista[][56], int* pIndex, int cantidadPos)
{
    int i;
    int ret=-1;
    for(i=0; i<cantidadPos; i++)
    {
        printf("%s\n",lista[i]);
        if(lista[i][0]=='\0')
        {
            *pIndex =i;
            ret=0;
            break;
        }
    }
    return ret;
}

int getString(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos)
{
    int ret=-1;
    char arrayAuxiliar[20];
    while(intentos>0)
    {
        printf(pMsg);
        fflush( stdin ); //LIMPIA BUFFER WINDOWS
        //__fpurge(stdin); //LIMPIA BUFFER LINUX
        fgets(arrayAuxiliar,sizeof(arrayAuxiliar),stdin);
        arrayAuxiliar[strlen(arrayAuxiliar)-1] = '\0';
        if( pResult != NULL && strlen(arrayAuxiliar) >= min && strlen(arrayAuxiliar) <= max && validarLetra(arrayAuxiliar)==0)
        {
            strncpy(pResult,arrayAuxiliar,max);
            ret=0;
            break;
        }
        else
        {
            printf(pMsgError);
        }
        intentos--;
    }
    return ret;
}

int validarLetra (char letras[])
{
    int ret=0;
    int i=0;
    int CantidadLetras;
    CantidadLetras=strlen(letras);
    while (i<CantidadLetras && ret==0)
    {
        if (isalpha(letras[i])!=0)
        {
            i++;
        }
        else
        {
            ret=1;
        }
    }
    return ret;
}

int isValidInt(int numero, int maximo, int minimo)
{
    int ret = -1;
    if(numero<=maximo && numero>=minimo)
    {
        ret = 0;

    }
    return ret;
}

int getInt(int *resultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int i;
    int buffer;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos>=0)
    {
        for(i=0; i<=reintentos; i++)
        {
            printf("%s", mensaje);
            scanf("%d",&buffer);
            if(!isValidInt(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("\n %s", mensajeError);
            }
        }
    }
    return retorno;
}

int isValidFloat(float numero, float maximo, float minimo)
{
    if(numero>=minimo && numero<=maximo)
    {
        return 1;
    }
    return 0;
}

int getFloat(float *resultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos)
{
    int retorno = -1;
    float buffer;

    if(mensaje!= NULL && mensajeError != NULL && resultado != NULL && minimo<=maximo && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%f",&buffer);
            if(isValidFloat(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
            reintentos--;
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidChar(char letra, char maximo, char minimo)
{
    if(letra>=minimo && letra<= maximo)
    {
        return 1;
    }
    return 0;
}

int getChar(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado)
{
    int retorno = -1;
    char buffer;
    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && reintentos>=0)
    {
        do
        {
            printf("%s", mensaje);
            fflush( stdin ); //LIMPIA BUFFER WINDOWS
            //__fpurge(stdin); //LIMPIA BUFFER LINUX
            scanf("%c", &buffer);
            if(isValidChar(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
            reintentos--;
        }
        while(reintentos>=0);
    }
    return retorno;
}
