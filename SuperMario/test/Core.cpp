#include "Core.h"
#include "MapManager.h"
#include "ObjectManager.h"
#include "Player.h"

CCore* CCore::m_pInst = NULL;

CCore::CCore() {

}

CCore::~CCore() {
	CMapManager::DestroyInst();
	CObjectManager::DestroyInst();
}

CCore* CCore::GetInst() {
	if (!m_pInst)
		m_pInst = new CCore;
	return m_pInst;
}

void CCore::DestroyInst() {
	SAFE_DELETE(m_pInst);
}

bool CCore::Init() {
	if (!CMapManager::GetInst()->Init())
		return false;
	if (!CObjectManager::GetInst()->Init())
		return false;
	return true;
}

void CCore::Run() {
	while (true)
	{
		int iStage = OutputMenu();
		if (iStage == 4)
			break;
		else if (iStage == 0)
			continue;
		CMapManager::GetInst()->Run(iStage - 1);
	}
}

int CCore::OutputMenu() {
	system("cls");
	cout << "     <<������ ����>>" << endl;
	cout << "- ���� �̵�: ���� ����Ű" << endl;
	cout << "- ������ �̵�: ������ ����Ű" << endl;
	cout << "- ����: ������Ű" << endl;
	cout << "- �÷��� �� �����ϱ�: e" << endl << endl;
	cout << "1. ��������1" << endl;
	cout << "2. ��������2" << endl;
	cout << "3. ��������3" << endl;
	cout << "4. ����" << endl;
	cout << "��ȣ�� �Է��ϼ���: ";
	int iInput = InputInt();
	while (iInput < 1 || iInput > 4) {
		return 0;
	}
	return iInput;
}