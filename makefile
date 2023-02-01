compile:
	g++ -O2 -o prueba.exe prueba.cc glad.c ./Shader/*.cc ./Window/*.cc -lglfw -lGL -lm -lX11 -lpthread -lXrandr -ldl
run:
	./prueba.exe
clean:
	rm -f *.exe