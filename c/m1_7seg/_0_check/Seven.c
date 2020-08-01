#include "SevenControl.c"

void main()
{
	SevenControl_start();
	while(SevenControl_is_end() == false) {
		SevenControl_update();
	}
}
