void comandosAt() {

  // Verificar se há comandos disponíveis no monitor serial
  if (Serial.available() > 0) {
    // Ler o comando da porta serial
    String command = Serial.readStringUntil('\n');

    limparBufferSerial(); // Limpa o buffer serial antes de enviar um novo comando AT
    ESP8266_SERIAL.println(command); // Enviar o comando para o ESP8266
  }

  // Verificar se há resposta do ESP8266
  while (ESP8266_SERIAL.available()) {
    char c = ESP8266_SERIAL.read();
    Serial.write(c);  // Imprimir resposta do ESP8266 no monitor serial
  }

  // Aguardar um pouco antes de enviar outro comando
  delay(1000);
}