#pragma once

#include "CObject.h"
#include "CInventory.h"

class CItem;
enum class PLAYER_JOB;


class CPlayer : public CObject
{
private:
	char  m_szName[256];
	float m_fHp;
	float m_fMp;
	float m_fAttackInfo;
	float m_fDefenseInfo;
	bool  m_bAlreadyMountWeapon;
	bool  m_bAlreadyMountArmor;

	CItem* m_CurMountWeapon;
	CItem* m_CurMountArmor;


	CInventory* m_player_Inventory;


	PLAYER_JOB m_player_job;


public:
	void Set_Name(const char* _szName) { strcpy_s(m_szName, sizeof(m_szName), _szName); }
	void Set_Hp(float _fHp) { m_fHp = _fHp; }
	void Set_Mp(float _fMp) { m_fMp = _fMp; }
	void Set_AttackInfo(float _f) { m_fAttackInfo = _f; }
	void Set_DefenseInfo(float _f) { m_fDefenseInfo = _f; }

	void Set_Already_MountWeapon(bool _b) { m_bAlreadyMountWeapon = _b; }
	void Set_Already_MountArmor(bool _b) { m_bAlreadyMountArmor = _b; }

	void Set_CurWeapon(CItem* _Item) { m_CurMountWeapon = _Item; }
	void Set_CurArmor(CItem* _Item) { m_CurMountArmor = _Item; }


	void Set_Job(PLAYER_JOB _e) { m_player_job = _e; }


public:
	const char* Get_Name() { return m_szName; }
	float Get_Hp() { return m_fHp; }
	float Get_Mp() { return m_fMp; }
	float Get_AttackInfo() { return  m_fAttackInfo; }
	float Get_DefenseInfo() { return m_fDefenseInfo; }

	bool Get_Already_MountWeapon() { return m_bAlreadyMountWeapon; }
	bool Get_Already_MountArmor() { return m_bAlreadyMountArmor; }

	CItem* Get_CurWeapon() { return m_CurMountWeapon; }
	CItem* Get_CurArmor() { return m_CurMountArmor; }

	CInventory* Get_Inventory() { return m_player_Inventory; } // const 써야할지 말지 고민
	PLAYER_JOB Get_Job() { return m_player_job; }



public:
	void InitPlayer_StructMem()
	{
		m_CurMountWeapon = nullptr;
		m_CurMountArmor = nullptr;
		m_bAlreadyMountWeapon = false;
		m_bAlreadyMountArmor = false;
		m_player_Inventory = nullptr;

		

		FILE* fFile = nullptr;
		if (0 == fopen_s(&fFile, "../Player_data//PlayerMoney.txt", "rb"))
		{
			m_player_Inventory = new CInventory();

			int iMoney(0);
			fread(&iMoney, sizeof(int), 1, fFile); // 돈 읽어온후
			m_player_Inventory->iMoney = iMoney;

			fclose(fFile);
		}

	}
	

public:

	CPlayer(const char* _szName, float _fHp, float _fMp, float _fAttack, float _fDefense, PLAYER_JOB _e);


	CPlayer();
	~CPlayer();


};

