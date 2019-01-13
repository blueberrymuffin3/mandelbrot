# ----------------------------
# Set NAME to the program name
# Set ICON to the png icon file name
# Set DESCRIPTION to display within a compatible shell
# Set COMPRESSED to "YES" to create a compressed program
# ----------------------------

NAME        ?= MANDELB2
COMPRESSED  ?= NO
ICON        ?= iconc.png
DESCRIPTION ?= "Mandelbrot"

# ----------------------------

include $(CEDEV)/include/.makefile

install:
	tilp --no-gui bin/$(NAME).8xp 

sleep:
	sleep 3

palette:
	python3 genpal.py > src/palette.h

.PHONY: install, sleep, palette
