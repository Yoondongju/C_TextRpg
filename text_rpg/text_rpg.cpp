#pragma once

#include "pch.h"
#include "CCore.h"
#include "CPlayer.h"
#include "CSlime.h"
#include "CGolem.h"


#include "CItem.h"
#include "CInventory.h"

#include "CObject.h"
#include "CMonster.h"



void GameStart();


void Enter_HuntingStage();
void Enter_Slime_Stage();
void Enter_Golem_Stage();

void Enter_Store();
void Enter_Inventory();


void Player_Update();

void Player_Save();




extern CPlayer* g_Player;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CCore::CreatePlayer();



	if (nullptr != g_Player)
		GameStart();


	delete g_Player;
	g_Player = nullptr;

	return 0;
}



void GameStart()
{
	while (true)
	{		
		Player_Update();

		int iInput(0);
		system("cls");
		cout << "==================================================" << endl;
		cout << "�̸�: " << g_Player->Get_Name() << endl << "ü��: " << g_Player->Get_Hp() << "\t" << "����: " << g_Player->Get_Mp() << "\t" << "���ݷ�: " << g_Player->Get_AttackInfo() << "\t" << "����: " << g_Player->Get_DefenseInfo() << endl;
		cout << "1. ����Ͱ���\t2. ������ �����ϱ�\t3. ��������\t4. �κ��丮 �����" << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
		{
			Enter_HuntingStage();
		}
		break;

		case 2:
		{
			Player_Save();
			return;
		}
		break;

		case 3:
		{
			Enter_Store();
		}
			break;

		case 4:
		{
			Enter_Inventory();
		}
			break;

		default:
		{
			cout << "�߸��� �Է��Դϴ�. �ٽ��Է����ּ���" << endl;
			system("pause");
		}
		break;

		}
	}
}

void Enter_HuntingStage()
{
	while (true)
	{
		if (0 >= g_Player->Get_Hp())
			break;

		int iInput(0);
		system("cls");
		cout << "==================================================" << endl;
			cout << "�̸�: " << g_Player->Get_Name() << endl << "ü��: " << g_Player->Get_Hp() << "\t" << "����: " << g_Player->Get_Mp() << "\t" << "���ݷ�: " << g_Player->Get_AttackInfo() << "\t" << "����: " << g_Player->Get_DefenseInfo() << endl;
		cout << "1. ���������\t2. �����\t3. �� �ܰ�" << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
		{
			Enter_Slime_Stage();
		}
		break;

		case 2:
		{
			Enter_Golem_Stage();
		}
		break;

		case 3:
		{
			return;
		}
		break;

		default:
		{
			cout << "�߸��� �Է��Դϴ�. �ٽ��Է����ּ���" << endl;
			system("pause");
		}
		break;

		}
	}
}

void Enter_Slime_Stage()
{
	CSlime slime("������", 100.f, 5.f);
	int iInput(0);

	while (true)
	{
		if (0 >= g_Player->Get_Hp())
		{
			cout << g_Player->Get_Name() << "���� ����ϼ̽��ϴ�..�κ�� ���ư��ϴ�" << endl;
			system("pause");
			break;
		}

		if (0 >= slime.Get_Hp())
		{
			cout << "������ óġ����..����ͷ� ���ư��ϴ�"<<endl;
			cout << slime.Get_DropMoney() << " ��带 ȹ���ϼ̽��ϴ�" << endl;
			g_Player->Get_Inventory()->iMoney += slime.Get_DropMoney();

			system("pause");
			break;
		}

		system("cls");
		cout << "==================================================" << endl;
		cout << "�̸�: " << g_Player->Get_Name() << endl << "ü��: " << g_Player->Get_Hp() << "\t" << "����: " << g_Player->Get_Mp() << "\t" << "���ݷ�: " << g_Player->Get_AttackInfo() << "\t" << "����: " << g_Player->Get_DefenseInfo() << endl;
		cout << endl;
		cout << "==================================================" << endl;
		cout << "�̸�: " << slime.Get_Name() << endl << "ü��: " << slime.Get_Hp() << "\t" << "���ݷ�: " << slime.Get_AttackInfo() << endl;

		cout << "1. �����ϱ�\t2. ��������" << endl;
		cin >> iInput;

		
		switch (iInput)
		{
		case 1:
		{
			float fHp = g_Player->Get_Hp();
			fHp -= slime.Get_AttackInfo();
			g_Player->Set_Hp(fHp);

			slime.Set_Hp(slime.Get_Hp() - g_Player->Get_AttackInfo());
		}
		break;

		case 2:
		{
			return;
		}
		break;

		default:
		{
			cout << "�߸��� �Է��Դϴ�. �ٽ��Է����ּ���" << endl;
			system("pause");
		}
		break;
		}
	}
}

