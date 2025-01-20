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

		cout << "1. ���� �����ϱ�" << endl;
		cout << "2. �̾� �ϱ�" << endl;

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
							fread(&Buffer, sizeof(CItem), 1, fFile); // ������ �о����

							if ( 0 != feof(fFile)) // feof�� ������ �������� ����ų�� true�� ��ȯ�ϴ°Ծƴ϶� ���������� �����ؼ� 2�� �������Ƽ� �Ʒ��� ���Z��
								break;  // http://www.drpaulcarter.com/cs/common-c-errors.php#4.2 
							
							switch (Buffer.eItem)
							{
							case PLAYER_ITEM::SWORD:
							{
								CInventory* a = g_Player->Get_Inventory(); // �� ���� ������� �𸣰ھ�							
								a->iItem[(size_t)PLAYER_ITEM::SWORD].push_back(new CItem(Buffer));	// ������ �����Ҵ� ���� ������ �����������	
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
					strcpy_s(szPlayerJob, sizeof("����"), "����");
					break;

				case PLAYER_JOB::WIZARD:
					strcpy_s(szPlayerJob, sizeof("������"), "������");
					break;

				case PLAYER_JOB::ROGUE:
					strcpy_s(szPlayerJob, sizeof("����"), "����");
					break;

				default:
					break;
				}



				// ���� ���ڿ��� �ٲ�����ϳ�? �ϴ� ��ĳ������ üũ
				char szPlayerItem[(size_t)PLAYER_ITEM::END] = "";
				cout << "�ҷ��� Player �̸�: " << g_Player->Get_Name() << endl;
				cout << "�ҷ��� Player ����: " << szPlayerJob << endl;
				cout << "�ҷ��� Player ���� ���: " << g_Player->Get_Inventory()->iMoney << endl;

				bool bCheck = false;
				for (size_t i = 0; i < (size_t)PLAYER_ITEM::END; ++i)
				{
					if ( 0 < g_Player->Get_Inventory()->iItem[i].size() )
					{
						cout << "�ҷ��� Player ���� ������ ���: " << g_Player->Get_Inventory()->iItem[i][0]->szName << " (" << g_Player->Get_Inventory()->iItem[i].size() <<"�� ������)" << endl;
						bCheck = true;
					}

					if ((size_t)PLAYER_ITEM::END == i + 1)
					{
						if (!bCheck)
							cout << "�ҷ��� Player ���� ������ ���: �����ϰ� ��ž������� �����ϴ�.." << endl;
					}
				}


				fclose(fFile);
			}
			else // �ҷ��� ������ ���ٸ�
			{
				cout << "����� ������ �����ϴ�..���� �������ּ���!" << endl;
			}

			system("pause");
			return;
		}
		else // 1,2���� �ƿ� �ٸ��� ��������
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			system("cls");
		}

	}


	system("cls");
	cout << "Player �̸��� �Է��ϼ���: ";
	cin >> szName;

	while (true)
	{
		system("cls");

		cout << "Player ������ ������ (1. ���� 2. ������ 3. ����) : ";
		cin >> iPlayer_Job;

		if ((size_t)PLAYER_JOB::WARRIOR != iPlayer_Job
			&& (size_t)PLAYER_JOB::WIZARD != iPlayer_Job
			&& (size_t)PLAYER_JOB::ROGUE != iPlayer_Job)
		{
			cout << "�߸��� �Է��Դϴ�. �ٽ� ����ּ���" << endl;
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

