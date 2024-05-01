void configuraEsp() {

  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);
  lcd.println("  Conectando ao ");
  lcd.setCursor(0, 1);
  lcd.println("     Wi-Fi...   ");

  Serial.println("-------------------------\n");
  Serial.println("Configurando ESP8266...\n");

  limparBufferSerial(); // Limpa o buffer serial antes de enviar um novo comando AT
  ESP8266_SERIAL.println("AT+RESTORE");
  Serial.println("- Restaurando ESP:\n");
  Serial.println(aguardarResposta(1));
  Serial.println("\n");

  limparBufferSerial(); // Limpa o buffer serial antes de enviar um novo comando AT
  ESP8266_SERIAL.println("AT+CWMODE=1");
  Serial.println("- Alterando para modo Estação:\n");
  Serial.println(aguardarResposta(1));
  Serial.println("-------------------------\n");

  // Conectando Wi-Fi
  conectaWifi();

}