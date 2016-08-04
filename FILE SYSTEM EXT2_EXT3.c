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



char *auxconc;
char *auxconc2;

int ContadorInstrucciones=0;
int ContadorComandosExitosos=0;


int ErrorInterprete=0;
int ErrorComando=0;
int ErrorCrearDisco=0;
int ErrorEliminarDisco=0;
int ErrorCrearParticionPrimaria=0;
int ErrorT=0;


int fin=0;

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

typedef struct
{
    char part_status;
    char part_type;
    char part_fit;
    int part_start;
    int part_size;
    char part_name[16];
    int formateada;

}Particion;

typedef struct
{
    int mbr_tamano;
    char mbr_fecha_creacion[25];
    int mbr_disk_signature;
    Particion particiones[4];
}MbrDisco;


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

char*ConcatenarCadenaCaracter(char* cadena,char caracter)
{
    auxconc=(char*)malloc(1+(strlen(cadena)+1));
    int contador=0;
    while (contador<(strlen(cadena)))
    {
        auxconc[contador]=cadena[contador];
        contador++;
    }
    auxconc[contador]=caracter;
    contador++;

    while(auxconc[contador]!=NULL)
    {
        auxconc[contador]=NULL;
        contador++;
    }
    return auxconc;
}

char* LeerScript(char path[])
{
    char* pathoriginal=path;
    char finalizado[250];
    strcpy(finalizado,"cd /\n");
    if(pathoriginal[0]=='\"')
    {
        pathoriginal++;
        path++;
        int q=0;
        while(path[q]!='\"')
        {
            q++;
        }
        path[q]='\0';
        pathoriginal[q]='\0';
    }
    FILE *archivo;
    char caracter;
    char* cadenafinal="";
    archivo = fopen(path,"r");

    if (archivo == NULL)
    {
        cadenafinal="Archivo No Encontrado en el Directorio";
	printf("\n::::::::::::::::::::::::::::Error_2.1 de apertura del archivo. \n\n");
        ErrorInterprete++;
    }
    else
    {
        printf("\n:::::El contenido del archivo de prueba es:::::: \n\n");
        int n=0;
        char nuevo;
        int contador=0;
        while(feof(archivo)==0){
        fseek(archivo,(sizeof(char)*contador),SEEK_SET);
        fread(&nuevo,sizeof(char),1,archivo);
        cadenafinal=ConcatenarCadenaCaracter(cadenafinal,nuevo);
	contador++;
        }
        fclose(archivo);
    }

    return cadenafinal;
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
        ErrorT=0;
        ErrorInterprete=0;
        ErrorComando=0;
        ErrorCrearDisco=0;
        ErrorEliminarDisco=0;
        ErrorCrearParticionPrimaria=0;

        ContadorInstrucciones=0;
        ContadorComandosExitosos=0;
        fin=0;

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

                ErrorT=ErrorComando+ErrorInterprete+ErrorCrearDisco;
                printf("\n");
                printf("|---------------------------------|\n");
                printf("|(*)Errores Generales:   '%i'      |\n",ErrorT);
                printf("|-Errores Interprete:    '%i'      |\n",ErrorInterprete);
                printf("|-Errores Comando:       '%i'      |\n",ErrorComando);
                printf("|-Errores CrearDisco:    '%i'      |\n",ErrorCrearDisco);
                printf("|-Errores EliminarDisco: '%i'      |\n",ErrorEliminarDisco);
                printf("|-Errores CrearPartPrim: '%i'      |\n",ErrorCrearParticionPrimaria);
                printf("|                                 |\n");
                printf("|+Instrucciones Ejetutadas:  '%i'  |\n",ContadorInstrucciones);
                printf("|+Instrucciones Exitosas  :  '%i'  |\n",ContadorComandosExitosos);
                printf("|---------------------------------|\n");
                printf("\n|*******Fin del programa*********|\n");
                ErrorT=0;
                ErrorInterprete=0;
                ErrorComando=0;
                ErrorCrearDisco=0;
                ErrorEliminarDisco=0;
                ErrorCrearParticionPrimaria=0;

                ContadorInstrucciones=0;
                ContadorComandosExitosos=0;
                fin=0;

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
    printf("****************************INICIO INTERPRETE ****************************\n");
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


            //QUITA MAYusculas--------------------------------------------------
            int contadormay=0;
            while(instruccion[contadormay])
            {
                instruccion[contadormay]=tolower(instruccion[contadormay]);
                contadormay++;
            }


            strcpy(nuevafuncion.nombre,instruccion);
            printf("Interprete #_El Nombre de La Instruccion es::= %s\n", nuevafuncion.nombre);

        }else if(entrada[contador]=='\\')//--------------------si es doble barra
        {
            barraactiva=1;
            printf(":::::Reconocido: CONTINUA EL MISMO COMANDO EN OTRA LINEA ARRIBA EL \\::::::\n");
            contador++;
        }else if(entrada[contador]=='-'){//---------------------------si es Guion PARAMETROS OPCIONALES

            /******************************************************************/
            /*                 parametros con y sin comillas                  */
            /******************************************************************/
            numeroparametros++;
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
            ErrorInterprete++;

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
                    ErrorInterprete++;
                    size=0;
                }
            }else
            if(!strcmp(nombreparametro,"unit"))//---------------si reconoce unit
            {
                unit=1;
                //validacion para reconocer solo 'm' y 'k' como dimencionales
                if(parametro[0]=='m' || parametro[0]=='k' || parametro[0]=='b'||parametro[0]=='M' || parametro[0]=='K' || parametro[0]=='B')
                {
                    nuevafuncion.unit=parametro[0];
                    printf("unit: %c\n",nuevafuncion.unit);
                    limpiarvar(parametro,100);
                    limpiarvar(nombreparametro,100);
                }
                else
                {
                    unit=0;
                    printf("\n\n Interprete #_ ERROR_1.8: Parametro de 'unit' Invalido \n\n");
                    ErrorInterprete++;
                }
            }else
             if(!strcmp(nombreparametro,"path"))//---------------si reconoce path
            {
                //agrega el directorio
                path=1;
                strcpy(nuevafuncion.path,parametro);
                limpiarvar(parametro,100);
                limpiarvar(nombreparametro,100);

            }else
            if(!strcmp(nombreparametro,"name"))//------------------reconoce name
            {
                name=1;
                strcpy(nuevafuncion.name,parametro);
                limpiarvar(parametro,100);
                limpiarvar(nombreparametro,100);
            }else
            if(!strcmp(nombreparametro,"type"))//------------------reconoce type
            {

                type=1;
                if(parametro[0]=='p' || parametro[0]=='e'  || parametro[0]=='l'||parametro[0]=='P' || parametro[0]=='E'  || parametro[0]=='L'){
                    nuevafuncion.type=parametro[0];
                    limpiarvar(parametro,100);
                    limpiarvar(nombreparametro,100);
                }
                else{
                type=0;
                    printf("\n\n Interprete #_ ERROR_3.4: Parametro de 'type' Invalido \n\n");
                    ErrorInterprete++;
                }

            }else
            if(!strcmp(nombreparametro,"fit"))//--------------------reconoce fit
            {

                fit=1;
                if(!strcmp(parametro,"bf") || !strcmp(parametro,"ff") || !strcmp(parametro,"wf")||!strcmp(parametro,"BF") || !strcmp(parametro,"FF") || !strcmp(parametro,"WF")  )
                {
                    strcpy(nuevafuncion.fit,parametro);
                    limpiarvar(parametro,100);
                    limpiarvar(nombreparametro,100);
                }
                else
                {
                    fit=0;
                    printf("\n\n Interprete #_ ERROR: Parametro de 'fit' Invalido \n\n");
                    ErrorInterprete++;
                }

            }else
            if(!strcmp(nombreparametro,"delete"))//--------------reconoce delete
            {

                delete_=1;
                if((!strcmp(parametro,"fast")) || (!strcmp(parametro,"full"))||(!strcmp(parametro,"FULL")) || (!strcmp(parametro,"FAST")) )
                {
                    strcpy(nuevafuncion.delete_,parametro);
                    limpiarvar(parametro,100);
                    limpiarvar(nombreparametro,100);
                }
                else
                {
                    delete_=0;
                    printf("\n\n Interprete #_ ERROR_3.5: Parametro de 'delete' Invalido \n\n");
                    ErrorInterprete++;
                }

            }else
            if(!strcmp(nombreparametro,"add"))//--------------------reconoce add
            {

                add=1;
                if(CadenaEsNumero(parametro)==0)
                {
                    nuevafuncion.add=atoi(parametro);
                    limpiarvar(parametro,100);
                    limpiarvar(nombreparametro,100);
                }
                else if(parametro[0]=='-')
                {
                    if(CadenaEsNumero(parametro)==0)
                    {
                        nuevafuncion.add=atoi(parametro)*-1;
                        limpiarvar(parametro,100);
                        limpiarvar(nombreparametro,100);
                    }
                }
                else{
                    printf("\n\n Interprete #_ ERROR_3.6: Parametro de 'add' Invalido (debe ser numero)\n\n");
                    ErrorInterprete++;
                    add=0;
                }

            }else{
                printf("\n\n Interprete #_ ERROR_1.4: Parametro Opcional Invalido \n\n");
                ErrorInterprete++;
            }

        }else if(entrada[contador]=='+'){//---------------------------si es Guion PARAMETROS Obligatorios

            /******************************************************************/
            /*                 parametros con y sin comillas                  */
            /******************************************************************/
            numeroparametros++;
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
            ErrorInterprete++;

            }
            /******************************************************************/
            /*                 Reservadas de Parametros                       */
            /******************************************************************/

            if(!strcmp(nombreparametro,"size"))//---------------si reconoce size
            {
            //VAlida Que el SIZE SEA UN NUMERO y mayor a 0
                size=2;
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
                    printf("\n\n Interprete #_ ERROR_1.9: Parametro de 'size' Invalido \n\n");
                    ErrorInterprete++;
                    size=0;
                }
            }else
            if(!strcmp(nombreparametro,"unit"))//---------------si reconoce unit
            {
                unit=2;
                //validacion para reconocer solo 'm' y 'k' como dimencionales
                if(parametro[0]=='m' || parametro[0]=='k' || parametro[0]=='b'||parametro[0]=='M' || parametro[0]=='K' || parametro[0]=='B')
                {
                    nuevafuncion.unit=parametro[0];
                    printf("unit: %c\n",nuevafuncion.unit);
                    limpiarvar(parametro,100);
                    limpiarvar(nombreparametro,100);
                }
                else
                {
                    unit=0;
                    printf("\n\n Interprete #_ ERROR_1.7: Parametro de 'unit' Invalido \n\n");
                    ErrorInterprete++;
                }
            }else
             if(!strcmp(nombreparametro,"path"))//---------------si reconoce path
            {
                //agrega el directorio
                path=2;
                strcpy(nuevafuncion.path,parametro);
                limpiarvar(parametro,100);
                limpiarvar(nombreparametro,100);
            }else
            if(!strcmp(nombreparametro,"name"))//------------------reconoce name
            {
                name=2;
                strcpy(nuevafuncion.name,parametro);
                limpiarvar(parametro,100);
                limpiarvar(nombreparametro,100);
            }else
            if(!strcmp(nombreparametro,"type"))//------------------reconoce type
            {

                type=2;
                if(parametro[0]=='p' || parametro[0]=='e'  || parametro[0]=='l'||parametro[0]=='P' || parametro[0]=='E'  || parametro[0]=='L'){
                    nuevafuncion.type=parametro[0];
                    limpiarvar(parametro,100);
                    limpiarvar(nombreparametro,100);
                }
                else{
                type=0;
                    printf("\n\n Interprete #_ ERROR_3.4: Parametro de 'type' Invalido \n\n");
                    ErrorInterprete++;
                }

            }else
            if(!strcmp(nombreparametro,"fit"))//--------------------reconoce fit
            {

                fit=2;
                if(!strcmp(parametro,"bf") || !strcmp(parametro,"ff") || !strcmp(parametro,"wf")||!strcmp(parametro,"BF") || !strcmp(parametro,"FF") || !strcmp(parametro,"WF")  )
                {
                    strcpy(nuevafuncion.fit,parametro);
                    limpiarvar(parametro,100);
                    limpiarvar(nombreparametro,100);
                }
                else
                {
                    fit=0;
                    printf("\n\n Interprete #_ ERROR: Parametro de 'fit' Invalido \n\n");
                    ErrorInterprete++;
                }

            }else
            if(!strcmp(nombreparametro,"delete"))//--------------reconoce delete
            {
                delete_=2;
                if((!strcmp(parametro,"fast")) || (!strcmp(parametro,"full"))||(!strcmp(parametro,"FULL")) || (!strcmp(parametro,"FAST")) )
                {
                    strcpy(nuevafuncion.delete_,parametro);
                    limpiarvar(parametro,100);
                    limpiarvar(nombreparametro,100);
                }
                else
                {
                    delete_=0;
                    printf("\n\n Interprete #_ ERROR_3.5: Parametro de 'delete' Invalido \n\n");
                    ErrorInterprete++;
                }
            }else
            if(!strcmp(nombreparametro,"add"))//--------------------reconoce add
            {

                add=2;
                if(CadenaEsNumero(parametro)==0)
                {
                    nuevafuncion.add=atoi(parametro);
                    limpiarvar(parametro,100);
                    limpiarvar(nombreparametro,100);
                }
                else if(parametro[0]=='-')
                {
                    if(CadenaEsNumero(parametro)==0)
                    {
                        nuevafuncion.add=atoi(parametro)*-1;
                        limpiarvar(parametro,100);
                        limpiarvar(nombreparametro,100);
                    }
                }
                else{
                    printf("\n\n Interprete #_ ERROR_3.6: Parametro de 'add' Invalido (debe ser numero)\n\n");
                    ErrorInterprete++;
                    add=0;
                }

            }else{
            printf("\n\n Interprete #_ ERROR_1.5: Parametro obligatorio Invalido \n\n");
            ErrorInterprete++;
            }


        }else if(entrada[contador]=='\n'){

                contador++;
                printf(":::::Reconocido: SAlto Linea::::::\n");
                if((entrada[contador]=='-'||entrada[contador]=='+')){

                }else{

                    if(ErrorInterprete==0 && fin==0){

                        if(instruccion!=NULL||instruccion[0]!='\0'){

                            if(!strcmp(instruccion,"exec")){//******************EXEC

                                printf("\n-----------------------------------------------------------------------\n");
                                printf("/******************Ejecutando COMANDO...****************************/\n");
                                printf("-----------------------------------------------------------------------\n\n");

                                ContadorInstrucciones++;
                                if(path==1)
                                {
                                    printf("\n\n Ejecutar Script... \n\n");
                                    //--------------------------------------------------------Ejecutar Script
                                    char *f=LeerScript(nuevafuncion.path);
                                    printf("\n\n La Cadena Final es:  %s \n\n",f);

                                   Interprete(f);
                                   limpiarvar(instruccion,100);


                                }else{
                                    printf("\n\nInterprete #_ ERROR_1.6: Ingrese todos los parametros obligatorios de 'exec'\n\n");
                                    ErrorComando++;
                                }
                            //FIN DEL EXEC
                            }else if(!strcmp(instruccion,"mkdisk")){//**********MKDISK

                                printf("\n-----------------------------------------------------------------------\n");
                                printf("/******************Ejecutando COMANDO...****************************/\n");
                                printf("-----------------------------------------------------------------------\n\n");

                                if(unit==0){
                                    printf("Colocando unit Aleatoria...\n");
                                    nuevafuncion.unit='m';
                                }else{

                                    if(nuevafuncion.unit=='b'){
                                        printf("\n\nInterprete #_ ERROR2: Parametros 'mkdisk' Invalidos\n\n");
                                        printf("Recolocando dimencional en MB \n");
                                        nuevafuncion.unit='m';
                                    }else{
                                    }
                                }

                                if(unit==0 && numeroparametros==3   && path==1 && name==1 && size==1)
                                {
                                    printf("Creando disco...\n");
                                    //----------------------------------------------------------CrearArchivo(nuevafuncion);
                                    CrearDisco(nuevafuncion);
                                    limpiarvar(instruccion,100);

                                }
                                else if(unit==2 && numeroparametros==4   && path==1 && name==1 && size==1)
                                {
                                    printf("Creando disco...\n");
                                    //----------------------------------------------------------CrearArchivo(nuevafuncion);
                                    CrearDisco(nuevafuncion);
                                    limpiarvar(instruccion,100);

                                }
                                else
                                {
                                    printf("\n\nInterprete #_ ERROR_2.2: Parametros 'mkdisk' Invalidos\n\n");
                                    ErrorComando++;
                                }

                                ContadorInstrucciones++;
                                limpiarvar(instruccion,100);

                            }//FIN DEL ,MKDISK
                            else if(!strcmp(instruccion,"rmdisk")){//***********RMDISK
                                ContadorInstrucciones++;
                                if(path==1&&numeroparametros==1){

                                    int opcion;
                                    printf("%s\n", "(!)-¿Desea eliminar este Disco?");
                                    printf("%s\n", "1-Si");
                                    printf("%s\n", "2-no");

                                    printf("%s\n", "");
                                    printf(">>>>:~$ ");
                                    scanf("%d",&opcion);

                                    if(opcion>0 && opcion<3){

                                    switch(opcion)
                                    {
                                    case 1:

                                        printf("Eliminando disco...\n");
                                        //------------------------------------------------------EliminarDisco(nuevafuncion);
                                        EliminarDisco(nuevafuncion);
                                        limpiarvar(instruccion,100);

                                    break;
                                    case 2:
                                        printf("*******OPERACION CANCELADA*********\n");
                                    break;
                                    default:
                                        printf("Error FATAL \n");
                                    break;
                                    }
                                    }else
                                    {
                                     opcion=1;
                                     printf(" \n");
                                     printf("%s\n", ">>>> Error De Seleccion <<<< ");

                                    }

                                }else{
                                    printf("\n\nInterprete #_ ERROR_3.1: Parametros 'rmdisk' Invalidos\n\n");
                                    ErrorComando++;
                                }


                            }//FIN DEL RMDISK
                            else if(!strcmp(instruccion,"fdisk")){//------------FDISK

                                printf("\n-----------------------------------------------------------------------\n");
                                printf("/******************Ejecutando COMANDO...****************************/\n");
                                printf("-----------------------------------------------------------------------\n\n");

                                ContadorInstrucciones++;
                                if(path==1 && name==1)
                                {
                                    if(unit==0){
                                        printf("Colocando unit Aleatoria...\n");
                                        nuevafuncion.unit='k';
                                    }
                                    if(type==0){
                                        printf("Colocando type Aleatorio...\n");
                                        nuevafuncion.type='p';
                                    }
                                    if(fit==0){
                                        printf("Colocando fit Aleatorio...\n");
                                        strcpy(nuevafuncion.fit,"wf");
                                    }

                                    if((add==1 && delete_==1)||(add==2 && delete_==2)||(add==1 && delete_==2)||(add==2 && delete_==1))
                                    {
                                        printf("\n\nInterprete #_ ERROR_3.2: Parametros 'fdisk' Invalidos(add y delete estan juntos)\n\n");
                                        ErrorComando++;
                                    }else if(add==2 && delete_==0){//---------AUMENTAR TAMAÑO
                                        printf("Reducir o Aumentar...\n");
                                        //------------------------------------------------------Reducir o Aumentar
                                        limpiarvar(instruccion,100);
                                    }else if(add==0 && delete_==2){//_--------ELIMINAR PARTICION

                                         if(nuevafuncion.type=='p' || nuevafuncion.type=='e'||nuevafuncion.type=='P' || nuevafuncion.type=='E')
                                        {

                                            int opcion;
                                            printf("%s\n", "(!)-¿Desea eliminar esta Particion?");
                                            printf("%s\n", "1-Si");
                                            printf("%s\n", "2-no");

                                            printf("%s\n", "");
                                            printf(">>>>:~$ ");
                                            scanf("%d",&opcion);

                                            if(opcion>0 && opcion<3){

                                                switch(opcion)
                                                {
                                                case 1:
                                                //-----------------------------------------------EliminarParticion(funcion);
                                                printf("Eliminar Particion...\n");
                                                //EliminarParticion(nuevafuncion);
                                                limpiarvar(instruccion,100);
                                                break;
                                                case 2:
                                                    printf("*******OPERACION CANCELADA*********\n");
                                                break;
                                                default:
                                                    printf("Error FATAL \n");
                                                break;
                                                }
                                            }else
                                            {
                                                opcion=1;
                                                printf(" \n");
                                                printf("%s\n", ">>>> Error De Seleccion <<<< ");
                                            }

                                        }
                                        else
                                        {
                                            //--------------------------------------------------EliminarParticionLogica(funcion);
                                            printf("Eliminar Particion Logica...\n");
                                            limpiarvar(instruccion,100);
                                        }

                                    }else if (add==0 && delete_==0 && size==1){//---Crear Particion

                                        if(nuevafuncion.type=='p' ||  nuevafuncion.type=='e'||nuevafuncion.type=='P' ||  nuevafuncion.type=='E')
                                        {
                                            printf("Creando Particion...\n\n");
                                            //--------------------------------------------------CrearParticion(nuevafuncion);
                                            //CrearParticion(nuevafuncion);
                                            limpiarvar(instruccion,100);

                                        }
                                        else
                                        {
                                             printf("Creando Particion Logican...\n");
                                            //--------------------------------------------------CrearParticionLogica(nuevafuncion);
                                             //CrearParticionLogica2(nuevafuncion);
                                             limpiarvar(instruccion,100);

                                        }

                                    }else{
                                        printf("\n\nInterprete #_ ERROR_3.3: Parametros 'fdisk' Invalidos(*)\n\n");
                                        ErrorComando++;

                                    }


                                }else{
                                    printf("\n\nInterprete #_ ERROR_3.2: Parametros Obligatorios del 'fdisk'\n\n");
                                    ErrorComando++;
                                }

                            }//fin del fdisk

                            else{
                                //printf("\n\nInterprete #_ ERROR_3.0: ERROR EN EL COMANDO Invalido\n\n");
                                //ErrorComando++;
                            }

                        }else{
                           printf("\n\n-------------------------------------------------------------No Hay Instruccion\n\n");
                        }
                    }else{
                        printf("\n (*) Errores Encontrados En Interprete : '%i' \n", ErrorInterprete);
                        printf("**************************************************************************\n");
                        printf("***********  Existen Errores En La Sintaxis ******************************\n");
                        printf("**************************************************************************\n\n");
                    }
            }

        }//FIN SALTO DE LINEA
        else{ //--------------------------------------SEGUIR AVANZANDO LA CADENA
            contador++;
        }


    }

    printf("\n (*) Errores Encontrados En Interprete : '%i' \n", ErrorInterprete);
    printf("**************************** FIN INSTRUCCION ******************************\n");



    /*////////////////////////////////////////////////////////////////////////*/
    /***********************VALIDAR CRACIONES**********************************
    /*////////////////////////////////////////////////////////////////////////*/



