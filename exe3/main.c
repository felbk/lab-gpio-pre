#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
  stdio_init_all();
  const int BTred = 28;
  const int LEDred = 4;
  const int BTgreen = 26;
  const int LEDgreen = 6;

  gpio_init(BTred);
  gpio_init(BTgreen);
  gpio_init(LEDred);
  gpio_init(LEDgreen);
  gpio_set_dir(BTgreen, false);
  gpio_set_dir(BTred, false);
  gpio_set_dir(LEDgreen, true);
  gpio_set_dir(LEDred, true); //true = out , false = in
  gpio_pull_up(BTgreen);
  gpio_pull_up(BTred);
  bool red = false ;
  bool green = false ;


  while (true) {
    if (!gpio_get(BTred)) {
      if (red){
        red = false;
        gpio_put(LEDred, 0);
      }
      else{
        red = true;
        gpio_put(LEDred, 1);
      }
       while (!gpio_get(BTred)) {
      };
      
    }
    if (!gpio_get(BTgreen)) {
       if (green){
        green = false;
        gpio_put(LEDgreen, 0);
      }
      else{
        green = true;
        gpio_put(LEDgreen, 1);
      }
       while (!gpio_get(BTgreen)) {
      };
    }
    
  }
}
