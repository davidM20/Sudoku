#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int pantalla[34][100];


int seguimiento[300][200];

float puntaje=0;  // 12,5 debe ser la suma


int matriz[16]={0,2,1,0,4,0,0,3,4,0,0,1,0,2,3,0};
int correto[16]={3,2,1,4,4,1,2,3,4,3,2,1,1,2,3,4};
char respuesta[16]="3214412343211234";


char aux[10]="";

// acumula el timpo de espera para que se active cada recuadro
int times[16]={0};

char historial_puntos[1000]="";

// 
char datos[10]="";

// cuenta los errores acumulados
int canti_error=0;


// value guarda los valores de los recuadros que fueron escritos para permitir que se pueda redescribir
int value[16]={0};

// es literalmente un cursor
void cursor(int x, int y);

// compara el resultado con lo que respondio el usuario
int verificar_resp(int partida[],int respuesta[]);

// Muestra el cuadro de partida ganada
int victoria();

// lee un elemento externo 
char leer(char arreglo[]);

// Comando de compilacion   : gcc -o nn nn.c -L/usr/X11R6/lib -lX11 -lXtst  y tilix -e ./nn

// Borrra solo los elementos que no se encuentren en el segundo buffers
void borrrar(int x, int y);

// escucha los que el usuario teclea
int keyb();

// crea el borde en la matriz
void marquito();

// es un goto pero que se comporta como segundo buffer
void gotoxy(int num, int x, int y);

// Imprime en pantalla el numero pero mas grande
void numero(int num, int x, int y);

// es un goto normal para ubicar en pantalla los mensajes
void gotoxyO(int x,int y);

// muestra los numero que corresponden al partida
void juego();

// esta funcion permite al usuario responder o retractar la respuesta
int recuadro_respues();

// Ubica el texto en la coordenada usando gotoxyO
void texto_posicion(const char texto[], int x, int y);

//  Crea las divisiones del sudoku
void recuadro();

// captura las coordenadas del mouse
void coords(Display *display, int *x, int *y);

// Crea un archivo externo que comunica los datos con el resto del sistema
void arc(char cadena[]);

// Mide el tiempo en reacion a la posicion del cursor y en base a eso muestra el mensaje para rellenar el sudoku
void partidas(int matriz[], int x ,int y );

// Muestra la pantalla de partida perdida
int game_over();

// escribe los datos de una manera clara y entendible usando "|" para separar los elementos
void writee(char destino[], char palabra[]);

// lee el contenido de un archivo externo
char leer2(char arreglo[]);

// activate es una variable que cuenta el tiempo transcurrido que lleva el cursor sobre la opcion confirmar partida
int activate=0;

// cuenta los elementos en un array char
int len(char Nombre_de_cadena_de_caracteres[]);

// ES EL AUXILIAR PARA BORRAR CUANDO EL CURSOR RECORRA MAS DE DOS NUMEOROS EN LA COORDENADA
void borrrar1();

void juego_aleatorio(int matriz[], int respuesta[], char respuestaa[]);

// cada de utiliza para medir el tiempo 
int cada=0;

// aqui se guardan las coordenadas del cursor
int x=0, y=0;

// Son un registro de las coordenadas del cursor para evaluar el momento adecuado para borrrar pantalla
int aux_x=0, aux_y=0; 

