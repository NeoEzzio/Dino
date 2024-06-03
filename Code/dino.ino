#include <LiquidCrystal.h>
#include "Dinosaurio.h"
#include "Cactus.h"
#include "Ave.h"

LiquidCrystal lcd(22, 23, 5, 18, 19, 21);
Dinosaurio dino;
Cactus cactus(16);
Ave ave(20);

const int buzzerPin = 25;  // Pin del buzzer

// Diseño en 1B
byte dinoReposo[8] = {
    B00000, B00000, B00111, B00101, B10111, B10100, B01101, B01100
};
byte dinoCamina1[8] = {
    B00000, B00111, B00101, B10111, B10100, B01110, B01100, B00010
};
byte dinoCamina2[8] = {
    B00000, B00111, B00101, B10111, B10100, B01110, B01100, B10000
};
byte dinoSalta[8] = {
    B00111, B00101, B10111, B10100, B01101, B01100, B10000, B00000
};
byte cactus1[8] = {
    B00000, B00000, B00001, B10101, B01101, B00110, B00100, B00100
};
byte ave1[8] = {
    B00000, B00100, B11111, B00000, B00000, B00000, B00000, B00000
};
byte ave2[8] = {
    B00000, B00000, B11111, B00100, B00000, B00000, B00000, B00000
};

// Para el botón
struct Button {
    const uint8_t PIN;
    bool pressed;
};
Button button1 = {4, false};

int velocidad = 300;
bool perdio = false;
int score = 0;

void reiniciarJuego();
void mostrarEstadoFinal();

void IRAM_ATTR isr() {
    button1.pressed = true;
}

void setup() {
    lcd.begin(16, 2);
    Serial.begin(115200);
    pinMode(button1.PIN, INPUT_PULLUP);
    attachInterrupt(button1.PIN, isr, FALLING);

    pinMode(buzzerPin, OUTPUT);  // Configura el pin del buzzer como salida

    lcd.createChar(0, dinoReposo);
    lcd.createChar(1, dinoCamina1);
    lcd.createChar(2, dinoCamina2);
    lcd.createChar(3, dinoSalta);
    lcd.createChar(4, cactus1);
    lcd.createChar(5, ave1);
    lcd.createChar(6, ave2);

    lcd.setCursor(13, 0);
    lcd.print(score);

    lcd.setCursor(0, 1);
    lcd.write(byte(0));

    delay(4000);
}

void loop() {
    randomSeed(analogRead(score));
    if (!perdio) {
        int dif = cactus.getPosicion() - ave.getPosicion();
        int pos = 16;
        lcd.clear();

        // Si se presiona el btn
        if (button1.pressed) {
            dino.saltar();
            lcd.setCursor(0, 0);
            button1.pressed = false;
            tone(buzzerPin, 1000, 200);  // Sonido para el salto
        } else {
            lcd.setCursor(0, 1);
            dino.caminar();
        }

        // Dibujar
        lcd.write(byte(dino.getEstado()));
        cactus.mover();
        lcd.setCursor(cactus.getPosicion(), 1);
        lcd.write(byte(4));
        ave.mover();
        lcd.setCursor(ave.getPosicion(), 0);
        lcd.write(byte(ave.getEstado()));
        lcd.setCursor(13, 0);
        lcd.print(score);

        // Si llegan al final
        if (cactus.getPosicion() < 0) {
            if (dif > 2) pos = random(16, 18);
            else pos = 16;
            cactus.setPosicion(pos);
        }
        if (ave.getPosicion() < 0) {
            if (dif > 2) pos = random(16, 18);
            else pos = 16;
            ave.setPosicion(pos);
        }

        // Aumentar velocidad
        if (score == 10) velocidad = 250;
        if (score == 15) velocidad = 200;

        // Cuando se encuentre con un elemento
        if (dino.getXPosicion() == ave.getPosicion()) {
            if (dino.getYPosicion() == 1) {
                perdio = true;
                Serial.println("Ave");
            }
            score++;
        }
        if (dino.getXPosicion() == cactus.getPosicion()) {
            if (dino.getYPosicion() == 0) {
                perdio = true;
                Serial.println("Cac");
            }
            score++;
        }

        delay(velocidad);
    } else {
        mostrarEstadoFinal();
        if (button1.pressed) {  // Verifica el botón de reinicio en el estado de juego inactivo
            button1.pressed = false;
            reiniciarJuego();
        }
    }
}

void mostrarEstadoFinal() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Score:");
    lcd.print(score);
    lcd.setCursor(0, 1);
    lcd.print("Fin del Juego...");
    delay(1000);
}

void reiniciarJuego() {
    lcd.clear();
    cactus.setPosicion(16);
    ave.setPosicion(10);
    score = 0;
    perdio = false;
    lcd.setCursor(13, 0);
    lcd.print(score);
    delay(1000);
}