void Enter_Golem_Stage()
{
	CGolem golem("��", 100.f, 8.f);
	int iInput(0);

	while (true)
	{
		if (0 >= g_Player->Get_Hp())
		{
			cout << g_Player->Get_Name() << "���� ����ϼ̽��ϴ�..�κ�� ���ư��ϴ�" << endl;
			system("pause");
			break;
		}

		if (0 >= golem.Get_Hp())
		{
			cout << "�� óġ����..����ͷ� ���ư��ϴ�"<< endl;
			cout << golem.Get_DropMoney() << " ��带 ȹ���ϼ̽��ϴ�" << endl;
			g_Player->Get_Inventory()->iMoney += golem.Get_DropMoney();

			system("pause");
			break;
		}

		system("cls");
		cout << "==================================================" << endl;
		cout << "�̸�: " << g_Player->Get_Name() << endl << "ü��: " << g_Player->Get_Hp() << "\t" << "����: " << g_Player->Get_Mp() << "\t" << "���ݷ�: " << g_Player->Get_AttackInfo() << "\t" << "����: " << g_Player->Get_DefenseInfo() << endl;
		cout << endl;
		cout << "==================================================" << endl;
		cout << "�̸�: " << golem.Get_Name() << endl << "ü��: " << golem.Get_Hp() << "\t" << "���ݷ�: " << golem.Get_AttackInfo() << endl;

		cout << "1. �����ϱ�\t2. ��������" << endl;
		cin >> iInput;


		switch (iInput)
		{
		case 1:
		{	float fHp = g_Player->Get_Hp();
			fHp -= golem.Get_AttackInfo();
			g_Player->Set_Hp(fHp);

			golem.Set_Hp(golem.Get_Hp() - g_Player->Get_AttackInfo());
		}
		break;

		case 2:
		{
			return;
		}
		break;

		default:
		{
			cout << "�߸��� �Է��Դϴ�. �ٽ��Է����ּ���" << endl;
			system("pause");
		}
		break;
		}
	}
}

void Enter_Store()
{
	int iInput(0);

	while (true)
	{
		int iPlayerMoney = g_Player->Get_Inventory()->iMoney; // ���� ���Ŵϱ� ������

		system("cls");

		cout << "\t\t\t############################### ���� ###############################" << endl<<endl<<endl;
		cout << "\t\t\t\t\t���Ǹ��"<<endl; 
		cout << "\t\t\t\t\t1. �Ѽհ�( 500�� ) ���ݷ�: 10" << endl;
		cout << "\t\t\t\t\t2. õ����( 1000�� ) ����: 10" << endl;
		cout <<	"\t\t\t\t\t3. ��������( 2000�� ) ���ݷ�: 30"<< endl;
		cout << "\t\t\t\t\t4. �κ�� ���ư���" << endl;
		cout << endl << endl << endl;
		cout << "\t\t\t############################### ���� ###############################" << endl<<endl;

		cout << "�������: " << iPlayerMoney << " ���Դϴ�." << endl;
		cout << "���Ͻô� ������ �����ϼ���: ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
		{
			if (0 > (iPlayerMoney - 500))
			{
				cout << "������尡 �����մϴ�.." << endl;
				system("pause");
			}
			else
			{
				g_Player->Get_Inventory()->iMoney -= 500;
				g_Player->Get_Inventory()->iItem[(size_t)PLAYER_ITEM::SWORD].push_back(new CItem("�Ѽհ�", true, false, 10.f, 0.f, ITEM_TYPE::WEAPON, PLAYER_ITEM::SWORD));

				cout << "�Ѽհ��� �����ϼ̽��ϴ�." << endl;
				system("pause");
			}			
		}
			break;

		case 2:
		{
			if (0 > (iPlayerMoney - 1000))
			{
				cout << "������尡 �����մϴ�.." << endl;
				system("pause");
			}
			else
			{
				g_Player->Get_Inventory()->iMoney -= 1000;
				g_Player->Get_Inventory()->iItem[(size_t)PLAYER_ITEM::ARMOR].push_back(new CItem("õ����", true, false, 0.f, 10.f, ITEM_TYPE::ARMOR, PLAYER_ITEM::ARMOR));

				cout << "õ������ �����ϼ̽��ϴ�." << endl;
				system("pause");
			}
		}
			break;

		case 3:
		{
			if (0 > (iPlayerMoney - 2000))
			{
				cout << "������尡 �����մϴ�.." << endl;
				system("pause");
			}
			else
			{
				g_Player->Get_Inventory()->iMoney -= 2000;
				g_Player->Get_Inventory()->iItem[(size_t)PLAYER_ITEM::POWERFUL_WEAPON].push_back(new CItem("��������", true, false, 30.f, 0.f, ITEM_TYPE::WEAPON, PLAYER_ITEM::POWERFUL_WEAPON));

				cout << "�������⸦ �����ϼ̽��ϴ�." << endl;
				system("pause");
			}
		}
			break;

		case 4:
			return;
			break;

		default:
		{
			cout << "�߸��� �Է��Դϴ�. �ٽ��Է����ּ���" << endl;
			system("pause");
		}
			break;
		}


	}


}

