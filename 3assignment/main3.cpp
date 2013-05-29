/*
** Max Marchuk
** CS 202 ** Karla Fant ** Program #3
**This is the file that has the user input and output and all of that...
*/

#include "hfile3.h"

void addNew(blog &blog1);
int main(){
 
    // Testing the operator overloading
   /////////////////////////////////// 
    blog blog1; 
    link newLink;
    char temp1[10];
    strcpy(temp1, "Object 1");
    newLink.setAuthor(temp1);
    newLink.setTitle(temp1);
    newLink.setKeyword(temp1);   
    newLink.setURL(temp1);
    newLink.setRating(9);
    
    link newLink2;
    char temp2[10];
    strcpy(temp2, "object 2");
    newLink2.setAuthor(temp2);
    newLink2.setTitle(temp2);
    newLink2.setKeyword(temp2);   
    newLink2.setURL(temp2);
    newLink2.setRating(1);


    cout << "\n\nFirst: \n" << newLink;
    cout << "\n\nSecond:\n" << newLink2; 
    if(newLink == newLink2)
        cout << "\n\nBoth objects are different!";
    newLink = newLink2;

    if(newLink != newLink2)
        cout << "\n\nBoth objects are the same!";
    
    cout << "\n\nFirst after: \n" << newLink;
    cout << "\n\nSecond after:\n" << newLink2;


   //end testing 
  ///////////////////////////////////////////////////
    addNew(blog1);
}


//the add function that collects the data and throws it into a post pointer 
//and then into the add functoin in the data structure
void addNew(blog & blog1){
    
    int menuChoice= 0;
    bool valid = false; 
    cout << "What kind of post would you like to create? \n" 
         << "1) Text Response \n"
         << "2) Link Response \n"
         << "3) Cancel\n"
         << "Choice: ";
    cin >> menuChoice;
    cin.ignore();

    //make a temporary post pointer for placing all of the data into
    post * tempPost = new post;

    switch(menuChoice){
        //if the menu choice is 1
        case 1: 
            {
            //gather text info        
            text tempText;
            cin >> tempText;
            tempPost = &tempText; 
            blog1.insertNew(tempPost);
            valid = true;
            break;
            }
            //if the meny choice is 2
        case 2:
            {
            //gather link info
            link tempLink;
            cin >> tempLink;
            tempPost = &tempLink; 
            blog1.insertNew(tempPost);
            valid = true;
            break;
            }
            //if the menu choice is 3
        case 3:
            valid = true;
            return;
            //if the menu choice is none of the above
        default: 
            cout << "\nInvalid Menu choice!";
            valid = false;
        }

    //display all of the posts
   blog1.displayAll(); 

}



