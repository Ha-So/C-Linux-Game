#*********************************************************************
#* Program name:  C++ Agent	
#* File name: makefile
#* Author: Haris Sohail
#* Date: 06/12/17
#* Description: This is the makefile for the entire Fantasy Game program.
#* Type "make" to compile this program, the executable is named "runGame" 
#*********************************************************************/


CXX = g++

CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = mainGame.o Floor.o Agent.o Skyscraper.o Basement.o First.o menu.o Second.o Third.o Fourth.o Fifth.o

SRCS =  mainGame.cpp Floor.cpp Agent.cpp Skyscraper.cpp Basement.cpp First.cpp menu.cpp Second.cpp Third.cpp Fourth.cpp Fifth.cpp

HEADERS = Floor.hpp Agent.hpp Skyscraper.hpp Basement.hpp First.hpp menu.hpp Second.hpp Third.hpp Fourth.hpp Fifth.hpp
	

runGame: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS}  -o runGame

clean:
	$(RM) *.o 