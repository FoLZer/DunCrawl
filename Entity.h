#pragma once

//---------------------------------------------------------------------------

#ifndef EntityH
#define EntityH
//---------------------------------------------------------------------------
#endif

#include "MovableObject.h"

class Entity : public MovableObject {
	//health,armor,etc...
public:
    using MovableObject::MovableObject;
};