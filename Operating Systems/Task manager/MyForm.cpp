#include "MyForm.h"
#include "process.h"

using namespace test;//ʹ��MyForm.h�ж��������ռ�

[STAThread]//���߳����ԣ���Щ���Ҫ���߳�

int main()
{
	Application::EnableVisualStyles();
	System::Windows::Forms::Application::Run(gcnew test::MyForm());

	return 0;
}