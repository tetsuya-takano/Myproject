#include "GameManager.h"


//static SaveData::saveData = NULL;
static GameManager* s_GameManager = NULL;

GameManager::GameManager() {
	// TODO �����������ꂽ�R���X�g���N�^�[�E�X�^�u

}

GameManager::~GameManager() {
	// TODO Auto-generated destructor stub
}

GameManager* GameManager::sharedInstance(){

	if(!s_GameManager){
		s_GameManager = new GameManager();
		s_GameManager->init();
	}
	return s_GameManager;
}

bool GameManager::init(){
	stage_id = 4;

	return true;
}
