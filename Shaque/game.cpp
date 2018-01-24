#include "game.h"
#include "player.h"


Game::Game(Player* white, Player* black) {
	_pwhite = white;
	_pblack = black;
}

Game::Game(Player* white, Player* black, UI* ui) {
	_pwhite = white;
	_pblack = black;
	_pUI = ui;
}

const std::vector<State>* Game::getStateHistory() const {
	return &_state_history;
}

const std::vector<Move>* Game::getMoveHistory() const {
	return &_move_history;
}

const UI* Game::getUI() const {
	return _pUI;
}

GameRecording Game::Play() {
	State currentState = State::initialize();
	Move move;
	while (true) {
		_state_history.push_back(currentState);

		if (_pUI) {
			_pUI->drawBoard(currentState);
		}

		if (currentState.getTurnColor() == WHITE) {
			move = _pwhite->askMove(*this, currentState, WHITE);
		}
		else {
			move = _pblack->askMove(*this, currentState, BLACK);
		}

		currentState = currentState.advanceTurn(move);
		_move_history.push_back(move);
	}
}