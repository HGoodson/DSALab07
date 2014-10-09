AutomatedMakefile = am
CC = g++

LAB_07_PATH = /$(DRIVE_LETTER)/07-Romberg_Integration
GTKMM_PATH = /$(DRIVE_LETTER)/MinGW/gtkmm

INC_DIRS = -I$(LAB_07_PATH)/CSC2110/
LIB_DIRS = -L$(LAB_07_PATH)/CSC2110/
LIBS = -lCSC2110

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o


