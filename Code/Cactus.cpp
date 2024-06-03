#include "Cactus.h"

Cactus::Cactus(int posicionInicial) {  
  x = posicionInicial;  
}

void Cactus::mover() {   
  x = x - 1;
}

int Cactus::getPosicion() {
  return x;
}

void Cactus::setPosicion(int pos){
  x = pos;
}

