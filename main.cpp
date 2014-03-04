#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>

#define IZQUIERDA 75
#define DERECHA 77

char avion_l1[]={' ',' ',' ', '*',' ',' ',' ',0};        
char avion_l2[]={' ',' ','*', '*','*',' ',' ',0};
char avion_l3[]={' ','*',' ', '*',' ','*',' ',0};

char explosion_l1[]={' ',' ','*','*',' ',' ',' ',0};      
char explosion_l2[]={' ','*','*','*','*',' ',' ',0};
char explosion_l3[]={' ',' ','*','*',' ',' ',' ',0};

char explosion_r1[]={'*',' ','*','*',' ','*',' ',0};       
char explosion_r2[]={' ','*','*','*','*',' ',' ',0};
char explosion_r3[]={'*',' ','*','*',' ','*',' ',0};

char borrar_avion[]={' ',' ',' ',' ',' ',' ',' ',0};

int Num_vidas = 3;
int Corazones = 3;

int ix = 40;
int iy = 19;

int y = 8 , x = 12;
int yy = 12, xx = 17;
int y1 = 6 , x1 = 58;
int y2 = 9 , x2 = 70;
int y3 = 5 , x3 = 43;
int y4 = 4 , x4 = 33;
int y5 = 14 , x5 = 22;
int y6 = 10 , x6 = 40;
int y7 = 8 , x7 = 53;
int y8 = 6 , x8 = 64;
int i,v;

int repeticion = 0 , nivel = 1;
bool condicion = false;

void gotoxy(int x, int y){
     
     HANDLE hCon;
     COORD dwPos;
     
     dwPos.X = x;
     dwPos.Y = y;
     
     hCon = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleCursorPosition(hCon, dwPos);
     
     }

void vidas(int vi){
     gotoxy(2,1); printf("VIDAS %d", vi);
     }

void Barra_salud(int n){
     
     gotoxy(72,1); printf(" ");
     gotoxy(73,1); printf(" ");
     gotoxy(74,1); printf(" ");
     
     for (v = 0; v < n; v++){
         
         gotoxy(72+v,1); printf("%c",3);
         
         }
     
     }

void Explosion(void){
     
     gotoxy(ix,iy); puts(explosion_l1);
     gotoxy(ix,iy+1); puts(explosion_l2);
     gotoxy(ix,iy+2); puts(explosion_l3);
     
     Sleep(380);
     
     gotoxy(ix,iy); puts(explosion_r1);
     gotoxy(ix,iy+1); puts(explosion_r2);
     gotoxy(ix,iy+2); puts(explosion_r3);
     
     Sleep (380);
     
     gotoxy(ix,iy); puts(avion_l1);
     gotoxy(ix,iy+1); puts(avion_l2);
     gotoxy(ix,iy+2); puts(avion_l3);
     
     }
     
