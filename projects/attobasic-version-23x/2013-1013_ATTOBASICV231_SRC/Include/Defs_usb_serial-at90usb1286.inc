.equ __ctors_start = 0x1d7e0/2
.equ usb_init = 0x1d7f0/2
.equ usb_shutdown = 0x1d822/2
.equ usb_configured = 0x1d83e/2
.equ usb_serial_getchar = 0x1d844/2
.equ usb_serial_available = 0x1d88c/2
.equ usb_serial_flush_input = 0x1d8c0/2
.equ usb_serial_putchar = 0x1d8e6/2
.equ usb_serial_putchar_nowait = 0x1d96a/2
.equ usb_serial_flush_output = 0x1d9ac/2
.equ usb_serial_get_baud = 0x1d9cc/2
.equ usb_serial_get_stopbits = 0x1d9de/2
.equ usb_serial_get_paritytype = 0x1d9e4/2
.equ usb_serial_get_numbits = 0x1d9ea/2
.equ usb_serial_get_control = 0x1d9f0/2
.equ usb_serial_set_control = 0x1d9f6/2
.equ USB_GEN_int = 0x1da4c/2
.equ USB_COM_int = 0x1dac0/2
.equ cdc_line_coding = 0x20a0
.equ usb_configuration = 0x20a8
.equ cdc_line_rtsdtr = 0x20a9
.equ transmit_flush_timer = 0x20aa
.equ transmit_previous_timeout = 0x20ab
.equ usb_suspended = 0x20ac