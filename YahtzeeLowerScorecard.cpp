#include <iostream>
using namespace std;
#include <algorithm>
int main()
{
	int playerScore = 0;
	string gameResult;
	int playAgainAnswer;

	// Roll 5 dice at random
	srand(time(0));
	int dice[5]{};
	while (true) {
		for (int i = 0; i < 5; i++)
			dice[i] = rand() % 6 + 1;

		// Sort the dice lowest to highest
		sort(dice, dice + 5);

		// Display the dice on the console
		for (int i = 0; i < 5; i++)
			cout << "|" << dice[i];
		cout << "|" << endl;

		// Store the dice in integer variables (solely to facilitate the lab)
		int d1 = dice[0],
			d2 = dice[1],
			d3 = dice[2],
			d4 = dice[3],
			d5 = dice[4];

		//TODO: Complete the decisions for the lab:
		//IF d1 == d2 AND d2 == d3 AND d3 == d4 AND d4 == d5 THEN Yahtzee
		if (d1 == d2 && d2 == d3 && d3 == d4 && d4 == d5) {
			gameResult = "Yahtzee";
			playerScore += 50;
		}
		//IF d1 == d2 – 1 AND d2 == d3 – 1 AND d3 == d4 – 1 AND d4 == d5 – 1 THEN Straight
		else if (d1 == d2 - 1 && d2 == d3 - 1 && d3 == d4 - 1 && d4 == d5 - 1) {
			gameResult = "Large Straight";
			playerScore += 40;
		}
		// Small Straight
		// #abcd, a#bcd, ab#cd, abc#d, abcd# 
		else if (
			d2 == d3 - 1 && d3 == d4 - 1 && d4 == d5 - 1
			|| d1 == d3 - 1 && d3 == d4 - 1 && d4 == d5 - 1
			|| d1 == d2 - 1 && d2 == d4 - 1 && d4 == d5 - 1
			|| d1 == d2 - 1 && d2 == d3 - 1 && d3 == d5 - 1
			|| d1 == d2 - 1 && d2 == d3 - 1 && d3 == d4 - 1) {
			gameResult = "Small Straight";
			playerScore += 30;
		}
		// Full House
		//aaabb or aabbb
		else if (d1 == d2 && d2 == d3 && d4 != d1 && d4 == d5 || d3 == d4 && d4 == d5 && d1 == d2 && d1 != d3) {
			gameResult = "Full House";
			playerScore += 25;
		}
		// 4 of a kind (Sum of all dice) aaaa# or #aaaa. 
		else if (d1 == d2 && d2 == d3 && d3 == d4 || d2 == d3 && d3 == d4 && d4 == d5) {
			gameResult = "4 of the kind";
			playerScore += d1 + d2 + d3 + d4 + d5;
		}
		// 3 of a kind (Sum of all dice) aaa##, #aaa#, or ##aaa
		else if (d1 == d2 && d2 == d3 || d2 == d3 && d3 == d4 || d3 == d4 && d4 == d5) {
			gameResult = "3 of the kind";
			playerScore += d1 + d2 + d3 + d4 + d5;
		}
		//Chance (Sum of all dice)
		else {
			gameResult = "Chance";
			playerScore += d1 + d2 + d3 + d4 + d5;
		}

		cout << gameResult << endl;
		cout << playerScore << endl;
		cout << "Do you want to play again? ( 1 = Yes, 2 = No): ";
		cin >> playAgainAnswer;
		if (playAgainAnswer == 2) {
			break;
		}
	}
}

