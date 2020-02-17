#include <bits/stdc++.h>
#include <string>
#include <sstream>
//ini menggunakan brute force dikarenakan jumlah loker lebih sedikit dari 100;
using namespace std;

vector < string > data;
vector < vector < string > > loker;
int jumlahLoker = 0, isiLoker=0;

void removeDupWord(string str)
{
    istringstream ss(str);

    do {
        string word;
        ss >> word;

        data.push_back(word);
    } while (ss);
}

void statusLokerCheck()
{
    printf("No Loker\t Tipe Identitas\t No Identitas\n");
    if(!loker.empty())
    {
        for(int i=0; i<loker.size(); i++)
        {
           cout << loker[i][0] << '\t' << loker[i][1] << '\t' << loker[i][2] << endl;
        }
    }
}

string inputIdentitas()
{
    vector < string > tmpIdentitas;
    if(isiLoker == jumlahLoker)
    {
        for(int i=0; i<jumlahLoker; i++)
        {
            if(loker[i][1].compare("kosong") == 0)
            {
            	
                loker[i][1] = data[1];
                loker[i][2] = data[2];
                return "Kartu identitas tersimpan di loker nomor " + loker[i][0];
            }
        }
        return "Maaf loker sudah penuh";
    }
    string test;
    if(isiLoker < jumlahLoker)
    {
        isiLoker++;
        test = to_string(isiLoker);
        tmpIdentitas.push_back(test);
        tmpIdentitas.push_back(data[1]);
        tmpIdentitas.push_back(data[2]);
        loker.push_back(tmpIdentitas);
    }
    return "Kartu identitas tersimpan di loker nomor " + test;
}

string hapusLoker()
{
    if(!loker.empty())
    {
        for(int i=0; i<loker.size(); i++)
        {
            if(loker[i][0].compare(data[1]) == 0)
            {
                loker[i][1] = "kosong";
                loker[i][2] = "kosong";
                return "Loker nomor " + data[1] + " berhasil dikosongkan";
            }
        }
    }
    else
    {
        return "Loker kosong";
    }
}

string cariIdentitas()
{
    if(!loker.empty())
    {
        for(int i=0; i<loker.size(); i++)
        {
            if(loker[i][2].compare(data[1]) == 0)
            {
                return "Kartu identitas tersebut berada di loker nomor " + loker[i][0];
            }
        }
    }
    else
    {
        return "Loker kosong";
    }
    return "Nomor identitas tidak ditemukan";
}

int main ()
{
    string s = "testMasBro";
    int statusLoker = 0;

    while(true)
    {
        getline(cin, s);
        data.clear();
        removeDupWord(s);

        if(data[0].compare("init") == 0)
        {
            if(statusLoker == 0)
            {
                statusLoker = 1;
                jumlahLoker = stoi(data[1]);
                cout << "Berhasil membuat loker dengan jumlah " << jumlahLoker << endl;
            }
            else
            {
                cout << "Jumlah loker sudah ditentukan" << endl;
            }
        }
        else if (data[0].compare("status") == 0)
        {
            if(statusLoker == 1)
            {
                statusLokerCheck();

            }
            else
            {
                cout << "Jumlah loker belum di tentukan" << endl;
            }
        }
        else if (data[0].compare("input") == 0)
        {
            if(statusLoker == 1)
            {
                cout << inputIdentitas() << endl;
            }
            else
            {
                cout << "Jumlah loker belum ditentukan" << endl;
            }
        }
        else if (data[0].compare("leave") == 0)
        {
            if(statusLoker == 1)
            {
                cout << hapusLoker() << endl;
            }
            else
            {
                cout << "Jumlah loker belum di tentukan" << endl;
            }
        }
        else if (data[0].compare("find") == 0)
        {
            if(statusLoker == 1)
            {
                cout << cariIdentitas() << endl;
            }
            else
            {
                cout << "Jumlah loker sudah di tentukan" << endl;
            }
        }
        else if (data[0].compare("exit") == 0)
        {
            break;
        }
    }

    return 0;
}
