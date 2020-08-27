#include <iostream>
//[1] namespace std because I hate typing std:: 
using namespace std; 
//[2]String library for getline
#include <string>
//[3]Included vector library 
#include <vector>
//[4]this is where I will save all the info 
struct names {
	string name;
	int score;
};
int main() {
	//[5]Creating vector that holds struct names
	vector<names> list;
	//[6]amount of people can be changed in the future if wanted. 
	int people = 3;
	cout << "Enter the names of three runners and their finishing times.\nI will tell you who came in first, second, and third.\n\n";
	for (int i = 0; i < people; i++) {
		names temp;
		cout << "Name of Runner " << i + 1 << ": ";
		//[7]getline here to get whole line ;)
		getline(cin, temp.name);
		//[8]prompt for finishing time
		
		cout << "Runner " << i + 1 << "'s finishing time: ";
		cin >> temp.score;
		//[9]cin ignore here because its an int 
		cin.ignore(1000, 10);
		//[10]if user inputs invalid num, then console will ask to input again and again and again!!! (until entered a valid num)
		while (temp.score < 0) {
			cout << "Enter positive values only for each runner's time.\n";
			cout << "Runner " << i + 1 << "'s finishing time: ";
			cin >> temp.score;
			//[10]cin ignore here because its an int 
			cin.ignore(1000, 10);
		}

		//[11]push back the object temp into the vector
		list.push_back(temp);
		cout << "\n";
	}
	//[12]manually sorting based on the list[i].score which is an int 
	for (int i = 0; i < list.size(); i++) {
		int miniPos = i;
		names temp;
		//[13]sorting loop starts
		for (int j = i + 1; j < list.size(); j++) if (list[j].score < list[miniPos].score) miniPos = j;
		temp = list[miniPos];
		list[miniPos] = list[i];
		list[i] = temp;
	}
	//[14]output, made a string array of the number indicators "st" "nd" "rd" "th" which will allow proper grammar 
	for (int i = 0; i < people; i++) {
		string thing[4] = { "st", "nd", "rd", "th" };
		cout << list[i].name << " came in " << i + 1 << (i > 3 ? thing[3] : thing[i]) << " place.\n";
	}
}