if(ErrorInterprete==0 && fin==0){

    if(instruccion!=NULL||instruccion[0]!='\0'){

        if(!strcmp(instruccion,"exec")){//**************************************exec

            printf("\n-----------------------------------------------------------------------\n");
            printf("/******************Ejecutando COMANDO...****************************/\n");
            printf("-----------------------------------------------------------------------\n\n");

            ContadorInstrucciones++;
            if(path==1)
            {
                printf("\n\n Ejecutar Script... \n\n");
                //--------------------------------------------------------Ejecutar Script
                char *f=LeerScript(nuevafuncion.path);
                printf("\n\n La Cadena Final es:  %s \n\n",f);

                Interprete(f);
                limpiarvar(instruccion,100);


            }else{
                printf("\n\nInterprete #_ ERROR_1.6: Ingrese todos los parametros obligatorios de 'exec'\n\n");
                ErrorComando++;
            }
        }else if(!strcmp(instruccion,"mkdisk")){//*******************************mkdisk

            printf("\n-----------------------------------------------------------------------\n");
            printf("/******************Ejecutando COMANDO...****************************/\n");
            printf("-----------------------------------------------------------------------\n\n");

            if(unit==0){
                printf("Colocando unit Aleatoria...\n");
                nuevafuncion.unit='m';
            }else{

                if(nuevafuncion.unit=='b'){
                    printf("\n\nInterprete #_ ERROR2: Parametros 'mkdisk' Invalidos\n\n");
                    printf("Recolocando dimencional en MB \n");
                    nuevafuncion.unit='m';
                }else{
                }
            }

            if(unit==0 && numeroparametros==3   && path==1 && name==1 && size==1)
            {
                printf("Creando disco...\n");
                //----------------------------------------------------------CrearArchivo(nuevafuncion);
                CrearDisco(nuevafuncion);
                limpiarvar(instruccion,100);

            }
            else if(unit==2 && numeroparametros==4   && path==1 && name==1 && size==1)
            {
                printf("Creando disco...\n");
                //----------------------------------------------------------CrearArchivo(nuevafuncion);
                CrearDisco(nuevafuncion);
                limpiarvar(instruccion,100);

            }
            else
            {
                printf("\n\nInterprete #_ ERROR_2.2: Parametros 'mkdisk' Invalidos\n\n");
                ErrorComando++;
            }

            ContadorInstrucciones++;
            limpiarvar(instruccion,100);
        }//fin del mkdisk
        else if(!strcmp(instruccion,"rmdisk")){//*******************************rmdisk
            ContadorInstrucciones++;
            if(path==1&&numeroparametros==1){
            int opcion;
            printf("%s\n", "(!)-¿Desea eliminar este Disco?");
            printf("%s\n", "1-Si");
            printf("%s\n", "2-no");

            printf("%s\n", "");
            printf(">>>>:~$ ");
            scanf("%d",&opcion);

            if(opcion>0 && opcion<3){

            switch(opcion)
            {
            case 1:

                printf("Eliminando disco...\n");
                //------------------------------------------------------EliminarDisco(nuevafuncion);
                EliminarDisco(nuevafuncion);
                limpiarvar(instruccion,100);

            break;
            case 2:
                printf("*******OPERACION CANCELADA*********\n");
            break;
            default:
                printf("Error FATAL \n");
            break;
            }
            }else
            {
             opcion=1;
             printf(" \n");
             printf("%s\n", ">>>> Error De Seleccion <<<< ");

            }

        }else{
            printf("\n\nInterprete #_ ERROR_3.1: Parametros 'rmdisk' Invalidos\n\n");
            ErrorComando++;
        }
        }//fin del rmdisk
        else if(!strcmp(instruccion,"fdisk")){//--------------------------------fdisk

            printf("\n-----------------------------------------------------------------------\n");
            printf("/******************Ejecutando COMANDO...****************************/\n");
            printf("-----------------------------------------------------------------------\n\n");

            ContadorInstrucciones++;
            if(path==1 && name==1)
            {
                if(unit==0){
                    printf("Colocando unit Aleatoria...\n");
                    nuevafuncion.unit='k';
                }
                if(type==0){
                    printf("Colocando type Aleatorio...\n");
                    nuevafuncion.type='p';
                }
                if(fit==0){
                    printf("Colocando fit Aleatorio...\n");
                    strcpy(nuevafuncion.fit,"wf");
                }

                if((add==1 && delete_==1)||(add==2 && delete_==2)||(add==1 && delete_==2)||(add==2 && delete_==1))
                {
                    printf("\n\nInterprete #_ ERROR_3.2: Parametros 'fdisk' Invalidos(add y delete estan juntos)\n\n");
                    ErrorComando++;
                }else if(add==2 && delete_==0){//---------AUMENTAR TAMAÑO
                    printf("Reducir o Aumentar...\n");
                    //------------------------------------------------------Reducir o Aumentar
                    limpiarvar(instruccion,100);
                }else if(add==0 && delete_==2){//_--------ELIMINAR PARTICION

                     if(nuevafuncion.type=='p' || nuevafuncion.type=='e'||nuevafuncion.type=='P' || nuevafuncion.type=='E')
                    {

                        int opcion;
                        printf("%s\n", "(!)-¿Desea eliminar esta Particion?");
                        printf("%s\n", "1-Si");
                        printf("%s\n", "2-no");

                        printf("%s\n", "");
                        printf(">>>>:~$ ");
                        scanf("%d",&opcion);

                        if(opcion>0 && opcion<3){

                            switch(opcion)
                            {
                            case 1:
                            //-----------------------------------------------EliminarParticion(funcion);
                            printf("Eliminar Particion...\n");
                            //EliminarParticion(nuevafuncion);
                            limpiarvar(instruccion,100);
                            break;
                            case 2:
                                printf("*******OPERACION CANCELADA*********\n");
                            break;
                            default:
                                printf("Error FATAL \n");
                            break;
                            }
                        }else
                        {
                            opcion=1;
                            printf(" \n");
                            printf("%s\n", ">>>> Error De Seleccion <<<< ");
                        }

                    }
                    else
                    {
                        //--------------------------------------------------EliminarParticionLogica(funcion);
                        printf("Eliminar Particion Logica...\n");
                        limpiarvar(instruccion,100);
                    }

                }else if (add==0 && delete_==0 && size==1){//---Crear Particion

                    if(nuevafuncion.type=='p' ||  nuevafuncion.type=='e'||nuevafuncion.type=='P' ||  nuevafuncion.type=='E')
                    {
                        printf("Creando Particion...\n\n");
                        //--------------------------------------------------CrearParticion(nuevafuncion);
                        //CrearParticion(nuevafuncion);
                        limpiarvar(instruccion,100);

                    }
                    else
                    {
                         printf("Creando Particion Logican...\n");
                        //--------------------------------------------------CrearParticionLogica(nuevafuncion);
                         //CrearParticionLogica2(nuevafuncion);
                         limpiarvar(instruccion,100);

                    }

                }else{
                    printf("\n\nInterprete #_ ERROR_3.3: Parametros 'fdisk' Invalidos(*)\n\n");
                    ErrorComando++;

                }


            }else{
                printf("\n\nInterprete #_ ERROR_3.2: Parametros Obligatorios del 'fdisk'\n\n");
                ErrorComando++;
            }

        }//fin del fdisk
        else{
            //printf("\n\nInterprete #_ ERROR_3.0: ERROR EN EL COMANDO Invalido\n\n");
            //ErrorComando++;
        }

    }else{
       printf("\n\n-------------------------------------------------------------No Hay Instruccion\n\n");
    }
}else{
    printf("\n (*) Errores Encontrados En Interprete : '%i' \n", ErrorInterprete);
    printf("**************************************************************************\n");
    printf("***********  Existen Errores En La Sintaxis ******************************\n");
    printf("**************************************************************************\n\n");
}


}