int main(){
    system("clear");
    leer(datos);
    leer2(historial_puntos);

    juego_aleatorio(matriz,correto,respuesta)   ;

    int i=0,j=0, periodo=0, selec=0, tiempo=0;
    Display *display;
    int valor;

    display = XOpenDisplay(NULL);

    if (datos[0]!='1')
    {
    
        recuadro();
        marquito();
        juego();
        //borrrar1();
        
        
        
        while (cada !='1')
        {
            
            coords(display,&x,&y);
            x = (x/10)-59;
            y = (y/24)-14;




            // Verificamos que el cuadro este dentro de la terminal    
            if (x>=1 && x<77 && y>1 && y<24)
            {
                
                // se hace la comparacion 
                if(x>aux_x+2 || x<aux_x-2 || y>aux_y+2 || y<aux_y-2 ) { borrrar1(); marquito();}
            
                aux_x =x;
                aux_y =y;
                
                //marquito();
                //system("clear");
                juego();
                partidas(matriz,x,y);
                borrrar(x,y);

                usleep(16600); // El tiempo esta ajustado para los 60Hz

                
                //partidas(matriz,x,y);

                if ((x>71 && x<79) && (y>5 && y <=7) && activate>20)
                {
                    int resp=0, apun=0;
                    // apun es una variables que indica a que elemeto estamos senalando sea "s" o "n"
                    // respuesta es lo que descide el usuario

                    while (1)
                    {

                    texto_posicion("  ___________________________________________  ",18,7);
                    texto_posicion("  ┃                                         ┃  ",18,8);
                    texto_posicion("  ┃  █▀▀ █▀█ █▄░█ █▀▀ █ █▀█ █▀▄▀█ ▄▀█ █▀█   ┃  ",18,9);
                    texto_posicion("  ┃  █▄▄ █▄█ █░▀█ █▀░ █ █▀▄ █░▀░█ █▀█ █▀▄   ┃  ",18,10);
                    texto_posicion("  ┃  ░░░ ░░░ ░░░░ ░░░ ░ ░░░ ░░░░░ ░░░ ░░░   ┃  ",18,11);
                    texto_posicion("  ┃                                         ┃  ",18,12);
                    texto_posicion("  ┃                                         ┃  ",18,13);
                    texto_posicion("  ┃                                         ┃  ",18,14);
                    texto_posicion("  ┃                                         ┃  ",18,15);
                    texto_posicion("  ┃_________________________________________┃  ",18,16);
                    texto_posicion("  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░   ",18,17);

                    texto_posicion("█▀▀",29,13);
                    texto_posicion("▄▄█",29,14);
                    texto_posicion("   ",29,15);

                    texto_posicion("█▄ █",47,13);
                    texto_posicion("█ ▀█",47,14);
                    texto_posicion("    ",47,15);

                    // Marcar la opcion 
                    if (apun==0)
                    {
                        texto_posicion("█▄ █",47,13);
                        texto_posicion("█ ▀█",47,14);
                        texto_posicion("░░░░",47,15);
                        
                    }
                    if (apun==1)
                    {
                        texto_posicion("█▀▀",29,13);
                        texto_posicion("▄▄█",29,14);
                        texto_posicion("░░░",29,15);
                    }


                    //printf("%d",cada);
                    resp = keyb();

                    // ir hacia la izquierda
                    if (resp =='a')
                    {
                        if(apun==0) apun++;

                        if(apun>1)  apun--;

                    }

                
                    // ir hacia la derecha
                    if (resp=='d')
                    {
                        if (apun==1) apun--;

                        if(apun<0) apun++; 
                                
                        
                    }

                    
                    activate=0;

                    // Cado que no desee salir
                    if (resp==13 && apun==0)
                    {
                        break;
                    }
                    // Validar si el usuario gano
                    if (resp==13 && apun==1)

                    {   int acumE=verificar_resp(matriz,correto);

                        if (acumE==0)
                        {
                            victoria();
                            puntaje=100;
                            usleep(900000);
                            cada='1';
                            break;
                        }
                        
                        
                        
                        if (acumE>0)
                        {
                            puntaje=100;
                            puntaje= puntaje-12.5*acumE;
                            cada='1';
                            game_over();
                            usleep(900000);
                            break;
                        }
                        
                        
                    }
                }

            }
                
                if ((x>71 && x<79) && (y>5 && y <=7)){
                    activate++;
                }

    //          Cuando el cursor este sobre la "X" de la esquina se le da la opcion de salir de la parida
                if ((x>= 73 && x<=79) && (y>=2 && y<=4) && periodo > 20 )
                {
                    while (1)
                    {

                    texto_posicion("  ___________________________________________  ",18,7);
                    texto_posicion("  ┃                                         ┃  ",18,8);
                    texto_posicion("  ┃           █▀ ▄▀█ █░░ █ █▀█ ▄▀▀▄         ┃  ",18,9);
                    texto_posicion("  ┃           ▄█ █▀█ █▄▄ █ █▀▄   ▀          ┃  ",18,10);
                    texto_posicion("  ┃           ░░ ░░░ ░░░ ░ ░░░   ▀          ┃  ",18,11);
                    texto_posicion("  ┃                                         ┃  ",18,12);
                    texto_posicion("  ┃                                         ┃  ",18,13);
                    texto_posicion("  ┃                                         ┃  ",18,14);
                    texto_posicion("  ┃                                         ┃  ",18,15);
                    texto_posicion("  ┃_________________________________________┃  ",18,16);
                    texto_posicion("  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░   ",18,17);

                    texto_posicion("█▀▀",29,13);
                    texto_posicion("▄▄█",29,14);
                    texto_posicion("   ",29,15);

                    texto_posicion("█▄ █",47,13);
                    texto_posicion("█ ▀█",47,14);
                    texto_posicion("    ",47,15);

                    // Marcar la opcion 
                    if (selec==0)
                    {
                        texto_posicion("█▄ █",47,13);
                        texto_posicion("█ ▀█",47,14);
                        texto_posicion("░░░░",47,15);
                        
                    }
                    if (selec==1)
                    {
                        texto_posicion("█▀▀",29,13);
                        texto_posicion("▄▄█",29,14);
                        texto_posicion("░░░",29,15);
                    }


                    //printf("%d",cada);
                    cada = keyb();

                    // ir hacia la izquierda
                    if (cada =='a')
                    {
                        if(selec==0) selec++;

                        if(selec>1)  selec--;

                    }

                
                    // ir hacia la derecha
                    if (cada=='d')
                    {
                        if (selec==1) selec--;

                        if(selec<0) selec++; 
                                
                        
                    }

                    


                    // Cado que no desee salir
                    if (cada==13 && selec==0)
                    {
                        break;
                    }
                    // caso que desee abandonar la partida
                    if (cada==13 && selec==1)
                    {
                        cada='1';
                        break;
                    }

                    periodo=0;

                    }
                        
                }
            
                periodo++;
                
            
                

            }// AQUI TERNINA EL IF QUE SE ASEGURA QUE EL CURSOR ESTE DENTRO DEL RANGO ADECUADO

            if(x<1 || x>79 || y<0 || y>24){
                    
            usleep(100000);
            }   
        


        }// AQUI TERMINA EL WHILE
        arc("1");
            
        XCloseDisplay(display);


    }

    // Guardo el ppuntaje que se haya alcanzado
    FILE *puntos= fopen("puntos.txt","w");

    // Arreglo auxiliar
    char punt[6]="";
    
    // Convertimos los puntos de float a cadena de caracteres
    gcvt(puntaje,4,punt);// hago la conversion de float a cadena de texto

    // concateno un espacion en blanco
    punt[len(punt)]+=' ';

    // creamos un arreglo
    writee(historial_puntos,punt);

    // se guarda 
    fputs(historial_puntos,puntos);

    // cierre de proceso
    fclose(puntos);

    
    return 0;
}

// lee el array pantalla e interpreta los "0" como los elementos que debe borrrar
void borrrar(int x, int y){

    int fact_x =2;
    int fact_y =2;

    for (int  i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cursor(x,y);
            if (pantalla[i+y-fact_y][j+x-fact_x]==0  ) 
            {
                
                gotoxyO(j+x-fact_x  ,i+y-fact_y+1  );
                printf(" ");
                setbuf(stdout,NULL);
    
            }
            if (pantalla[i+y-fact_x][j+x-fact_y]==1)
            {
    
                gotoxyO(j+x-fact_x ,i+y+1-fact_y );
                printf("┃");//  margen vertical
                setbuf(stdout,NULL);
   
            }
            if (pantalla[i+y-fact_y][j+x-fact_x]==2)
            {

               
                gotoxyO(j+x-fact_x ,i+y+1-fact_y );
                printf("_");
                setbuf(stdout,NULL);
                    
               
                //cursor(x,y);
                

    
            }
            if (pantalla[i+y-fact_y][j+x-fact_x]==3 )
            {
                
            
                gotoxyO(j+x-fact_x ,i+y+1-fact_y );
                printf("┃");
                setbuf(stdout,NULL);
                    
               // cursor(x,y);
                

    
            }
            if (pantalla[i+y-fact_y][j+x-fact_x]==4 )
            {
                
                    gotoxyO(j+x-fact_x ,i+y+1-fact_y );
                    printf("━");
                    setbuf(stdout,NULL);

                //cursor(x,y);
                
    
            }
            if (pantalla[i+y-fact_y][j+x-fact_x]==5 )
            {

                    gotoxyO(j+x-fact_x ,i+y+1-fact_y );
                    printf("┃");
                    setbuf(stdout,NULL);
                //cursor(x,y);
    
            }
            if (pantalla[i+y-fact_y][j+x-fact_x]==6 )
            {

                gotoxyO(j+x-fact_x ,i+y+1-fact_y );
                printf("┊");
                setbuf(stdout,NULL);
                //cursor(x,y);
    
            }
            if (pantalla[i+y-fact_y][j+x-fact_x]==7 )
            {// █
                

                gotoxyO(j+x-fact_x ,i+y+1-fact_y );
                printf("┄");
                setbuf(stdout,NULL);
                //cursor(x,y);
    
            }
            if (pantalla[i+y-fact_y][j+x-fact_x]==8 )
            {// █ ▄

                gotoxyO(j+x-fact_x ,i+y-fact_y+1 );
                printf("█");
                setbuf(stdout,NULL);
                //cursor(x,y);
            }
            if (pantalla[i+y-fact_y][j+x-fact_x]==9 )
            {// █ ▄ ▀
                
                gotoxyO(j+x-fact_x ,i+y-fact_y+1 );
                printf("▄");
                setbuf(stdout,NULL);

                //cursor(x,y);
    
            }
            if (pantalla[i+y-fact_y][j+x-fact_x]==10 )
            {// █ ▄ ▀
                

                gotoxyO(j+x-fact_x ,i+y-fact_y+1 );
                printf("▀");
                setbuf(stdout,NULL);
                //cursor(x,y);
    
            }



        }//usleep(1000);
        
    }
    

}