void jugar(void){
     
     //rutina asteroides
     
     gotoxy(x,y); printf("%c",2);
     gotoxy(xx,yy); printf("%c",2);
     gotoxy(x1,y1); printf("%c",2);
     gotoxy(x2,y2); printf("%c",2);
     gotoxy(x3,y3); printf("%c",2);
     gotoxy(x4,y4); printf("%c",2);
     gotoxy(x5,y5); printf("%c",2);
     gotoxy(x6,y6); printf("%c",2);
     gotoxy(x7,y7); printf("%c",2);
     gotoxy(x8,y8); printf("%c",2);
     Sleep(70);
     
     gotoxy(x,y); printf(" ");
     gotoxy(xx,yy); printf(" ");
     gotoxy(x1,y1); printf(" ");
     gotoxy(x2,y2); printf(" ");
     gotoxy(x3,y3); printf(" ");
     gotoxy(x4,y4); printf(" ");
     gotoxy(x5,y5); printf(" ");
     gotoxy(x6,y6); printf(" ");
     gotoxy(x7,y7); printf(" ");
     gotoxy(x8,y8); printf(" ");
     if(y > 20){
          
          y=4;
          x= (rand() % 70) + 6;
          }
     if(yy > 20){
          
          yy=4;
          xx= (rand() % 70) + 6;
          }
     if(y1 > 20){
          
          y1=4;
          x1= (rand() % 70) + 6;
          }
     if(y2 > 20){
          
          y2=4;
          x2= (rand() % 70) + 6;
          }
     if(y3 > 20){
          
          y3=4;
          x3= (rand() % 70) + 6;
          }
          
     if(y4 > 20){
          
          y4=4;
          x4= (rand() % 70) + 6;
          }     
     if(y5 > 20){
          
          y5=4;
          x5= (rand() % 70) + 6;
          }
     
     if(y6 > 20){
          
          y6=4;
          x6= (rand() % 70) + 6;
          }
     
     if(y7 > 20){
          
          y7=4;
          x7= (rand() % 70) + 6;
          }
     
     if(y8 > 20){
          
          y8=4;
          x8= (rand() % 70) + 6;
          }
     
     
     
     
     //Mover avion
     if(kbhit()){
                 unsigned char tecla = getch();
                 
                 switch(tecla){
                               case IZQUIERDA:
                                    if(ix>4){
                                            
                                            gotoxy(ix,iy);puts(borrar_avion);
                                            gotoxy(ix,iy+1);puts(borrar_avion);
                                            gotoxy(ix,iy+2);puts(borrar_avion);
                                            ix-=2;

                                            gotoxy(ix,iy);puts(avion_l1);
                                            gotoxy(ix,iy+1);puts(avion_l2);
                                            gotoxy(ix,iy+2);puts(avion_l3);

                                            }
                                            break;
                                case DERECHA:
                                     if (ix<70){
                                            
                                            gotoxy(ix,iy);puts(borrar_avion);
                                            gotoxy(ix,iy+1);puts(borrar_avion);
                                            gotoxy(ix,iy+2);puts(borrar_avion);
                                            ix+=2;

                                            gotoxy(ix,iy);puts(avion_l1);
                                            gotoxy(ix,iy+1);puts(avion_l2);
                                            gotoxy(ix,iy+2);puts(avion_l3);

                                               }
                               break;
                               
                               }//switch
     }//if
     
     //Golpes asteroides
     
     if((x>ix && x<ix+6 && y==iy-1)||(xx>ix && xx<ix+6 && yy==iy-1)||(x1>ix && x1<ix+6 && y1==iy-1)||(x2>ix && x2<ix+6 && y2==iy-1)||(x3>ix && x3<ix+6 && y3==iy-1)||(x4>ix && x4<ix+6 && y4==iy-1)||(x5>ix && x5<ix+6 && y5==iy-1)||(x6>ix && x6<ix+6 && y6==iy-1)||(x7>ix && x7<ix+6 && y7==iy-1)||(x8>ix && x8<ix+6 && y8==iy-1)){
              Corazones --;
              Barra_salud(Corazones);
              printf("\a");
              }
     
     gotoxy(ix,iy);puts(avion_l1);
     gotoxy(ix,iy+1);puts(avion_l2);
     gotoxy(ix,iy+2);puts(avion_l3);
     
     if(!Corazones){
                    Num_vidas--;
                    vidas(Num_vidas);
                    Explosion();
                    Corazones = 3;
                    Barra_salud(Corazones);
                  }
     
     y++;
     yy++;
     y1++;
     y2++;
     y3++;
     y4++;
     y5++;
     y6++;
     y7++;
     y8++;     
     
     }
     
int main(){
    
    vidas(Num_vidas);
    Barra_salud(Corazones);
    gotoxy(ix,iy);puts(avion_l1);
    gotoxy(ix,iy+1);puts(avion_l2);
    gotoxy(ix,iy+2);puts(avion_l3);
    
    while(Num_vidas > 0){
    jugar();
}
    
    getch();
    return 0;
    }   
