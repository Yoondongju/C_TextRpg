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
		cout << "이름: " << g_Player->Get_Name() << endl << "체력: " << g_Player->Get_Hp() << "\t" << "마나: " << g_Player->Get_Mp() << "\t" << "공격력: " << g_Player->Get_AttackInfo() << "\t" << "방어력: " << g_Player->Get_DefenseInfo() << endl;
		cout << "1. 사냥터가기\t2. 저장후 종료하기\t3. 상점가기\t4. 인벤토리 열어보기" << endl;
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
			cout << "잘못된 입력입니다. 다시입력해주세요" << endl;
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
			cout << "이름: " << g_Player->Get_Name() << endl << "체력: " << g_Player->Get_Hp() << "\t" << "마나: " << g_Player->Get_Mp() << "\t" << "공격력: " << g_Player->Get_AttackInfo() << "\t" << "방어력: " << g_Player->Get_DefenseInfo() << endl;
		cout << "1. 슬라임잡기\t2. 골렘잡기\t3. 전 단계" << endl;
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
			cout << "잘못된 입력입니다. 다시입력해주세요" << endl;
			system("pause");
		}
		break;

		}
	}
}

void Enter_Slime_Stage()
{
	CSlime slime("슬라임", 100.f, 5.f);
	int iInput(0);

	while (true)
	{
		if (0 >= g_Player->Get_Hp())
		{
			cout << g_Player->Get_Name() << "님이 사망하셨습니다..로비로 돌아갑니다" << endl;
			system("pause");
			break;
		}

		if (0 >= slime.Get_Hp())
		{
			cout << "슬라임 처치성공..사냥터로 돌아갑니다"<<endl;
			cout << slime.Get_DropMoney() << " 골드를 획득하셨습니다" << endl;
			g_Player->Get_Inventory()->iMoney += slime.Get_DropMoney();

			system("pause");
			break;
		}

		system("cls");
		cout << "==================================================" << endl;
		cout << "이름: " << g_Player->Get_Name() << endl << "체력: " << g_Player->Get_Hp() << "\t" << "마나: " << g_Player->Get_Mp() << "\t" << "공격력: " << g_Player->Get_AttackInfo() << "\t" << "방어력: " << g_Player->Get_DefenseInfo() << endl;
		cout << endl;
		cout << "==================================================" << endl;
		cout << "이름: " << slime.Get_Name() << endl << "체력: " << slime.Get_Hp() << "\t" << "공격력: " << slime.Get_AttackInfo() << endl;

		cout << "1. 공격하기\t2. 도망가기" << endl;
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
			cout << "잘못된 입력입니다. 다시입력해주세요" << endl;
			system("pause");
		}
		break;
		}
	}
}

