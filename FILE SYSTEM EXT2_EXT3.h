/*
 * Universidad de San Carlos de Guatemala
 * Facultad de Ingenieria
 * Escuela de Ciencias y Sistemas
 * Manejo e implementacion de archivos
 * Seccion A
 * Laboratorio
 * Practica 1
 * 12/06/2016 23:59 hrs
 *
 * Carlos Josue Monterroso Barrios
 * 201314646
 *
 */

/**********************Area de librerias***************************************/
#include <stdio.h>
//atoi
#include <stdlib.h>
//directorios
#include <dirent.h>
//crear directorios
#include <sys/stat.h>
//comparacion de cadenas
#include <string.h>
//time
#include <time.h>
//-----------------------------------------------------------------
/********************Area de variables globales********************************/


/********************Area de Structs*******************************************/
typedef struct
{

    int esnuevonodo;
    char nombre[100];
    char name2[100];
    int contador;
    char nombreparametro[100];
    char parametro[100];
    int size;
    char size2[100];
    char unit;
    char path[100];
    char type;
    char delete_[100];
    char name[100];
    char id[100];
    int add;
    char fit[100];
    char idvector[6];
    int p;

    char count[100];
    int count2;

}Funcion;


/********************Area de Metodos Herramienta*******************************/

//metodo Limpia la Variable
void limpiarvar(char aux[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        aux[i] = '\0';
    }
}

//Verifica si el Char es una LETRA de la A-z
int EsLetra(char caracter)
{
    if((caracter >= 'a' && caracter <= 'z' ) || (caracter >= 'A' && caracter <= 'Z' ))
    {
        return 1;
    }else
    {
        return 0;
    }
}

//retorna 0 si la cadena es numero
int CadenaEsNumero(char entrada[])
{
    int resultado=0;
    int contador=0;
    while(entrada[contador])
    {
        if(EsNumero(entrada[contador])==0)
        {
            resultado++;
        }
        contador++;
    }
    return resultado;
}

//Verifica si el Char es un numero del 0-9
int EsNumero (char caracter2[])
{
    if(caracter2 >= '0' && caracter2 <= '9')
    {
        return 1;
    }else
    {
        return 0;
    }

}
/*******************************************************************************/



/******************************************************************************/
/******************** INICiO De METODOS DEL PROGRAMA **************************/
/******************************************************************************/
//*metodo1
int main (){

    //llena los Arreglos de Las Montadas DE PArticiones
    //llenarletras();

    //inicia El lanzador del programa
    menu_principal();
    //termino el programa
	printf("\n");
	printf("::::::::::::::::::::::::::::::::: \n");
	printf("\n");
	printf("\n");
   	printf("Carlos Monterroso 201314646 \n");
   	printf("\n");
   	printf("Apagando el sistema... \n");
   	printf("\n");
   	printf("\n");
   	printf("::::::::::::::::::::::::::::::::: \n");

    return 0;
}
//*metodo2
void menu_principal (){
    int opcion=1;
    char comando[100];

    while(strcmp(comando,"exit")!=0)
    {
       /***********************************************************************/
       /***************************Menu Principal******************************/
       /***********************************************************************/
        printf("%s\n", "_____________________________________________________");
        printf("                   %s\n", "Sistema de Archivos");
        printf("                   %s\n", " ");
        printf("              %s\n", "LWH (LINUX – WINDOWS Híbrido)");
        printf("%s\n", "_____________________________________________________");
        printf("%s\n", "");
        printf("%s\n", "Ingrese el numero de la opcion");
        printf("%s\n", "1. Ingresar Comando");
        printf("%s\n", "");
        printf(">>>>:~$ ");

        limpiarvar(comando,100);
        scanf(" %[^\n]", comando);

       /*----------------------------------------------------------------------*/

       /***********************************************************************/
       /***********************Seleccion de Opciones****************************/
       /***********************************************************************/

                Interprete(comando);//*************METODO DEL INTERPRETE
                //fgets(comando,100,stdin);
                //LeerComando(comando);


                printf("*******Fin del programa*********\n");

    }

}

