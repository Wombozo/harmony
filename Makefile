all: exe $(clean)

exe: note.o scale.o main.o utils.o chord.o
	g++ -o $@ $^

note.o: note.cpp
	g++ -o $@ -c $<
chord.o: chord.cpp
	g++ -o $@ -c $<
scale.o: scale.cpp
	g++ -o $@ -c $<
utils.o: utils.cpp
	g++ -o $@ -c $<
main.o: main.cpp
	g++ -o $@ -c $<


clean:
	rm *.o
