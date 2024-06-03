#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main() {

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	NNetworkGUI::MyForm frm;
	Application::Run(%frm);

	return 0;
}