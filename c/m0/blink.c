#include <wiringPi.h>
#define pin 3
int main (void)
{
  wiringPiSetup () ;
  pinMode (pin, OUTPUT) ;
  for (;;)
  {
    digitalWrite (pin, HIGH) ; delay (500) ;
    digitalWrite (pin,  LOW) ; delay (500) ;
  }
  return 0 ;
}