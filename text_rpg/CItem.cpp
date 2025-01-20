#include "CItem.h"

#include "pch.h"

CItem::CItem(const char* _szName, bool _bHave, bool _bMount, float _fAttackInfo, float _fDefenseInfo, ITEM_TYPE _eType, PLAYER_ITEM _eItem)
{
	strcpy_s(szName, strlen(_szName) + 1, _szName);
	bHave = _bHave;
	bMount = _bMount;
	fAttackInfo = _fAttackInfo;
	fDefenseInfo = _fDefenseInfo;
	eItemType = _eType;
	eItem = _eItem;
}

CItem::CItem(const CItem& _Item)
{
	strcpy_s(szName, strlen(_Item.szName) + 1, _Item.szName);
	bHave = _Item.bHave;
	bMount = _Item.bMount;
	fAttackInfo = _Item.fAttackInfo;
	fDefenseInfo = _Item.fDefenseInfo;
	eItemType = _Item.eItemType;
	eItem = _Item.eItem;
	
}

CItem::CItem()
{
}

CItem::~CItem()
{
}
