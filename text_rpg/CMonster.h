#pragma once

#include "CObject.h"

class CMonster : public  CObject
{
protected:
	char m_szName[256];
	int m_iDropMoney;
	float m_fHp;
	float m_fAttackInfo;


public:
	void Set_Hp(float _f) { m_fHp = _f; }
	void Set_fAttackInfo(float _f) { m_fAttackInfo = _f; }


	const char* Get_Name() { return m_szName; }
	float Get_Hp() { return m_fHp; }
	float Get_AttackInfo() { return m_fAttackInfo; }
	int Get_DropMoney() { return m_iDropMoney; }

public:
	CMonster();
	~CMonster();

};