void borrrar1(){

    for (int  i = 0; i < 24; i++)
    {
        for (int j = 2; j < 80; j++)
        {
            cursor(x,y);
            if (pantalla[i][j]==0  ) 
            {
                
                gotoxyO(j,i+1);
                printf(" ");
                setbuf(stdout,NULL);
    
            }
            if (pantalla[i][j]==1)
            {
    
                gotoxyO(j,i+1);
                printf("┃");//  margen vertical
   
            }
            if (pantalla[i][j]==2)
            {

               
                gotoxyO(j,i+1);
                printf("_");
                    
               
                //cursor(x,y);
                

    
            }
            if (pantalla[i][j]==3 )
            {
                
            
                gotoxyO(j,i+1);
                printf("┃");
                    
               // cursor(x,y);
                

    
            }
            if (pantalla[i][j]==4 )
            {
                
                    gotoxyO(j,i+1);
                    printf("━");

                //cursor(x,y);
                
    
            }
            if (pantalla[i][j]==5 )
            {

                    gotoxyO(j,i+1);
                    printf("┃");
                    setbuf(stdout,NULL);
                //cursor(x,y);
    
            }
            if (pantalla[i][j]==6 )
            {

                gotoxyO(j,i+1);
                printf("┊");
                setbuf(stdout,NULL);
                //cursor(x,y);
    
            }
            if (pantalla[i][j]==7 )
            {// █
                

                gotoxyO(j,i+1);
                printf("┄");
                setbuf(stdout,NULL);
                //cursor(x,y);
    
            }
            if (pantalla[i][j]==8 )
            {// █ ▄

                gotoxyO(j,i+1);
                printf("█");
                setbuf(stdout,NULL);
                //cursor(x,y);
            }
            if (pantalla[i][j]==9 )
            {// █ ▄ ▀
                
                gotoxyO(j,i+1);
                printf("▄");
                setbuf(stdout,NULL);

                //cursor(x,y);
    
            }
            if (pantalla[i][j]==10 )
            {// █ ▄ ▀
                

                gotoxyO(j,i+1);
                printf("▀");
                setbuf(stdout,NULL);
                //cursor(x,y);
    
            }



        }//usleep(1000);
        
    }
    

}

// crea un segundo mapa x,y deonde se cargan los elementos que no se desean borrar
void gotoxy(int num, int x, int y){

    pantalla[y-1][x]= num;   
    setbuf(stdout,NULL);

}

void cursor(int x, int y){
    texto_posicion("▄█▀",x,y);
    texto_posicion("▀ ▀▄",x,y+1);
}

// es una funcion gotoxy normal
void gotoxyO(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);
}

// Ubica el texto en pantala usando las coordenadas x,y
void texto_posicion(const char texto[], int x, int y){
    setbuf(stdout,NULL);
    gotoxyO(x,y);
    printf("%s",texto);
    setbuf(stdout,NULL);

}

// retorna el valor digiado por el usuario al a hora de dar su respuesta
int recuadro_respues(){

    int valor=0;
    int elec=1;

    char aux[4]="";

    while (1)
    {
                texto_posicion("  ___________________________________________  ",18,7);
                texto_posicion("  ┃                                         ┃  ",18,8);
                texto_posicion("  ┃   █▀█ █▀▀ █▀ █▀█ █░█ █▀▀ █▀ ▀█▀ ▄▀█  ▀  ┃  ",18,9);
                texto_posicion("  ┃   █▀▄ ██▄ ▄█ █▀▀ █▄█ ██▄ ▄█ ░█░ █▀█  ▄  ┃  ",18,10);
                texto_posicion("  ┃   ░░░ ░░░ ░░ ░░░ ░░░ ░░░ ░░ ░░░ ░░░     ┃  ",18,11);
                texto_posicion("  ┃                                         ┃  ",18,12);
                texto_posicion("  ┃                                         ┃  ",18,13);
                texto_posicion("  ┃                                         ┃  ",18,14);
                texto_posicion("  ┃                                         ┃  ",18,15);
                texto_posicion("  ┃_________________________________________┃  ",18,16);
                texto_posicion("  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░   ",18,17);


                texto_posicion("┃⬛️  ⬛️┃",24,13);
                texto_posicion("┃  ⬛️  ┃",24,14);
                texto_posicion("┃⬛️  ⬛️┃",24,15);

                texto_posicion("_________________",36,12);
                texto_posicion("┃                ┃",36,13);
                texto_posicion("┃                ┃",36,14);
                texto_posicion("┃________________┃",36,15);

                 // Mostrar lo selecionado

                if (elec==0)
                {
                    texto_posicion("┃🟥  🟥┃",24,13);
                    texto_posicion("┃  🟥  ┃",24,14);
                    texto_posicion("┃🟥  🟥┃",24,15);
                }

                if (elec==1)
                {
                    texto_posicion("_________________",36,12);
                    texto_posicion("┃░░░             ┃",36,13);
                    texto_posicion("┃░░░             ┃",36,14);
                    texto_posicion("┃░░░_____________┃",36,15);
                }

                

                valor = keyb();

                
//              Mover el cursor hacia la derecha
                if (valor == 'd' && elec <2)
                {
                    elec++;
                }
//              Mover el cursor hacia la izquierda
                if (valor =='a'&& elec >0)
                {
                    elec--;
                }

                        

                 // Si el usuario teclea enter y el puntero apunta a la opcion de salir entonces se sale del bucle
                if (valor == 13 && elec==0)
                {
                    system("clear");
                    recuadro();
                    marquito();
                    recuadro();
                    juego();
                    break;
                }


                if (elec==1)  
                {
                    if (valor=='1' || valor=='2' || valor=='3' || valor =='4')
                    {
                        aux[0]=valor;
                        system("clear");
                        recuadro();
                        marquito();
                        recuadro();
                        juego();
                        break;
                    }
                   
                }

            

    }return (int)atoi(aux);

    
}

