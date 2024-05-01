void conectaWifi() {

  bool conectado = false;
  String resposta = "";

  Serial.println("Conectando Wi-Fi...\n");

  while (!conectado) {
    for (int i = 0; i < redes; i++) {

      Serial.println("- Conectando a rede: " + listaSsids[i] + "\n");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Conectando a:  ");

      lcd.setCursor(0, 1);
      lcd.print(listaSsids[i]);

      limparBufferSerial();  // Limpa o buffer serial antes de enviar o comando AT

      ESP8266_SERIAL.print("AT+CWJAP=");
      ESP8266_SERIAL.print("\"");
      ESP8266_SERIAL.print(listaSsids[i]);
      ESP8266_SERIAL.print("\",\"");
      ESP8266_SERIAL.print(listaSenhas[i]);
      ESP8266_SERIAL.println("\"");

      resposta = aguardarResposta(15 /*segundos*/);

      if (resposta.indexOf("OK") != -1) {
        Serial.println("Conectado!\n");
        Serial.println("-------------------------\n");
        conectado = true;

        piscaLcdDuplo();

        lcd.setCursor(0, 0);
        lcd.print("   Conectado!   ");

        lcd.setCursor(0, 1);
        lcd.print("WiFi: " + listaSsids[i]);

        delay(1000);

        break; // Sai do loop for se a conexão for bem-sucedida

      } else if (resposta.indexOf("FAIL") != -1) {
        Serial.println("Falha\n");
        conectado = false;

      } else {
        Serial.println("Erro não especificado: " + resposta);
        conectado = false;
      }

      Serial.println("-------------------------\n");
    }
  }
}