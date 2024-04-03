void animacaoInicial()
{

  int tempoAnimacaoPontinhos = 100;

  lcd.clear();
  lcd.setBacklight(HIGH);

  Serial.println("Iniciando sistema... \n");

  lcd.setCursor(0, 0);
  lcd.print("    Iniciando   ");

  lcd.setCursor(0, 1);
  lcd.print("                ");

  // Animação de pontos
  for (int i = 0; i < 16; i++)
  {
    lcd.setCursor(i, 1);
    lcd.print(".");
    delay(tempoAnimacaoPontinhos);
  }

  lcd.setBacklight(LOW);
  delay(300);
  lcd.setBacklight(HIGH);

  lcd.clear();

  Serial.println("***************");
  Serial.println("*  SmartHome  *");
  Serial.println("*   Versão 2  *");
  Serial.println("*************** \n");

  lcd.setCursor(0, 0);
  lcd.print("   SmartHome    ");

  lcd.setCursor(0, 1);
  lcd.print("    Versao 2    ");
  delay(1000);

  lcd.setBacklight(LOW);
  lcd.clear();
}