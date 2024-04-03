String aguardarResposta(int tempoEspera) {

  String resposta, respEsp = "";

  delay(1000 * tempoEspera);

  while (ESP8266_SERIAL.available()) {
    char c = ESP8266_SERIAL.read();
    respEsp += c;
  }

  if (respEsp.indexOf("OK") != -1) {
    resposta = "Ok\n";
    //Serial.println(resposta);
  }

  else if (respEsp.indexOf("ERROR" || "FAIL") != -1) {
    resposta = "Falha\n";
    //Serial.println(resposta);
  }

  else if (respEsp.indexOf("busy") != -1) {
    resposta = "ESP8266 Ocupado\n";
    //Serial.println(resposta);
    delay(1000);
  }

  else {
    resposta = respEsp;
    //Serial.println("Erro: " + respEsp);
    delay(1000);
  }
  return resposta;
}

String verificaModo() {

  String resposta, respEsp = "";

  delay(1000);

  while (ESP8266_SERIAL.available()) {
    char c = ESP8266_SERIAL.read();
    respEsp += c;
  }

  if (respEsp.indexOf("CWMODE:1") != -1) {
    resposta = "Estação";
    //Serial.println(resposta);
  }

  else if (respEsp.indexOf("CWMODE:2") != -1) {
    resposta = "Ponto de acesso";
    //Serial.println(resposta);
  }

  else if (respEsp.indexOf("CWMODE:3") != -1) {
    resposta = "Misto";
    //Serial.println(resposta);
  }

  else if (respEsp.indexOf("busy") != -1) {
    resposta = "ESP8266 Ocupado";
    //Serial.println(resposta);
    delay(1000);
  }

  else {
    resposta = respEsp;
    //Serial.println("Erro: " + respEsp);
    delay(1000);
  }

  return resposta;
}

// void verificaConexao() {

//   String respEsp = "";
//   bool conectado = 0;

//   delay (5000);

//   ESP8266_SERIAL.print("AT+CIFSR");

//   delay(3000);

//     while (ESP8266_SERIAL.available()) {
//     char c = ESP8266_SERIAL.read();
//     respEsp += c;
//   }

//   Serial.println(respEsp);

//   if (respEsp.indexOf("0.0.0.0") != -1) {
//     conectado = 0;
//     Serial.println(conectado);
//   }

//   else {
//     Serial.print("Conectado");
//   }

// }