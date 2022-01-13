#include <iostream>

#include <fstream>

#include <sstream>

#include <math.h>

 using namespace std;

 class LoginManager{
     public:


         LoginManager() {
             AccessGranted == 1;
         }
        void Login(){
            cout << "Hey please enter your username and password \n";
            cout << "USERNAME OR EMAIL :";
            cin >> UserName;
            int userID = checkFile(UserName, "user.dat");
           //  ActualUserName = getFile("user.dat");

            if (userID != 0)
            {
                cout << "Enter password\n";
                cin >> PassWord;
                int passID = checkFile(PassWord, "pass.dat");
              //  ActualPassWord = getFile("pass.dat");

                if (userID == passID)
                {
                cout << "You are granted access" << endl;

                }

                else
                {
                    cout << "Incorrect password" << endl;
                    Login();
                }
            }
            else
                {
                    cout << "Username does not match" << endl;
                    Login();
                }
        }

        void AddUser(const string username, const string password)
        {
            if(checkFile(username, "user.dat") != 0)
            {
                cout << "that user name is not available";
                return; // will exit code immediately
            }
            int id = 1 + getLastID();
            saveFile(username, "user.dat", id);
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

        int checkFile(string attempt, const char *Credentials){
        string data;
        fstream Register;

        string currentfile;
        long long eChar; // encrypted data

        Register.open(Credentials, ios::in); // to read the file
        while(1)
          {
            //getline(Register, eChar); now instead of data variable. info will come from eChar. we were not able to save int in string
            Register >> currentfile;
            if(currentfile.find("#ID:") != string::npos)
            {
                if(attempt == data)
                {
                    Register.close();
                    currentfile.erase(0, 4);
                    int id;
                    istringstream(currentfile) >> id;
                    return id;
                }

                else
                {
                    data.erase(data.begin(), data.end());
                }
            }
            else
            {
               istringstream(currentfile) >> eChar;
               data += (char)decrypt(eChar); // it will decrypt our password. and we changed decrypt from int to char so that we can add two strings
               currentfile = "";
            }
             if (Register.peek() == EOF)  //EOF stands for end of file
             {
                 Register.close();
                 return 0;
             }
          }

        }

        void saveFile(string p_line, const char *p_filename, const int& id)
        {
          fstream Register;
          //Register.open(p_filename, ios::out);  to write to the file
             Register.open(p_filename, ios::app);// to append in the file
             Register.seekg(0, ios::end);

             if(Register.tellg() != 0)
             Register << "\n";
             Register.seekg(0, ios::beg);

            for (int i = 0; i < p_line.length(); i++)
                {
                    Register << encrypt(p_line[i]);
                    Register << "\n"; //to get encrypted password character wise in new lines
                }
                Register << "#ID:" << id; // its better to save password with 0 at the end for now.
                Register.close();
        }



        long long encrypt(int p_letters)
        {
            return powf(p_letters, 5)*4 - 14;
        }
        int decrypt(long long p_letters)
        {
            return powf((p_letters + 14) / 4, 1/5.f);
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
//            username       password
cred.AddUser("bakhtiyaris", "bakhtiyar");  // add username and password using this function
cred.Login();

cin.get();
}



