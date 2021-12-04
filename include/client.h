#include <iostream>
#include <vector>
#ifndef CLIENT_H
#define CLIENT_H

using namespace std;

struct date
{
    int year;
    int month;
    int day;
};


class client
{
    public:
        void set_name(const string & given_name);
        string get_name();
        void set_ip(string given_ip);
        vector<string> get_ip();
        void set_card_number();
        int get_card_number();
        void set_balance(double given_balance);
        double get_balance();
        void set_account_opening_date();
        date get_account_opening_date();
        void set_card_expiration_date();
        date get_card_expiration_date();


    private:
        string name;
        vector<string> authorised_ip;
        int card_number;
        date account_opening_date;
        date card_expiration_date;
        double balance = 0;
        //... recent transactions[10];
};

#endif
