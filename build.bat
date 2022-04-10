del Makefile*
del *.user
del .qmake.stash
rmdir /S /Q release
rmdir /S /Q debug
rmdir /S /Q .qtc_clangd

qmake
make