#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

char leer(char arreglo[]);

char leer2(char arreglo[]);

void marquito();
void gotoxy(int num, int x, int y);

int items(char k[]);

void borrrar();

void texto_posicion(const char texto[], int x, int y);

void gotoxyO(int x,int y);

void coversion(int i, int x, int y);

void arc(char cadena[]);

int keyM();

void lin(char datoo []);

void volver(int x, int y);

void numeros(int i, int x, int y);

int len(char Nombre_de_cadena_de_caracteres[]);

void stringg_read(char tu_array[],char resultado[] ,int indice);

//funcio critica para la libreria
void orgranizar2(int indices[], char texto[]);


int pantalla[24][80];

char ranking[]="ranking";

int d=0;

char datos[1000]="";
char nombres[2000]="";

int main(){


    marquito();
    borrrar();
    leer(datos);
    leer2(nombres);
    

    int m=24, salida=0;
    int indicador=0;
    while (1)
    {    

        if (salida==27)
        {
            break;
        }

        if(indicador==0){

        
            // Muestra de titulo
            for ( int i = 0; i < 8; i++)
            {
                coversion(ranking[i],m,2);
                m+=4;
            }

    // Muestra de puntos 
            int xx=0, yy=0;

            char cadena0[1000]="";
            for (int i = 0; i < items(datos); i++)
            {
            stringg_read(datos,cadena0,i);
                
                for (int j = 0; j <=len(cadena0); j++)
                {
                    numeros(cadena0[j],7+xx,6+yy);
                    xx+=4;
                }
                usleep(90000);
                lin(cadena0);
                xx=0;
                yy+=4;            
                
            }
            //printf("%d",yy);

    // Muestra de nombres

            // variables para que las variables de coordenada incrementen
            int x=0, y=0;
            // se guarda auxiliarmente el nombre para que pueda ser medido e impreso
            char cadena[1000]="";

            // con items cuenta la cantidad de elementos
            for (int i = 0; i < items(nombres); i++)
            {
                // stringg_read lee el contenido
                stringg_read(nombres,cadena,i);

                for (int j = 0; j < len(cadena); j++)
                {   
                    // conversion imprime caracter por caracter cada letra
                    coversion(cadena[j],45+x,6+y);
                    x+=4;
                }
                // lin limpia la cadena de texto para que se utilizable una gran variedad de veces
                usleep(90000);
                lin(cadena);
                // x se iguala a 0 para que la variable no crezca indefinidamente solo hasta la longitd del nombre
                x=0;

                y+=4;
                
            }
            if (y>16)
            {
                usleep(7000);
                volver(5,22+y);
            }
            if (y<=16)
            {
                usleep(7000);
                volver(5,22);
            }


        }
        indicador++;
        
        gotoxyO(70,23);
        salida= keyM();
        setbuf(stdout,NULL);



    }


    return 0;
}

void volver(int x, int y){

texto_posicion("─█▀▀─█▀▀─█▀▀ ",x,y+0);

texto_posicion("─█▀▀─▀▀█─█── ",x,y+1);

texto_posicion("─▀▀▀─▀▀▀─▀▀▀ ",x,y+2);


}


void borrrar(){

    for (int  i = 0; i < 23; i++)
    {
        for (int j = 0; j < 80; j++)
        {
            if (pantalla[i][j]==0)
            {
                //pantalla[i][j]=0;
                gotoxyO(j+1,i+1);
                printf(" ");
                setbuf(stdout,NULL);
    
            }
            if (pantalla[i][j]==1)
            {
                //pantalla[i][j]=0;
                gotoxyO(j+1,i+1);
                printf("┃");//  margen vertical
                setbuf(stdout,NULL);
    
            }
            if (pantalla[i][j]==2)
            {
                //pantalla[i][j]=0;
                gotoxyO(j+1,i+1);
                printf("_");
                setbuf(stdout,NULL);
    
            }
            if (pantalla[i][j]==3)
            {
                //pantalla[i][j]=0;
                gotoxyO(j+1,i+1);
                printf("┃");
                setbuf(stdout,NULL);
    
            }
            if (pantalla[i][j]==4)
            {
                
                gotoxyO(j+1,i+1);
                printf("━");
                setbuf(stdout,NULL);
    
            }
            if (pantalla[i][j]==5)
            {
                
                gotoxyO(j+1,i+1);
                printf("┃");
                setbuf(stdout,NULL);
    
            }
            if (pantalla[i][j]==6)
            {
                
                gotoxyO(j+1,i+1);
                printf("┊");
                setbuf(stdout,NULL);
    
            }
            if (pantalla[i][j]==7)
            {// █
                
                gotoxyO(j+1,i+1);
                printf("┄");
                setbuf(stdout,NULL);
    
            }
            if (pantalla[i][j]==8)
            {// █ ▄
                
                gotoxyO(j+1,i+1);
                printf("█");
                setbuf(stdout,NULL);
    
            }
            if (pantalla[i][j]==9)
            {// █ ▄ ▀
                
                gotoxyO(j+1,i+1);
                printf("▄");
                setbuf(stdout,NULL);
    
            }
            if (pantalla[i][j]==10)
            {// █ ▄ ▀
                
                gotoxyO(j+1,i+1);
                printf("▀");
                setbuf(stdout,NULL);
    
            }
            


            
        }
        
    }
    

}

