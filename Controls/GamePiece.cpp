#include "GamePiece.h"
#include <iostream>

using namespace std;

GamePiece::GamePiece(){
	value = 0;
}

GamePiece::~GamePiece(){
}

void GamePiece::print(){
	
}

int GamePiece::GetValue(){
	return value;
}