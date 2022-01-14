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

<<<<<<< Updated upstream
=======
        void AddUser()
        {
             string username;
             string password;
               int id = 1 + getLastID();
             cout << "select username\n";
             cin >> username;
            if(checkFile(username, "user.dat") != 0)
            {
                cout << "that user name is not available\n";
                 AddUser(); 
            }
            else
            {
                 saveFile(username, "user.dat", id);
            }


          cout << "set password\n";
          cin >> password;
           saveFile(password, "pass.dat", id);

        }

        int getLastID()
        {
            fstream file;
            file.open("user.dat", ios::in);
            file.seekg(0, ios::end);

            if (file.tellg() == -1)
                return 0;
            string s;

            for(int i = -1; s.find("#") == string::npos; i--)
            {
                file.seekg(i, ios::end);
                file >> s;
            }
            file.close();
            s.erase(0, 4);
            int id;// temp varaible
            istringstream(s) >> id; // to convert string into int
            return id;
        }
>>>>>>> Stashed changes

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
int option;
LoginManager cred;
<<<<<<< Updated upstream
cred.Login();
=======


//            username       password
//cred.AddUser("bakhtiyaris", "bakhtiyar");  // add username and password using this function

 cout << "****************************************************" << "WELCOME" << "****************************************************\n" << endl;
     cout << "Already have a account press 1 to logIn\n " << "To create a account press 2\n" << "To exit press 3\n" <<endl;
     cin >> option;

if (option == 1)
{
    cred.Login();
}
else if (option == 2)
{
    cred.AddUser();
}
else if (option == 3)
{
    cout << "we are sad to see you going ,\n visit again soon\n";
    return 0;

}
>>>>>>> Stashed changes

cin.get();
}



