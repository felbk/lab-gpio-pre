#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
  stdio_init_all();
  const int r = 5 ; 
  const int p = 8 ;
  const int b = 11 ; 
  const int y = 15 ; 
  const int ordem[] = {r,p,b,y};

  const int BT = 28 ;
  for (int i = 0; i<4 ; i++){
    gpio_init(ordem[i]);
    gpio_set_dir(ordem[i],true); //out

  }
  gpio_init(BT);
  gpio_set_dir(BT, false);
  gpio_pull_up(BT);

  while (true) {
    if (!gpio_get(BT)){
      for (int i = 0 ; i<4 ; i++){
        gpio_put(ordem[i],1);
        sleep_ms(300); 
        gpio_put(ordem[i],0);

      }
    }
    // Use delay de 300 ms entre os estados!
  }
}
