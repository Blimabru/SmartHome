void limparBufferSerial() {
  while (ESP8266_SERIAL.available() > 0) {
    ESP8266_SERIAL.read(); // Lê e descarta os dados disponíveis no buffer
  }
}