// escucha de las pulsaciones del teclado
int keyb(){
  int c;
  /* configuramos el terminal para que las pulsaciones se envien  directamente a stdin  "/bin/stty raw"   */
  system ("/bin/stty raw");
  c=getchar();
/* Se restaura el modo normal de trabajo de la terminal   "/bin/stty cooked"  */
  system ("/bin/stty cooked");
  
  return c;

}

// le das un numro y te imprime el correspondiente en caracteres ascii
void numero(int num, int x, int y){

    if (num==1 || num ==49)
    {
        texto_posicion("▄█ ",x,y);
        texto_posicion(" █ ",x,y+1);
        texto_posicion(" █ ",x,y+2);
        // Traducido para que el el programa lo entienda
        gotoxy(9,x,y);gotoxy(8,x+1,y);gotoxy(0,x+2,y);

        gotoxy(0,x,y+1);gotoxy(8,x+1,y+1);gotoxy(0,x+2,y+1);

        gotoxy(0,x,y+2);gotoxy(8,x+1,y+2);gotoxy(0,x+2,y+2);


    }
    if (num==2 || num == 50)
    {
        texto_posicion("▀█ ",x,y);
        texto_posicion("▄█ ",x,y+1);
        texto_posicion("█▄ ",x,y+2);

    // Traducido para que el el programa lo entienda
        gotoxy(10,x+0,y);gotoxy(8,x+1,y);gotoxy(0,x+2,y);

        gotoxy(9,x,y+1); gotoxy(8,x+1,y+1);gotoxy(0,x+2,y+1);

        gotoxy(8,x,y+2);gotoxy(9,x+1,y+2);gotoxy(0,x+2,y+2);
        
    }
    if (num==3 || num == 51)
    {
        texto_posicion("▀█ ",x,y);
        texto_posicion("▄█ ",x,y+1);
        texto_posicion("▄█ ",x,y+2);


        // Traducido para que el el programa lo entienda
        gotoxy(10,x,y);gotoxy(8,x+1,y);gotoxy(0,x+2,y);

        gotoxy(9,x,y+1); gotoxy(8,x+1,y+1);gotoxy(0,x+2,y+1);

        gotoxy(9,x,y+2);gotoxy(8,x+1,y+2);gotoxy(0,x+2,y+2);
    }
    if (num ==4 || num == 52)
    {
        texto_posicion("█ █",x,y);
        texto_posicion("█▄█",x,y+1);
        texto_posicion("  █",x,y+2);

        // Traducido para que el el programa lo entienda
        gotoxy(8,x,y);gotoxy(0,x+1,y); gotoxy(8,x+2,y);

        gotoxy(8,x,y+1); gotoxy(9,x+1,y+1); gotoxy(8,x+2,y+1);

        gotoxy(0,x,y+2);gotoxy(0,x+1,y+2);gotoxy(8,x+2,y+2);
        
    }
    
    


}

// Stringg crea un lista de elemetos con un array de entrada 
void writee(char destino[], char palabra[]){
    setbuf(stdout,NULL);        int total = len(palabra);    
    int final= len(destino);    int i =0;
    if (destino[final-1]!='|')
    {
        destino[final]= destino[final]+'|'; 
    }
    // se concatena para encerrar un elemento
    final= len(destino);         
    
        for (i ; i< total; i++)
        {
        destino[final]= destino[final]+palabra[i];
        final++;
        }
        destino[final]= destino[final]+'|';       //   


}

//cuenta los elementos de un array char
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

// Crea la lineas que forman la cuadricula de juego
void recuadro(){
    int y =9;
    // Version Users
    texto_posicion("┃▀▄ ▄▀┃",73,2);
    texto_posicion("┃ ▄▀▄ ┃",73,3);
    texto_posicion("┃▀___▀┃",73,4);

    // Version entendible para el Buffer
    gotoxy(3,73,2);gotoxy(10,74,2); gotoxy(9,75,2);  gotoxy(9,77,2); gotoxy(10,78,2); gotoxy(3,79,2);

    gotoxy(3,73,3);gotoxy(9,75,3); gotoxy(10,76,3);  gotoxy(9,77,3); gotoxy(3,79,3);

    gotoxy(3,73,4);gotoxy(10,74,4); gotoxy(2,75,4);  gotoxy(2,76,4);  gotoxy(2,77,4); gotoxy(10,78,4); gotoxy(3,79,4);


    texto_posicion("┃     ▄▀┃ ",71,5);
    texto_posicion("┃▄  ▄▀  ┃ ",71,6);
    texto_posicion("┃▀▄▀    ┃ ",71,7);
   
    gotoxy(1,71,5);gotoxy(0,72,5);gotoxy(0,73,5);gotoxy(0,75,5);gotoxy(0,75,5);gotoxy(0,76,5);gotoxy(9,77,5);gotoxy(10,78,5);
    
    gotoxy(1,71,6);gotoxy(9,72,6);gotoxy(0,73,6);gotoxy(0,74,6);gotoxy(9,75,6); gotoxy(10,76,6);gotoxy(0,77,6);gotoxy(0,78,6);

    gotoxy(1,71,7);gotoxy(10,72,7);gotoxy(9,73,7);gotoxy(10,74,7);gotoxy(0,75,7);gotoxy(0,76,7);gotoxy(0,77,7);gotoxy(0,78,7);

    

    // techo y piso del recuadro
    for (int i = 0; i < 40; i++)
    {
        gotoxy(2,20+i,2);
        texto_posicion("_",20+i,2);

        gotoxy(2,20+i,22);
        texto_posicion("_",20+i,22);
        
    }

    // Costados del recuadro
    for (int i = 0; i < 20; i++)
    {
        gotoxy(1,20,i+3);
        texto_posicion("┃",20,i+3);

        gotoxy(1,60,i+3);
        texto_posicion("┃",60,i+3);

    }

    // Division horizontal
    for (int i = 0; i < 37; i++)
    {
        gotoxy(4,22+i,12);
        texto_posicion("━",22+i,12);
    }

    // Division Vertical

    for (int i = 0; i < 18; i++)
    {
        gotoxy(5,40,4+i);
        texto_posicion("┃",40,4+i);
    }


    // Divisiones verticales internas

    for (int i = 0; i < 20; i++)
    {
        // superior
        if (i <10 && i>4)
        {
            gotoxy(6,30,i);
            texto_posicion("┊",30,i);
        }
        if (i>14 && i <22)
        {
            gotoxy(6,30,i);
            texto_posicion("┊",30,i);
        }

        // Inferior
        if (i <10 && i>4)
        {
            gotoxy(6,50,i);
            texto_posicion("┊",50,i);
        }
        if (i>14 && i <22)
        {
            gotoxy(6,50,i);
            texto_posicion("┊",50,i);
        }
        
        
    }
    
    // division horizontal interna
    for (int  i = 0; i < 60; i++)
    {
        // superior
        if (i>23 && i <37)
        {
           gotoxy(7,i,7);
           texto_posicion("┄",i,7);
        }

        if (i>43 && i <57)
        {
            gotoxy(7,i,7);
            texto_posicion("┄",i,7);
        }


        // Inferior
        if (i>23 && i <37)
        {
           gotoxy(7,i,17);
           texto_posicion("┄",i,17);
        }

        if (i>43 && i <57)
        {
            gotoxy(7,i,17);
            texto_posicion("┄",i,17);
        }
        
        
    }
    
     
    
}

