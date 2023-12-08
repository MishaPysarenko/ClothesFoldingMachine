#include <string.h>

//#include <avr/wdt.h>

//#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей   A4 - SDA : A5 - SCL

#include <GyverEncoder.h>
#define CLK A1
#define DT A2
#define SW A3
Encoder enc(CLK, DT, SW);
//--------------------------------------------------------------------------------
#define D1 2//{
#define D2 3//
#define D3 4//
#define D4 5//  --датчики для проверки окончание работы двигателя
#define D5 6//--датчик для 5й платформы низ
#define D6 7//}-датчик для 5й платформы верх
#define D7 8//  --датчик для проверки окончания работы запайки
#define ButtonStart A6//кнопка старта
//--------------------------------------------------------------------------------
#define R1 9
#define R2 10
#define R3 11
#define R4 12
#define R5 A0
//--------------------------------------------------------------------------------
unsigned short int cursor = 0; //курсор в меню
unsigned short int Rele[] = {R1,R2,R3,R4,R5};
unsigned short int Sensor[] = {D1,D2,D3,D4,D5,D6,D7};
String menuList[3] = {"Algortm 1", "Algortm 2", "Algortm 3"};
//-----------------------технические функции--------------------------------------
bool waitForSeconds(short int R, short int D) {
  digitalWrite(R, HIGH);
  delay(500);
  unsigned long startTime = millis(); // запоминаем текущее время
  while ((millis() - startTime) < 10000) {
    if(digitalRead(D))
    {
      digitalWrite(R, LOW);
      return 0;
    }
  }
  digitalWrite(R, LOW);
  return 1;
}
void SetInitialPosition(bool initialPosition = 1){
  if(initialPosition)//позиция №1 все опустилось
  {

    EngineRotation(R1, D1);
    EngineRotation(R2, D2);
    EngineRotation(R3, D3);
    EngineRotation(R4, D4);
    EngineRotation(R5, D5);
  }
  else//позиция №2 5я платформа 45*
  {

    EngineRotation(R1, D1);
    EngineRotation(R2, D2);
    EngineRotation(R3, D3);
    EngineRotation(R4, D4);
    EngineRotation(R5, D6);
  }
  delay(3000);
}
bool chekWork(){
  lcd.setCursor(0, 1);
  if(waitForSeconds(R1, D1)){
    lcd.print("Error D1");
    return 0;
  }
  if(waitForSeconds(R2, D2)){
    lcd.print("Error D2");
    return 0;
  }
  if(waitForSeconds(R3, D3)){
    lcd.print("Error D3");
    return 0;
  }
  if(waitForSeconds(R4, D4)){
    lcd.print("Error D4");
    return 0;
  }
  if(waitForSeconds(R5, D5)){
    lcd.print("Error D5");
    return 0;
  }
  return 1;
}
void EngineRotation(unsigned short int R,unsigned short int D){
  digitalWrite(R, HIGH);
  delay(100);
  while(!digitalRead(D))
  {
        
  }
  digitalWrite(R, LOW);
}
void MainLogic()
{
    switch(cursor)
    {
      case 0://Алгоритм 1
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Rele[1], Sensor[1]");
        if(waitForSeconds(R1, D1))
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Error 1");
          while(1){

          }
        }
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Rele[2], Sensor[2]");
        if(waitForSeconds(R2,D2))
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Error 2");
          while(1){

          }
        }
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Rele[3], Sensor[3]");
        if(waitForSeconds(R3, D3))
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Error 3");
          while(1){

          }
        }
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Rele[4], Sensor[4]");
        if(waitForSeconds(R4, D4))
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Error 4");
          while(1){

          }
        }
        //EngineRotation(R4, D4);//4
        break;
      case 1://Алгоритм 2
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Rele[5], Sensor[5]");
        if(waitForSeconds(R5, D5))
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Error 3");
          while(1){

          }
        }
        //EngineRotation(R5, D5);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Rele[1], Sensor[1]");
        if(waitForSeconds(R1, D1))
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Error 3");
          while(1){

          }
        }
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Rele[2], Sensor[2]");
        if(waitForSeconds(R2, D2))
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Error 2");
          while(1){

          }
        }
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Rele[3], Sensor[3]");
        if(waitForSeconds(R3, D3))
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Error 3");
          while(1){

          }
        }
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Rele[4], Sensor[4]");
        if(waitForSeconds(R4, D4))
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Error 4");
          while(1){

          }
        }
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Rele[5], Sensor[6]");
        if(waitForSeconds(R5, D6))
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Error 5");
          while(1){

          }
        }
        break;
      case 2://Алгоритм 3
      break;
    }
}
//------------------------функкции отрисовки---------------------------------------
void DrawMenu(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(menuList[cursor]);
  lcd.setCursor(0, 1);
  lcd.print(menuList[cursor + 1]);

}
//---------------------------------------------------------------------------------
void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(ButtonStart, INPUT);

  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(A0,OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setBacklight(255);
  lcd.setCursor(0, 0);
  lcd.print("Check");
  delay(1000);
  enc.setType(TYPE2);//настройка типа енкодара ------------------------------------------------------------------------------
  lcd.clear();
  lcd.setCursor(0, 0);
  if(!chekWork())
  {
    lcd.setCursor(0, 0);
    lcd.print("Reboot System");
    delay(1000);
    while(1){
      
    }
  }
  lcd.print("Startt System");
  delay(1000);
  DrawMenu();
}

void loop() {
  enc.tick();
  lcd.setCursor(14, 0);
  lcd.print(digitalRead(ButtonStart));
  if(enc.isTurn())
  {
    if(enc.isRight())cursor++;
    else cursor--;
    if(cursor > 2)cursor = 0;
    DrawMenu();
    if(cursor != 0)
    {
      if(waitForSeconds(R5, D6))
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Error");
        while(1){

        }
      }
    }
    else
    {
      if(waitForSeconds(R5, D5))
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Error");
        while(1){

        }
      }    
    }
  }
  if(!(digitalRead(D7)))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(menuList[(cursor)]);
    MainLogic();
    DrawMenu();
  }
}
