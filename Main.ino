#include <LiquidCrystal_I2C.h>
#include "credenciais.h"

#define ESP8266_BAUDRATE 115200  // Velocidade da comunicação serial com o ESP8266
#define ESP8266_SERIAL Serial1   // Defina a porta serial que está conectada ao ESP8266

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicializa o display no endereco 0x27

void setup() {
  Serial.begin(9600);                      // Inicializa a comunicação serial para debug
  ESP8266_SERIAL.begin(ESP8266_BAUDRATE);  // Inicializa a comunicação serial com o ESP8266
  lcd.init();

  animacaoInicial();
  configuraEsp();
  telaEspera();
}

void loop() {
  //comandosAt(); // Imprime Comandos AT no monitor Serial para testar resposta do ESP8266.
}