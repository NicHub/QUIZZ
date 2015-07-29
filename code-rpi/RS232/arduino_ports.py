#!/usr/bin/env python
# -*- coding: utf-8 -*-





import RS232_3

if __name__ == '__main__':

    RS232_3.list_USB_Devices()
    RS232_3.openRS232()
    RS232_3.closeRS232()
    RS232_3.writeUSBPortsToFile()

