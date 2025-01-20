#pragma once

#include "CObject.h"

enum class ITEM_TYPE;
enum class PLAYER_ITEM;

class CItem : CObject
{
public:
	char szName[256];
	bool bHave;			 // 소유여부
	bool bMount;		 // 장착여부
	float fAttackInfo;   // 아이템 공격력
	float fDefenseInfo;  // 아이템 방어력
	ITEM_TYPE eItemType; // 아이템 타입
	PLAYER_ITEM eItem;   // 실질적인 아이템 종류  << 여기 안에 포함되어있는 아이템이여야 설계가능


	


	CItem(const char* _szName, bool _bHave, bool _bMount, float _fAttackInfo, float _fDefenseInfo, ITEM_TYPE _eType, PLAYER_ITEM _eItem);
	CItem(const CItem& _Item); // 복사 생성자
	


	CItem(); // 기본 생성자 만들기 
	~CItem();

};
