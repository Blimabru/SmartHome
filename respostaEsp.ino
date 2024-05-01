String aguardarResposta(int tempoEspera) {

  String resposta, respEsp = "";

  delay(1000 * tempoEspera);

  while (ESP8266_SERIAL.available()) {
    char c = ESP8266_SERIAL.read();
    respEsp += c;
  }

  /*if (respEsp.indexOf("OK") != -1) {
    resposta = "Ok\n";
    
  }

  else*/
  if (respEsp.indexOf("ERROR" || "FAIL") != -1) {
    resposta = "Falha\n";

  }

  else if (respEsp.indexOf("busy") != -1) {
    resposta = "ESP8266 Ocupado\n";

    delay(1000);
  }

  else {
    resposta = respEsp;
    //Serial.println("Erro: " + respEsp);
    delay(1000);
  }
  limparBufferSerial();  // Limpa o buffer serial após receber a resposta do ESP8266
  return resposta;
}