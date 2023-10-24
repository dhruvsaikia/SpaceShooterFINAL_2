#pragma once
#include "AUnit.h"
#include "SpaceShooter.h"

class Enemy2 : public AUnit
{
public:
    Enemy2(int x);
    ~Enemy2(void);

    virtual void moveDown(void) override; 
};

