#ifndef AVE_h
#define AVE_h
#include "Arduino.h"

class Ave {
  private:    
    int x;         
    int estado;

  public:
    Ave(int posicionInicial);
    void mover();
    int getEstado();
    int getPosicion();    
    void setPosicion(int pos); 
};

#endif