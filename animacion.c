#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



void texto_posicion(const char texto[], int x, int y);


void gotoxy(int x,int y);

void menu_de_carga();

void cls();


int main(){

    menu_de_carga();
    return 0;
}



void texto_posicion(const char texto[], int x, int y){
    setbuf(stdout,NULL);
    gotoxy(x,y);
    printf("%s",texto);
    setbuf(stdout,NULL);

}



void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);
}



void menu_de_carga(){
    cls();
    texto_posicion("█▀▀ ▄▀█ █▀█ █▀▀ ▄▀█ █▄░█ █▀▄ █▀█",27,8);
    texto_posicion("█▄▄ █▀█ █▀▄ █▄█ █▀█ █░▀█ █▄▀ █▄█",27,9);

    texto_posicion("░░░░░░░░░░░░░░░░░░░░░░░░",30,11);
    texto_posicion("░░░░░░░░░░░░░░░░░░░░░░░░",30,12);
    for (int i = 0; i < 20; i++)
    {
        
        texto_posicion("█",i+30,11);
        texto_posicion("█",i+30,12);
        usleep(35000);
    }
}


void cls(){
    #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}