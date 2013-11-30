

#ifndef SHOT_H_
#define SHOT_H_

#include "cocos2d.h"
using namespace cocos2d;

class Shot : public Character{

private:

public:
	Shot();
	virtual ~Shot();

	virtual void update(float dt);
};

#endif /* SHOT_H_ */
