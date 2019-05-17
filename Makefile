EXE= exe
CP=g++

all: $(EXE)

$(EXE): main.o err.o n.o nn.o an.o sn.o fn.o ssn.o ffn.o i.o ch.o sc.o
	$(CP) -o $@ $^

main.o: main.cpp
	$(CP) -o $@ -c $<

n.o: Note.cpp
	$(CP) -o $@ -c $<

err.o: errors.cpp
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

i.o: Interval.cpp
	$(CP) -o $@ -c $<

ch.o: Chord.cpp
	$(CP) -o $@ -c $<

sc.o: Scale.cpp
	$(CP) -o $@ -c $<

.SILENT: clean
clean:
	rm *.o
