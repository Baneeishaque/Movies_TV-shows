/* 
 * Movies/TV shows Website
 * Developer :
 * Description : 
 */

#include <iostream>
#include <string>

using namespace std;

class Person {
    // Access specifier

protected:

    // Data Members
    string name, email_ID, birth_date, address, phone_number;
    int age;

public:

    // Member Functions()

    set_data(string given_name, int given_age, string given_email_ID) {
        name = given_name;
        age = given_age;
        email_ID = given_email_ID;
    }

    int get_age() {
        return age;
    }
};

class Movie {
    // Access specifier
protected:

    // Data Members
    string title, category, cast, release_date;
    int running_time_minutes;
    float rating;

public:

    // Member Functions()

    set_data(string given_title, string given_category, string given_cast, string given_release_date, float given_rating, int given_running_time_minutes) {
        title = given_title;
        category = given_category;
        cast = given_cast;
        release_date = given_release_date;
        rating = given_rating;
        running_time_minutes = given_running_time_minutes;
    }

    string get_title() {
        return title;
    }

    string get_category() {
        return category;
    }

};

class TV_Show {
    // Access specifier
protected:

    // Data Members
    string title, category, cast, release_date;
    int episode_number, running_time_minutes;
    float rating;


public:

    // Member Functions()

    set_data(string given_title, string given_category, string given_cast, string given_release_date, float given_rating, int given_episode_number, int given_running_time_minutes) {

        title = given_title;
        category = given_category;
        cast = given_cast;
        release_date = given_release_date;
        rating = given_rating;
        episode_number = given_episode_number;
        running_time_minutes = given_running_time_minutes;
    }

    string get_title() {
        return title;
    }

    string get_category() {
        return category;
    }

};

int main(int argc, char** argv) {

    Movie movies[5];
    TV_Show tv_shows[5];

    movies[0].set_data("The Blind Side", "Adult", "Sandra Bullock", "November 19, 2009", 4.5, 126);
    movies[1].set_data("The Reader", "Adult", "Bernhard Schlink", "November 20, 2010", 4, 120);
    movies[2].set_data("Der Vorleser", "Adult", "Kathleen DiGrado", "November 21, 2011", 3.5, 115);
    movies[3].set_data("Vintage", "Neutral", "Sean Kernan", "November 22, 2012", 3, 110);
    movies[4].set_data("From Here to Eternity", "Neutral", "Ruth Franklin", "November 23, 2013", 2.5, 105);

    tv_shows[0].set_data("The Killers", "Adult", "Fred Zinnemann", "November 22, 2014", 4.5, 1, 55);
    tv_shows[1].set_data("Brute Force", "Adult", "Burt Lancaster,", "November 22, 2015", 4, 2, 60);
    tv_shows[2].set_data("Desert Fury", "Neutral", "Montgomery Clift", "November 23, 2016", 3.5, 3, 65);
    tv_shows[3].set_data("I Walk Alone", "Neutral", "Frank Sinatra", "November 23, 2017", 3, 4, 70);
    tv_shows[4].set_data("All My Sons", "Neutral", "Deborah Kerr", "November 23, 2000", 2.5, 5, 75);

    string in_name, in_email_ID;
    int in_age;

    cout << "Enter your name : ";
    cin >> in_name;

    bool valid_age = false;
    do {
        cout << "Enter your age : ";
        cin >> in_age;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid entry!" << endl;
        } else {
            // We got some valid input! Set the flag so we can leave the loop!
            valid_age = true;
        }

    } while (valid_age == false);

    bool valid_mail = false;
    do {
        cout << "Enter your email ID : ";
        cin >> in_email_ID;

        size_t at = in_email_ID.find('@');
        if (at == string::npos) {
            cout << "Invalid entry!" << endl;
        } else {
            size_t dot = in_email_ID.find('.', at + 1);
            if (dot == string::npos) {
                cout << "Invalid entry!" << endl;
            } else {
                // We got some valid input! Set the flag so we can leave the loop!
                valid_mail = true;
            }
        }
    } while (valid_mail == false);

    // Declare an object of class person
    Person person;
    person.set_data(in_name, in_age, in_email_ID);

    bool is_adult;
    if (person.get_age() >= 18) {
        is_adult = true;
    } else {
        is_adult = false;
    }

    cout << "\nMovies" << endl;
    for (int i = 0; i < 5; i++) {

        if (is_adult) {
            cout << movies[i].get_title() << endl;
        } else {
            if (movies[i].get_category() == "Adult") {
                continue;
            }
            cout << movies[i].get_title() << endl;
        }
    }

    cout << "\nTV Shows" << endl;
    for (int i = 0; i < 5; i++) {
        if (is_adult) {
            cout << tv_shows[i].get_title() << endl;
        } else {
            if (tv_shows[i].get_category() == "Adult") {
                continue;
            }
            cout << tv_shows[i].get_title() << endl;
        }
    }

    return 0;
}

