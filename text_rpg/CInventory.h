#pragma once

class CItem;

enum class PLAYER_ITEM
{
	NONE,
	SWORD,
	ARMOR,
	POWERFUL_WEAPON,
	END,
};





class CInventory
{
public:
	int iMoney;
	vector<CItem*> iItem[(size_t)PLAYER_ITEM::END]; // �����Ҵ� �Ұ�

	CInventory()
	{
		iMoney = 50000;

	}

};