// valida la posicin del cursor para permitir escribir o no 
void partidas(int matriz[], int x ,int y ){

    int t =60;// define el timepo de activacion

//            Primer cuadrado
            if ((x>22 && x<30) && (y<7 && y>2) && (times[0]>t && matriz[0]==0)  || ( times[0] > t && value[0]!=0) && (x>22 && x<30) && (y<7 && y>2))
            {   
                // recuadro_respues retorna el valor ingresado por el usuario
                int a=recuadro_respues();
                value[0]=1;

                if(a!=respuesta[0] && a!=13){
                    // aqui van game over
                    matriz[0]= a;
                    
                    
                }
                if (a == respuesta[0])
                {
                    matriz[0]= a;
                    puntaje+=12.5;
                    juego();
                }
                

                times[0]=0;
            }

//          Segundo Cuadrado
            if ((x>30 && x<=37) && (y>2 && y<7) && (times[1]>t && matriz[1]==0) || (value[1]!=0 && times[1]>t) && (x>30 && x<=37) && (y>2 && y<7) )
            {
                value[1]=1;
                int a =recuadro_respues();
                if (a== respuesta[1]&& a!=13)
                {
                    matriz[1]=a;
                    puntaje+=12.5;
                    juego();
                }
                if(a != respuesta[1]){
                    // aqui van game over
                    
                    matriz[1]=a;
                    
                }

                times[1]=0;
            }
//          Tercer cuadro
            if ((x>22 && x<37)&& (y>=7 && y<=10 )&& times[2]>t && matriz[2]==0  || (value[2]!=0 && times[2]>t) && (x>22 && x<37)&& (y>=7 && y<=10 ))
            {
                int a =recuadro_respues();
                value[2]=1;
                if (a== respuesta[2]&& a!=13)
                {
                    matriz[2]=a;

                    juego();
                }
                if(a != respuesta[2]&& a!=13){
                    // aqui van game over
                    
                    matriz[2]=a;
                }

                times[2]=0;
                
            }
//          Cuarto cuadrado
            if ((x>30&& x<37)&& (y>=7 && y<=10) && (matriz[3]==0 && times[3]>t) || (value[3]!=0 && times[3]>t) && (x>30&& x<37)&& (y>=7 && y<=10) )
            {
                int a =recuadro_respues();
                value[3]=1;
                if (a== respuesta[3])
                {
                    matriz[3]=a;
                    puntaje+=12.5;
                    juego();
                }if(a != respuesta[3]&& a!=13){
                    // aqui van game over
                    
                    matriz[3]=a;

                }
                times[3]=0;
            }

//          Quinto Cuadrado
            if ((x>43 && x<50) && (y>2 && y<7) && (matriz[4]==0 && times[4]>t) || (value[4]!=0 && times[4]>t) && (x>43 && x<50) && (y>2 && y<7) )
            {
                int a =recuadro_respues();
                value[4]=1;
                if (a== respuesta[4])
                {
                    matriz[4]=a;
                    puntaje+=12.5;
                    juego();
                }if(a != respuesta[4]&& a!=13){
                    // aqui van game over
                    
                    matriz[4]=a;
                }
                times[4]=0;
            }

//          Sexto Cuadrado
            if ((x>50 && x<57) && (y>2 && y<7) && (matriz[5]==0 && times[5]>t) || (value[5]!=0 && times[5]>t) && (x>50 && x<57) && (y>2 && y<7) )
            {
                int a =recuadro_respues();
                value[5]=1;
                if (a== respuesta[5]&& a!=13)
                {
                    matriz[5]=a;
                    puntaje+=12.5;
                    juego();
                }
                if(a != respuesta[5]&& a!=13){
                    // aqui van game over
                    
                    matriz[5]=a;

                }
                times[5]=0;
            }
//          Septimo Cuadrado
            if ((x>39 && x<50) && (y>7 && y<=11) && (matriz[6]==0 && times[6]>30) || (value[6]!=0 && times[6]>t) && (x>40 && x<50) && (y>7 && y<=10) )
            {
                int a =recuadro_respues();
                value[6]=1;
                if (a== respuesta[6])
                {
                    matriz[6]=a;
                    puntaje+=12.5;
                    juego();
                }
                if(a != respuesta[6]&& a!=13){
                    // aqui van game over
                    
                    matriz[6]=a;
                }
                times[6]=0;
            }
//          Octavo Cuadrado
            if ((x>50 && x<57) && (y>7 && y<=10) && (matriz[7]==0 && times[7]>t) || (value[7]!=0 && times[7]>t) && (x>50 && x<57) && (y>7 && y<=10) )
            {
                int a =recuadro_respues();
                value[7]=1;
                if (a== respuesta[7])
                {
                    matriz[7]=a;
                    puntaje+=12.5;
                    juego();
                }if(a != respuesta[7]&& a!=13){
                    // aqui van game over
                    
                    matriz[7]=a;
                }
                times[7]=0;
            }
//          Noveno Cuadrado
            if ((x>23 && x<30) && (y>12 && y<=17) && (matriz[8]==0 && times[8]>t) || (value[8]!=0 && times[8]>t) && (x>23 && x<30) && (y>12 && y<=17) )
            {
                int a =recuadro_respues();
                value[8]=1;
                if (a== respuesta[8])
                {
                    matriz[8]=a;
                    puntaje+=12.5;
                    juego();
                }if(a != respuesta[8]&& a!=13){
                    // aqui van game over
                    
                    matriz[8]=a;
                }
                times[8]=0;
            }
//          Decimo Cuadrado
            if ((x>30 && x<37) && (y>12 && y<=17) && (matriz[9]==0 && times[9]>t) || (value[9]!=0 && times[9]>t) && (x>30 && x<37) && (y>12 && y<=17))
            {
                int a =recuadro_respues();
                value[9]=1;
                if (a== respuesta[9])
                {
                    matriz[9]=a;
                    puntaje+=12.5;
                    juego();
                }if(a != respuesta[9]&& a!=13){
                    // aqui van game over
                    
                    matriz[9]=a;
                }

                times[9]=0;
            }
//          Cuadrado  11
            if ((x>23 && x<30) && (y>17 && y<=23) && (matriz[10]==0 && times[10]>t) || (value[10]!=0 && times[10]>t) && (x>23 && x<30) && (y>17 && y<=23) )
            {
                int a =recuadro_respues();
                value[10]=1;
                if (a== respuesta[10])
                {
                    matriz[10]=a;
                    puntaje+=12.5;
                    juego();
                }if(a != respuesta[10]&& a!=13){
                    // aqui van game over
                    
                    matriz[10]=a;
                }
                times[10]=0;
            }
//          Cuadrado  12  para que esto se cumpla el cursor debe de estar en la coordenada correcta durante un tiempo t 
            if ((x>30 && x<37) && (y>17 && y<=23) && (matriz[11]==0 && times[11]>t) || (value[11]!=0 && times[10]>t) && (x>30 && x<37) && (y>17 && y<=23) )
            {
                int a =recuadro_respues();
                value[11]=1;
                if (a== respuesta[11])
                {
                    matriz[11]=a;
                    puntaje+=12.5;
                    juego();
                }if(a != respuesta[11]){
                    // aqui van game over
                    
                    matriz[11]=a;
                }
                times[11]=0;
            }
//          Cuadrado  13
            if ((x>43 && x<50) && (y>12 && y<=17) && (matriz[12]==0 && times[12]>t) || (value[12]!=0 && times[12]>t) && (x>43 && x<50) && (y>12 && y<=17) )
            {
                int a =recuadro_respues();
                value[12]=1;
                if (a== respuesta[12])
                {
                    matriz[12]=a;
                    puntaje+=12.5;
                    juego();
                }if(a != respuesta[12]&& a!=13){
                    // aqui van game over
                    
                    matriz[12]=a;
                }
                times[12]=0;
            }
//          Cuadrado  14
            if ((x>50 && x<57) && (y>12 && y<=17) && (matriz[13]==0 && times[13]>t) || (value[13]!=0 && times[13]>t) && (x>50 && x<57) && (y>12 && y<=17) )
            {
                int a =recuadro_respues();
                value[13]=1;
                if (a== respuesta[13])
                {
                    matriz[13]=a;
                    puntaje+=12.5;
                    juego();
                }if(a != respuesta[13]&& a!=13){
                    // aqui van game over
                    
                    matriz[13]=a;
                }
                times[13]=0;
            }
//          Cuadrado  (15)
            if ((x>43 && x<50) && (y>17 && y<=23) && (matriz[14]==0 && times[14]>t) || (value[14]!=0 && times[14]>t) && (x>43 && x<50) && (y>17 && y<=23) )
            {
                int a =recuadro_respues();
                value[14]=1;
                if (a== respuesta[14])
                {
                    matriz[14]=a;
                    puntaje+=12.5;
                    juego();
                }if(a != respuesta[14]&& a!=13){
                    // aqui van game over
                    
                    matriz[14]=a;
                }
                times[14]=0;
            }
//          Cuadrado  16
            if ((x>50 && x<57) && (y>17 && y<=23) && (matriz[15]==0 && times[15]>t) || (value[15]!=0 && times[15]>t) && (x>50 && x<57) && (y>17 && y<=23)  )
            {
                int a =recuadro_respues();
                value[15]=1;
                if (a== respuesta[15])
                {
                    matriz[15]=a;
                    puntaje+=12.5;
                    juego();
                }if(a != respuesta[15]&& a!=13){
                    // aqui van game over
                    
                    matriz[15]=a;
                }
                times[15]=0;
            }






          // Tiempos para la ejecucion del programa

//          Primer recuadro (1)
            if ((x>22 && x<30) && (y<7 && y>2))
            {   
                times[0]+=1; 
                
            }
//          Segundo Cuadrado (2)
            if ((x>30 && x<=37) && (y>2 && y<7))
            {
                times[1]+=1;
            }
//          Tercer cuadro (3)
            if ((x>22 && x<37)&& (y>=7 && y<=10))
            {
                times[2]+=1;    
            }
//          Cuarto cuadrado (4)
            if ((x>30&& x<37)&& (y>=7 && y<=10))
            {
                times[3]+=1;
            }

//          Quinto Cuadrado (5)
            if ((x>43 && x<50) && (y>2 && y<7) )
            {
                
                times[4]+=1;
            }
//          Sexto Cuadrado  (6)
            if ((x>50 && x<57) && (y>2 && y<7) )
            {
              
                times[5]+=1;
            }
//          Septimo Cuadrado  (7)
            if ((x>40 && x<50) && (y>7 && y<=10) )
            {
               
                times[6]+=1;
            }
//          Octavo Cuadrado  (8)
            if ((x>50 && x<57) && (y>7 && y<=10))
            {
                times[7]+=1;
            }
//          Noveno Cuadrado (9)
            if ((x>23 && x<30) && (y>12 && y<=17) )
            {
                times[8]+=1;
            }
//          Decimo Cuadrado (10)
            if ((x>30 && x<37) && (y>12 && y<=17))
            {
                times[9]+=1;
            }
//          Cuadrado  (11)
            if ((x>23 && x<30) && (y>17 && y<=23) )
            {
                times[10]+=1;
            }
//          Cuadrado  (12)
            if ((x>30 && x<37) && (y>17 && y<=23))
            {
                times[11]+=1;
            }
//          Cuadrado  (13)
            if ((x>43 && x<50) && (y>12 && y<=17) )
            {
                times[12]+=1;
            }
//          Cuadrado  (14)
            if ((x>50 && x<57) && (y>12 && y<=17))
            {
                times[13]+=1;
            }
//          Cuadro (15)
            if ((x>43 && x<50) && (y>17 && y<=23))
            {
                times[14]+=1;
            }            
//          Cuadrado  (16)
            if ((x>50 && x<57) && (y>17 && y<=23) )
            {
                times[15]+=1;
            }

}

