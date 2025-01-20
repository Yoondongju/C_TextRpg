#pragma once


#include <iostream>
#include <vector>


using namespace std;


#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif


enum class PLAYER_JOB
{
	WARRIOR = 1,
	WIZARD,
	ROGUE,
	END
};


enum class ITEM_TYPE
{
	NONE,
	WEAPON,
	ARMOR,
	END,
};


class CPlayer;
