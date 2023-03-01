#ifndef ALGORITMI2_H_INCLUDED
#define ALGORITMI2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Esta funcion retorna un elemento de un arreglo tipo stringg
char *read(char tu_array[],int indice);

// Esta es una dependencia es solo para el uso de la libreria 
void orgranizar2(int array_locale[], char tu_array[]);

// Esta funcion se encarga se limpiar los arreglos de caracteres
void lin(char datoo []);

// Esta funcion enumera los elemtos de un arreglo
int len(char Nombre_de_cadena_de_caracteres[]);

// Se encarga de generar un arrglo stringg apartir de un arraglo normal
void write(char destino[], char palabra[]);

// Enumera los elementos de un arrglo tipo stringg
int items(char k[]);

//Muestra en pantalla un mensaje de salida
void stop();

// para posicionar elementos en la terminal
void gotoxy(int x,int y);



// Limpia pantalla
void cls();



char *read(char tu_array[],int indice){ //Lista es el resulta de emular un arreglo de estrings
    int array_locale[10000];
    static char resultado[10000]="";
    // limpio para que funcione por cada llamada que reciba
    lin(resultado);
    indice++;
    // organizar guarda en array locale un mapa con la disribucion de los elementos en el arreglo
    orgranizar2(array_locale,tu_array); 
    setbuf(stdout,NULL); 
    
    int j=0; int d =0;
    if (indice>0){
        j= array_locale[indice-1];
    }
    setbuf(stdout,NULL);
    for (j ; j < array_locale[indice]; j++){

          if (tu_array[j]!='|')         // |∮∮|⌈⌈
          {
            resultado[d]=resultado[d]+tu_array[j];
            d++;
          }
    }
    char *textt=resultado;

    return textt;
    

}

void orgranizar2(int array_locale[], char tu_array[]){ // Organiza es una funcion para dividir el arrglo char en secciones y asi simular un arrglo de strings
	int i =0;   int auxtt=0;
    int numMax_library= strlen(tu_array);
    setbuf(stdout,NULL);
    for(i ; i <= numMax_library; i++) // Esta funcion segmenta una cadena de char para pasen a ser un string emulado
    {
        if (tu_array[i]=='|'){        
            array_locale[auxtt]= i;
            auxtt++;
        }
    }setbuf(stdout,NULL);

}

void lin(char datoo []){
    int max = len(datoo);     // max es el numero de elemtos que recibe de "datoo" asi la funcion se adapta con facilidad 
    memset(datoo, 0, max);

}

int len(char Nombre_de_cadena_de_caracteres[]){ // len es una funcion para contar el numero de elemtos de una funcion

    int contador=0;     char check;
    int i =0;
        for(i; i < 10000; i++ ){
            check = Nombre_de_cadena_de_caracteres[i];
            if ( check == '\0')
                break;
            contador ++;
        }
        return contador;
}

// Stringg crea un lista de elemetos con un array de entrada 
void write(char destino[], char palabra[]){
    setbuf(stdout,NULL);
    int total = len(palabra);    
    int final= len(destino);
    int i =0;
    if (destino[final-1]!='|')
    {
        destino[final]= destino[final]+'|'; 
    }
    
    
    final= len(destino);         
    
        for (i ; i< total; i++)
        {
        destino[final]= destino[final]+palabra[i];
        final++;
        }
        destino[final]= destino[final]+'|';       //   


}


int items(char k[]){
    int item = len(k);    int numero=0;
    int i=0;
    for (i; i <item; i++)
    {
        if (k[i]=='|')  // |
        {
            numero++;
        }
    }numero--;
    return numero;
    
}

//Muestra en pantalla un mensaje de salida
void stop(){
    printf("\n\n\nPRESS ENTER FOR CONTINUE  ......");
    getchar();
}




void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);
}





void cls(){
    #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}


























































#endif // ALGORITMI2_H_INCLUDED