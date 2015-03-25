//p1.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
	char choose; 												//choose:玩家是否要玩游戏 
	int games = 0, win = 0;   									//games:总的游戏场数, win: 赢的场数 
	
	cout << "需要玩游戏吗（Y/N）？";
	cin >> choose;
	
	if ('Y' == choose) do{ 
		games += 1;
		
		int i, j,randnum[3], guessnum[3];						//randnum[3]: 3个随机数, guessnum[3]: 3个答案 
		int chance = 7, rnrp, rnwp;								//count: 玩家机会数, rnrp: 数字正确位置错误的个数 
																//rnwp: 数字正确位置错误的个数 
		srand(time(NULL));
	
		i = 0;
		while (i < 3) {											//生成3个不同随机数 
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
	
		while (0 != chance) {									//玩家开始猜测，机会为零时强制结束 
			rnrp = 0, rnwp =0;
			cout << "请输入你猜测的数字：" << endl;
			for (i=0; i<3; i++) {
				cin >> guessnum[i];
				}
			
			for (i=0; i<3; i++) {								//判断数字正确位置正确和数字正确
				for (j=0; j<3; j++) {							//位置错误的个数 
					if (guessnum[i] == randnum[j]) {
						i == j ? rnrp += 1 : rnwp += 1;
					}
				}
			}
			
			if (3 == rnrp) {									//玩家才出数字，提前结束游戏，胜场数+1 
				cout << "恭喜，你猜对了！" << endl;
				win += 1;
				break;
			}else {												//玩家未猜出数字，给予相应提示并减少一次机会 
				cout << rnrp << 'A' << rnwp << 'B' << endl;
				chance -= 1;
			}
				
		}
		
		if (0 == chance) {										//玩家因机会用完而强制结束游戏，公布正确答案 
			cout << "很遗憾，你没有在规定次数内才对。答案是 ";
			for (i=0; i<3; i++) {
				cout << randnum[i];
				}
			cout << endl;
		}
		cout << "需要玩游戏吗（Y/N）？";
		cin >> choose;
	}while ('Y' == choose);
	
	cout << "你一共玩了" << games << "局，赢了" << win\
	 << "局，输了" << games - win << "局" << endl;				//游戏结束，输出统计结果 
	return 0; 
}
