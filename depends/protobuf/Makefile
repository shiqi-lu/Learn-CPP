include ../../common.def

PKG = protobuf-2.6.1.tar.gz
PKGDIR = $(PKG:.tar.gz=)

.PHONY: all
all: $(PKGDIR)
	cd $(PKGDIR) && ./configure --prefix=$(CPPET) \
		--libdir=$(CPPET)/lib --includedir=$(CPPET)/include \
		--bindir=$(CPPET)/bin --with-pic
	cd $(PKGDIR) && make
	cd $(PKGDIR) && make install

$(PKGDIR):
ifeq ($(TARGETOS), WINDOWS)
	tar -zxvf $(PKG) 2>/dev/null || /bin/true
else
	tar zxvf $(PKG)
endif

.PHONY: clean
clean:
	@rm -rf $(PKGDIR)
	@rm -rf $(CPPET)/bin/protoc
	@rm -rf $(CPPET)/lib/libproto* $(CPPET)/include/google/protobuf
