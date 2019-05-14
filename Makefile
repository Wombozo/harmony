EXE= exe
CP=g++

all: $(EXE) clean

$(EXE): main.o nn.o an.o sn.o fn.o ssn.o ffn.o
	$(CP) -o $@ $^

main.o: main.cpp
	$(CP) -o $@ -c $<

nn.o: NaturalNote.cpp
	$(CP) -o $@ -c $<

an.o: AlteredNote.cpp
	$(CP) -o $@ -c $<

sn.o: SharpNote.cpp
	$(CP) -o $@ -c $<

fn.o: FlatNote.cpp
	$(CP) -o $@ -c $<

ssn.o: DblSharpNote.cpp
	$(CP) -o $@ -c $<

ffn.o: DblFlatNote.cpp
	$(CP) -o $@ -c $<


.SILENT: clean
clean:
	rm *.o
