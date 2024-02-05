#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Phonebook{
private:
    string f;

public:
    Phonebook(string f) : f{ f } {}

    void add_record(string company_name, string person_name, string phone, string adress, string work_type) 
    {
        ofstream file(f, ios::app);
        if (!file.is_open()) 
        {
            cout << "Error" << endl;
        }
        else 
        {
            file << company_name << "," << person_name << "," << phone << "," << adress << "," << work_type << endl;
            file.close();
        }
    }

    void show_data() {
        ifstream file(f);
        string line;
        if (!file.is_open()) 
        {
            cout << "Error" << endl;
        }
        else 
        {
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
    }

    vector<string> find(string s_data) 
    {
        ifstream file(f);
        string line;
        vector<string> data;
        if (!file.is_open()) 
        {
            cout << "Error" << endl;
        }
        else 
        {
            while (getline(file, line))
            {
                if (line.find(s_data) != string::npos)
                {
                    data.push_back(line);
                }
            }
            file.close();
        }
        return data;
    }
};

int main() 
{
    Phonebook pb("pb.txt");

    pb.add_record("IBM", "Unknown", "1234567890", "Internet City", "Worker");
    pb.add_record("IBM", "Sasha", "534234654787", "Internet City", "Boss");
    pb.add_record("Microsoft", "Sasha", "865234847", "Russia", "Worker");

    vector<string> data = pb.find("IBM"); //Поиск по названию компании
    vector<string> data2 = pb.find("Sasha");//Поиск по имени
    vector<string> data3 = pb.find("Russia"); // Поиск по адресу
    cout << "Data:" << endl;
    for (string rec : data) 
    {
        cout << rec << endl;
    }

    cout << "Data:" << endl;
    for (string rec : data2)
    {
        cout << rec << endl;
    }

    cout << "Data:" << endl;
    for (string rec : data3)
    {
        cout << rec << endl;
    }

    pb.show_data();
}