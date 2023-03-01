#ifndef MONITA_H_INCLUDED
#define MONITA_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void texto_posicion(const char texto[], int x, int y);

void gotoxy(int x,int y);

void monachina();

void cls();

int keyM();


// Esta funcion se encarga se limpiar los arreglos de caracteres
void lin(char datoo []);

// Esta funcion enumera los elemtos de un arreglo
int len(char Nombre_de_cadena_de_caracteres[]);



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

void cls(){
    #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
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




void monachina(){

texto_posicion(" _______ad88888888888888888888888a,                                         ",10,1);
usleep(35000);
texto_posicion("________a88888\"8888888888888888888888,                                         ",10,2);
usleep(35000);
texto_posicion("______,8888\"__\"P88888888888888888888b,                                         ",10,3);
usleep(35000);
texto_posicion("______d88_________`\"\"P88888888888888888,                                         ",10,4);
usleep(35000);
texto_posicion("_____,8888b_______________\"\"88888888888888,                                         ",10,5);
usleep(35000);
texto_posicion("_____d8P\'\'\'__,aa,______________\"\"888888888b                                         ",10,6);
usleep(35000);
texto_posicion("_____888bbdd888888ba,__,I_________\"88888888,                                         ",10,7);
usleep(35000);
texto_posicion("_____8888888888888888ba8\"_________,88888888b                                         ",10,8);
usleep(35000);
texto_posicion("____,888888888888888888b,________,8888888888                                         ",10,9);
usleep(35000);
texto_posicion("____(88888888888888888888,______,88888888888,                                         ",10,10);
usleep(35000);
texto_posicion("____d888888888888888888888,____,8___\"8888888b                                         ",10,11);
usleep(35000);
texto_posicion("____88888888888888888888888__.;8\'\"\"\"__(888888                                         ",10,12);
usleep(35000);
texto_posicion("____8888888888888I\"8888888P_,8\"_,aaa,__888888                                         ",10,13);
usleep(35000);
texto_posicion("____888888888888I:8888888\"_,8\"__`b8d\'__(88888                                         ",10,14);
usleep(35000);
texto_posicion("____(8888888888I\'888888P\'_,8)__________88888                                         ",10,15);
usleep(35000);
texto_posicion("_____88888888I\"__8888P\'__,8\")__________88888                                         ",10,16);
usleep(35000);
texto_posicion("_____8888888I\'___888\"___,8\"_(._.)_______88888                                         ",10,17);
usleep(35000);
texto_posicion("_____(8888I\"_____\"88,__,8\"_____________,8888P                                         ",10,18);
usleep(35000);
texto_posicion("______888I\'_______\"P8_,8\"_____________,88888)                                         ",10,19);
usleep(35000);
texto_posicion("_____(88I\'__________\",8\"__M\"\"\"\"\"\"M___,888888\'                                         ",10,20);
usleep(35000);
texto_posicion("____,8I\"____________,8(____\"aaaa\"___,8888888                                         ",10,21);
usleep(35000);
texto_posicion("___,8I\'____________,888a___________,8888888)                                         ",10,22);
usleep(35000);
texto_posicion("__,8I\'____________,888888,_______,888888888                                         ",10,23);
usleep(35000);
texto_posicion("_,8I\'____________,8888888\'`-===-\'888888888\'                                         ",10,24);
usleep(35000);
texto_posicion(",8I\'____________,8888888\"________88888888\"                                         ",10,25);
usleep(35000);
texto_posicion("8I\'____________,8\"____88_________\"888888P                                         ",10,26);
usleep(35000);
texto_posicion("8I____________,8\'_____88__________`P888\"                                         ",10,27);
usleep(35000);
texto_posicion("8I___________,8I______88____________\"8ba,.                                         ",10,28);
usleep(35000);
texto_posicion("(8,_________,8P\'______88______________88\"\"8bma,.                                         ",10,29);
usleep(35000);
texto_posicion("_8I________,8P\'_______88,______________\"8b___\"\"P8ma,                                         ",10,30);
usleep(35000);
texto_posicion("_(8,______,8d\"________`88,_______________\"8b_____`\"8a                                         ",10,31);
usleep(35000);
texto_posicion("__8I_____,8dP_________,8X8,________________\"8b.____:8b                                         ",10,32);
usleep(35000);
texto_posicion("__(8____,8dP\'__,I____,8XXX8,________________`88,____8)                                         ",10,33);
usleep(35000);
texto_posicion("___8,___8dP\'__,I____,8XxxxX8,_____I,_________8X8,__,8                                         ",10,34);
usleep(35000);
texto_posicion("___8I___8P\'__,I____,8XxxxxxX8,_____I,________`8X88,I8                                         ",10,35);
usleep(35000);
texto_posicion("___I8,__\"___,I____,8XxxxxxxxX8b,____I,________8XXX88I,                                         ",10,36);
usleep(35000);
texto_posicion("___`8I______I\'__,8XxxxxxxxxxxxXX8____I________8XXxxXX8,                                         ",10,37);
usleep(35000);
texto_posicion("____8I_____(8__,8XxxxxxxxxxxxxxxX8___I________8XxxxxxXX8,                                         ",10,38);
usleep(35000);
texto_posicion("___,8I_____I[_,8XxxxxxxxxxxxxxxxxX8__8________8XxxxxxxxX8,                                         ",10,39);
usleep(35000);
texto_posicion("___d8I,____I[_8XxxxxxxxxxxxxxxxxxX8b_8_______(8XxxxxxxxxX8,                                         ",10,40);
usleep(35000);
texto_posicion("___888I____`8,8XxxxxxxxxxxxxxxxxxxX8_8,_____,8XxxxxxxxxxxX8                                         ",10,41);
usleep(35000);
texto_posicion("___8888,____\"88XxxxxxxxxxxxxxxxxxxX8)8I____.8XxxxxxxxxxxxX8                                         ",10,42);
usleep(35000);
texto_posicion("__,8888I_____88XxxxxxxxxxxxxxxxxxxX8_`8,__,8XxxxxxxxxxxxX8\"                                         ",10,43);
usleep(35000);
texto_posicion("__d88888_____`8XXxxxxxxxxxxxxxxxxX8\'__`8,,8XxxxxxxxxxxxX8\"                                         ",10,44);
usleep(35000);
texto_posicion("__888888I_____`8XXxxxxxxxxxxxxxxX8\'____\"88XxxxxxxxxxxxX8\"                                         ",10,45);
usleep(35000);
texto_posicion("__88888888bbaaaa88XXxxxxxxxxxxXX8)______)8XXxxxxxxxxXX8\"                                         ",10,46);
usleep(35000);
texto_posicion("__8888888I,_``\"\"\"\"\"\"8888888888888888aaaaa8888XxxxxXX8\"                                         ",10,47);
usleep(35000);
texto_posicion("__(8888888I,______________________.__```\"\"\"\"\"88888P\"                                         ",10,48);
usleep(35000);
texto_posicion("___88888888I,___________________,8I___8,_______I8\"                                         ",10,49);
usleep(35000);
texto_posicion("____\"\"\"88888I,________________,8I\'____\"I8,____;8\"                                         ",10,50);
usleep(35000);
texto_posicion("___________`8I,_____________,8I\'_______`I8,___8)                                         ",10,51);
usleep(35000);
texto_posicion("____________`8I,___________,8I\'__________I8__:8\'                                         ",10,52);
usleep(35000);
texto_posicion("_____________`8I,_________,8I\'___________I8__:8                                         ",10,53);
usleep(35000);
texto_posicion("______________`8I_______,8I\'_____________`8__(8                                         ",10,54);
usleep(35000);
texto_posicion("_______________8I_____,8I\'________________8__(8;                                         ",10,55);
usleep(35000);
texto_posicion("_______________8I____,8\"__________________I___88,                                         ",10,56);
usleep(35000);
texto_posicion("______________.8I___,8\'_______________________8\"8,                                         ",10,57);
usleep(35000);
texto_posicion("______________(PI___\'8_______________________,8,`8,                                         ",10,58);
usleep(35000);
texto_posicion("_____________.88\'____________,@@___________.a8X8,`8,                                         ",10,59);
usleep(35000);
texto_posicion("_____________(88_____________@@@_________,a8XX888,`8,                                         ",10,60);
usleep(35000);
texto_posicion("____________(888_____________@@\'_______,d8XX8\"__\"b_`8,                                         ",10,61);
usleep(35000);
texto_posicion("___________.8888,_____________________a8XXX8\"____\"a_`8,                                         ",10,62);
usleep(35000);
texto_posicion("__________.888X88___________________,d8XX8I\"______9,_`8,                                         ",10,63);
usleep(35000);
texto_posicion("_________.88:8XX8,_________________a8XxX8I\'_______`8__`8,                                         ",10,64);
usleep(35000);
texto_posicion("________.88\'_8XxX8a_____________,ad8XxX8I\'________,8___`8,                                         ",10,65);
usleep(35000);
texto_posicion("________d8\'__8XxxxX8ba,______,ad8XxxX8I\"__________8__,__`8,                                         ",10,66);
usleep(35000);
texto_posicion("_______(8I___8XxxxxxX888888888XxxxX8I\"____________8__II__`8                                         ",10,67);
usleep(35000);
texto_posicion("_______8I\'___\"8XxxxxxxxxxxxxxxxxxX8I\'____________(8__8)___8;                                         ",10,68);
usleep(35000);
texto_posicion("______(8I_____8XxxxxxxxxxxxxxxxxX8\"______________(8__8)___8I                                         ",10,69);
usleep(35000);
texto_posicion("______8P\'_____(8XxxxxxxxxxxxxxX8I\'________________8,_(8___:8                                         ",10,70);
usleep(35000);
texto_posicion("_____(8\'_______8XxxxxxxxxxxxxxX8\'_________________`8,_8____8                                         ",10,71);
usleep(35000);
texto_posicion("_____8I________`8XxxxxxxxxxxxX8\'___________________`8,8___;8                                         ",10,72);
usleep(35000);
texto_posicion("_____8\'_________`8XxxxxxxxxxX8\'_____________________`8I__,8\'                                         ",10,73);
usleep(35000);
texto_posicion("_____8___________`8XxxxxxxxX8\'_______________________8\'_,8\'                                         ",10,74);
usleep(35000);
texto_posicion("_____8____________`8XxxxxxX8\'________________________8_,8\'                                         ",10,75);
usleep(35000);
texto_posicion("_____8_____________`8XxxxX8\'________________________d\'_8\'                                         ",10,76);
usleep(35000);
texto_posicion("_____8______________`8XxxX8_________________________8_8\'                                         ",10,77);
usleep(35000);
texto_posicion("_____8________________\"8X8\'_________________________\"8\"                                         ",10,78);
usleep(35000);
texto_posicion("_____8,________________`88___________________________8                                         ",10,79);
usleep(35000);
texto_posicion("_____8I________________,8\'__________________________d)                                         ",10,80);
usleep(35000);
texto_posicion("_____`8,_______________d8__________________________,8                                         ",10,81);
usleep(35000);
texto_posicion("______(b_______________8\'_________________________,8\'                                         ",10,82);
usleep(35000);
texto_posicion("_______8,_____________dP_________________________,8\'                                         ",10,83);
usleep(35000);
texto_posicion("_______(b_____________8\'________________________,8\'                                         ",10,84);
usleep(35000);
texto_posicion("________8,___________d8________________________,8\'                                         ",10,85);
usleep(35000);
texto_posicion("________(b___________8\'_______________________,8\'                                         ",10,86);
usleep(35000);
texto_posicion("_________8,_________a8_______________________,8\'                                         ",10,87);
usleep(35000);
texto_posicion("_________(b_________8\'______________________,8\'                                         ",10,88);
usleep(35000);
texto_posicion("__________8,_______,8______________________,8\'                                         ",10,89);
usleep(35000);
texto_posicion("__________(b_______8\'_____________________,8\'                                         ",10,90);
usleep(35000);
texto_posicion("___________8,_____,8_____________________,8\'                                         ",10,91);
usleep(35000);
texto_posicion("___________(b_____8\'____________________,8\'                                         ",10,92);
usleep(35000);
texto_posicion("____________8,___d8____________________,8\'                                         ",10,93);
usleep(35000);
texto_posicion("____________(b__,8\'___________________,8\'                                         ",10,94);
usleep(35000);
texto_posicion("_____________8,,I8___________________,8\'                                         ",10,95);
usleep(35000);
texto_posicion("_____________I8I8\'__________________,8\'                                         ",10,96);
usleep(35000);
texto_posicion("_____________`I8I__________________,8\'                                         ",10,97);
usleep(35000);
texto_posicion("______________I8\'_________________,8\'                                         ",10,98);
usleep(35000);
texto_posicion("______________\"8_________________,8\'                                         ",10,99);
usleep(35000);
texto_posicion("______________(8________________,8\'                                         ",10,100);
usleep(35000);
texto_posicion("______________8I_______________,8\'                                         ",10,101);
usleep(35000);
texto_posicion("______________(b,___8,________,8)                                         ",10,102);
usleep(35000);
texto_posicion("______________`8I___\"88______,8i8,                                         ",10,103);
usleep(35000);
texto_posicion("_______________(b,__________,8\"8\")                                         ",10,104);
usleep(35000);
texto_posicion("_______________`8I__,8______8)_8_8                                         ",10,105);
usleep(35000);
texto_posicion("________________8I__8I______\"__8_8                                         ",10,106);
usleep(35000);
texto_posicion("________________(b__8I_________8_8                                         ",10,107);
usleep(35000);
texto_posicion("________________`8__(8,________b_8,                                         ",10,108);
usleep(35000);
texto_posicion("_________________8___8)________\"b\"8,                                         ",10,109);
usleep(35000);
texto_posicion("_________________8___8(_________\"b\"8                                         ",10,110);
usleep(35000);
texto_posicion("_________________8___\"I__________\"b8,                                         ",10,111);
usleep(35000);
texto_posicion("_________________8________________`8)                                         ",10,112);
usleep(35000);
texto_posicion("_________________8_________________I8                                         ",10,113);
usleep(35000);
texto_posicion("_________________8_________________(8                                         ",10,114);
usleep(35000);
texto_posicion("_________________8,_________________8,                                         ",10,115);
usleep(35000);
texto_posicion("_________________Ib_________________8)                                         ",10,116);
usleep(35000);
texto_posicion("_________________(8_________________I8                                         ",10,117);
usleep(35000);
texto_posicion("__________________8_________________I8                                         ",10,118);
usleep(35000);
texto_posicion("__________________8_________________I8                                         ",10,119);
usleep(35000);
texto_posicion("__________________8,________________I8                                         ",10,120);
usleep(35000);
texto_posicion("__________________Ib________________8I                                         ",10,121);
usleep(35000);
texto_posicion("__________________(8_______________(8\'                                         ",10,122);
usleep(35000);
texto_posicion("___________________8_______________I8                                         ",10,123);
usleep(35000);
texto_posicion("___________________8,______________8I                                         ",10,124);
usleep(35000);
texto_posicion("___________________Ib_____________(8\'                                         ",10,125);
usleep(35000);
texto_posicion("___________________(8_____________I8                                         ",10,126);
usleep(35000);
texto_posicion("___________________`8_____________8I                                         ",10,127);
usleep(35000);
texto_posicion("____________________8____________(8\'                                         ",10,128);
usleep(35000);
texto_posicion("____________________8,___________I8                                         ",10,129);
usleep(35000);
texto_posicion("____________________Ib___________8I                                         ",10,130);
usleep(35000);
texto_posicion("____________________(8___________8\'                                         ",10,131);
usleep(35000);
texto_posicion("_____________________8,_________(8                                         ",10,132);
usleep(35000);
texto_posicion("_____________________Ib_________I8                                         ",10,133);
usleep(35000);
texto_posicion("_____________________(8_________8I                                         ",10,134);
usleep(35000);
texto_posicion("______________________8,________8\'                                         ",10,135);
usleep(35000);
texto_posicion("______________________(b_______(8                                         ",10,136);
usleep(35000);
texto_posicion("_______________________8,______I8                                         ",10,137);
usleep(35000);
texto_posicion("_______________________I8______I8                                         ",10,138);
usleep(35000);
texto_posicion("_______________________(8______I8                                         ",10,139);
usleep(35000);
texto_posicion("________________________8______I8,                                         ",10,140);
usleep(35000);
texto_posicion("________________________8______8_8,                                         ",10,141);
usleep(35000);
texto_posicion("________________________8,_____8_8\'                                         ",10,142);
usleep(35000);
texto_posicion("_______________________,I8_____\"8\"                                         ",10,143);
usleep(35000);
texto_posicion("______________________,8\"8,_____8,                                         ",10,144);
usleep(35000);
texto_posicion("_____________________,8\'_`8_____`b                                         ",10,145);
usleep(35000);
texto_posicion("____________________,8\'___8______8,                                         ",10,146);
usleep(35000);
texto_posicion("___________________,8\'____(a_____`b                                         ",10,147);
usleep(35000);
texto_posicion("__________________,8\'_____`8______8,                                         ",10,148);
usleep(35000);
texto_posicion("__________________I8/______8______`b,                                         ",10,149);
usleep(35000);
texto_posicion("__________________I8-/_____8_______`8,                                         ",10,150);
usleep(35000);
texto_posicion("__________________(8/-/____8________`8,                                         ",10,151);
usleep(35000);
texto_posicion("___________________8I/-/__,8_________`8                                         ",10,152);
usleep(35000);
texto_posicion("___________________`8I/--,I8________-8)                                         ",10,153);
usleep(35000);
texto_posicion("____________________`8I,,d8I_______-8)                                         ",10,154);
usleep(35000);
texto_posicion("______________________\"bdI\"8,_____-I8                                         ",10,155);
usleep(35000);
texto_posicion("___________________________`8,___-I8\'                                         ",10,156);
usleep(35000);
texto_posicion("____________________________`8,,--I8                                         ",10,157);
usleep(35000);
texto_posicion("_____________________________`Ib,,I8                                         ",10,158);
usleep(35000);
texto_posicion("______________________________`I8I                                         ",10,159);
usleep(35000);}









#endif 