/*
 * Character.cpp
 *
 *  Created on: 2013/11/09
 *      Author: gameprogram
 */

#include "Character.h"


Character::Character() {
	// TODO 自動生成されたコンストラクター・スタブ
}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

bool Character::load(const char* filename){
	return (this->initWithFile(filename));
}

void Character::update(float dt){

}