void Interprete(char entrada[])
{
    //***************VARIABLES GLOBALES*****************************************
    Funcion nuevafuncion;
    int size=0;
    int unit=0;
    int path=0;
    int type=0;
    int name=0;
    int delete_=0;
    int add=0;
    int fit=0;
    int id=0;
    int numeroparametros=0;
    int barraactiva=0;
    int contador=0;
    int p=0;
    int count=0;
    int contadorParametrosObligatorios=0;
    char instruccion[100];
    limpiarvar(instruccion,100);
    char nombreparametro[100];
    limpiarvar(nombreparametro,100);
    char parametro[100];
    limpiarvar(parametro,100);
    nuevafuncion.count2=0;

    printf(" Ejecutando...\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf( "Se A Ejecutado ----- Interprete:: \"%s\" \n", entrada );

        //*******************INICIO DEL INTERPRETE**********************************
    while(entrada[contador]!=NULL)
    {
        if(entrada[contador]=='#')//------------------------SI es Un Comentario
        {
            printf("Interprete #_ Reconocido COMENTARIO::::::\n");
            while(entrada[contador]!='\n' && entrada[contador]!='\0')
            {
                contador++;
            }
        }
         else if(entrada[contador]==' ')//------------------si es espacio blanco
        {
            printf(":::::Reconocido: ESPACIO::::::\n");
            contador++;

        }else if(EsLetra(entrada[contador])==1){//--------------------SI es letraç

            while(EsLetra(entrada[contador])==1)
            {
                char y1[1];
                y1[0]=entrada[contador];
                strncat(instruccion,y1,1);
                contador++;
            }

            size=0;
            unit=0;
            path=0;
            type=0;
            fit=0;
            delete_=0;
            name=0;
            add=0;
            numeroparametros=0;

            strcpy(nuevafuncion.nombre,instruccion);
            printf("Interprete #_El Nombre de La Instruccion es::= %s\n", nuevafuncion.nombre);

        }else if(entrada[contador]=='\\')//--------------------si es doble barra
        {
            barraactiva=1;
            contador++;
        }else if(entrada[contador]=='-'){//---------------------------si es Guion PARAMETROS OPCIONALES

            /******************************************************************/
            /*                 parametros con y sin comillas                  */
            /******************************************************************/

            contador++;
            while(entrada[contador]!=':')//limite del parametro(-parm:x)
            {
                char y2[1];
                y2[0]=entrada[contador];
                strncat(nombreparametro,y2,1);
                contador++;
            }

            if(entrada[contador]==':'&&entrada[contador+1]==':'){

                 contador=contador+2;
                 int contadorpar=0;
                 while(nombreparametro[contadorpar])
                 {
                     nombreparametro[contadorpar]=tolower(nombreparametro[contadorpar]);
                     contadorpar++;
                 }
                 printf("Interprete #_***********Parametro Reconocido (sin mayusculas)::::= %s\n",nombreparametro);

                 char prueba;

                 if(entrada[contador]!='\"')//si no hay comillas en el contenido del parametro
                 {
                     while(entrada[contador]!=' ' && entrada[contador]!='\n' && entrada[contador]!='#' && entrada[contador]!=NULL)
                     {
                     char y3[1];
                     y3[0]=entrada[contador];
                     strncat(parametro,y3,1);
                     contador++;
                     }

                     printf("**********Contenido Parametro Sin Comillas= %s\n",parametro);
                     char fn[1];
                     fn[0]='\0';
                     strncat(parametro,fn,1);

                 }else //si existieran comillas en el parametro
                 {
                     char y4[1];
                     y4[0]=entrada[contador];
                     strncat(parametro,y4,1);
                     contador++;
                     while(entrada[contador]!='\"') //&& entrada[contador]!=' ' esto se quita si truena
                     {
                     prueba=entrada[contador];
                     //parametro=ConcatenarCadenaCaracter(parametro,entrada[contador]);
                     //char *x4=entrada[contador];
                     char y5[1];
                     y5[0]=entrada[contador];
                     strncat(parametro,y5,1);

                         contador++;
                     }
                     char y6[1];
                     y6[0]=entrada[contador];
                     strncat(parametro,y6,1);
                     contador++;
                     char fn[1];
                     fn[0]='\0';
                     strncat(parametro,fn,1);
                     printf("::::::Contenido de Un Parametro con Comillas = %s\n",parametro);
                 }
            }else{

            printf("Interprete #_ ERROR_1.1 Sintaxis Incorrecta Se Esperaba ':' \n");

            }

            /******************************************************************/
            /*                 Reservadas de Parametros                       */
            /******************************************************************/

            if(!strcmp(nombreparametro,"size"))//---------------si reconoce size
            {
             //VAlida Que el SIZE SEA UN NUMERO y mayor a 0
                size=1;
                if(CadenaEsNumero(parametro)==0)
                {
                    nuevafuncion.size=atoi(parametro);
                    printf("size: %i\n",nuevafuncion.size);

                    limpiarvar(parametro,100);
                    limpiarvar(nombreparametro,100);
                    limpiarvar(parametro,100);
                    limpiarvar(nombreparametro,100);

                }else if(parametro[0]=='-')
                {
                    //parametro++;(aqui se puede cagar esta mierda))
                    if(CadenaEsNumero(parametro)==0)
                    {
                        nuevafuncion.size=atoi(parametro)*-1;
                        printf("size: %i\n",nuevafuncion.size);
                        limpiarvar(parametro,100);
                        limpiarvar(nombreparametro,100);
                    }
                }else{
                    printf("\n\n Interprete #_ ERROR_1.2: Parametro de 'size' Invalido \n\n");
                    size=0;
                }
            }else
            if(!strcmp(nombreparametro,"unit"))//---------------si reconoce unit
            {

            }else
             if(!strcmp(nombreparametro,"path"))//---------------si reconoce path
            {

            }else
            if(!strcmp(nombreparametro,"name"))//------------------reconoce name
            {

            }else
            if(!strcmp(nombreparametro,"type"))//------------------reconoce type
            {

            }else
            if(!strcmp(nombreparametro,"fit"))//--------------------reconoce fit
            {

            }
            if(!strcmp(nombreparametro,"delete"))//--------------reconoce delete
            {

            }else
            if(!strcmp(nombreparametro,"add"))//--------------------reconoce add
            {

            }else{
                printf("\n\n Interprete #_ ERROR_1.4: Parametro Opcional Invalido \n\n");
            }

        }else if(entrada[contador]=='+'){//---------------------------si es Guion PARAMETROS Obligatorios

            /******************************************************************/
            /*                 parametros con y sin comillas                  */
            /******************************************************************/

            contador++;
            while(entrada[contador]!=':')//limite del parametro(-parm:x)
            {
                char y2[1];
                y2[0]=entrada[contador];
                strncat(nombreparametro,y2,1);
                contador++;
            }

            if(entrada[contador]==':'&&entrada[contador+1]==':'){

                 contador=contador+2;
                 int contadorpar=0;
                 while(nombreparametro[contadorpar])
                 {
                     nombreparametro[contadorpar]=tolower(nombreparametro[contadorpar]);
                     contadorpar++;
                 }
                 printf("Interprete #_***********Parametro Reconocido (sin mayusculas)::::= %s\n",nombreparametro);

                 char prueba;

                 if(entrada[contador]!='\"')//si no hay comillas en el contenido del parametro
                 {
                     while(entrada[contador]!=' ' && entrada[contador]!='\n' && entrada[contador]!='#' && entrada[contador]!=NULL)
                     {
                     char y3[1];
                     y3[0]=entrada[contador];
                     strncat(parametro,y3,1);
                     contador++;
                     }

                     printf("**********Contenido Parametro Sin Comillas= %s\n",parametro);
                     char fn[1];
                     fn[0]='\0';
                     strncat(parametro,fn,1);

                 }else //si existieran comillas en el parametro
                 {
                     char y4[1];
                     y4[0]=entrada[contador];
                     strncat(parametro,y4,1);
                     contador++;
                     while(entrada[contador]!='\"') //&& entrada[contador]!=' ' esto se quita si truena
                     {
                     prueba=entrada[contador];
                     //parametro=ConcatenarCadenaCaracter(parametro,entrada[contador]);
                     //char *x4=entrada[contador];
                     char y5[1];
                     y5[0]=entrada[contador];
                     strncat(parametro,y5,1);

                         contador++;
                     }
                     char y6[1];
                     y6[0]=entrada[contador];
                     strncat(parametro,y6,1);
                     contador++;
                     char fn[1];
                     fn[0]='\0';
                     strncat(parametro,fn,1);
                     printf("::::::Contenido de Un Parametro con Comillas = %s\n",parametro);
                 }
            }else{

            printf("Interprete #_ ERROR_1.3 Sintaxis Incorrecta Se Esperaba ':' \n");

            }
            /******************************************************************/
            /*                 Reservadas de Parametros                       */
            /******************************************************************/

            if(!strcmp(nombreparametro,"size"))//---------------si reconoce size
            {

            }else
            if(!strcmp(nombreparametro,"unit"))//---------------si reconoce unit
            {

            }else
             if(!strcmp(nombreparametro,"path"))//---------------si reconoce path
            {

            }else
            if(!strcmp(nombreparametro,"name"))//------------------reconoce name
            {

            }else
            if(!strcmp(nombreparametro,"type"))//------------------reconoce type
            {

            }else
            if(!strcmp(nombreparametro,"fit"))//--------------------reconoce fit
            {

            }else
            if(!strcmp(nombreparametro,"delete"))//--------------reconoce delete
            {

            }else
            if(!strcmp(nombreparametro,"add"))//--------------------reconoce add
            {

            }else{
            printf("\n\n Interprete #_ ERROR_1.5: Parametro obligatorio Invalido \n\n");
            }


        }else{ //--------------------------------------SEGUIR AVANZANDO LA CADENA
            contador++;
        }


    }
    /*////////////////////////////////////////////////////////////////////////*/
    /***********************VALIDAR CRACIONES**********************************
    /*////////////////////////////////////////////////////////////////////////*/


}
