CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Estabelecendo .o para cada .cpp
OBJETOS = mainF.o forma.o retangulo.o circulo.o triangulo.o

# Alvo: exe
formas: $(OBJETOS)
	$(CXX) $(CXXFLAGS) $(OBJETOS) -o formas

# Transformando .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Dependencias dos headers(.h), mudou .h, recompila quem o usar
mainF.o: forma.h retangulo.h circulo.h triangulo.h
forma.o: forma.h
retangulo.o: forma.h retangulo.h
circulo.o: forma.h circulo.h
triangulo.o: forma.h triangulo.h

# Limpeza
clean:
	rm -f $(OBJETOS) formas