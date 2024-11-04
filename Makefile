ttt: clean
	g++ --std=c++14 main.cpp board.cpp tic_tac_toe.cpp board_printer.cpp rules.cpp main_menu.cpp battle_tic_tac_toe.cpp goblin.cpp reaper.cpp -o ttt
	./ttt

bpt: clean
	g++ --std=c++14 board_printer.cpp board_printer_test.cpp board.cpp -o bpt
	./bpt

bt: clean
	g++ --std=c++14 board_test.cpp board.cpp -o bt
	./bt

rt: clean
	g++ --std=c++14 rules_test.cpp rules.cpp board.cpp -o rt
	./rt

tttt: clean
	g++ --std=c++14 tic_tac_toe_test.cpp board_printer.cpp rules.cpp tic_tac_toe.cpp board.cpp -o gt
	./gt

clean:
	@rm -f bpt
	@rm -f bt
	@rm -f gt
	@rm -f rt
	@rm -f ttt
