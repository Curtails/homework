#include "MyForm.h"
#include "process.h"

using namespace test;//使用MyForm.h中定义的命令空间

[STAThread]//单线程特性，有些组件要求单线程

int main()
{
	Application::EnableVisualStyles();
	System::Windows::Forms::Application::Run(gcnew test::MyForm());

	return 0;
}