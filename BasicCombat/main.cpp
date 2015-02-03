//
//  main.cpp
//  BasicCombat
//
//  Created by Rudy Summers on 1/30/15.
//  Copyright (c) 2015 Rudyard Summers. All rights reserved.
//

#include <iostream>
using namespace std;

//All the variables
string name;
string playerclass;
string selectedMission;


//All functions
string introductions(); //Player picks a name
string classSelection(); //Player picks a class
bool readMission(); //The function that checks to see if the player has picked a mission that is actually coded
string missionSelect(); //Player selects a mission
void goblinMission(); //The goblin mission!
void clearScreen(); //makes a bunch of endl's in order to clear the screen.
void branchOff(); //The sublevel of the Goblin Mission


//function that takes player name
void clearScreen(){
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}

string introductions(){
    cout<<"Adventurer, what is your name?"<<endl;
    cin>>name;
    cout<<"Ah yes "<<name<<". I've heard of you."<<endl;
    return name;
}

string classSelection(){
    bool selected = false;
    string tentativechoice;
    
    cout<<"So, "<<name<<", everyone in the land has heard of your potency. What is your profession?"<<endl;
    cout<<"1 - Mage | 2 - Archer | 3 - Warrior | 4 - Rogue"<<endl;
    while (selected == false) {
        cin >> tentativechoice;
        if (tentativechoice == "1"){
            playerclass = "Mage";
            selected = true;
        }else if (tentativechoice == "2"){
            playerclass = "Archer";
            selected = true;
        }else if (tentativechoice == "3"){
            playerclass = "Warrior";
            selected = true;
        }else if (tentativechoice == "4"){
            playerclass = "Rogue";
            selected = true;
        }else {
            cout <<"That isn't a valid answer. Try again"<<endl;
        }
    }
    
    return playerclass;
}


string missionSelect(){
    bool selected = false;
    string tentativechoice;
    
    cout<<"What job do you wish to take?"<<endl;
    cout<<"1 - Goblin Den | 2 - Orc Fortress | 3 - Dragon Lair"<<endl;
    while (selected ==false){
        cin >>tentativechoice;
        if (tentativechoice == "1"){
            selectedMission = "Goblin";
            selected = true;
        }else if (tentativechoice == "2"){
            selectedMission = "Orc";
            selected = true;
        }else if (tentativechoice == "3"){
            selectedMission = "Dragon";
            selected = true;
       }else {
            cout <<"That isn't a valid answer. Try again"<<endl;
        }
        
    }
    readMission();
    return selectedMission;
}


void goblinMission(){
    clearScreen();
    string courseofAction;
    bool selected = false;
    
    cout<<"This mission is given to you by the mayor of a local town, who has been dealing with issues related to a goblin infestation"<<endl;
    cout<<"You scout out the local area and hunt down one primary lead: an abandoned mine, a few miles out of town."<<endl;
    if(playerclass == "Rogue"){
        cout<<"You approach you mine stealthily."<<endl;
        bool hiding = true;
    }
    cout<<"You slowly enter the mine. You notice a primary entranceway, as well as a side passage."<<endl;
    cout<<"1 - Go Down The Main Path | 2 - Take The Side Path"<<endl;
    //chose your path
    while (selected == false){
        string tentativeChoice;
        cin>>tentativeChoice;
        if(tentativeChoice == "1"){
            courseofAction = "Main";
            selected = true;
        }else if (tentativeChoice == "2"){
            courseofAction = "Side";
            selected = true;
        }else{
            cout<<"That isn't a valid answer. Try again"<<endl;
        }
    }
    if(courseofAction == "Side"){
        branchOff();
    }
    clearScreen();
    cout<<"You continue along the main path for quite some time, the mine twisting to the left and the right with little warning, clearly having taken the path of least resistance."<<endl;
    cout<<"Finally, as you peek around the corner, you notice two goblins standing guard about five feet away. What do you do?"<<endl;
    cout<<"1 - Head On Charge | ";
    if(playerclass == "Rogue"){
        cout<<"2 - Distract Them And Sneak By"<<endl;
    }
}

bool readMission(){
    if(selectedMission == "Goblin"){
        goblinMission();
        return true;
    }else{
        cout<<"Unfortunately, that jobs aren't available yet. Please selected another"<<endl;
        selectedMission = "";
        missionSelect();
        return false;
    }
}
void branchOff(){
    
}



int main(int argc, const char * argv[]) {
    
    introductions();
    classSelection();
    clearScreen();
    cout << "Hmm, you're a "<<playerclass<<"? Quite interesting."<<endl;
    missionSelect();
    return 0;
}



