
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void dragline()
{
  cout<<endl;
  for(int i=0;i<35;i++)
   cout<<"-"; 
}

int calculateTotal(vector<int>& accounts) 
{
    int sum = 0;
  
    for (int i=0;i<accounts.size();i++) 
    {
      
        sum += accounts[i];
    }
    return sum;
}

int main() {
    /*
    “+” - записати новий рахунок рівний сумі двох попередніх;
    “д” — записати новий рахунок вдвічі більший за попередній;
    “с” — скасувати попередній записаний рахунок.
    */
   
    string input;
    for (int i = 0; i < 3; i++)
    {
        dragline();
        cout << "\n\tПриклад " << i + 1;
        cout<<"\n“+” - записати новий рахунок рівний сумі двох попередніх;";
        cout<<"\n“д” — записати новий рахунок вдвічі більший за попередній;";
        cout<<"\n“с” — скасувати попередній записаний рахунок";
        dragline();
        cout << "\nВведіть рядок : ";
        getline(cin, input);

        vector<int> accounts;
        istringstream iss(input);
        string token;

        while (iss >> token) 
        {
            if (token == "с") 
            {
                if (!accounts.empty())
                {
                    accounts.pop_back();
                   // cout << "\nSize c =" << accounts.size();
                }
            }
            else if (token == "д")
            {
                if (!accounts.empty()) 
                {
                    int previous = accounts.back();
                    accounts.push_back(previous * 2);
                
                }
            }
            else if (token == "+")
            {
                if (accounts.size() >= 2)
                {
                    int last =  accounts.back();
                    //cout << "\nSize + =" << last;
                  accounts.pop_back();  
                  int secondLast = accounts.back();
                  accounts.push_back(last);
                    accounts.push_back(last + secondLast);
                    //calcula(accounts);
                }
            }

            else
            {
                int account = stoi(token);
              if(account<333 && account>-333)
                accounts.push_back(account);
              else
              {
                cout<<"\nВи порушили умову :(";
                break;
              }
            }
        }
       
        int total = calculateTotal(accounts);
      dragline();
        cout << "\nВивід : " << total << endl;
    }
    return 0;
}