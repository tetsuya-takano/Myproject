/*
 * Character.cpp
 *
 *  Created on: 2013/11/09
 *      Author: gameprogram
 */

#include "Enemy.h"


Enemy::Enemy() {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u
}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}

bool Enemy::load(const char* filename){
	return (this->initWithFile(filename));
}

void Enemy::update(float dt){

}
