#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

/*******************IOCTL COMMAND ARGUMENTS *************************/

#define KLCD_MAGIC_NUMBER         0xBC // a "magic" number to uniquely identify the device

#define IOCTL_CLEAR_DISPLAY       '0'
#define IOCTL_PRINT_ON_FIRSTLINE  '1'
#define IOCTL_PRINT_ON_SECONDLINE '2'
#define IOCTL_PRINT_WITH_POSITION '3'
#define IOCTL_CURSOR_ON           '4'
#define IOCTL_CURSOR_OFF          '5'

/******************* IOCTL MACROS ***********************************/

#define KLCD_IOCTL_CLEAR_DISPLAY       _IOW(KLCD_MAGIC_NUMBER, IOCTL_CLEAR_DISPLAY, struct ioctl_mesg)
#define KLCD_IOCTL_PRINT_ON_FIRSTLINE  _IOW(KLCD_MAGIC_NUMBER, IOCTL_PRINT_ON_FIRSTLINE, struct ioctl_mesg)
#define KLCD_IOCTL_PRINT_ON_SECONDLINE _IOW(KLCD_MAGIC_NUMBER, IOCTL_PRINT_ON_SECONDLINE, struct ioctl_mesg)
#define KLCD_IOCTL_PRINT_WITH_POSITION _IOW(KLCD_MAGIC_NUMBER, IOCTL_PRINT_WITH_POSITION, struct ioctl_mesg)

#define KLCD_IOCTL_CURSOR_ON           _IOW(KLCD_MAGIC_NUMBER, IOCTL_CURSOR_ON, struct ioctl_mesg)
#define KLCD_IOCTL_CURSOR_OFF          _IOW(KLCD_MAGIC_NUMBER, IOCTL_CURSOR_OFF, struct ioctl_mesg)

#define MAX_BUF_LENGTH    50


struct ioctl_mesg
{
	char kbuf[MAX_BUF_LENGTH];   // a string to be printed on the LCD
	unsigned int lineNumber;
	unsigned int nthCharacter;
};

struct ioctl_mesg msg;

int main()
{
	char command;
	int fd;

	fd = open("/dev/klcd", O_WRONLY | O_NDELAY);
	if (fd < 0)
	{
		printf("Unable to open klcd \n");
		return -1;
	}

	printf("0 (to clear the LCD display)\n");
	printf("1 (to write on the first line of the LCD)\n"); 
	printf("2 (to write on the second line of the LCD)\n");
	printf("3 (to write on the specified position(line number, nth Character) of the LCD)\n");
	printf("4 (to enable a blinking cursor on the LCD)\n");
	printf("5 (to disable a blinking cursor on the LCD)\n");

	while(1)
	{


		printf("Enter your command: ");	
		scanf("%c", &command);
		switch (command)
		{
			case(IOCTL_CLEAR_DISPLAY):    // clear the LCD display
				printf("KLCD IOCTL Option: Clear Display\n");
				if (ioctl(fd,(unsigned int) IOCTL_CLEAR_DISPLAY, &msg) < 0)
					perror("[ERROR] IOCTL_CLEAR_DISPLAY\n");
				break;
			
			case(IOCTL_PRINT_ON_FIRSTLINE):
				printf("KLCD IOCTL Option: Print on first line\n");
				printf("Enter your message: ");
				memset(msg.kbuf, '\0', sizeof(char) *MAX_BUF_LENGTH);
				msg.lineNumber = 1;
				gets(msg.kbuf);
				if(ioctl(fd, (unsigned int)IOCTL_PRINT_ON_FIRSTLINE, &msg) < 0)
					perror("[ERROR] IOCTL_PRINT_ON_FIRSTLINE\n");
				break;

			case(IOCTL_PRINT_ON_SECONDLINE):
				printf("KLCD IOCTL Option: Print on Second Line\n");
				printf("Enter your message: ");
				memset(msg.kbuf, '\0', sizeof(char) *MAX_BUF_LENGTH);
				msg.lineNumber = 2;
				fgets(msg.kbuf, sizeof(msg.kbuf) , stdin);
				if(ioctl(fd, (unsigned int)IOCTL_PRINT_ON_SECONDLINE, &msg) < 0);
					perror("[ERROR] IOCTL_PRINT_ON_SECONDLINE\n");
				break;
			default:
				printf("[User level Debug] klcd Driver (ioctl): No such command\n");
				break;
		}
	}
	close(fd);
	printf("KLCD User level test program\n");	
	return 0;

}
