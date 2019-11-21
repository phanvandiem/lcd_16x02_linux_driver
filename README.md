# lcd_16x02_linux_driver

This is a kernel level Linux Device driver to control a 16x2 character LCD (with HD44780 LCD controller) with 4 bit mode.

Provide API for app in userspace to comminicate with LCD
The LCD is interfaced with a micro-controller using GPIO pins.
Driver is written on the Raspberry Pi 3 B, the kernel version 4.19.75-v7+

### List of APIs

| Function | Description |
| void lcd_init(void) | Init LCD, set default configure (display + cursor + blink on) |
| void lcd_clear_display(void) | Clear display and set cursor to home position |
| void lcd_put_char(char c) | Display character at current cursor position |
| Plugin | README |
| ------ | ------ |
| Dropbox | [plugins/dropbox/README.md][PlDb] |
| GitHub | [plugins/github/README.md][PlGh] |
| Google Drive | [plugins/googledrive/README.md][PlGd] |
| OneDrive | [plugins/onedrive/README.md][PlOd] |
| Medium | [plugins/medium/README.md][PlMe] |
| Google Analytics | [plugins/googleanalytics/README.md][PlGa] |
