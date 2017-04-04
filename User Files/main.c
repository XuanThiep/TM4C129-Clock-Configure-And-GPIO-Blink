#include <stdbool.h>
#include <stdint.h>
#include "driverlib/inc/hw_memmap.h"
#include "driverlib/inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"



int main(void)
{
	/* Configure system clock using external clock and PLL */
	SysCtlClockFreqSet(SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN | SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480,
						120000000);

	/* Enable GPIO Peripheral Clock */
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);

	/* Configure Led as gpio output */
	GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	while(1)
	{
		GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0 | GPIO_PIN_1 ,0xff);
		SysCtlDelay(2000000);
		GPIOPinWrite(GPIO_PORTN_BASE,GPIO_PIN_0 | GPIO_PIN_1 ,0x00);
		SysCtlDelay(2000000);
	}
}
