OPTIONS1 = -std=c++2a -O2
OPTIONS2 = -lglfw -lGL -lm -lX11 -lpthread -lXrandr -ldl
prueba.o: prueba.cc
	g++ $(OPTIONS1) -c prueba $(OPTIONS2)
glad.o: ./glad/glad.c
	g++ $(OPTIONS1) -c ./glad/glad.c $(OPTIONS2)
shader.o: ./Shader/*.cc
	g++ $(OPTIONS1) -c ./Shader/FragmentShader.cc $(OPTIONS2)
	g++ $(OPTIONS1) -c ./Shader/Program.cc $(OPTIONS2)
	g++ $(OPTIONS1) -c ./Shader/Shader.cc $(OPTIONS2)
	g++ $(OPTIONS1) -c ./Shader/VertexShader.cc $(OPTIONS2)
window.o: ./Window/*.cc
	g++ $(OPTIONS1) -c ./Window/Window.cc $(OPTIONS2)

compile:
	g++ -std=c++2a -O2 -o prueba.exe prueba.cc ./glad/glad.c ./Shader/*.cc ./Window/*.cc ./Texture/*.cc ./Image_Loader/*.cpp ./Camera/*.cc -lglfw -lGL -lm -lX11 -lpthread -lXrandr -ldl
debug:
	g++ -std=c++2a -O2 -o prueba.exe prueba.cc ./glad/glad.c ./Shader/*.cc ./Window/*.cc ./Texture/*.cc ./Image_Loader/*.cpp ./Camera/*.cc -lglfw -lGL -lm -lX11 -lpthread -lXrandr -ldl -g
run: compile
	./prueba.exe
clean:
	rm -f *.exe