#include <iostream>

#include <fstream>

 using namespace std;

 class LoginManager{
     public:


         LoginManager() {
             AccessGranted == 1;
         }
        void Login(){
            cout << "Hey please enter your username and password \n enter user: kbakhtiyaris\npassword: bakhtiyar\n";
            cout << "USERNAME OR EMAIL :";
            cin >> UserName;
             ActualUserName = getFile("user.dat");

            if (UserName==ActualUserName)
            {
                cout << "enter password\n";
                cin >> PassWord;
                ActualPassWord = getFile("pass.dat");

                if (PassWord==ActualPassWord)
                {
                cout << "you are granted access" << endl;
                cin.get();
                }

                else
                {
                    cout << "incorrect password" << endl;
                    Login();
                }
            }
            else
                {
                    cout << "username does not match" << endl;
                    Login();
                }
        }


        string getFile(char *Credentials){
        string data;
        fstream Register;
        int eChar; // encrypted data

        Register.open(Credentials, ios::in); // to read the file
        while(1)
          {
            //getline(Register, eChar); // now instead of data variable. info will come from eChar. we were not able to save int in string
            Register >> eChar;
            if(eChar == 0)
            {
              Register.close();
              return data;
            }
            data += (char)decrypt(eChar); // it will decrypt our password. and we changed decrypt from int to char so that we can add two strings
          }

        }

        void saveFile(string p_line, const char *p_filename )
        {
          fstream Register;
          Register.open(p_filename, ios::out); // to write to the file
            for (int i = 0; i < p_line.length(); i++)
                {
                    Register << encrypt(p_line[i]);
                    Register << "\n"; //to get encrypted password character wise in new lines
                }
                Register << "0"; // its better to save password with 0 at the end.
                Register.close();
        }



        int encrypt(int p_letters)
        {
            return p_letters + 3;
        }
        int decrypt(int p_letters)
        {
            return p_letters - 3;
        }

    private:
        string UserName;
        string PassWord;
    string ActualUserName ;
    string ActualPassWord ;
     bool AccessGranted;
 };


int main() {

LoginManager cred;
cred.Login();

cin.get();
}



