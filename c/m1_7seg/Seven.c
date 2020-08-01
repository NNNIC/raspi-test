#include <wiringPi.h>
#include "SevenControl.c"

int main()
{
	SevenControl_start();
	while(SevenControl_is_end() == false) {
		SevenControl_update();
	}
	return 0;
}
