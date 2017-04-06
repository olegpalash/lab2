#include <iostream>
#include <vector>
#include "Train.hpp"

using namespace std;

int main()
{
    vector<Train> trains;
    
    bool cont = true;
    while (cont)
    {
        cout << "[1] Додати потяг." << endl;
        cout << "[2] Вивести список потягів." << endl;
        cout << "[3] Вивести інформацію про потяг." << endl;
        cout << "[4] Видалити потяг." << endl;
        cout << "[0] Вихід." << endl;
        cout << "> ";
        
        
        int ans;
        cin >> ans;
        
        if (ans == 1)
        {
            Train tmp;
            tmp.ReadData();
            trains.push_back(tmp);
        }
        else if (ans == 2)
        {
            if (trains.empty())
            {
                cout << "Реєстр порожній!" << endl;
            }
            else
            {
                cout << "№ п.п.\tНомер потяга" << endl;
                for (int i = 0; i < trains.size(); i++)
                {
                    cout << i+1 << "\t" << trains[i].GetNumber() << endl;
                }
            }
        }
        else if (ans == 3)
        {
            cout << "Введіть номер потяга: ";

            int num;
            cin >> num;
            
            bool found = false;
            for (int i = 0; i < trains.size(); i++)
            {
                if (trains[i].GetNumber() == num)
                {
                    found = true;
                    trains[i].PrintData();
                    trains[i].PrintRideTime();
                    break;
                }
            }
            
            if (!found) cout << "Потяг з таким номером не знайдено!" << endl;
        }
        else if (ans == 4)
        {
            cout << "Введіть номер потяга: ";
            
            int num;
            cin >> num;
            
            bool found = false;
            vector<Train>::iterator it = trains.begin();
            while(it != trains.end())
            {
                if (it->GetNumber() == num)
                {
                    found = true;
                    trains.erase(it);
                    break;
                }
                it++;
            }
            
            if (!found) cout << "Потяг з таким номером не знайдено!" << endl;
        }
        else if (ans == 0)
        {
            cont = false;
        }
        cout << endl;
    }
    
    return 0;
}

