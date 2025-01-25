#include "Arduino.h"

void setup()
{
    Serial.begin(115200);  // Inicialitzar Serial (UART0)
    Serial2.begin(115200, SERIAL_8N1, 17, 16); // Inicialitzar Serial2 (UART2) amb pins GPIO17 (TX2) i GPIO16 (RX2)
}

void loop()
{
    // Leer datos de la UART0 y enviarlos a la UART2
    if (Serial.available())
    {
        char c = Serial.read();
        Serial2.write(c);
    }
    // Leer datos de la UART2 y enviarlos a la UART0
    if (Serial2.available())
    {
        char c = Serial2.read();
        Serial.write(c);
    }
}
