#include "userMainWindow.h"
#include "carLogin.h"
#include "userMainWindow.h"
#include "rentWindow.h"

using namespace System;
using namespace System::Windows::Forms;

User^ AuthenticateUser()
{
    while (true)
    {
        User^ user = nullptr;
        CPECaroSell::userMainwindow registerForm;
        CPECaroSell::carLogin loginForm;
        loginForm.ShowDialog();


        if (loginForm.SwitchToMain)
        {
            
            registerForm.ShowDialog();

            if (registerForm.switchToLogin)
            {
                continue;
            }
            else
            {
                return registerForm.user;
            }
        }
        else if (registerForm.switchToRentForm) 
        {
            CPECaroSell::rentWindow mainForm(user);
            mainForm.ShowDialog();

            if (mainForm.switchBackToUserMain)
            {
                continue;
            }
            else
            {
                break; // Exiting the program
            }
        }
        else
        {
            return loginForm.user;
        }
    }
}

//void HandleUserSession()
//{
//    User^ user = nullptr;
//    while (true)
//    {
//        user = AuthenticateUser();
//
//        if (user != nullptr)
//        {
//            CPECaroSell::rentWindow mainForm(user);
//            mainForm.ShowDialog();
//
//            if (mainForm.switchBackToUserMain)
//            {
//                continue;
//            }
//            else
//            {
//                break; // Exiting the program
//            }
//        }
//        else
//        {
//            break; // No user, exit program
//        }
//    }
//}

int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    //HandleUserSession();

    AuthenticateUser();

    return 0;
}
