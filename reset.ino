#include <avr/wdt.h>

void resetArduino() {
  wdt_disable();  // Desativa o timer do watchdog para evitar que o reset ocorra imediatamente
  wdt_enable(WDTO_15MS);  // Habilita o timer do watchdog com um atraso curto
  while (1);  // Aguarda o reset ocorrer
}