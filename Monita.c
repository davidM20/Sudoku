#include <stdio.h>
#include<stdlib.h>
#include "monita.h"
#include <unistd.h>

// La clave es 2202     password

char clave[20]="";

// verifica que lo que ingreso el usuario sea la clave
int validar_clave(char clave[]);

// Muestra en pantalla * a medida que el usuario escribe
void imprimir_que_se_escribe();

// Muestra una animacion de carga
void menu_de_carga();

int a = 0;
int x=54,y=12;

int main(){
    


    while(1){

 // SI LA CLAVE FUE INCORRECTA SE LIMPIA
    if (a>3)
    {
        a=0;
        lin(clave);
    }
    
    cls();
    texto_posicion(" █▀█ ▄▀█ █▀ █▀ █ █ █ █▀█ █▀█ █▀▄",x+25,y+6);
    texto_posicion(" █▀▀ █▀█ ▄█ ▄█ ▀▄▀▄▀ █▄█ █▀▄ █▄▀",x+25,y+7);
    texto_posicion(" ░░░ ░░░ ░░ ░░ ░░░░░ ░░░ ░░░ ░░░",x+25,y+8);

    texto_posicion("#####################################",x+22,y+10);
    texto_posicion("#####################################",x+22,y+13);
    texto_posicion("#                                   #",x+22,y+11);
    texto_posicion("#                                   #",x+22,y+12);


    // Captura de clave y muestra de los carcateres escritos
    imprimir_que_se_escribe();
   
    
    // Verificar que la clave sea correcta
    if (a== 3)
    {
        if (validar_clave(clave)>0)
        {
            menu_de_carga();
            cls();
            system("./usuario");
            break;
        }
        
    }

    // Clave 
    if (clave[a]=='q')
    {
        break;
    }
    

    a++;
   
    

    }
    
    //system()
    
    

    return 0;
}



int validar_clave(char clave[]){

    int respuesta=0;

    if (clave[0]=='2' && clave[1]=='2' &&clave[2]=='0' &&clave[3]=='2')
    {
        respuesta=1;
    }
    
    return respuesta;

}


void imprimir_que_se_escribe(){


 if (clave[0]!='\0')
    {
        texto_posicion("▄ ▄",x+25,y+11);
        texto_posicion("▄▀▄",x+25,y+12);
    }
    
    if (clave[1]!='\0')
    {
        texto_posicion("▄ ▄",x+29,y+11);
        texto_posicion("▄▀▄",x+29,y+12);
    }
    if (clave[2]!='\0')
    {
        texto_posicion("▄ ▄",x+33,y+11);
        texto_posicion("▄▀▄",x+33,y+12);
    }

    clave[a] = clave[a]+keyM();

    if (clave[3]!='\0')
    {
        texto_posicion("▄ ▄",x+37,y+11);
        texto_posicion("▄▀▄",x+37,y+12);
    }





}


void menu_de_carga(){

    cls();
    texto_posicion("█▀▀ ▄▀█ █▀█ █▀▀ ▄▀█ █▄░█ █▀▄ █▀█",x+22,y+8);
    texto_posicion("█▄▄ █▀█ █▀▄ █▄█ █▀█ █░▀█ █▄▀ █▄█",x+22,y+9);

    texto_posicion("░░░░░░░░░░░░░░░░░░░░░░░░",x+25,y+11);
    texto_posicion("░░░░░░░░░░░░░░░░░░░░░░░░",x+25,y+12);
    for (int i = 0; i < 20; i++)
    {
        
        texto_posicion("█",x+i+25,y+11);
        texto_posicion("█",x+i+25,y+12);
        usleep(39000);
    }
    

}