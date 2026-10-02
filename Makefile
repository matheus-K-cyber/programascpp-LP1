CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Estabelecendo .o para cada .cpp
OBJETOS = mainZoo.o zoologico.o animal.o leao.o papagaio.o elefante.o

# Alvo: exe
formas: $(OBJETOS)
	$(CXX) $(CXXFLAGS) $(OBJETOS) -o zoo

# Transformando .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Dependencias dos headers(.h), mudou .h, recompila quem o usar
mainZoo.o: zoologico.h animal.h
zoologico.o: zoologico.h animal.h leao.h papagaio.h elefante.h
animal.o: animal.h
leao.o: animal.h leao.h
papagaio.o: animal.h papagaio.h
elefante.o: animal.h elefante.h

# Limpeza
clean:
	rm -f $(OBJETOS) zoo