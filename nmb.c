#include <stdio.h>
#include <stdlib.h>
#include "algoritmi2.h"

// Comando de compilacion   gcc -o nmb nmb.c -L/usr/X11R6/lib -lX11 -lXtst  Y  tilix -e ./nmb

char nombre[15]="";

char historial_Name[21000]="";

char finaly[100]="";

char er[2]=" ";

int leer(char nombre[]);

char leer2(char arreglo[]);

void volver(int x, int y);

void coversion(int i, int x, int y);

void texto_posicion(const char texto[], int x, int y);

void error(int x, int y);

int keyM();



int a = 0,b=0, aux=0,x=0, d=0;

int main(){
    cls();
    leer2(historial_Name);

    while(1){

 // SI LA CLAVE FUE INCORRECTA SE LIMPIA
    if (a==11)
    {   cls();
        a=0;
        x=0;
        lin(nombre);
    }

    if (b==127)
    {   cls();
        a=0;
        x=0;
        lin(nombre);
    }
    
    texto_posicion(" █▄░█ █▀█ █▀▄▀█ █▄▄ █▀█ █▀▀",26,6);
    texto_posicion(" █░▀█ █▄█ █░▀░█ █▄█ █▀▄ ██▄",26,7);
    texto_posicion(" ░░░░ ░░░ ░░░░░ ░░░ ░░░ ░░░",26,8);

    texto_posicion("####################################################",16,10);
    texto_posicion("#",16,11);
    texto_posicion("#",67,11);

    texto_posicion("#",16,12);
    texto_posicion("#",67,12);

    texto_posicion("#",16,13);
    texto_posicion("#",67,13);
    
    texto_posicion("####################################################",16,14);

    volver(5,21);

    texto_posicion("",x,26);


    // Captura de clave y muestra de los carcateres escritos
    //imprimir_que_se_escribe();
   
    
    // caso de letras con mas de tres caracteres
    if (aux!=b && d>2 && b>96 && b<123)
    {
       x+=2;
      
       nombre[a]=b;
       d=0;
       
    }


    // caso que sea una letra "I" se hace un espaciado normal
    if (aux!=b && d<3 && b==105 && b!=13 && b>96 && b<123)
    {
       x+=1;
      
       nombre[a]=b;
       d=0;
       a++;
    }

    // Verifico si es una letra "i" para hacer el espaciado correcto
    if (aux!=b && d<3 && b!=105 && b!=13 && b>96 && b<123)
    {
       x+=2;
     
       nombre[a]=b;
       d=0;
       a++;
    }



    // Valido el enter con el nombre
    if (leer(nombre)==1 && b==13 && b!=32)
    {
        write(historial_Name,nombre); // copio nombre en el arreglo finaly
        lin(er);
        er[0]='Q';
        er[1]='Q';

        // Estoy guardando el mensaje de error como que no hubo
        FILE *archivo = fopen("errol.txt", "w");
        fputs(er,archivo);
        fclose(archivo);

        // Se guarda el nombre del usuario
        FILE *archivo1 = fopen("Name.txt", "w");
        fputs(historial_Name,archivo1);
        fclose(archivo1);


        break;
    }

    // Verifico que no se haya lanzado un enter vacio
    if (leer(nombre)==0 && b==13)
    {
        // mensaje de que debe de ingresar su nombre
        error(55,2);
    }

    if (b == 27)
    {   
        lin(er);
        er[0]='1';
        FILE *archivo2 = fopen("errol.txt", "w");
        fputs(er,archivo2);
        fclose(archivo2);
        break;
    }
    
    
   
    aux=b;
    coversion(b,16+x+1,11);
    //printf("%d", b);
    b= keyM();
    

    }
    
   
    
    

    return 0;
}

// este leer es de validacion y no de leer archivo
int leer(char nombre[]){
int retur=0;
 
  if (len(nombre)>2)
  {
    retur =1;
  }
  
  return retur;
    

}

char leer2(char arreglo[]){
    

    FILE *arch = fopen("Name.txt", "r+");
    if (!arch)
    {
        printf("no se ha encontrado el archivo");
        
    }

    int a=0, aux=0; 
    // Se lee y se guarda los datos traidos del archivo
    while (1)
    {
        a = fgetc(arch);
        if (a==EOF)
        {
            break;
        }
        
        arreglo[aux]+=a;
        setbuf(stdout,NULL);
        aux++;

        
        
    }
    fclose(arch);

  

}

