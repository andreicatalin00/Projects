#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
using namespace std;

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

class BJPlayer{
public:
    vector <int> sum = {0};
    vector <vector <string>> hand = {{}};
    vector <int> noOfAces = {0};
    string nickname = "player1234";
public:
    int chips = 0;
    bool done = false;
public:
    void addCard(int no);
    void split(){
        this->sum.push_back(this->sum[0]/2);
        this->sum[0] /= 2;
        this->hand.push_back({});
        this->hand[1].push_back(this->hand[0][1]);
        this->hand[0].pop_back();
        this->noOfAces.push_back(this->noOfAces[0]/2);
        this->noOfAces[0] -= this->noOfAces[0]/2;
        cout << this->noOfAces[0];
        if(this->noOfAces[0] > 0){
            this->done = true;
        }

    }
    void operator++(int){
        this->addCard(0);
    }
    void printHand(){
        cout << "Your hand" << endl;
        cout << "---------" << endl;
        for(int j = 0; j < hand.size(); j++) {
            for (string i : this->hand[j]) {
                cout << i << " ";
            }
            cout << "~ " << this->sum[j] << endl << endl;
        }
    }

};
class BJDealer : public BJPlayer{
public:
    void printHand(){
        cout << "Dealer's hand" << endl;
        cout << "---------" << endl;
        for (string i : this->hand[0]) {
            cout << i << " ";
        }
        if(this->hand[0].size() == 1)
            cout << "? ";
        cout << "~ " << this->sum[0] << endl << endl;
    }
};
//void operator << (ofstream &console, const BJPlayer &p){
//}
void operator++(BJPlayer &p){
    p.addCard(1);
}
class Blackjack{
public:
    bool split = false;
    int bet = 0;
    BJDealer dealer;
    BJPlayer player;
    bool done = false;
public:
    Blackjack(){
        cout << "Welcome to the Blackjack table!\n";
        cout << "-------------------------------" << endl;
        cout << "-Blackjack pays 2 to 1\n";
        cout << "-Dealer hits 16 and stops at 17\n\n";
//        cout << "How many chips do you want to join with?\n";
//        cin >> player.chips;
        cout << "Place your bet:\n";
        cin >> this->bet;
        startGame(this->bet);

    }
    void startGame(int Bet){
        player++;
        dealer++;
        player++;
        dealer.printHand();
        player.printHand();
        ofstream fout("bjHandHistory.txt", ios::out | ios::app);
        string answer;
        if(player.sum[0] == 21)
        {
            cout << "You have BlackJack! You've won " << this->bet*2.5 <<"$\n";
            this->done = true;
            fout << "Bet: " << this->bet << " Win/Loss: " << this->bet*2.5 << " " << currentDateTime() << endl;
        }
        if(player.sum[0] > 21){
            this->done = true;
        }
        while(not done) {
            cout << "Do you want to stand/hit/double/split?" << endl;
            cin >> answer;
            if (answer == "hit") {
                player++;
                if (player.sum[0] >= 21) {
                    this->done = true;
                }
            } else if (answer == "split") {
                if (player.hand[0][1] == player.hand[0][0]) {
                    player.split();
                    this->split = true;
                    if(player.done){
                        this->done = true;
                    }
                    cout << this->done;
                    player++;
                    ++player;
                }else {
                    cout << "You can't split with different cards\n";
                }
            }
            else if (answer == "hit 1"){
                player++;
                if (player.sum[0] >= 21) {
                    this->done = true;
                }
            }
            else if(answer == "hit 2"){
                ++player;
                if (player.sum[1] >= 21) {
                    this->done = true;
                }

            }
            else if (answer == "stand") {
                this->done = true;
            }
            player.printHand();
        }
        if(this->done == true)
        {
            while(dealer.sum[0] <= 16)
                dealer++;
            dealer.printHand();
        }
        if(player.sum[0] < 21 and (dealer.sum[0] > 21 or dealer.sum[0] < player.sum[0]))
        {
            cout << "You've won " << this->bet*2 <<"$\n";
            fout << "Bet: " << this->bet << " Win/Loss: " << this->bet*2 << " " << currentDateTime() << endl;

        }
        if(player.sum[0] < 21 and dealer.sum[0] == player.sum[0] )
        {
            cout << "Push... " << this->bet <<"$\n";
            fout << "Bet: " << this->bet << " Win/Loss: " << this->bet << " " << currentDateTime() << endl;
        }
        if(player.sum[0] > 21 or dealer.sum[0] > player.sum[0])
        {
            cout << "You lost! Good luck next round\n";
            fout << "Bet: " << this->bet << " Win/Loss: -" << this->bet << " " << currentDateTime() << endl;
        }

    };



};
void BJPlayer::addCard(int no) {
    int card = rand() % 13 + 2;
    switch(card){
        case 11:
            this->noOfAces[no] ++;
            this->sum[no] += 11;
            this->hand[no].push_back("A");
            break;
        case 12:
            this->sum[no] += 10;
            this->hand[no].push_back("J");
            break;
        case 13:
            this->sum[no] += 10;
            this->hand[no].push_back("Q");
            break;
        case 14:
            this->sum[no] += 10;
            this->hand[no].push_back("K");
            break;
        case 10:
            this->sum[no] += 10;
            this->hand[no].push_back("T");
            break;
        default:
            this->sum[no] += card;
            this->hand[no].push_back(to_string(card));

    }
    if(sum[no] > 21){
        if(this->noOfAces[no] > 0)
        {
            sum[no] -= 10;
            this->noOfAces[no] --;
        }
        else{
            done = true;
        }
    }
}
int main() {
    srand(time(NULL));
    Blackjack casino;
    vector <vector <string>> hand = {{"sda","dsada"},{"dsasda"},{}};
    cout << currentDateTime() << endl;

}
