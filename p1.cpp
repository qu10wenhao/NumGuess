//p1.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	char choose; 										//choose:judge wheather the user want to play the game 
	int games = 0, win = 0;   								//games:number of the total games, win: number of the game that the player wins 
	
	cout << "Do you want to play this game(Y/N)？";
	cin >> choose;
	
	while('Y' == choose){ 
		games += 1;
		
		int i, j,randnum[3], guessnum[3];						//randnum[3]: 3 random numbers, guessnum[3]: 3 answers 
		int chance = 7, rnrp, rnwp;							//count: player's chance, rnrp: the number of A(right number right place) 
																//rnwp: the number of B(right number wrong place)
		srand(time(NULL));
	
		i = 0;
		while (i < 3) {									//create 3 different random numbers
			bool flag = true;
			randnum[i] = rand() * 10 / (RAND_MAX + 1);
			for (j=0; j<i; j++){
				if (randnum[i] == randnum[j]) {
					flag = false;
				}
			}
			if (flag) {
				i += 1;
			}
		}
	
		while (0 != chance) {								//player starts to guess, forcibly end when player has no chance 
			rnrp = 0, rnwp =0;
			cout << "You guess：" << endl;
			for (i=0; i<3; i++) {
				cin >> guessnum[i];
				}
			
			for (i=0; i<3; i++) {							//judge wheather the number and its location is right
				for (j=0; j<3; j++) {						
					if (guessnum[i] == randnum[j]) {
						i == j ? rnrp += 1 : rnwp += 1;
					}
				}
			}
			
			if (3 == rnrp) {							//player wins 
				cout << "Congratulation, you are right！" << endl;
				win += 1;
				break;
			}else {									//wrong guess, show the number of A and B
				cout << rnrp << 'A' << rnwp << 'B' << endl;
				chance -= 1;
			}
				
		}
		
		if (0 == chance) {								//player has no chance, show the right answer!
			cout << "What a pity, you didn't guess it, the answer is: ";
			for (i=0; i<3; i++) {
				cout << randnum[i];
				}
			cout << endl;
		}
		cout << "Again(Y/N)？";
		cin >> choose;
	}
	
	cout << "You have played" << games << "games, won" << win\
	 << "times, lost" << games - win << "times" << endl;					//game over!
	return 0; 
}
