# Specify the location of the bmptk library
BMPTK      := C:\bmptk

# Specify target chip or board or system
TARGET     := win

# Specify the project name, the default is main (.cpp, .c, or .asm)
# this is also the main .cpp file to compile
# the default is main.cpp (or main.c, or main.asm)
PROJECT    := 

# Specify project-specific files (other than the main, if any)
OBJECTS    := 
SOURCES    := 
HEADERS    := 
LIBRARIES  := 

# google test
GTEST      += C:/gtest-1.7.0/
SEARCH     += $(GTEST) $(GTEST)/include $(GTEST)/src
SOURCES    += gtest-all.cc 

# specify (extra) results you want to get (if any)
RESULTS    := 

# The Makefile.inc does all the work
include $(BMPTK)/Makefile.inc
