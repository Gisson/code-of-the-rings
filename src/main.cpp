#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
string chooseMoves(const char* character);
 
int main()
{
    string magicPhrase;
    getline(cin, magicPhrase);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "+.>-." << endl;
    string moves = "+";
    int last_letter = 65;
    for(int j=0;j<magicPhrase.length();j++){
        for(int i=last_letter;;i++){
            if((char)i == magicPhrase[j]){
                moves +=".";
                cerr<<"Letter is "<<(char)i<<endl;
                last_letter=i;
                break;
            }
            else{
                if(i==91 ){
                    if(magicPhrase[j] == (char)32){
                        cerr<<"SPACE?"<<endl;
                        //Its most likely a space
                        moves += ".+";
                        last_letter=65;
                        break;
                    }
                    else{
                        moves+="+";
                        i=64;
                    }
                }
                else{
                    moves +="+";
                }
            }
        }
    }
    cout<< moves<<endl;
}
