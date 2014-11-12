include common.def

DIRS = depends c++ boost stl

ifeq ($(TARGETOS), WINDOWS)
DIRS += win32
endif

.PHONY: all $(DIRS) clean

all: $(DIRS)

$(DIRS):
	@if [ "x$(CPPET)" = "x" ]; then \
		echo "Please set environment variable 'CPPET' first.";\
		exit 1;\
	fi

	make -C $@

clean:
	@for i in $(DIRS); do \
		make -C $$i clean; \
	done;
