Kod programu:
#include <reg52.h>
#include <intrins.h>
#include "lcd.h"
#include "mkd51sim.h"
#include "<conio.h>";
#define CLEAR_GRAPH_MEMORY 2
#define COPY_SCREEN 1
xdata char PTWY _at_ 0x8008;
xdata unsigned char POT1 _at_ 0x8006;
unsigned char xdata PTWE _at_ 0x8008;
//unsigned char xdata PTWY _at_ 0x8009;
unsigned char xdata PTSEG _at_ 0x8018;
unsigned char xdata POT0 _at_ 0x8005;
unsigned char xdata LCDWRITE _at_ 0x800a;
unsigned char xdata tekst1[32]="NACISNIJ X0 W CIAGU 3 SEKUND";
unsigned char xdata tekst2[32]="TERAZ NACISNIJ X1 ";
unsigned char xdata tekst3[32]="PRZEKREC POT1 DO KONCA";
unsigned char xdata tekst4[32]="NACISNIJ X4 I X5 JEDNOCZESNIE";
unsigned char xdata tekst5[32]="NACISNIJ X5 I PRZEKREC POT0 ";
unsigned char xdata tekst6[32]="NACISNIJ X4 I X1 JEDNOCZESNIE";
unsigned char xdata tekst7[32]="DZIEKUJE ZA GRE WYNIK DIODY";
bit flag=0;
char kwys[] = {0, 1, 2, 3};
int presc=0;
int x=1;
void main(void) {
int w0, w1, w2, w3, x0, x1, x2, x3,x4,w4,x5,w5;
POT0=0;
POT1=0;
TMOD=1;
IE=0x82;
TH0=(-2500)>>8;
TL0=(-2500)&0xff;
TCON=0x10;
while(1){
POT1=0;
w0=1;
w1=2;
w2=4;
w3=8;
w4=16;
w5=32;
x0 = w0 & PTWE;
x1 = w1 & PTWE;
x2 = w2 & PTWE;
x3 = w3 & PTWE;
x4 = w4 & PTWE;
x5 = w5 & PTWE;
switch (x){
case 1: disptext(tekst1); if (x0==0) {PTWY=0x1;} break;
case 2: disptext(tekst2); if (x1==0) {PTWY=PTWY+0x2;} break;
case 3: disptext(tekst3); if (POT1>0xC8) {PTWY=PTWY+0x4;} break;
case 4: disptext(tekst4); if (x4==0&&x5==0) {PTWY=PTWY+0x8;} break;
case 5: disptext(tekst5); if (x5==0&&POT0>0xC8) {PTWY=PTWY+0x16;} break;
case 6: disptext(tekst6); if (x1==0&&x4==0) {PTWY=PTWY+0x32;} break;
case 7: {disptext(tekst7);
}
}
if(flag==1) x++;
flag=0;
}
}
void a() interrupt 1 {
TH0=(-2500)>>8;
TL0=(-2500)&0xff;
if(++presc==1500)
{ presc=0;
flag=1;
}
}
