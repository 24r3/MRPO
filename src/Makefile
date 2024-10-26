build/brain-games: *.c games/*.c headers/*.h
	gcc brain-games.c engine.c games/nok.c games/geom.c -o build/brain-games

check_quality:
	cpplint ./*.c ./games/*.c ./headers/*.h

clean:
	rm -rf ./build/brain-games
