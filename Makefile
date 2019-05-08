all: exe $(clean)

exe: note.o scale.o main.o
	g++ -o $@ $^

note.o: note.cpp
	g++ -o $@ -c $<

scale.o: scale.cpp
	g++ -o $@ -c $<

main.o: main.cpp
	g++ -o $@ -c $<


clean:
	rm *.o
