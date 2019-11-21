# lcd_16x02_linux_driver

This is a kernel level Linux Device driver to control a 16x2 character LCD (with HD44780 LCD controller) with 4 bit mode.

Provide API for app in userspace to comminicate with LCD
The LCD is interfaced with a micro-controller using GPIO pins.
Driver is written on the Raspberry Pi 3 B, the kernel version 4.19.75-v7+

### List of APIs

| Function | Description|
|void lcd_clear_display(void) |	Clear display and set cursor to home position|
|void lcd_put_char(char c) |	Display character at current cursor position|
|void lcd_put_string(const char *s) |	Display string at current cursor position|
|void lcd_put_string_super(const char *s)	Clear display and display on 2 line if string length > 16
void lcd_goto_xy(unsigned char x, unsigned char y)	Set cursor to specified position
void lcd_scroll_left(void)	scroll text to left
void lcd_scroll_right(void)	scroll 2 line text to right
void lcd_set_display(unsigned char display, unsigned char cursor, unsigned char blink)	Set cursor to home position
void lcd_upload_custom_char(unsigned char location, unsigned char *charmap)	Upload data for custom char to CGRAM
void lcd_set_auto_scroll(unsigned char status)	Set enable or disable auto move all the text one space to the left each time a letter is added |
