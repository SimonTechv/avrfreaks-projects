.equ __ctors_start = 0x1ef40/2
.equ usb_init = 0x1ef50/2
.equ usb_shutdown = 0x1ef82/2
.equ usb_configured = 0x1ef9e/2
.equ usb_serial_getchar = 0x1efa4/2
.equ usb_serial_available = 0x1efec/2
.equ usb_serial_flush_input = 0x1f020/2
.equ usb_serial_putchar = 0x1f046/2
.equ usb_serial_putchar_nowait = 0x1f0ca/2
.equ usb_serial_flush_output = 0x1f10c/2
.equ usb_serial_get_baud = 0x1f12c/2
.equ usb_serial_get_stopbits = 0x1f13e/2
.equ usb_serial_get_paritytype = 0x1f144/2
.equ usb_serial_get_numbits = 0x1f14a/2
.equ usb_serial_get_control = 0x1f150/2
.equ usb_serial_set_control = 0x1f156/2
.equ USB_GEN_int = 0x1f1ac/2
.equ USB_COM_int = 0x1f220/2
.equ cdc_line_coding = 0x20a0
.equ usb_configuration = 0x20a8
.equ cdc_line_rtsdtr = 0x20a9
.equ transmit_flush_timer = 0x20aa
.equ transmit_previous_timeout = 0x20ab
.equ usb_suspended = 0x20ac