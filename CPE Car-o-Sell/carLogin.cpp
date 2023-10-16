#include "carLogin.h"
#include "carSignUp.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();

    // Create instances of both forms
    CPECaroSell::carLogin loginForm;
    CPECaroSell::userMainwindow mainForm;

    // Show the login form initially
    Application::Run(% loginForm);

    // When the login is successful, show the userMainwindow form
    if (loginForm.SetLoginSuccessful()) {
        loginForm.Close();  // Close the login form
        Application::Run(% mainForm);  // Show the userMainwindow form
    }


    return 0;  // Add this line to return an integer (0 indicates successful execution)
}
