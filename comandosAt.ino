void comandosAt()
{

    // Verificar se há comandos disponíveis no monitor serial
    if (Serial.available() > 0)
    {
        // Ler o comando da porta serial
        String command = Serial.readStringUntil('\n');

        // Enviar o comando para o ESP8266
        ESP8266_SERIAL.println(command);

        // Aguardar um pouco para o ESP8266 responder
        delay(1000);

        // Verificar se há resposta do ESP8266
        while (ESP8266_SERIAL.available())
        {
            char c = ESP8266_SERIAL.read();
            Serial.write(c); // Imprimir resposta do ESP8266 no monitor serial
        }
    }

    // Aguardar um pouco antes de enviar outro comando
    delay(1000);
}