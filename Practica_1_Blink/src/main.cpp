#include <Arduino.h>
int pin_DAC=25;
int pin_ADC=34;
int LED=13;

void led(){
  for(int i=0;i<10;i++){
    digitalWrite(LED,HIGH);
    Serial.println("ON");
    delay(500);
    digitalWrite(LED,LOW);
    Serial.println("OFF");
    delay(500);
  }
}

void adc_dac(){
  int valor=0;
  for (int cont= 0; cont < 256; cont++){
    dacWrite(pin_DAC, cont);
    delay(50);
    valor = analogRead(pin_ADC);
    valor = map(valor, 0, 4096, 0, 255);
    Serial.println("VALOR:");
    Serial.println(valor);
    delay(100);
  }
}

void opcions(){
    Serial.println("Opcions");
    Serial.println("1. LED");
    Serial.println("2. ADC");
}

void menu(){
  char entrada;
  int b=0;
  if(b==0){
    opcions();
    entrada=Serial.read();
    }
  if(entrada=='1'){
    b=1;
    led();
    opcions();
    entrada=Serial.read();
  }
  else if(entrada=='2'){
    b=1;
    adc_dac();
    opcions();
    entrada=Serial.read();
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
  analogReadResolution(12);
}

void loop() {
  delay(100);
  if (Serial.available()){
    menu();
  }
}