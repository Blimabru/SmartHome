 void alternarModoEsp() {
  
  ESP8266_SERIAL.println("AT+CWMODE?");

  String modoOperacao = verificaModo();

  if (modoOperacao != "Estação") {
    ESP8266_SERIAL.println("AT+CWMODE=1");
    delay(1000);
    Serial.println("Alternado para modo estação.\n");
  }
  
  else {
    Serial.println("Ok\n");
  }
}
