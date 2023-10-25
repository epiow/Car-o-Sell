#include "userMainWindow.h"
#include "carLogin.h"
#include "userMainWindow.h"
#include "rentWindow.h"
#include "adminWindow.h"
#include "sellWindow.h"
#include "sellList.h"

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
                CPECaroSell::rentWindow^ rentWin= gcnew CPECaroSell::rentWindow(user);
                rentWin->ShowDialog();
 
                if (rentWin->switchBackToUserMain)
                {
                    continue;
                }
            }
            else if (mainWinForm.switchToSellWindow) {           
                CPECaroSell::sellWindow^ SellWindow = gcnew CPECaroSell::sellWindow(user);
                SellWindow->ScurrentUser = loginForm.currentUser;
                SellWindow->ShowDialog();

                if (SellWindow->switchToSellList) {

                    CPECaroSell::sellList^ SellList = gcnew CPECaroSell::sellList(user);
                    SellList->SLcurrentUser = SellWindow->ScurrentUser;
                    SellList->ShowDialog();
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

int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    AuthenticateUser();

    return 0;
}