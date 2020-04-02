#pragma once

#include <iostream>
#include <Windows.h>
#include "Types.h"

struct InputData{

	bool keys[(int)InputKey::COUNT];
	
	InputData();
	
	void Update();
		
};