void CrearDisco(Funcion funcion)
{

    MbrDisco mbr;
    mbr.mbr_tamano=funcion.size;
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
    printf("SYSTEM $_ HORA Creacion: %s\n",output);
    int id=funcion.path;



    //*******************************VErifica la fecha**************************
    int k=0;
    int l=0;
    for(k=0;k<25;k++)
    {
    mbr.mbr_fecha_creacion[l++]=output[k];
    }
    mbr.mbr_disk_signature=id;
    int tamano=0;
    if(funcion.unit=='k'||funcion.unit=='K')
    {
        tamano=funcion.size*1024;
    }
    else
    {
        tamano=funcion.size*(1024*1024);
    }
    //**************************************************************************

    //******************* Quita "comillas" en la path **************************
    char pathauxiliar[100];
    strcpy(pathauxiliar,funcion.path);

    char finalizado[100];
    strcpy(finalizado,"cd /\n");

    if(pathauxiliar[0]=='\"')
    {
        limpiarvar(funcion.path,100);
        int q=1;
        while(pathauxiliar[q]!='\"')
        {
            char c2[1];
            c2[0]=pathauxiliar[q];
            strncat(funcion.path,c2,1);
            q++;
        }

    }
    //**************************************************************************
        //******************* Quita "comillas" al name **************************
    char pathauxiliar2[100];
    strcpy(pathauxiliar2,funcion.name);

    char finalizado2[100];
    strcpy(finalizado2,"cd /\n");
    if(pathauxiliar2[0]=='\"')
    {
        limpiarvar(funcion.name,100);
        int q=1;
        while(pathauxiliar2[q]!='\"')
        {
            char c2[1];
            c2[0]=pathauxiliar2[q];
            strncat(funcion.name,c2,1);
            q++;
        }

    }
    //**************************************************************************



    /**************Verifica el Nombre***************/
    int con1=0;
    int valExtencion=0;
    while(funcion.name[con1]!=NULL){

        if(funcion.name[con1]=='.'){

            if(funcion.name[con1+1]=='d'&&funcion.name[con1+2]=='s'&&funcion.name[con1+3]=='k'){
                valExtencion=1;
            }

        }
        con1++;
    }

    /**********************************************/
    //concatena el nombre con la path
    strcat(funcion.path,funcion.name);

    if(valExtencion==1){
    //**************************************************************************
    //*******Para crear Carpetas en los Directorios si no an sido Creadas*******

        int indice=0;
        char carpeta[100];
        while(funcion.path[indice]!='.')
        {
        if(funcion.path[indice]!='/')
            {
                //carpeta=ConcatenarCadenaCaracter(carpeta,pathoriginal[indice]);
                char c1[1];
                c1[0]=funcion.path[indice];
                strncat(carpeta,c1,1);
            }
            else
            {
                strcat(finalizado,"mkdir ");
                strcat(finalizado,"\"");
                strcat(finalizado,carpeta);
                strcat(finalizado,"\"");
                strcat(finalizado,"\n");
                strcat(finalizado,"cd ");
                strcat(finalizado,"\"");
                strcat(finalizado,carpeta);
                strcat(finalizado,"\"");
                strcat(finalizado,"\n");
                strcat(carpeta,"");
                limpiarvar(carpeta,100);

            }
            indice++;
        }

        printf("\nImprimir el comando q ejecuta en la terminal si el directorio no existe: %s\n",finalizado);

        system(finalizado);

        //**************************************************************************
        //**************************************************************************



        //************Aqui  La lectura y Escritura en el Archivo^*******************
        FILE* archivo= fopen(funcion.path, "ab");
        if (archivo==NULL)
        {
            printf("\n Interprete #_ ERROR_2.3_: Al tratar de Acceder al Archivo \n\n");
            ErrorCrearDisco++;
            //fclose(archivo);
        }
        else
        {
            int fin=(tamano/1024);
            char buffer[1024];
            int i=0;
            for(i=0;i<1024;i++){
            buffer[i]='\0';
            }
            int j=0;
            while(j!=fin){
            fwrite(&buffer,1024 , 1, archivo);
            j++;
            }
            fclose(archivo);
        }
        mbr.mbr_tamano=tamano;
        int i;
        for(i=0;i<4;i++)
        {
        mbr.particiones[i].part_start=-1;
        mbr.particiones[i].part_status='d';
        mbr.particiones[i].part_size=0;
        }

        FILE* file= fopen(funcion.path, "rb+");
        fseek(file,0,SEEK_SET);

        if (file==NULL)
        {
            printf("\n Interprete #_ ERROR_2.4 Al tratar de Acceder al Archivo \n\n");
            ErrorCrearDisco++;
            //fclose(file);
        }
        else
        {
            fwrite(&mbr, sizeof(MbrDisco), 1, file);
            fclose(file);
            printf("********************************************************\n");
            printf("---'DISCO CREADO CON EXITO'--- ^_^ '%s'\n\n",funcion.name);
            printf("********************************************************\n");
            ContadorComandosExitosos++;


        }
    }else{
        printf("\n Interprete #_ ERROR_2.5 ALCrear Disco La extencion No es Correcta \n\n");
        ErrorCrearDisco++;
    }

}

