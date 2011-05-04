LIBS:=`gorgon-config --libs --addons --addons_sdl --addons_magick`
all:
	g++ src/spritepack.cpp -o bin/spritepack.e $(LIBS)
	g++ src/animationpack_lua_to_gorgon.cpp -o bin/animationpack_lua_to_gorgon.e $(LIBS)
	g++ src/air_to_gap.cpp -o bin/air_to_gap.e $(LIBS)
#	g++ src/image.cpp -o bin/image.e `gorgon-config --libs --addons`
#	g++ src/sprite.cpp -o bin/sprite.e `gorgon-config --libs --addons`
