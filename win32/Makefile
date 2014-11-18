SRCS := $(wildcard *.cpp)
#OBJS := $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

BINS = LongFileNameTest

.PHONY: all clean strip

all: $(BINS) strip

LongFileNameTest: LongFileNameTest.cpp
	$(CXX) -D_UNICODE -DUNICODE -static-libgcc -static-libstdc++ $< -o $@

strip:
	@for i in $(BINS);\
		do strip -s $$i.exe;\
	done

clean:
	@for i in $(BINS);\
		do rm -f $$i.exe;\
	done

