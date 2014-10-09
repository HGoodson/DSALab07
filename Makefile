AutomatedMakefile = am
CC = g++

FILES = RecursiveIntegration.o RombergIntegration.o Problem22_1.o 
EXECUTABLE = Problem22_1.exe

LAB_07_PATH = /$(DRIVE_LETTER)/07-Romberg_Integration
GTKMM_PATH = /$(DRIVE_LETTER)/MinGW/gtkmm

INC_DIRS = -I$(LAB_07_PATH)/CSC2110/
LIB_DIRS = -L$(LAB_07_PATH)/CSC2110/
LIBS = -lCSC2110

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o


all: Project

Project: 	$(FILES)
		$(LINK) $(EXECUTABLE) $(FILES) $(LIBS)
		
Problem22_1.o: Problem22_1.h Problem22_1.cpp
			   $(COMPILE) Problem22_1.cpp
			   
RecursiveIntegration.o: RecursiveIntegration.h RecursiveIntegration.cpp
					$(COMPILE) RecursiveIntegration.cpp
					
RombergIntegration.o: RombergIntegration.h RombergIntegration.cpp
					$(COMPILE) RombergIntegration.cpp