#pragma once

#include "CObject.h"

enum class ITEM_TYPE;
enum class PLAYER_ITEM;

class CItem : CObject
{
public:
	char szName[256];
	bool bHave;			 // ��������
	bool bMount;		 // ��������
	float fAttackInfo;   // ������ ���ݷ�
	float fDefenseInfo;  // ������ ����
	ITEM_TYPE eItemType; // ������ Ÿ��
	PLAYER_ITEM eItem;   // �������� ������ ����  << ���� �ȿ� ���ԵǾ��ִ� �������̿��� ���谡��


	


	CItem(const char* _szName, bool _bHave, bool _bMount, float _fAttackInfo, float _fDefenseInfo, ITEM_TYPE _eType, PLAYER_ITEM _eItem);
	CItem(const CItem& _Item); // ���� ������
	


	CItem(); // �⺻ ������ ����� 
	~CItem();

};