void EliminarDisco(Funcion funcion){


//******************* Quita "comillas" en la path **************************
    char pathauxiliar[100];
    strcpy(pathauxiliar,funcion.path);

    char finalizado[100];
    strcpy(finalizado,"cd /\n");
    if(pathauxiliar[0]=='\"')
    {
        limpiarvar(funcion.path,100);
        int q=1;
        while(pathauxiliar[q]!='\"')
        {
            char c2[1];
            c2[0]=pathauxiliar[q];
            strncat(funcion.path,c2,1);
            q++;
        }

    }
  //**************************************************************************


    FILE *fichero;
    fichero = fopen(funcion.path, "r" );    /* El fichero ha de existir primeramente */
    if(fichero != NULL)
    {
        fclose(fichero);
        if(remove(funcion.path) == 0) {

            printf("************************************************************");
            printf( "---'DISCO ELIMINADO CON EXITO'--%s :S\n\n",funcion.path );
            printf("************************************************************");
            ContadorComandosExitosos++;
        }
        else{
            printf( "\nInterprete #_ ERROR_2.8 El Archivo no pudo ser eliminado...\n" );
            ErrorEliminarDisco++;
        }
    }
    else {
    printf( "Interprete #_ ERROR_2.9_: El archivo no fue encontrado...\n" );
    ErrorEliminarDisco++;
    //fclose(fichero);
    }

}
