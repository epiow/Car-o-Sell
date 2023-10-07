#include "carLogin.h"
#include "carSignUp.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    CPECaroSell::carLogin frm;
    Application::Run(% frm);
    return 0; // Add this line to return an integer (0 indicates successful execution)
}

