output: main.o clock.o display.o pixel.o number.o
	g++ -O3 main.o clock.o display.o pixel.o number.o -o $(HOME)/bin/kenny/clock.exe -LC:/Programming/PDCurses-3.9/lib -lpdcurses

main.o: main.cpp
	g++ -O3 -IC:/Programming/PDCurses-3.9/include -c main.cpp

clock.o: clock.cpp clock.h
	g++ -O3 -c clock.cpp

display.o: display.cpp display.h
	g++ -O3 -IC:/Programming/PDCurses-3.9/include -c display.cpp

pixel.o: pixel.h pixel.cpp
	g++ -O3 -IC:/Programming/PDCurses-3.9/include -c pixel.cpp

number.o: number.h number.cpp
	g++ -O3 -IC:/Programming/PDCurses-3.9/include -c number.cpp

clean:
	rm main.o
	rm clock.o
	rm display.o
	rm pixel.o
	rm number.o
