#include "Core.h"

int main() {
	if (!CCore::GetInst()->Init()) {
		cout << "���� �ʱ�ȭ ����!!" << endl;
		CCore::DestroyInst();
		return 0;
	}
	CCore::GetInst()->Run();
	CCore::DestroyInst();

	return 0;
}