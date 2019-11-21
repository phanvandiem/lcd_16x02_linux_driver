#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


#define DEVICE_NODE "/dev/klcd"
#define BUFFER_SIZE 50

/* function check entry point open of klcd */
int open_klcd()
{
	int fd = open(DEVICE_NODE, O_RDWR);
	if (fd < 0)
	{
		printf("Can not open the device file\n");
		exit(1);
	}
	return fd;
}

/* function checks entry point release of klcd */
void close_klcd(int fd)
{
	close(fd);
}

void write_klcd()
{
	int ret = 0;
	char user_buf[BUFFER_SIZE];
	printf("Enter your message: ");
	scanf(" %[^\n]s", user_buf);
	int fd = open_klcd();
	ret = write(fd, user_buf, strlen(user_buf) + 1);
	close_klcd(fd);

	if (ret < 0)
		printf("Coult not write the message to %s\n", DEVICE_NODE);
	else
		printf("Wrote the message to %s\n", DEVICE_NODE);
}

int main()
{
	int ret = 0;
	char option = 'q';
	int fd = -1;

	printf("Select below options:\n");
	printf("\to (to open a device node)\n");
	printf("\tc (to close the device node)\n");
	printf("\tw (to write data to device node)\n");
	printf("\tq (to quit the application)\n");

	while(1)
	{
		printf("Enter your option: ");
		scanf(" %c",&option);

		switch (option)
		{
			case 'o':
				if (fd < 0)
					fd = open_klcd();
				else
					printf("%s has already opened\n", DEVICE_NODE);
				break;

			case 'c':
				if (fd > -1)
					close_klcd(fd);
				else
					printf("%s has not opened yet! can not close\n", DEVICE_NODE);
				fd = -1;
				break;

			case 'q':
				if (fd > -1)
					close_klcd(fd);
				printf("Quit the application. Good bye\n");
				return 0;

			case 'w':
				write_klcd();
				break;

			default:
				printf("Invalid option %c\n", option);
				break;
		}
	};
	return 0;
}	




