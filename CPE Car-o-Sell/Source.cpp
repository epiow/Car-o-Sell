#include "userMainWindow.h"
#include "carLogin.h"
#include "userMainWindow.h"
#include "rentWindow.h"
#include "adminWindow.h"

using namespace System;
using namespace System::Windows::Forms;

User^ AuthenticateUser()
{
    while (true)
    {
        User^ user = nullptr;
        CPECaroSell::userMainwindow mainWinForm;
        CPECaroSell::carLogin loginForm;
        CPECaroSell::adminWindow adminMainForm;
        loginForm.ShowDialog();


        if (loginForm.SwitchToMain)
        {
            
            mainWinForm.ShowDialog();

            if (mainWinForm.switchToLogin)
            {
                continue;
            }
            else if (mainWinForm.switchToRentForm)
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
                return mainWinForm.user;
            }
        }
        else if (loginForm.SwitchToAdmin)
        {
            adminMainForm.ShowDialog();

            if (adminMainForm.switchToLogin)
            {
                continue;
            }
            else
            {
                return adminMainForm.user;
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
