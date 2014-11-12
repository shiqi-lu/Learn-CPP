include ../common.def

PKG = boost_1_45_0.tar.bz2
PKGDIR = $(PKG:.tar.bz2=)
PATCH1 = 1.45.0_mingw45.patch

ifeq ($(TARGETOS), WINDOWS)
TOOLSET = --with-toolset=mingw
else
BCXXFLAGS = "cxxflags=-fPIC" # we needs if for static linking on Linux
endif

BJAMOPTS = --layout=system variant=release link=static

.PHONY: all
all: $(PKGDIR)
	patch -p0 < $(PATCH1)
	cd $(PKGDIR) && ./bootstrap.sh $(TOOLSET) \
		--prefix=../../ --libdir=../../lib \
		--includedir=../../include/ \
		--with-libraries=thread,test,regex,program_options,filesystem,system,date_time
	sed -i -e 's/mingw/gcc/' $(PKGDIR)/project-config.jam
	cd $(PKGDIR) && ./bjam $(BCXXFLAGS) $(BJAMOPTS)
	cd $(PKGDIR) && ./bjam $(BCXXFLAGS) $(BJAMOPTS) install

$(PKGDIR):
	tar -jxf $(PKG) 2>/dev/null | /bin/true

.PHONY: clean
clean:
	rm -rf $(PKGDIR)
	rm -rf $(CPPET)/lib/libboost* $(CPPET)/include/boost
