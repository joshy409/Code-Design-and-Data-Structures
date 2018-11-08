#pragma once
#include <iostream>
#include "IBox.h"
#include "RedBox.h"
#include "BlueBox.h"
#include "IFactory.h"

class Factory :
	public IFactory
{
private:
	Factory();
	Factory(Factory const&);
	void operator=(Factory const&);
public:
	static Factory& GetInstance();
	IBox * Create(std::string type);
};

