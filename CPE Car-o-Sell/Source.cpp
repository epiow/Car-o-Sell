#include "userMainWindow.h"
#include "carLogin.h"
#include "sellWindow.h"
#include "userMainWindow.h"
#include "rentWindow.h"
#include "adminWindow.h"
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
            while (mainWinForm.switchToRentForm)
            {
                CPECaroSell::rentWindow mainForm(user);
                mainForm.ShowDialog();

                if (mainForm.switchBackToUserMain)
                {
                    CPECaroSell::calendar Calendar;
                    Calendar.ShowDialog();
                    continue;
                }
            }

            while (mainWinForm.switchToSellWindow)
            {
                CPECaroSell::sellWindow mainForm(user);
                mainForm.ShowDialog();

                if (mainForm.switchBackToUserMain)
                {
                    mainWinForm.switchToSellWindow = false;
                }
                if (mainForm.switchToSellList) {
                    CPECaroSell::sellList SellList;
                    SellList.ShowDialog();
                }

            }
            if (loginForm.SwitchToAdmin)
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
}

int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    AuthenticateUser();

    return 0;
}