void Enter_Inventory()
{
	// � �������� ���� �Ͽ����� üũ�ϱ� ���� ��������

	int iInput(0);
	CInventory* playerInventory = g_Player->Get_Inventory();

	while (true)
	{
		size_t i = 0;

		system("cls");

		cout << "\t\t\t############################### �κ��丮 ###############################" << endl << endl << endl;
		cout << "\t\t\t\t\t�������" << endl;

		int iCount = 0;
		for (i; i < (size_t)PLAYER_ITEM::END; ++i)
		{
			if ( 0 < playerInventory->iItem[i].size()) // item�� �����Ҷ� ���� ���� ���� �ٵ� �װ� �׸��̶� �̰͵� �����ұ� ����غ�����
			{
				cout << "\t\t\t\t\t" << i  << ". " << playerInventory->iItem[i][0]->szName << " (" << g_Player->Get_Inventory()->iItem[i].size() << "�� ������)" << endl;
				iCount = 1;
			}
		}

		if (0 == iCount)
			cout << "\t\t\t\t\t" << "�����ϰ� ��Ű� ���׿�.." << endl;

		cout << "\t\t\t\t\t"<< i <<". " <<"�κ�� ���ư���" << endl;
		cout << endl << endl << endl;
		cout << "\t\t\t############################### �κ��丮 ###############################" << endl << endl;

		cout << "�������: " << playerInventory->iMoney << " ���Դϴ�." << endl;


		if (nullptr != g_Player->Get_CurWeapon())
			cout << "���� �������� ����: " << g_Player->Get_CurWeapon()->szName << endl;
		else
			cout << "���� �������� ����: ����" << endl;

		if (nullptr != g_Player->Get_CurArmor())
			cout << "���� �������� ��: " << g_Player->Get_CurArmor()->szName << endl;
		else
			cout << "���� �������� ��: ����" << endl;

		
		cout << endl << "�����ϰ��� �ϴ� ��� �����ϼ���: ";
		cin >> iInput;

		cout << endl << endl;
		switch (iInput)
		{

		case (size_t)PLAYER_ITEM::SWORD:
		{
			if ( 0 < playerInventory->iItem[(size_t)PLAYER_ITEM::SWORD].size())
			{	
				if (playerInventory->iItem[(size_t)PLAYER_ITEM::SWORD][0] == g_Player->Get_CurWeapon())
					cout << playerInventory->iItem[(size_t)PLAYER_ITEM::SWORD][0]->szName << "�� �̹� ������ �Դϴ�." << endl;
				else
				{
					if (g_Player->Get_Already_MountWeapon()) // �̹� ������ �̹� �����Ѱ� �ִٸ� 
					{
						float fAtt = g_Player->Get_AttackInfo();
						fAtt -= g_Player->Get_CurWeapon()->fAttackInfo;

						g_Player->Set_AttackInfo(fAtt);					
					}

					playerInventory->iItem[(size_t)PLAYER_ITEM::SWORD][0]->bMount = true;
					cout << playerInventory->iItem[(size_t)PLAYER_ITEM::SWORD][0]->szName << " ���� �Ϸ�" << endl;
					g_Player->Set_AttackInfo(g_Player->Get_AttackInfo() + playerInventory->iItem[(size_t)PLAYER_ITEM::SWORD][0]->fAttackInfo);
					g_Player->Set_Already_MountWeapon(true);
					g_Player->Set_CurWeapon(playerInventory->iItem[(size_t)PLAYER_ITEM::SWORD][0]);
				}
				system("pause");
			}
				
		}
		break;

		case (size_t)PLAYER_ITEM::ARMOR:
		{
			if ( 0 < playerInventory->iItem[(size_t)PLAYER_ITEM::ARMOR].size())
			{
				if(playerInventory->iItem[(size_t)PLAYER_ITEM::ARMOR][0] == g_Player->Get_CurArmor())
					cout << playerInventory->iItem[(size_t)PLAYER_ITEM::ARMOR][0]->szName << "�� �̹� ������ �Դϴ�." << endl;
				else
				{
					if (g_Player->Get_Already_MountArmor()) // �̹� ������ �̹� �����Ѱ� �ִٸ� 
					{
						float fDe = g_Player->Get_DefenseInfo();
						fDe -= g_Player->Get_CurArmor()->fDefenseInfo;

						g_Player->Set_DefenseInfo(fDe);
					}

					playerInventory->iItem[(size_t)PLAYER_ITEM::ARMOR][0]->bMount = true;
					cout << playerInventory->iItem[(size_t)PLAYER_ITEM::ARMOR][0]->szName << " ���� �Ϸ�" << endl;
					g_Player->Set_DefenseInfo(g_Player->Get_DefenseInfo() + playerInventory->iItem[(size_t)PLAYER_ITEM::ARMOR][0]->fDefenseInfo);
					g_Player->Set_Already_MountArmor(true);
					g_Player->Set_CurArmor(playerInventory->iItem[(size_t)PLAYER_ITEM::ARMOR][0]);
				}
				system("pause");
			}
				
		}
		break;

		case (size_t)PLAYER_ITEM::POWERFUL_WEAPON:
		{
			if ( 0 < playerInventory->iItem[(size_t)PLAYER_ITEM::POWERFUL_WEAPON].size())
			{
				if (playerInventory->iItem[(size_t)PLAYER_ITEM::POWERFUL_WEAPON][0] == g_Player->Get_CurWeapon())
					cout << playerInventory->iItem[(size_t)PLAYER_ITEM::POWERFUL_WEAPON][0]->szName << "�� �̹� ������ �Դϴ�." << endl;
				else
				{
					if (g_Player->Get_Already_MountWeapon()) // �̹� ������ �̹� �����Ѱ� �ִٸ� 
					{
						float fAtt = g_Player->Get_AttackInfo();
						fAtt -= g_Player->Get_CurWeapon()->fAttackInfo;

						g_Player->Set_AttackInfo(fAtt);
					}

					playerInventory->iItem[(size_t)PLAYER_ITEM::POWERFUL_WEAPON][0]->bMount = true;
					cout << playerInventory->iItem[(size_t)PLAYER_ITEM::POWERFUL_WEAPON][0]->szName << " ���� �Ϸ�" << endl;
					g_Player->Set_AttackInfo(g_Player->Get_AttackInfo() + playerInventory->iItem[(size_t)PLAYER_ITEM::POWERFUL_WEAPON][0]->fAttackInfo);
					g_Player->Set_Already_MountWeapon(true);
					g_Player->Set_CurWeapon(playerInventory->iItem[(size_t)PLAYER_ITEM::POWERFUL_WEAPON][0]);
					
				}
				system("pause");
			}			
		}
		break;

		case 4:
			return;
			break;

		case 5:
			break;

		default:
		{
			cout << "�߸��� �Է��Դϴ�. �ٽ��Է����ּ���" << endl;
			system("pause");
		}
		break;
		}

		// ������ ������ ���� ����� ex �����
		
	}


	


}

