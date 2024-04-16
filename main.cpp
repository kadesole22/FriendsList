#include <iostream>
#include <fstream>
#include "facebook.h"
using namespace std;

struct Profile{
    string name;
    string state;
};

// Overload the << operator for profile
ostream& operator << (ostream& out, const Profile& data){
    out << data.name << endl;
    out << data.state << endl;
    return out;
}

int main()

{
     //initializes a Queue named facebook that takes in strings
    Facebook<std::string> facebook_string;
    //Initializes a Queue named Facebook that takes in a profile struct
    Facebook<Profile> facebook_profile;

    //Parse the text file
    ifstream infile;
    infile.open("presidentsWstates.txt");
    string nextline;
    getline(infile,nextline);
    int c = 1;
    while(infile){

            string state = nextline.substr(nextline.size()-2, nextline.size());
            string name = nextline.substr(0,nextline.size()-2);

            //Adds the name as a friend to our facebook class using the function from facebookheader
            facebook_string.addFriend(name);
            //Initializes profile , stores name and state , adds profile as a friend
            Profile profileStruct;
            profileStruct.name = name;
            profileStruct.state = state;
            facebook_profile.addFriend(profileStruct);
            getline(infile,nextline);

    }

    infile.close();


    //Calls the firstFriend function to print first friend
    std :: cout << "\nFirst Friend: " << facebook_string.firstFriend();

    //calls removeFriend function to delete the first friend
    facebook_string.removeFriend();

    //calls the printFriendsF function to print the friends forward
    facebook_string.printFriendsF();

    //calls printFriendsR and prints friends but in a reversed order
    facebook_string.printFriendsR();

    //Calls resetFriend function to reset your friends list (making it empty)
    facebook_string.resetFriend();

    //uses checklist to see if the queue is empty. Depending on true or false will return different cout statements.
    if (facebook_string.checklist()){
        cout << "Friends list is empty!" << endl;
    } else {
        cout << "You have friends!" << endl;
        }

    std:: cout << "\nFirst Friend!\n" << facebook_profile.firstFriend() << endl;

    facebook_profile.removeFriend();

    facebook_profile.printFriendsF();

    facebook_profile.printFriendsR();

    facebook_profile.resetFriend();

    if (facebook_profile.checklist()){
         cout << "Friends list is empty!" << endl;
    } else {
        cout << "You have friends!" << endl;
        }

    return 0;

}
