/*
 * Character.cpp
 *
 *  Created on: 2013/11/09
 *      Author: gameprogram
 */

#include "Character.h"


Character::Character() {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u
}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

bool Character::load(const char* filename){
	return (this->initWithFile(filename));
}

void Character::update(float dt){

}