void Enter_Golem_Stage()
{
	CGolem golem("골렘", 100.f, 8.f);
	int iInput(0);

	while (true)
	{
		if (0 >= g_Player->Get_Hp())
		{
			cout << g_Player->Get_Name() << "님이 사망하셨습니다..로비로 돌아갑니다" << endl;
			system("pause");
			break;
		}

		if (0 >= golem.Get_Hp())
		{
			cout << "골렘 처치성공..사냥터로 돌아갑니다"<< endl;
			cout << golem.Get_DropMoney() << " 골드를 획득하셨습니다" << endl;
			g_Player->Get_Inventory()->iMoney += golem.Get_DropMoney();

			system("pause");
			break;
		}

		system("cls");
		cout << "==================================================" << endl;
		cout << "이름: " << g_Player->Get_Name() << endl << "체력: " << g_Player->Get_Hp() << "\t" << "마나: " << g_Player->Get_Mp() << "\t" << "공격력: " << g_Player->Get_AttackInfo() << "\t" << "방어력: " << g_Player->Get_DefenseInfo() << endl;
		cout << endl;
		cout << "==================================================" << endl;
		cout << "이름: " << golem.Get_Name() << endl << "체력: " << golem.Get_Hp() << "\t" << "공격력: " << golem.Get_AttackInfo() << endl;

		cout << "1. 공격하기\t2. 도망가기" << endl;
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
			cout << "잘못된 입력입니다. 다시입력해주세요" << endl;
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
		int iPlayerMoney = g_Player->Get_Inventory()->iMoney; // 자주 쓸거니까 빼놓음

		system("cls");

		cout << "\t\t\t############################### 상점 ###############################" << endl<<endl<<endl;
		cout << "\t\t\t\t\t물건목록"<<endl; 
		cout << "\t\t\t\t\t1. 한손검( 500원 ) 공격력: 10" << endl;
		cout << "\t\t\t\t\t2. 천갑옷( 1000원 ) 방어력: 10" << endl;
		cout <<	"\t\t\t\t\t3. 지존무기( 2000원 ) 공격력: 30"<< endl;
		cout << "\t\t\t\t\t4. 로비로 돌아가기" << endl;
		cout << endl << endl << endl;
		cout << "\t\t\t############################### 상점 ###############################" << endl<<endl;

		cout << "보유골드: " << iPlayerMoney << " 원입니다." << endl;
		cout << "원하시는 물건을 구매하세요: ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
		{
			if (0 > (iPlayerMoney - 500))
			{
				cout << "보유골드가 부족합니다.." << endl;
				system("pause");
			}
			else
			{
				g_Player->Get_Inventory()->iMoney -= 500;
				g_Player->Get_Inventory()->iItem[(size_t)PLAYER_ITEM::SWORD].push_back(new CItem("한손검", true, false, 10.f, 0.f, ITEM_TYPE::WEAPON, PLAYER_ITEM::SWORD));

				cout << "한손검을 구매하셨습니다." << endl;
				system("pause");
			}			
		}
			break;

		case 2:
		{
			if (0 > (iPlayerMoney - 1000))
			{
				cout << "보유골드가 부족합니다.." << endl;
				system("pause");
			}
			else
			{
				g_Player->Get_Inventory()->iMoney -= 1000;
				g_Player->Get_Inventory()->iItem[(size_t)PLAYER_ITEM::ARMOR].push_back(new CItem("천갑옷", true, false, 0.f, 10.f, ITEM_TYPE::ARMOR, PLAYER_ITEM::ARMOR));

				cout << "천갑옷을 구매하셨습니다." << endl;
				system("pause");
			}
		}
			break;

		case 3:
		{
			if (0 > (iPlayerMoney - 2000))
			{
				cout << "보유골드가 부족합니다.." << endl;
				system("pause");
			}
			else
			{
				g_Player->Get_Inventory()->iMoney -= 2000;
				g_Player->Get_Inventory()->iItem[(size_t)PLAYER_ITEM::POWERFUL_WEAPON].push_back(new CItem("지존무기", true, false, 30.f, 0.f, ITEM_TYPE::WEAPON, PLAYER_ITEM::POWERFUL_WEAPON));

				cout << "지존무기를 구매하셨습니다." << endl;
				system("pause");
			}
		}
			break;

		case 4:
			return;
			break;

		default:
		{
			cout << "잘못된 입력입니다. 다시입력해주세요" << endl;
			system("pause");
		}
			break;
		}


	}


}

