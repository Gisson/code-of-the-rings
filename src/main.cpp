#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdlib>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
string chooseMoves(const char* character);
 
class rune{
  private:
    int _letter=0;
    bool _triggered=false;
    string _possible_letters=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  public:
    rune(){ _letter=0; _triggered=false;}
    char get_letter(){return _possible_letters[_letter];}
    bool is_triggered(){return _triggered;}
    void next_letter(){ _letter=(_letter+1) % _possible_letters.length();}
    void previous_letter(){ _letter=(_letter==0)?_possible_letters.length()-1:_letter-1;}
};

class bilbo{
  private:
    int _current_rune=0;
    int _max_runes;
  public:
    bilbo(int max_runes){ _current_rune=0; _max_runes = max_runes; }
    int get_current_rune(){return _current_rune;}
    void go_right(){ _current_rune=(_current_rune+1) % _max_runes;}
    void go_left(){ _current_rune=(_current_rune==0)?_max_runes:_current_rune-1;}
    int get_max_runes(){return _max_runes;}
    string best_path(int target_position){
        if(target_position==_current_rune){
            return "";
        }
        string moves="";
        int old_rune=_current_rune;
        if(abs(target_position-old_rune)>15){
            for(int i=0;;i++){
                if(target_position==_current_rune){
                    break;
                }
                if(old_rune>15){
                    moves+=">";
                    go_right();
                }
                else{
                    moves+="<";
                    go_left();
                    //go left d times
                }
            }
        }else{
            cerr<<"gonna walk "<<abs(target_position-old_rune)<<endl;
            for(int i=0;;i++){
                                if(target_position==_current_rune){
                    break;
                }
                if(old_rune-target_position>0){
                    moves+="<";
                    go_left();
                    //go right d times d=abs(target-position)
                }
                else{
                    moves+=">";
                    go_right();
                    //go left d times
                }
            }
        }
        return moves;
    }
};

int best_rune(rune** runes, bilbo* b, const char target_letter){
    vector<int> possible_runes;
    for(int i=0;i<b->get_max_runes();i++){//search runes for one with the letter
      if(runes[i]->get_letter()==target_letter){
          cerr<<"Found a "<<target_letter<<" in "<<i<<endl;
        possible_runes.push_back(i);
        //cerr<<"Possible rune with value "<<runes[possible_runes[possible_runes.size()-1]]->get_letter()<<endl;
      }
    }
    if(possible_runes.size()>1){
       // cerr<<"Biger than 1"<<endl;
        int distance=numeric_limits<int>::max();
        for(int i=0;i<possible_runes.size();i++){
            if(abs(possible_runes[i]-b->get_current_rune())<distance){
                distance=abs(possible_runes[i]-b->get_current_rune());
            }
        }
        return possible_runes[0];
    }else if(possible_runes.size()==1){
       // cerr<<"Size 1"<<endl;
        return possible_runes[0];
    }else{
      //  cerr<<"empty"<<endl;
        return -1;
    }
}

int main()
{
    string magicPhrase;
    getline(cin, magicPhrase);
    rune* runes[30];
    for(int i=0;i<30;i++)
      runes[i]=new rune();
    bilbo b = bilbo(30);
    string moves="";
    for(int j=0;j<magicPhrase.length();j++){
          int rune_index=best_rune(runes,&b,magicPhrase[j]);
          //cerr<<"Best rune is "<<rune_index<<endl;
          if(rune_index==-1){
            while(1){
                if(runes[b.get_current_rune()]->get_letter()==magicPhrase[j]){
                    moves+=".";
                    break;
                }
                else{
                    runes[b.get_current_rune()]->next_letter();
                    moves+="+";
                }
            }
        }else{
          string predicted_moves=b.best_path(rune_index)+".";
          if(runes[b.get_current_rune()]->get_letter()==magicPhrase[j])
            moves+=predicted_moves;
          else{
            while(1){
                if(runes[b.get_current_rune()]->get_letter()==magicPhrase[j]){
                    moves+=".";
                    break;
                }
                else{
                    runes[b.get_current_rune()]->next_letter();
                    moves+="+";
                }
            }
          }
        }
          //decide best path
          //take path
    }
    cout<<moves<<endl;
}
