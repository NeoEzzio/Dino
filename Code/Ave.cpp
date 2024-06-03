#include "Ave.h"

Ave::Ave(int posicionInicial) {  
  estado = 5;
  x = posicionInicial;  
}

void Ave::mover() {   
  x = x - 1;
  if ( estado == 5 ) estado = 6;
  else estado = 5;
}

int Ave::getPosicion() {
  return x;
}

int Ave::getEstado() {
  return estado;
}

void Ave::setPosicion(int pos){
  x = pos;
}
