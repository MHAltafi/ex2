#include <iostream>
#include "client.h"
#include <random>
#include <ctime>
#include <sstream>

using namespace std;

bool is_alnum_checker(const string &name) //check kardan baraye adad va horuf boodane esm
{
    for (char const & c : name)
    {
        if(!isalnum(c))
        {
            return false;
        }
    }
    return true;
}

void client::set_name(const string & given_name)
{
    if(is_alnum_checker(given_name) && isalpha(given_name.at(0))) //check kardane alnum boodan o adad naboodane harfe aval
    {
        name = given_name;
    }
    else
    {
        throw invalid_argument("The given name consists of invalid characters. Only alphabet and numbers can be used, and the first character can't be a number.");
    }
}

string client::get_name()
{
    return name;
}

void client::set_card_number()
{
    mt19937 eng(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> Myran(1000,9999);
    card_number = Myran(eng);
}

int client::get_card_number()
{
    return card_number;
}

void client::set_balance(double given_balance)
{
    if(given_balance >= 0 )
    {
        balance = given_balance;
    }
    else
    {
        throw invalid_argument("Given balance is not valid.");
    }
}

double client::get_balance()
{
    return balance;
}

void client::set_account_opening_date()
{
    time_t now = time(0); //estefade az ctime va structe marboot be an
    tm *ltm = localtime(&now);
    account_opening_date.year = 1900 + ltm->tm_year;
    account_opening_date.month = 1 + ltm->tm_mon;
    account_opening_date.day = ltm->tm_mday;
}

date client::get_account_opening_date()
{
    return account_opening_date;
}

void client::set_card_expiration_date()
{
    card_expiration_date.year = account_opening_date.year +2;
    card_expiration_date.month = account_opening_date.month;
    card_expiration_date.day = account_opening_date.day;
}

date client::get_card_expiration_date()
{
    return card_expiration_date;
}

bool ip_dotcounter(const string &str)
{
    int dotcount = 0;
    for (char const &c : str)
    {
        if (c == '.') 
        {
            dotcount++;
        }
    }
    if(dotcount == 3)
    {
    return true;
    }
    return false;
}

vector<string> string_split(const string &option, char delimiter)
{
    //tabe baraye joda kardane commande dade shode ba delimiter dade shode va pushbacke har bakhsh tooye vector

    vector<string> result;
    stringstream stringinsstream(option);
    string item;

    while (getline(stringinsstream, item, delimiter))
    {
        result.push_back(item);
    }

    return result;
}

void client::set_ip(string given_ip)
{
    if(ip_dotcounter(given_ip))
    {
        vector<string> ip_parts = string_split(given_ip , '.');
        int correct = 0;
        for(auto i : ip_parts)
        {
            if(stoi(i) >= 0 && stoi(i) <= 255)
            {
                correct++;
            }
        }
        if (correct == 4)
        {
            authorised_ip.push_back(given_ip);
        }
        else
        {
            throw invalid_argument("Each part of IP is supposed to be between 0 and 255");
        } 
    }
    else
    {
        throw invalid_argument("IP is not valid");
    }
}

vector<string> client::get_ip()
{
    return authorised_ip;
}