// Imprime en pantalla los numeros de cada jugada
void juego(){

    int cursor=0;

// Recuadro (Derecho superior)
    for (int i = 0; i < 4; i++)
    {

        // recuadro (Sup derecho) (1)
        if (matriz[0]!=0)
        {
            /* (x,y)=(24,4) */
            numero(matriz[0],24,4);

        }

        // Recuadro (Sup Izquierdo)  (2)
        if (matriz[1]!=0) 
        {
            
            numero(matriz[1],34,4);
        }

        // Recuadro (Inf Derecho)   (3)
        if (matriz[2]!=0)
        {
            
            numero(matriz[2],24,8);
        }

        // Recuadro (Inf Izquierdo)  (4)
        if (matriz[3]!=0)
        {
            
            numero(matriz[3],34,8);
        }
        
        
        


    }

// Recuadro (Izquierdo superior)
    for (int i = 0; i < 4; i++)
    {

        // recuadro (Sup derecho)  (5)
        if (matriz[4]!=0)
        {
            /* (x,y)=(24,4) */
            numero(matriz[4],45,4);

        }

        // Recuadro (Sup Izquierdo)  (6)
        if (matriz[5]!=0)
        {
            /* code */
            numero(matriz[5],54,4);
        }

        // Recuadro (Inf Derecho)   (7)
        if (matriz[6]!=0)
        {
            /* code */
            numero(matriz[6],44,8);
        }

        // Recuadro (Inf Izquierdo)   (8)
        if (matriz[7]!=0)
        {
            /* code */
            numero(matriz[7],54,8);
        }
    }

// Recuadro (Derecho inferior)
    for (int i = 0; i < 4; i++)
    {
        // recuadro (Sup derecho)   (9)
        if (matriz[8]!=0)
        {
            /* (x,y)=(24,4) */
            numero(matriz[8],24,14);

        }

        // Recuadro (Sup Izquierdo)   (10)
        if (matriz[9]!=0)
        {
            /* code */
            numero(matriz[9],34,14);
            
        }

        // Recuadro (Inf Derecho)  (11)
        if (matriz[10]!=0)
        {
            /* code */
            numero(matriz[10],24,18);
        }

        // Recuadro (Inf Izquierdo)   (12)
        if (matriz[11]!=0)
        {
            /* code */
            numero(matriz[11],34,18);
        }
    }

// Recuadro (Izquierdo inferior)  (13)
    for (int i = 0; i < 4; i++)
    {
        // recuadro (Sup derecho)
        if (matriz[12]!=0)
        {
            /* (x,y)=(24,4) */
            numero(matriz[12],44,14);

        }

        // Recuadro (Sup Izquierdo) (14)
        if (matriz[13]!=0)
        {
            
            numero(matriz[13],54,14);
        }

        // Recuadro (Inf Derecho)   (15)
        if (matriz[14]!=0)
        {
            
            numero(matriz[14],44,18);
        }

        // Recuadro (Inf Izquierdo) (16)
        if (matriz[15]!=0)
        {
            
            numero(matriz[15],53,18);
        }
    }
    
    
    
    

}
// captura las coordenasas x,y del mouse
void coords(Display *display, int *x, int *y){
  XEvent event;
  XQueryPointer(display, DefaultRootWindow (display), &event.xbutton.root, &event.xbutton.window, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);              
  *x = event.xbutton.x;
  *y = event.xbutton.y;

  
}

