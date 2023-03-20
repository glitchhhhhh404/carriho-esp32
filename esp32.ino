#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

#define IR_RECEIVE_PIN 15 // define o pino que recebe o sinal do controle remoto

IRrecv irrecv(IR_RECEIVE_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Habilita o recebimento do sinal do controle remoto
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); // Exibe o valor hexadecimal do sinal recebido
    irrecv.resume(); // Reinicia o recebimento para receber o próximo sinal
  }
}
