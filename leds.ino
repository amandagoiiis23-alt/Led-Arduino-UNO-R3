#include <ShiftRegister74HC595.h>

#define dadosPin 9
#define latchPin 10
#define clockPin 11

ShiftRegister74HC595<1> registrador(dadosPin, clockPin, latchPin);

void desligar() {
  registrador.setAllLow();
  delay(1000);
}

void ligar() {
  registrador.setAllHigh();
  delay(1000);
}

void intercalar() {
  uint8_t valorPin[] = { B10101010 };
  registrador.setAll(valorPin);
  delay(1000);

  uint8_t valorPin1[] = { B01010101 };
  registrador.setAll(valorPin1);
  delay(1000);
}

void efeito() {
  for (int i = 0; i < 8; i++) {
    registrador.set(i, HIGH);
    delay(500);
  }

  for (int i = 7; i >= 0; i--) {
    registrador.set(i, LOW);
    delay(500);
  }
}

void setup() {
  registrador.setAllLow();
}

void loop() {
  ligar();
  desligar();
  intercalar();
  desligar();
  efeito();
  desligar();
}