#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// W:  ⇑

// elec es el elemnto que apunta a los elementos mostrados en pantalla (int elec=0;)
int elec=0;

// Ubica el texto en el lugar deseado
void texto_posicion(const char texto[], int x, int y);

// crea un marco al rededor de la vetana de la terminal
void marquito(const char caracter[]);

// Muestra el menu de opciones
void menu();

// Espara poner los elementos en pantalla
void gotoxy(int x,int y);

// Crea un maquito que indica cual opcion esta siendo apuntada
void seleccion(int e);

// Lee las pulsaciones de teclado
int keyb();

// aqui se ejecutara el juego
void numero(int num, int x, int y);

// leer es para cuendo el usuario 
int leer();

// limpia la pantalla
void cls();

// 0, 1, 2 es la secuencia de activacion

int main(void){
    // ee es la variable que almacena lo tecleado por el usuario
    int ee=0;
    
    // ir hacia abajo
    while(1){

    
        cls();  // se limpia la pantalla 
        menu(); // se muestra las opciones en pantalla
        seleccion(elec);// se muestra en pantalla al elemento al que estamos selecionando

        //printf("%d y %d",ee, elec);
        ee= keyb();  // Caturamos teclado

        // S control de bajada 115= 's'                                   's' en ascii es 115
        if (ee==115 || ee=='S')                                         // ee==115 || ee=='S'
        {
            
            if (elec==3)  elec=-1;                                      // if (elec==3)  elec=-1; 
            
            
            if(elec<3)  elec++;                                         // if(elec<3)  elec++;
            
            menu();                                                     // menu();
            seleccion(elec);                                            // seleccion(elec);
            

        }

        // Control de subir 
        if (ee == 119 || ee == 'W')                                     //  "w" en ascii es 119
        {
            // cuado elec valga 0 significa que esta en el primer elemento
            if (elec==0) elec=4; ee=0;                                  // if (elec==0) elec=4; ee=0;
        
            if (elec <=4) elec--;                                       // if (elec <=4) elec--;
            

            
            menu();                                                     // menu();
            seleccion(elec);                                            // seleccion(elec);

        }

        // Verificando el enter del usuario
        // Caso que se presione el "enter" en la opcion salir          if (ee==13 && elec==2)  '2' es el que le corresponde a opcion salir
        if (ee==13 && elec==2){                                      // if (ee==13 && elec==2) 
            break;
        }

    // si el usuario se encuentra selecionando la segunda opcion (Puntuacion)  se ejecuta esta sentencia '1' corresponde a opcion puntaje
        if (ee==13 && elec==1)                                      // if (ee==13 && elec==1) 
        {
            system("./puntuacion");

        }

        // caso que se presione el "enter" sobre la opcion Jugar
        if (ee==13 && elec==0)                                                          // if (ee==13 && elec==0)
        {
            // animacion de carga
            system("./animacion");                                                      // system("./animacion");
            // cargamos la seccion de nombre
            system("./nmb");
            // cargamos la partida
            system("./nn");

            // Essta seccion es para leer el codigo en el archivo "ur"
            if (leer()=='1')                                                            // if (leer()=='1')
            {
            // elec debe ser 0 para hacer un reinicio de las variables
            // de esta manera se vuele a ejecuatar el nombre y el sudoku
            elec =0;                                                                 // elec =0;
            ee=0;                                                                    // ee=0;
            }

            // se limpia la pantalla

            cls();
            // Volvemos a mostrar el menu
            menu();
            // he indicamos donde quedo el puntero del cursor                                                       seleccion(elec);
            seleccion(elec);                                                                                        // seleccion(elec);
            


        }

        // va la chica
        if (ee==13 && elec ==3)
        {
            // se muestra la chica en bickini
            system("gnome-terminal -- ./Monita");                                                   //gnome-terminal -- ./Monita
        }
    }  
     
    return 0;

}



void texto_posicion(const char texto[], int x, int y){
    setbuf(stdout,NULL);
    gotoxy(x,y);                        // gotoxy(x,y)
    printf("%s",texto);
    setbuf(stdout,NULL);

}

void marquito(const char caracter[]){

// Margen superior
gotoxy(0,1);
for (int i = 0; i < 80; i++)
{
    printf("%s",caracter);
    setbuf(stdout,NULL);
}


// Margenes verticales
for (int i = 0; i < 90; i++)
{
    gotoxy(0,1+i);
    printf("%s",caracter);
    setbuf(stdout,NULL);

    gotoxy(89,1+i);
    printf("%s",caracter);
    setbuf(stdout,NULL);
    

}
// Margen inferior
gotoxy(0,90);
for (int i = 0; i < 80; i++)
{
    printf("%s",caracter);
    setbuf(stdout,NULL);
}



}

