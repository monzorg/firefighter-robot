PROJECT_DIR       = $(CURDIR)
ARDUINO_DIR       = /usr/share/arduino
ARDUINO_LIBS      = ArduinoThread Wire FastLED SharpIR Arduino-Scheduler AnalogButtons
USER_LIB_PATH    :=  $(PROJECT_DIR)/../ext
AVRDUDE_CONF	  = /etc/avrdude.conf
# Only for archlinux
ARDMK_VENDOR      = archlinux-arduino
BOARD_TAG         = uno
#BOARD_SUB  		  = atmega328
MONITOR_BAUDRATE  = 9600
AVR_TOOLS_DIR     = /usr
AVRDUDE          = /usr/bin/avrdude -v -v -v -v #-v flag for debug purpose!
#CFLAGS_STD        = -std=gnu11
#CXXFLAGS_STD      = -std=gnu++14
CXXFLAGS += -pedantic -Wall -Wextra
MONITOR_PORT = /dev/ttyUSB0
CURRENT_DIR = $(shell basename $(CURDIR))
OBJDIR = $(PROJECT_DIR)/bin/$(BOARD_TAG)/$(CURRENT_DIR)

include /usr/share/arduino/Arduino.mk
