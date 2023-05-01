compile:
	g++ -O2 -o prueba.exe prueba.cc glad.c ./Shader/*.cc ./Window/*.cc ./Texture/*.cc ./Image_Loader/*.cpp -lglfw -lGL -lm -lX11 -lpthread -lXrandr -ldl
debug:
	g++ -O2 -o prueba.exe prueba.cc glad.c ./Shader/*.cc ./Window/*.cc ./Texture/*.cc ./Image_Loader/*.cpp -lglfw -lGL -lm -lX11 -lpthread -lXrandr -ldl -g
run:
	./prueba.exe
clean:
	rm -f *.exe