void menu(){
    marquito("█");
    texto_posicion("█████████████████████████████████████", 21,3);
    texto_posicion("█─▄▄▄▄█▄─██─▄█▄─▄▄▀█─▄▄─█▄─█─▄█▄─██─▄", 21,4);
    texto_posicion("█▄▄▄▄─██─██─███─██─█─██─██─▄▀███─██─█", 21,5);
    texto_posicion("▀▄▄▄▄▄▀▀▄▄▄▄▀▀▄▄▄▄▀▀▄▄▄▄▀▄▄▀▄▄▀▀▄▄▄▄▀", 21,6);


    // esta parte es importantisima para que se borre el elemento anterior 
    texto_posicion("    ",23,10);

    texto_posicion(" █ █▄ █ █ █▀▀ █ █▀█",30,9);
    texto_posicion(" █ █ ▀█ █ █▄▄ █ █▄█",30,10);
    texto_posicion("                      ",29,11); // esta parte es importantisima para que se borre el elemento anterior 

    // segunda opcion

    // esta parte es importantisima para que se borre el elemento anterior 
    texto_posicion("    ",20,15);
    
    texto_posicion(" █▀█ ▄▀█ █▄ █ █▄▀ █ █▄ █ █▀▀",26,14+0);
    texto_posicion(" █▀▄ █▀█ █ ▀█ █ █ █ █ ▀█ █▄█",26,14+1);
    texto_posicion("                           ",26,14+2); // esta parte es importantisima para que se borre el elemento anterior 
    

//  tercera opciom

    texto_posicion("    ",25,20); // esta parte es importantisima para que se borre el elemento anterior 

    texto_posicion(" █▀ ▄▀█ █   █ █▀█",32,19);
    texto_posicion(" ▄█ █▀█ █▄▄ █ █▀▄",32,20);
    texto_posicion("                  ",32,21);// esta parte es importantisima para que se borre el elemento anterior 



//      cuarta opcion
    texto_posicion("    ",60,21);// esta parte es importantisima para que se borre el elemento anterior 

    texto_posicion(" █▀▀▀█",68,18);
    texto_posicion(" █   █",68,19);
    texto_posicion("███████",68,20);
    texto_posicion("░░░░░░░",68,21);
    texto_posicion("███████",68,22);
    texto_posicion("🗝 ****",68,23);

    
    
}

void seleccion(int e){

    // e = 0 significa la qe se apunta a las letras de inicio
    if (e == 0)                                                                         // if (e == 0)
    {
        /* Iniciar partida */

        // aqui se muestra a que elemento estamos apuntado
        texto_posicion("████",23,10);

        texto_posicion(" █ █▄ █ █ █▀▀ █ █▀█   ",29,9);
        texto_posicion(" █ █░▀█ █ █▄▄ █ █▄█   ",29,10);
        texto_posicion(" ░ ░░░░ ░ ░░░ ░ ░░░   ",29,11);
        


    }

    // e=1 Significa que apunta a ver el puntaje "Ranking"
    if(e==1){

        // aqui se muestra a que elemento estamos apuntado
        texto_posicion("████",20,15);

        texto_posicion(" █▀█ ▄▀█ █▄ █ █▄▀ █ █▄ █ █▀▀ ",25,14+0);
        texto_posicion(" █▀▄ █▀█ █ ▀█ █ █ █ █ ▀█ █▄█ ",25,14+1);
        texto_posicion(" ░░░ ░░░ ░░░░ ░░░ ░ ░░░░ ░░░ ",25,14+2);
    }

    /*  Cambiar el modo de juego */
    if (e==2)
    {
        // aqui se muestra a que elemento estamos apuntado
        texto_posicion("████",25,20);

        texto_posicion("█▀ ▄▀█ █░░ █ █▀█  ",32,19);
        texto_posicion("▄█ █▀█ █▄▄ █ █▀▄  ",32,20);
        texto_posicion("░░ ░░░ ░░░ ░ ░░░  ",32,21);
    }

    if (e==3)
    {

        // aqui se muestra a que elemento estamos apuntado
        texto_posicion("████",60,21);


        texto_posicion(" ░█▀▀▀█ ",67,18);
        texto_posicion(" ░█░░░█ ",67,19);
        texto_posicion("░███████",67,20);
        texto_posicion("░░░░░░░░",67,21);
        texto_posicion("░███████",67,22);
        texto_posicion("🗝 ****",67,23);
    }



}

int keyb(){
  int c;
  /* configuramos el terminal para que las pulsaciones se envien
     directamente a stdin */
  system ("/bin/stty raw");

  c = getchar();
  
  /* Se restaura el modo normal de trabajo de la terminal */
  system ("/bin/stty cooked");
  return c;

}

void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);
}

/*void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);
}*/

void cls(){
    system("clear");
}

int leer(){
    int a=0;
    // Cargamos el dato de "ur.txt" para hacer que se reinicie las variables y que ya no almacene un '1' 
    // si no que en su lugar este una 'q'
    FILE *archivo = fopen("ur.txt", "r+"); 
    if (!archivo)
    {
        printf("no se ha encontrado el archivo"); 
    }
     
    // Se lee y se guarda los datos traidos del archivo   
    a = fgetc(archivo);
    return a;

}


/*void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);
}*/

/*void texto_posicion(const char texto[], int x, int y){
    setbuf(stdout,NULL);
    gotoxy(x,y);                        // gotoxy(x,y)
    printf("%s",texto);
    setbuf(stdout,NULL);

}*/

/*int leer(){
    int a=0;
    // Cargamos el dato de "ur.txt" para hacer que se reinicie las variables y que ya no almacene un '1' 
    // si no que en su lugar este una 'q'
    FILE *archivo = fopen("ur.txt", "r+");
    if (!archivo)
    {
        printf("no se ha encontrado el archivo"); 
    }
     
    // Se lee y se guarda los datos traidos del archivo   
    a = fgetc(archivo);
    return a;

}*/