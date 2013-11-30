/*
 * Character.cpp
 *
 *  Created on: 2013/11/09
 *      Author: gameprogram
 */

#include "Enemy.h"


Enemy::Enemy() {
	// TODO 自動生成されたコンストラクター・スタブ
}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}

bool Enemy::load(const char* filename){
	return (this->initWithFile(filename));
}

void Enemy::update(float dt){

}