void marquito(){

   
    
    // Margenes horizontales
    for (int i = 0; i < 80; i++)
    {
        gotoxy(4,i,1);

        gotoxy(4,i,4);
        
       // gotoxy(4,i,24);
        //texto_posicion("━",i,24);
        
    }
    
    // Margenes laterales
    for (int i = 1; i <= 24; i++)
    {
        gotoxy(5,0,i+1);
        // El "1" al inicio equivale a "☀"
        gotoxy(5,79,i+1);
        
    }
    


}

void numeros(int i, int x, int y){

if(i=='.'){

texto_posicion("    ",x,y+0);

texto_posicion("    ",x,y+1);

texto_posicion(" ██ ",x,y+2);
}

if(i=='0'){

texto_posicion(" ███ ",x,y+0);

texto_posicion(" █ █ ",x,y+1);

texto_posicion(" ███ ",x,y+2);
}
if(i=='1'){

texto_posicion(" ██ ",x,y+0);

texto_posicion(" ██ ",x,y+1);

texto_posicion(" ██ ",x,y+2);
}
if(i=='2'){

texto_posicion(" ██ ",x,y+0);

texto_posicion(" ▄█ ",x,y+1);

texto_posicion(" █▄ ",x,y+2);
}
if(i=='3'){

texto_posicion(" ██ ",x,y+0);

texto_posicion(" ▄█ ",x,y+1);

texto_posicion(" ▄█ ",x,y+2);
}
if(i=='4'){

texto_posicion(" █ █ ",x,y+0);

texto_posicion(" █▄█ ",x,y+1);

texto_posicion("   █ ",x,y+2);
}
if(i=='5'){

texto_posicion(" ██ ",x,y+0);

texto_posicion(" █  ",x,y+1);

texto_posicion(" ▄█ ",x,y+2);
}
if(i=='6'){

texto_posicion(" █▀█ ",x,y+0);

texto_posicion(" █▄▄ ",x,y+1);

texto_posicion(" █▄█ ",x,y+2);
}
if(i=='7'){

texto_posicion(" ▀▀█ ",x,y+0);

texto_posicion("   █ ",x,y+1);

texto_posicion("   █ ",x,y+2);
}
if(i=='8'){

texto_posicion(" █▀█ ",x,y+0);

texto_posicion(" █▄█ ",x,y+1);

texto_posicion(" █▄█ ",x,y+2);
}
if(i=='9'){

texto_posicion(" █▀█ ",x,y+0);

texto_posicion(" █▄█ ",x,y+1);

texto_posicion("   █ ",x,y+2);
}
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

char leer(char arreglo[]){
    

    FILE *archivo = fopen("puntos.txt", "r+");
    if (!archivo)
    {
        printf("no se ha encontrado el archivo");
        
    }

    int a=0, aux=0; 
    // Se lee y se guarda los datos traidos del archivo
    while (1)
    {
        a = fgetc(archivo);
        if (a==EOF)
        {
            break;
        }
        
        arreglo[aux]+=a;
        setbuf(stdout,NULL);
        aux++;

        
        
    }
    fclose(archivo);

  

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


void stringg_read(char tu_array[],char resultado[] ,int indice){ //Lista es el resulta de emular un arreglo de estrings
    int array_locale[10000];
    indice++;
    orgranizar2(array_locale,tu_array); 
    setbuf(stdout,NULL); 
    
    int j=0; int d =0;
    if (indice>0){
        j= array_locale[indice-1];
    }
    setbuf(stdout,NULL);
    for (j ; j < array_locale[indice]-1; j++){

          if (tu_array[j]!='|')         // |∮∮|⌈⌈
          {
            resultado[d]=resultado[d]+tu_array[j];
            d++;
          }
    }
    

}


void lin(char datoo []){
    int max = len(datoo);     // max es el numero de elemtos que recibe de "datoo" asi la funcion se adapta con facilidad 
    memset(datoo, 0, max);

}



void texto_posicion(const char texto[], int x, int y){
    setbuf(stdout,NULL);
    gotoxyO(x,y);
    printf("%s",texto);
    setbuf(stdout,NULL);

}

void gotoxyO(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);
}

void gotoxy(int num, int x, int y){

    pantalla[y-1][x]= num;


   
    setbuf(stdout,NULL);

}

int keyM(){


  int c;
  /* configuramos el terminal para que las pulsaciones se envien
     directamente a stdin */
  system ("/bin/stty raw");
  // c=getchar())!= '1' && (c != '2')  && (c !='3') && (c!='0') && (c!='4') && (c!='q' && c!='Q') 
  c=getchar();
        
  system ("/bin/stty cooked");
  return c;

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