void Player_Update()
{
	if (0 >= g_Player->Get_Hp())
		g_Player->Set_Hp(100.f); // �� ȸ��

}

void Player_Save()
{
	FILE* fFile = nullptr;
	//errno_t a = fopen_s(&fFile, "../Player_data//PlayerData.txt", "wb");

	if (0 == fopen_s(&fFile, "../Player_data//PlayerData.txt", "wb"))
	{
		cout << "Player ���� ����Ϸ�.." << endl;

		fwrite(g_Player, sizeof(CPlayer), 1, fFile); // Player�� ����� �ѹ��� �����ϴ°� �ƴ� ���������� �����ϴ°��� �����Ͱ���


		if (0 == fopen_s(&fFile, "../Player_data//PlayerMoney.txt", "wb"))
		{
			fwrite(&(g_Player->Get_Inventory()->iMoney), sizeof(int), 1, fFile);
		}


		if (0 == fopen_s(&fFile, "../Player_data//PlayerItem.txt", "wb"))
		{
			for (size_t i = 0; i < (size_t)PLAYER_ITEM::END; ++i)
			{
				if (0 < g_Player->Get_Inventory()->iItem[i].size())
				{
					for (size_t j = 0; j < g_Player->Get_Inventory()->iItem[i].size(); ++j)
					{
						fwrite(g_Player->Get_Inventory()->iItem[i][j], sizeof(CItem), 1, fFile);
					}
				}
					
			}
		}


		fclose(fFile);
	}
	else
		cout << "Player ���� �������.." << endl;

}




