all: proto write reader

# set 0 for static compile
# set 1 for dynamic compile
# if set 1, you must add the complete path of'$(CPPET)/lib' 
# in /etc/ld.so.conf and execute 'ldconfig' 
OPTION = 0

PROTOC = $(CPPET)/bin/protoc
STATIC_PB = $(CPPET)/lib/libprotobuf.a
PKGCONF = $(CPPET)/lib/pkgconfig/protobuf.pc

proto:
	$(PROTOC) --cpp_out=. addressbook.proto

write: addressbook.pb.cc write.cpp
ifeq ($(OPTION), 0)
	g++ addressbook.pb.cc write.cpp -o write $(STATIC_PB) -pthread -I$(CPPET)/include  -pthread -L$(CPPET)/lib -lpthread
else
	g++ addressbook.pb.cc write.cpp -o write `pkg-config --cflags --libs $(PKGCONF)`
endif

reader: addressbook.pb.cc reader.cpp
ifeq ($(OPTION), 0)
	g++ addressbook.pb.cc reader.cpp -o reader $(STATIC_PB) -pthread -I$(CPPET)/include  -pthread -L$(CPPET)/lib -lpthread
else
	g++ addressbook.pb.cc reader.cpp -o reader `pkg-config --cflags --libs $(PKGCONF)`
endif

clean:
	rm -f write reader *.pb.cc *.pb.h *.o
