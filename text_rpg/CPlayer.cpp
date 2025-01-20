#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer(const char* _szName, float _fHp, float _fMp, float _fAttack, float _fDefense, PLAYER_JOB _e)
{
	strcpy_s(m_szName, strlen(_szName) + 1, _szName);
	m_fHp = _fHp;
	m_fMp = _fMp;
	m_fAttackInfo = _fAttack;
	m_fDefenseInfo = _fDefense;
	m_bAlreadyMountWeapon = false;
	m_bAlreadyMountArmor = false;

	m_player_job = _e;

	m_CurMountWeapon = nullptr;
	m_CurMountArmor = nullptr;


	m_player_Inventory = new CInventory();
}

CPlayer::CPlayer()   // 파일로 인한 기본 복사 일때만 호출
{


}

CPlayer::~CPlayer()
{
	for (int i = 0; i < (size_t)PLAYER_ITEM::END; ++i)
	{
		for (int j = 0; j < m_player_Inventory->iItem[i].size(); ++j)
		{
			if (m_player_Inventory->iItem[i][j])
			{
				delete m_player_Inventory->iItem[i][j];
				m_player_Inventory->iItem[i][j] = nullptr;
			}
		}
		
	}
	
}
