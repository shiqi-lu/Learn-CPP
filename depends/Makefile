include ../common.def

PKG = boost_1_57_0.tar.bz2
PKGDIR = $(PKG:.tar.bz2=)

ifeq ($(TARGETOS), WINDOWS)
TOOLSET = --with-toolset=mingw
else
BCXXFLAGS = "cxxflags=-fPIC" # we needs if for static linking on Linux
endif

BJAMOPTS = --layout=system variant=release link=static

.PHONY: all
all: $(PKGDIR)
	cd $(PKGDIR) && ./bootstrap.sh $(TOOLSET) \
		--prefix=../../ --libdir=../../lib \
		--includedir=../../include/ \
		--with-libraries=all
	sed -i -e 's/mingw/gcc/' $(PKGDIR)/project-config.jam
	cd $(PKGDIR) && ./bjam $(BCXXFLAGS) $(BJAMOPTS)
	cd $(PKGDIR) && ./bjam $(BCXXFLAGS) $(BJAMOPTS) install

$(PKGDIR):
	tar -jxf $(PKG) 2>/dev/null | /bin/true

.PHONY: clean
clean:
	@rm -rf $(PKGDIR)
	@rm -rf $(CPPET)/lib/libboost* $(CPPET)/include/boost
