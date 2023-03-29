#include <LiquidCrystal.h>

LiquidCrystal lcd (12,11,10,9,8,7);
unsigned char corrente,aux=1,aux2=1,aux3=1,aux4=1,saida;
float valor;




void setup() {
  pinMode(1, INPUT_PULLUP); //botao incrementa grosso
  pinMode(2, INPUT_PULLUP); // botao decrementa grosso
  pinMode(3, OUTPUT); //saida PWM
  pinMode(4, INPUT_PULLUP);// botao liga desliga
  pinMode(5, INPUT_PULLUP);// botao incrementar
  pinMode(6, INPUT_PULLUP);// botao decrementar
  lcd.begin(16,2);// ativa display16x2
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("carga-eletronica");
  delay(3000);
  lcd.clear();  
  lcd.setCursor(0,0);
  lcd.print("corrente:");
  lcd.setCursor(14,0);
  lcd.print("A");


}

void loop() {
  if(digitalRead(5) == 0 && corrente < 255) //se o botao incrementar for pressionado
{                                   
  corrente++;
  delay(500);
  
}


if(digitalRead(6) == 0 && corrente>0) // se o botao decrementar for pressionado
{
corrente--;
delay(500);
}



if(digitalRead(1) == 0 && corrente < 231 && aux == 1)
{
  corrente = (corrente + 25);
  aux=0;
  delay(100);
}


if(digitalRead(1)==1)// se botao estiver solto permite incrementar
{
  aux=1;
  delay(100);
}


if(digitalRead(2)==0 && corrente>25 && aux2 ==1)
{
  corrente= (corrente - 25);
  aux2=0;
  delay(100);
}


if(digitalRead(2)==1)
{
  aux2=1;
  delay(100);
  analogWrite(3,valor);
  lcd.setCursor(10,0);
  lcd.print(valor);


}

if(digitalRead(4) == 0 && aux3== 1)
{
  aux4 = !aux4;  
  aux3= 0;
  delay(100);  
}

if(digitalRead(4) == 1 )
{
aux3= 1;
delay(100);
}


if(aux4==1)
{
  saida = 0;
  lcd.setCursor(0,1);
  lcd.print("saida desligada");
}

if(aux4 == 0){
  saida = corrente;
  lcd.setCursor(0,1);
  lcd.print("saida ligada    ");
}


analogWrite(3, saida);
valor = corrente/50.0;
lcd.setCursor(10,0);
lcd.print(valor);

}



