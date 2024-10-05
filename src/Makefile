build/brain-games: *.c games/*.c headers/*.h
	gcc brain-games.c engine.c games/nok.c games/geom.c -o build/brain-games

format_code:
	clang-format -i ./*.[ch]
	clang-format -i ./headers/*.[ch]
	clang-format -i ./games/*.[ch]

check_quality:
	cpplint ./*.c ./games/*.c ./headers/*.h

clean:
	rm -rf ./build/brain-games