// crea un marquito en la terminal
void marquito(){
   
    // Margenes horizontales
    for (int i = 0; i < 80; i++)
    {
        texto_posicion("━",i,1);
        gotoxy(4,i,1);
        
        gotoxy(4,i,24);
        texto_posicion("━",i,24);
        
    }
    
    // Margenes laterales
    for (int i = 1; i <= 24; i++)
    {
        gotoxy(5,0,i+1);
        texto_posicion("┃",0,i+1);
        
        gotoxy(5,80,i+1);
        texto_posicion("┃",80,i+1);
        
    }
    
}

void arc(char cadena[]){
    FILE *archivo = fopen("ur.txt", "w");

    fputs(cadena,archivo);
    fclose(archivo);

}

int verificar_resp(int partida[],int respuesta[]){
    int error=0;

    for (int i = 0; i < 16; i++)
    {
        if (partida[i]!=respuesta[i])
        {
            error++;
        }   
    }
    return error;
}


void juego_aleatorio(int matriz[], int respuesta[], char respuestaa[]){

    srand(time(NULL));
    int elecion = rand()%11;

    if (elecion==0)
    {
        int matriz0[16]={0,2,1,0,4,0,0,3,4,0,0,1,0,2,3,0};
        int correto0[16]={3,2,1,4,4,1,2,3,4,3,2,1,1,2,3,4};
        char respuesta0[16]="3214412343211234";

        memset(respuestaa,0,strlen(respuestaa));

        for (int i = 0; i < 16; i++)
        {
            matriz[i]=matriz0[i];
            respuesta[i]=correto0[i];
            respuestaa[i]+=respuesta0[i];
        }
        
    }
    
    if (elecion==1)
    {
        int matriz1[16] ={0,1,2,0,0,2,1,4,1,4,0,2,2,0,0,0};
        int correto1[16]={4,1,2,3,3,2,1,4,1,4,3,2,2,3,4,1};
        char respuesta1[16]="4123321414322341";

        memset(respuestaa,0,strlen(respuestaa));

        for (int i = 0; i < 16; i++)
        {
            matriz[i]=matriz1[i];
            respuesta[i]=correto1[i];
            respuestaa[i]+=respuesta1[i];
        }
        
    }

    if (elecion==2)
    {
        int matriz2[16]={2,4,3,1,1,3,0,4,0,0,0,0,4,0,0,0};
        int correto2[16]={2,4,3,1,1,3,2,4,1,3,4,2,4,2,3,1};
        char respuesta2[16]="2431132413424231";

        memset(respuestaa,0,strlen(respuestaa));

        for (int i = 0; i < 16; i++)
        {
            matriz[i]=matriz2[i];
            respuesta[i]=correto2[i];
            respuestaa[i]+=respuesta2[i];
        }
        
    }
// aqui quedo
    if (elecion==3)
    {
        int matriz3[16]={0,4,2,0,0,0,0,4,0,1,4,0,0,2,3,1};
        int correto3[16]={1,4,2,3,2,3,1,4,3,1,4,2,4,2,3,1};
        char respuesta3[16]="1423231431424231";

        memset(respuestaa,0,strlen(respuestaa));

        for (int i = 0; i < 16; i++)
        {
            matriz[i]=matriz3[i];
            respuesta[i]=correto3[i];
            respuestaa[i]+=respuesta3[i];
        }
        
    }

    if (elecion==4)
    {
        int matriz4[16] ={0,0,3,0, 3,0,0,4, 4,3,0,0, 2,0,0,3};
        int correto4[16]={1,4,3,2, 3,2,1,4, 4,3,2,1, 2,1,4,3};
        char respuesta4[16]="1432321443212143";

        memset(respuestaa,0,strlen(respuestaa));

        for (int i = 0; i < 16; i++)
        {
            matriz[i]=matriz4[i];
            respuesta[i]=correto4[i];
            respuestaa[i]+=respuesta4[i];
        }
        
    }

    if (elecion==5)
    {
        int matriz5[16] ={0,3,4,1, 4,0,3,2, 0,0,3,0, 0,0,0,0};
        int correto5[16]={2,3,4,1, 4,1,3,2, 1,4,3,2, 2,3,1,4};
        char respuesta5[16]="2341413214322314";

        memset(respuestaa,0,strlen(respuestaa));

        for (int i = 0; i < 16; i++)
        {
            matriz[i]=matriz5[i];
            respuesta[i]=correto5[i];
            respuestaa[i]+=respuesta5[i];
        }
        
    }

    if (elecion==6)
    {
        int matriz6[16] ={0,0,0,4, 4,1,2,3, 2,0,4,0, 3,0,1,0};
        int correto6[16]={3,2,1,4, 4,1,2,3, 2,1,4,3, 3,4,1,2};
        char respuesta6[16]="3214412321433412";

        memset(respuestaa,0,strlen(respuestaa));

        for (int i = 0; i < 16; i++)
        {
            matriz[i]=matriz6[i];
            respuesta[i]=correto6[i];
            respuestaa[i]+=respuesta6[i];
        }
        
    }

    if (elecion==7)
    {
        int matriz7[16]={0,3,0,0, 2,4,0,3, 0,1,3,2, 3,0,0,0};
        int correto7[16]={1,3,2,4, 2,4,1,3, 4,1,3,2, 3,2,4,1};
        char respuesta7[16]="1324241341323241";

        memset(respuestaa,0,strlen(respuestaa));

        for (int i = 0; i < 16; i++)
        {
            matriz[i]=matriz7[i];
            respuesta[i]=correto7[i];
            respuestaa[i]+=respuesta7[i];
        }
        
    }

    if (elecion==8)
    {
        int matriz8[16]={1,0,0,4, 0,4,0,1, 2,0,0,3, 0,0,1,2};
        int correto8[16]={1,2,3,4, 3,4,2,1, 2,1,4,3, 4,3,1,2};
        char respuesta8[16]="1234342121434312";

        memset(respuestaa,0,strlen(respuestaa));

        for (int i = 0; i < 16; i++)
        {
            matriz[i]=matriz8[i];
            respuesta[i]=correto8[i];
            respuestaa[i]+=respuesta8[i];
        }
        
    }

    if (elecion==9)
    {
        int matriz9[16]={0,0,3,0, 3,0,2,4, 1,3,0,0, 4,2,1,0};
        int correto9[16]={2,4,3,1, 3,1,2,4, 1,3,4,2, 4,2,1,3};
        char respuesta9[16]="2431312413424213";

        memset(respuestaa,0,strlen(respuestaa));

        for (int i = 0; i < 16; i++)
        {
            matriz[i]=matriz9[i];
            respuesta[i]=correto9[i];
            respuestaa[i]+=respuesta9[i];
        }
        
    }

    if (elecion==10)
    {
        int matriz10[16]={2,0,3,0, 0,0,2,4, 1,3,0,0, 4,0,3,0};
        int correto10[16]={2,4,3,1, 1,3,2,4, 1,3,4,2, 4,2,3,1};
        char respuesta10[16]="2431132413424231";

        memset(respuestaa,0,strlen(respuestaa));

        for (int i = 0; i < 16; i++)
        {
            matriz[i]=matriz10[i];
            respuesta[i]=correto10[i];
            respuestaa[i]+=respuesta10[i];
        }
        
    }
   
    

}

