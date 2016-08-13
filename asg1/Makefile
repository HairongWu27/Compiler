# $Id: Makefile,v 1.10 2015/04/07 04:39:51 hwu27 Exp $

GCC        = g++ -g -O0 -Wall -Wextra -std=gnu++11
MKDEP      = g++ -MM -std=gnu++11
VALGRIND   = valgrind --leak-check=full --show-reachable=yes

MKFILE     = Makefile
DEPFILE    = Makefile.dep
SOURCES    = auxlib.cpp oc.cpp stringset.cpp
HEADERS    = auxlib.h stringset.h
OBJECTS    = ${SOURCES:.cpp=.o} 
EXECBIN    = oc
SRCFILES   = ${HEADERS} ${SOURCES} ${MKFILE}
SMALLFILES = ${DEPFILE} foo.oc
CHECKINS   = ${SRCFILES} ${SMALLFILES}
LISTING    = Listing.ps



all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${GCC} -o${EXECBIN} ${OBJECTS}

%.o : %.cpp
	${GCC} -c $<

  
ci :
	ci  ${CHECKINS}
	
co :
	co ${CHECKINS}

clean :
	- rm ${OBJECTS}

spotless : clean
	- rm ${EXECBIN}  ${DEPFILE} 
	

${DEPFILE} :
	${MKDEP} ${SOURCES} ${CHECKINS}>${DEPFILE}

dep :
	- rm ${DEPFILE}
	${MAKE} --no-print-directory ${DEPFILE}

include Makefile.dep




