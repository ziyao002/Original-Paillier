LIBS:= ntl gmp
LIBFLAGS:=$(addprefix -l, $(LIBS));

main : main.cpp paillier.cpp
	g++ -std=c++11 -lpthread -g -O3 $^ -o $@ $(LIBFLAGS)