char leer(char arreglo[]){
    

    FILE *archivo = fopen("errol.txt", "r+");
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
    

    FILE *arch = fopen("puntos.txt", "r+");
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

int game_over(){
                texto_posicion("                                            ",18,7);
                texto_posicion("    ░██████╗░░█████╗░███╗░░░███╗███████╗    ",18,8);
                texto_posicion("    ██╔════╝░██╔══██╗████╗░████║██╔════╝    ",18,9);
                texto_posicion("    ██║░░██╗░███████║██╔████╔██║█████╗░░    ",18,10);
                texto_posicion("    ██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░    ",18,11);
                texto_posicion("    ╚██████╔╝██║░░██║██║░╚═╝░██║███████╗    ",18,12);
                texto_posicion("    ░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝    ",18,13);
                texto_posicion("    ░█████╗░██╗░░░██╗███████╗██████╗░       ",18,14);
                texto_posicion("    ██╔══██╗██║░░░██║██╔════╝██╔══██╗       ",18,15);
                texto_posicion("    ██║░░██║╚██╗░██╔╝█████╗░░██████╔╝  ",18,16);
                texto_posicion("    ██║░░██║░╚████╔╝░██╔══╝░░██╔══██╗  ",18,17);
                texto_posicion("    ╚█████╔╝░░╚██╔╝░░███████╗██║░░██║  ",18,18);
                texto_posicion("    ░╚════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝  ",18,19);
                texto_posicion("                                        ",18,20);
    return 49;
}

int victoria(){
texto_posicion("  ██╗░░░██╗██╗░█████╗░████████╗░█████╗░██████╗░██╗░█████╗░     ",19,9);
texto_posicion("  ██║░░░██║██║██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗██║██╔══██╗     ",19,10);
texto_posicion("  ╚██╗░██╔╝██║██║░░╚═╝░░░██║░░░██║░░██║██████╔╝██║███████║     ",19,11);
texto_posicion("  ░╚████╔╝░██║██║░░██╗░░░██║░░░██║░░██║██╔══██╗██║██╔══██║     ",19,12);
texto_posicion("  ░░╚██╔╝░░██║╚█████╔╝░░░██║░░░╚█████╔╝██║░░██║██║██║░░██║     ",19,13);
texto_posicion("  ░░░╚═╝░░░╚═╝░╚════╝░░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝╚═╝╚═╝░░╚═╝     ",19,14);

    return 49;
}


// Comando de compilacion   : gcc -o nn nn.c -L/usr/X11R6/lib -lX11 -lXtst  y tilix -e ./nn