void Enter_Inventory()
{
	// 어떤 아이템을 장착 하였는지 체크하기 위해 루프돌림

	int iInput(0);
	CInventory* playerInventory = g_Player->Get_Inventory();

	while (true)
	{
		size_t i = 0;

		system("cls");

		cout << "\t\t\t############################### 인벤토리 ###############################" << endl << endl << endl;
		cout << "\t\t\t\t\t보유목록" << endl;

		int iCount = 0;
		for (i; i < (size_t)PLAYER_ITEM::END; ++i)
		{
			if ( 0 < playerInventory->iItem[i].size()) // item이 존재할때 소유 여부 따짐 근데 그게 그말이라 이것도 압축할까 고민해봐야함
			{
				cout << "\t\t\t\t\t" << i  << ". " << playerInventory->iItem[i][0]->szName << " (" << g_Player->Get_Inventory()->iItem[i].size() << "개 보유중)" << endl;
				iCount = 1;
			}
		}

		if (0 == iCount)
			cout << "\t\t\t\t\t" << "보유하고 계신게 없네요.." << endl;

		cout << "\t\t\t\t\t"<< i <<". " <<"로비로 돌아가기" << endl;
		cout << endl << endl << endl;
		cout << "\t\t\t############################### 인벤토리 ###############################" << endl << endl;

		cout << "보유골드: " << playerInventory->iMoney << " 원입니다." << endl;


		if (nullptr != g_Player->Get_CurWeapon())
			cout << "현재 장착중인 무기: " << g_Player->Get_CurWeapon()->szName << endl;
		else
			cout << "현재 장착중인 무기: 없음" << endl;

		if (nullptr != g_Player->Get_CurArmor())
			cout << "현재 장착중인 방어구: " << g_Player->Get_CurArmor()->szName << endl;
		else
			cout << "현재 장착중인 방어구: 없음" << endl;

		
		cout << endl << "장착하고자 하는 장비를 선택하세요: ";
		cin >> iInput;

		cout << endl << endl;
		switch (iInput)
		{

		case (size_t)PLAYER_ITEM::SWORD:
		{
			if ( 0 < playerInventory->iItem[(size_t)PLAYER_ITEM::SWORD].size())
			{	
				if (playerInventory->iItem[(size_t)PLAYER_ITEM::SWORD][0] == g_Player->Get_CurWeapon())
					cout << playerInventory->iItem[(size_t)PLAYER_ITEM::SWORD][0]->szName << "은 이미 장착중 입니다." << endl;
				else
				{
					if (g_Player->Get_Already_MountWeapon()) // 이번 업뎃에 이미 장착한게 있다면 
					{
						float fAtt = g_Player->Get_AttackInfo();
						fAtt -= g_Player->Get_CurWeapon()->fAttackInfo;

						g_Player->Set_AttackInfo(fAtt);					
					}

					playerInventory->iItem[(size_t)PLAYER_ITEM::SWORD][0]->bMount = true;
					cout << playerInventory->iItem[(size_t)PLAYER_ITEM::SWORD][0]->szName << " 장착 완료" << endl;
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
					cout << playerInventory->iItem[(size_t)PLAYER_ITEM::ARMOR][0]->szName << "은 이미 장착중 입니다." << endl;
				else
				{
					if (g_Player->Get_Already_MountArmor()) // 이번 업뎃에 이미 장착한게 있다면 
					{
						float fDe = g_Player->Get_DefenseInfo();
						fDe -= g_Player->Get_CurArmor()->fDefenseInfo;

						g_Player->Set_DefenseInfo(fDe);
					}

					playerInventory->iItem[(size_t)PLAYER_ITEM::ARMOR][0]->bMount = true;
					cout << playerInventory->iItem[(size_t)PLAYER_ITEM::ARMOR][0]->szName << " 장착 완료" << endl;
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
					cout << playerInventory->iItem[(size_t)PLAYER_ITEM::POWERFUL_WEAPON][0]->szName << "를 이미 장착중 입니다." << endl;
				else
				{
					if (g_Player->Get_Already_MountWeapon()) // 이번 업뎃에 이미 장착한게 있다면 
					{
						float fAtt = g_Player->Get_AttackInfo();
						fAtt -= g_Player->Get_CurWeapon()->fAttackInfo;

						g_Player->Set_AttackInfo(fAtt);
					}

					playerInventory->iItem[(size_t)PLAYER_ITEM::POWERFUL_WEAPON][0]->bMount = true;
					cout << playerInventory->iItem[(size_t)PLAYER_ITEM::POWERFUL_WEAPON][0]->szName << " 장착 완료" << endl;
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
			cout << "잘못된 입력입니다. 다시입력해주세요" << endl;
			system("pause");
		}
		break;
		}

		// 장착을 여려번 할지 고민중 ex 무기방어구
		
	}


	


}

void Player_Update()
{
	if (0 >= g_Player->Get_Hp())
		g_Player->Set_Hp(100.f); // 피 회복

}

void Player_Save()
{
	FILE* fFile = nullptr;
	//errno_t a = fopen_s(&fFile, "../Player_data//PlayerData.txt", "wb");

	if (0 == fopen_s(&fFile, "../Player_data//PlayerData.txt", "wb"))
	{
		cout << "Player 정보 저장완료.." << endl;

		fwrite(g_Player, sizeof(CPlayer), 1, fFile); // Player의 멤버를 한번에 저장하는게 아닌 개별적으로 저장하는것이 좋을것같다


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
		cout << "Player 정보 저장실패.." << endl;

}




