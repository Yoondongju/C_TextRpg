#include "CCore.h"
#include "pch.h"

#include "CPlayer.h"
#include "CItem.h"

extern CPlayer* g_Player;

void CCore::CreatePlayer()
{
	char szName[256];
	int  iPlayer_Job(-1);

	int iIpunt(0);
	while (true)
	{
		system("cls");

		cout << "1. 새로 시작하기" << endl;
		cout << "2. 이어 하기" << endl;

		cin >> iIpunt;

		if (1 == iIpunt)
			break;
		else if (2 == iIpunt)
		{
			FILE* fFile = nullptr;
			if (0 == fopen_s(&fFile, "../Player_data//PlayerData.txt", "rb"))
			{
				if (nullptr == g_Player)
				{
					g_Player = new CPlayer();
					fread(g_Player, sizeof(CPlayer), 1, fFile);
					g_Player->InitPlayer_StructMem();

					fclose(fFile);

					if (0 == fopen_s(&fFile, "../Player_data//PlayerItem.txt", "rb"))
					{
						CItem Buffer;

						while ( true ) 
						{
							fread(&Buffer, sizeof(CItem), 1, fFile); // 아이템 읽어온후

							if ( 0 != feof(fFile)) // feof은 파일의 마지막을 가르킬때 true를 반환하는게아니라 마지막까지 도달해서 2번 루프돌아서 아래로 빼줫음
								break;  // http://www.drpaulcarter.com/cs/common-c-errors.php#4.2 
							
							switch (Buffer.eItem)
							{
							case PLAYER_ITEM::SWORD:
							{
								CInventory* a = g_Player->Get_Inventory(); // 왜 문제 생기는지 모르겠어							
								a->iItem[(size_t)PLAYER_ITEM::SWORD].push_back(new CItem(Buffer));	// 있으면 동적할당 복사 생성자 구현해줘야함	
								break;
							}
							case PLAYER_ITEM::ARMOR:
							{
								g_Player->Get_Inventory()->iItem[(size_t)PLAYER_ITEM::ARMOR].push_back(new CItem(Buffer));
								break;
							}
							case PLAYER_ITEM::POWERFUL_WEAPON:
							{
								CInventory* a = g_Player->Get_Inventory();
								a->iItem[(size_t)PLAYER_ITEM::POWERFUL_WEAPON].push_back(new CItem(Buffer));
								break;
							}
								

							default:
								break;
							}
						}

					}

				}




				char szPlayerJob[16] = "";

				switch (g_Player->Get_Job())
				{
				case PLAYER_JOB::WARRIOR:
					strcpy_s(szPlayerJob, sizeof("전사"), "전사");
					break;

				case PLAYER_JOB::WIZARD:
					strcpy_s(szPlayerJob, sizeof("마법사"), "마법사");
					break;

				case PLAYER_JOB::ROGUE:
					strcpy_s(szPlayerJob, sizeof("도적"), "도적");
					break;

				default:
					break;
				}



				// 전부 문자열로 바꿔줘야하나? 일단 어캐나오나 체크
				char szPlayerItem[(size_t)PLAYER_ITEM::END] = "";
				cout << "불러온 Player 이름: " << g_Player->Get_Name() << endl;
				cout << "불러온 Player 직업: " << szPlayerJob << endl;
				cout << "불러온 Player 소유 골드: " << g_Player->Get_Inventory()->iMoney << endl;

				bool bCheck = false;
				for (size_t i = 0; i < (size_t)PLAYER_ITEM::END; ++i)
				{
					if ( 0 < g_Player->Get_Inventory()->iItem[i].size() )
					{
						cout << "불러온 Player 소유 아이템 목록: " << g_Player->Get_Inventory()->iItem[i][0]->szName << " (" << g_Player->Get_Inventory()->iItem[i].size() <<"개 보유중)" << endl;
						bCheck = true;
					}

					if ((size_t)PLAYER_ITEM::END == i + 1)
					{
						if (!bCheck)
							cout << "불러온 Player 소유 아이템 목록: 보유하고 계신아이템이 없습니다.." << endl;
					}
				}


				fclose(fFile);
			}
			else // 불러올 파일이 없다면
			{
				cout << "저장된 정보가 없습니다..새로 시작해주세요!" << endl;
			}

			system("pause");
			return;
		}
		else // 1,2말고 아에 다른거 눌럿을때
		{
			cout << "잘못된 입력입니다." << endl;
			system("cls");
		}

	}


	system("cls");
	cout << "Player 이름을 입력하세요: ";
	cin >> szName;

	while (true)
	{
		system("cls");

		cout << "Player 직업을 고르세요 (1. 전사 2. 마법사 3. 도적) : ";
		cin >> iPlayer_Job;

		if ((size_t)PLAYER_JOB::WARRIOR != iPlayer_Job
			&& (size_t)PLAYER_JOB::WIZARD != iPlayer_Job
			&& (size_t)PLAYER_JOB::ROGUE != iPlayer_Job)
		{
			cout << "잘못된 입력입니다. 다시 골라주세요" << endl;
			system("pause");
			continue;
		}
		else
		{
			g_Player = new CPlayer(szName, 100.f, 100.f, 10.f, 0.f, (PLAYER_JOB)iPlayer_Job);
			break;
		}
	}

}

