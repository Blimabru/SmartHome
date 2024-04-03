void configuraEsp() {

  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);
  lcd.println("  Conectando ao ");
  lcd.setCursor(0, 1);
  lcd.println("     Wi-Fi...   ");

  Serial.println("Configurando ESP8266...\n");

  // Definindo ESP8266 como modo Estação
  alternarModoEsp();

  // Conectando Wi-Fi
  conectaWifi();

}