void coversion(int i, int x, int y){

if(i=='a'){
d+=5;
texto_posicion(" ▄▀█ ",x,y+0);

texto_posicion(" █▀█ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='b'){
d+=5;
texto_posicion(" █▄▄ ",x,y+0);

texto_posicion(" █▄█ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='c'){
d+=5;
texto_posicion(" █▀▀ ",x,y+0);

texto_posicion(" █▄▄ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='d'){
d+=5;
texto_posicion(" █▀▄ ",x,y+0);

texto_posicion(" █▄▀ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='e'){
d+=5;
texto_posicion(" █▀▀ ",x,y+0);

texto_posicion(" ██▄ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='f'){
d+=5;
texto_posicion(" █▀▀ ",x,y+0);

texto_posicion(" █▀  ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='g'){
d+=5;
texto_posicion(" █▀▀ ",x,y+0);

texto_posicion(" █▄█ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='h'){
d+=5;
texto_posicion(" █░█ ",x,y+0);

texto_posicion(" █▀█ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='i'){
d+=3;
texto_posicion(" █ ",x+1,y+0);

texto_posicion(" █ ",x+1,y+1);

texto_posicion(" ░ ",x+1,y+2);
}
if(i=='j'){
d+=5;
texto_posicion(" ░░█ ",x,y+0);

texto_posicion(" █▄█ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='k'){
d+=5;
texto_posicion(" █▄▀ ",x,y+0);

texto_posicion(" █░█ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='l'){
d+=5;
texto_posicion(" █░░ ",x,y+0);

texto_posicion(" █▄▄ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='m'){
d+=5;
texto_posicion(" █▀▄▀█ ",x,y+0);

texto_posicion(" █░▀░█ ",x,y+1);

texto_posicion(" ░░░░░ ",x,y+2);
}
if(i=='n'){
d+=5;
texto_posicion(" █▄░█ ",x,y+0);

texto_posicion(" █░▀█ ",x,y+1);

texto_posicion(" ░░░░ ",x,y+2);
}
if(i=='o'){
d+=5;
texto_posicion(" █▀█ ",x,y+0);

texto_posicion(" █▄█ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='p'){
d+=5;
texto_posicion(" █▀█ ",x,y+0);

texto_posicion(" █▀▀ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='q'){
d+=5;
texto_posicion(" █▀█ ",x,y+0);

texto_posicion(" ▀▀█ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='r'){
d+=5;
texto_posicion(" █▀█ ",x,y+0);

texto_posicion(" █▀▄ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='s'){
d+=5;
texto_posicion(" █▀ ",x,y+0);

texto_posicion(" ▄█ ",x,y+1);

texto_posicion(" ░░ ",x,y+2);
}
if(i=='t'){
d+=5;
texto_posicion(" ▀█▀ ",x,y+0);

texto_posicion(" ░█░ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='u'){
d+=5;
texto_posicion(" █░█ ",x,y+0);

texto_posicion(" █▄█ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='v'){
d+=5;
texto_posicion(" █░█ ",x,y+0);

texto_posicion(" ▀▄▀ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='w'){
d+=5;
texto_posicion(" █░█░█  ",x,y+0);

texto_posicion(" ▀▄▀▄▀ ",x,y+1);

texto_posicion(" ░░░░░ ",x,y+2);
}
if(i=='x'){
d+=5;
texto_posicion(" ▀▄▀ ",x,y+0);

texto_posicion(" █░█ ",x,y+1);

texto_posicion(" ░░░ ",x,y+2);
}
if(i=='y'){
d+=5;
texto_posicion(" █░█ ",x,y+0);

texto_posicion(" █▄█ ",x,y+1);

texto_posicion(" ░█░ ",x,y+2);
}
if(i=='z'){
d+=3;

texto_posicion(" ▀█ ",x,y+0);

texto_posicion(" █▄ ",x,y+1);

texto_posicion(" ░░ ",x,y+2);
}
}

void texto_posicion(const char texto[], int x, int y){
    setbuf(stdout,NULL);
    gotoxy(x,y);
    printf("%s",texto);
    setbuf(stdout,NULL);

}

void error(int x, int y){


texto_posicion("─█▀▀─█▀▀█─█▀▀█─█▀▀█─█▀▀█ ",x,y+0);

texto_posicion("─█▀▀─█▄▄▀─█▄▄▀─█──█─█▄▄▀ ",x,y+1);

texto_posicion("─▀▀▀─▀─▀▀─▀─▀▀─▀▀▀▀─▀─▀▀ ",x,y+2);

}

void volver(int x, int y){

texto_posicion("─█▀▀─█▀▀─█▀▀ ",x,y+0);

texto_posicion("─█▀▀─▀▀█─█── ",x,y+1);

texto_posicion("─▀▀▀─▀▀▀─▀▀▀ ",x,y+2);


}

int keyM(){
  int c;
  /* configuramos el terminal para que las pulsaciones se envien
     directamente a stdin */
  system ("/bin/stty raw");

  c=getchar();
        
  system ("/bin/stty cooked");
  return c;

}

