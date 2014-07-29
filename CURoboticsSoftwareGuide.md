AEMQ notes for software development:

- Install Atmel Studio 6.1 update 1.1 (build 2674), without .NET 4.0 and MSVS Shell
- During installation, you should be prompted to first install Atmel USB drivers,
	which are needed
- After installing, open Atmel Studio and start a new example project
- Choose the project for the SAM4S Xplained Pro Starter Kit
- Edit the main.c main() function by declaring a volatile int variable and looping
	while incrementing the variable, modulus 2000000. Add an if check for the
	variable equal to 1000000, and inside, use "ioport_toggle_pin_level(LED_0_PIN);"
	For example, main() might look like this:
	```
	int main( void ) {
		volatile int i;
		board_init();
		sysclk_init();
	
		for(;;) {
			if( i == 1000000 )
				ioport_toggle_pin_level(LED_0_PIN);
			i = (i+1)%2000000;
		}
	}
	```
- Now, plug a USB A to micro USB A into your computer and into the DEBUG USB port
	on the Atmel Xplained Pro board
- The green power light should come on
- Wait if any drivers need to be installed

- Hopefully Atmel Studio will detect the SAM4S -- toward the top right of the IDE,
	you should see SAM4SD32C as the device.  The programmer should be set to
	SWD on EDBG. You may need to set this manually by clicking on device programming.
	Also, make sure your programming/debug settings are such that the board will
	boot from Flash 0.  The programming clock can be any speed that is "slow enough"

- Press the green debug arrow in Atmel Studio to compile, load, and launch the
	program in debug mode on the board
- If successful, the yellow LED0 will start blinking (LED0, not the status LED!)
- If this doesn't work, ask someone what you are doing wrong and/or update this guide
- After you have completed these steps, try running FreeRTOS blinky
- Once these both work, you are ready to start developing code for AEMQ
- FreeRTOS Tutorial: http://www.freertos.org/tutorial/
- FreeRTOS Overview: http://aosabook.org/en/freertos.html


- Setup your GitHub account and install Git
- Fork the AEMQ repository so you have your own copy to work on
- Commit changes often
- Create a pull request when you are ready to have your changes picked up in the main repo.
	Note that we will perform a code review first.  Rework any changes until they are
	approved. See https://help.github.com/articles/using-pull-requests
- Start working on the next task
- A good reference for git: http://git-scm.com/book/en/Getting-Started
