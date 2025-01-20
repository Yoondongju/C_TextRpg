#include "CGolem.h"
#include "pch.h"

CGolem::CGolem(const char* _szName, float _fHp, float _fAttack)
{
	strcpy_s(m_szName, strlen(_szName) + 1, _szName);
	m_fHp = _fHp;
	m_fAttackInfo = _fAttack;
	m_iDropMoney = 400;
}