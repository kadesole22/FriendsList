#include <iostream>;
#include "Queue.h"


template <typename T>
class Facebook{


private:
    int numofFriends;
    T user;
    Queue<T>Friendslist;
public:
    //Calls the enqueue function from Queue class
    void addFriend(const T& data){
    Friendslist.enqueue(data);
    }

    //Calls the dequeue function from the Queue class
    void removeFriend(){
    Friendslist.dequeue();}

    //Calls the print function from the Queue class
    void printFriendsF(){
    Friendslist.print();}

    //Calls the reversePrint function from the Queue class
    void printFriendsR(){
    Friendslist.reversePrint();}

    //Calls the peek function from the Queue class
    T firstFriend(){
    return Friendslist.peek();}

    //Calls the makeEmpty function from the Queue class
    void resetFriend(){
    Friendslist.makeEmpty();}

    //Calls the isEmpty function from the Queue class
    bool checklist(){
    return Friendslist.isEmpty();}
};



