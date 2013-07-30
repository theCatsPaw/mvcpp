IDIR =src/lib


COMPILER=g++
CFLAGS=-I$(IDIR) -std=c++11

LINKFLAGS=-lwsock32
CC = $(COMPILER) $(CFLAGS)

CCOBJ = $(CC) -c -o

OBJS = obj/mvcpp.o obj/mvcpplib.o obj/mongoose.o obj/logging.o obj/request.o \
		obj/IP.o obj/config.o

TARGET = mvcpp.exe
all: build run

run: build
	$(TARGET)

clean:
	rm obj/*
	rm $(TARGET)

doc:
	doxygen doxygenconf
	
gensrc:
	python src/tools/generate.py

obj/mvcpp.o: src/mvcpp.cpp
	$(CCOBJ) obj/mvcpp.o src/mvcpp.cpp

obj/mvcpplib.o: src/lib/mvcpp/mvcpp.cpp
	$(CCOBJ) obj/mvcpplib.o src/lib/mvcpp/mvcpp.cpp

obj/logging.o: src/lib/mvcpp/logging.cpp
	$(CCOBJ) obj/logging.o src/lib/mvcpp/logging.cpp

obj/request.o: src/lib/mvcpp/request.cpp
	$(CCOBJ) obj/request.o src/lib/mvcpp/request.cpp

obj/IP.o: src/lib/mvcpp/IP.cpp
	$(CCOBJ) obj/IP.o src/lib/mvcpp/IP.cpp

obj/config.o: src/app/gensrc/Config.cpp
	$(CCOBJ) obj/config.o src/app/gensrc/Config.cpp

obj/mongoose.o: src/lib/mongoose/mongoose.c
	gcc -c -o obj/mongoose.o src/lib/mongoose/mongoose.c



build: $(OBJS)
	$(CC)  $(OBJS) $(LINKFLAGS) -o $(TARGET)