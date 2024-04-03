bool conectaWifi() {

  Serial.println("Conectando Wi-Fi...\n");

  ESP8266_SERIAL.println("AT+CWQAP");
  delay(500);

  for (int i = 0; i < redes; i++) {

    Serial.println("Conectando a rede: " + listaSsids[i] + "\n");

    ESP8266_SERIAL.print("AT+CWJAP=");
    ESP8266_SERIAL.print("\"");
    ESP8266_SERIAL.print(listaSsids[1]);
    ESP8266_SERIAL.print("\",\"");
    ESP8266_SERIAL.print(listaSenhas[1]);
    ESP8266_SERIAL.println("\"");

    Serial.println(aguardarResposta( 5 /*segundos*/ ));
  }
}