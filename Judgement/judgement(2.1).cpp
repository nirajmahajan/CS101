#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

// Class of a person
class person
{
private:
	string name;
	int score;
	int target;
	bool dealer;
public:
	person(string nam){
		name = nam;
		score = 0;
		target = 0;
		dealer = false;
	}
	string get_name(){
		return name;
	}
	int get_score(){
		return score;
	}
	int get_target(){
		return target;
	}
	bool check_dealer(){
		return dealer;
	}

	void name_change(string nam){
		name = nam;
	}

	void add_score(int num){
		score += num;
	}
	void set_score(int num){
		score = num;
	}
	void set_target(int num){
		target = num;
	}
	void is_dealer(){
		dealer = true;
	}
	void not_dealer(){
		dealer = false;
	}
	void round_over_reset(){
		target = 0;
		dealer = false;
	}
};

int int_input(){
	string temp;
	bool violation;
	int multiplier = 1;
	int ans = 0;
	while(true){
		violation = false;
		cin >> temp;
		for(int i = temp.size()-1; i >= 0 ; i--){
			if(!isdigit(temp[i])){
				violation = true;
				break;
			}
			else{
				char c = temp[i];
				ans += multiplier * atoi(&c);
				multiplier *= 10;
			}
		}
		if(!violation){
			return ans;
		}
		else{
			cout << "Invalid number\nEnter again:  ";
		}
	}
}

// takes input as Y or N
bool input_yes(){
	char temp;
	while(true){
		cin >> temp;
		if(isalpha(temp)){
			temp = tolower(temp);
			if(temp == 'y'){
				return true;
			}
			else if(temp == 'n'){
				return false;
			}
			else{
				cout << "Invalid! Please type in Y or N\n";
			}
		}
		else{
			cout << "Invalid! Please type in Y or N\n";
		}
	}
}

void declare_results(vector<person> &player_list){
	map<int, vector<string> > list;
	for(int i = 0; i < player_list.size(); i++){
		list[player_list.at(i).get_score()].push_back(player_list.at(i).get_name());
	}
	cout << "\n\nScore Card is: \n";
	int rank = player_list.size();
	for(map<int, vector<string> >::iterator li = list.begin(); li != list.end(); li++){
		if(li->second.size() != 1){
			rank -= li->second.size() - 1;
		}
		cout << "Rank " << rank << ": ";
		while(li->second.size() > 1){
			cout << li->second.at(li->second.size() - 1) << "  &  ";
			li->second.pop_back();
		}
		cout << li->second.at(0) << "		(" << li->first << ")\n";
		rank--;
	}
	cout << "\n\n";
}

// returns a vector iterator to the person with the given string name
vector<person>::iterator find_person_with_name(string nam, vector<person> &player_list){
	vector<person>::iterator vi = player_list.begin();
	while(true){
		if((*vi).get_name() == nam || vi == player_list.end()){
			return vi;
		}
		else{
			vi++;
		}
	}
}

// takes command to edit the content
void take_command(vector<person> &player_list, int &num_peep){
	cout << "\n\n";
	while(true){
		cout << "Key:\n'S' to swap 2 players\n'D' to delete a player\n'R' to rename a player\n'A' to add a player\n";
		cout << "'Q' to quit taking commands\n'SC' to show the score card till now\n'ES' to edit score of a player\n";
		cout << "Your command:  ";
		string command;
		cin >> command;
		for(int i = 0; i < command.size(); i++){
			command[i] = tolower(command[i]);
		}
		if(command == "q"){
			cout << "\n\n";
			return;
		}
		else if(command == "s"){
			person temp("temp");
			vector<person>::iterator pos1, pos2;
			while(true){
				string temp;
				cout << "\n\nEnter the name of first person: ";
				cin >> temp;
				pos1 = find_person_with_name(temp, player_list);
				if(pos1 != player_list.end()){
					break;
				}
				else{
					// not found
					cout << "Invalid name\n";
				}
			}
			while(true){
				string temp;
				cout << "\n\nEnter the name of second person: ";
				cin >> temp;
				pos2 = find_person_with_name(temp, player_list);
				if(pos2 != player_list.end()){
					break;
				}
				else{
					// not found
					cout << "Invalid name\n";
				}
			}
			// swap people
			temp = *pos1;
			*pos1 = *pos2;
			*pos2 = temp;
			cout << "SUCCESS!\n";
		}
		else if(command == "d"){
			vector<person>::iterator pos1;
			while(true){
				string temp;
				cout << "\n\nName of person to delete: ";
				cin >> temp;
				pos1 = find_person_with_name(temp, player_list);
				if(pos1 != player_list.end()){
					break;
				}
				else{
					// not found
					cout << "Invalid name\n";
				}
			}
			player_list.erase(pos1);
			cout << "SUCCESS!\n";
		}
		else if(command == "a"){
			vector<person>::iterator pos1;
			string temp;
			cout << "\n\nName of new person: ";
			cin >> temp;
			person newc(temp);
			while(true){
				cout << "\n\nName of person before which new person is to be added: ";
				cin >> temp;
				pos1 = find_person_with_name(temp, player_list);
				if(pos1 != player_list.end()){
					break;
				}
				else{
					// not found
					cout << "Invalid name\n";
				}
			}
			player_list.insert(pos1, newc);
			cout << "SUCCESS!\n";
		}
		else if(command == "r"){
			vector<person>::iterator pos1;
			while(true){
				string temp;
				cout << "\n\nName of person to rename (type in existing name): ";
				cin >> temp;
				pos1 = find_person_with_name(temp, player_list);
				if(pos1 != player_list.end()){
					break;
				}
				else{
					// not found
					cout << "Invalid name\n";
				}
			}
			string temp;
			cout << "To what is the name to be changed to: ";
			cin >> temp;
			(*pos1).name_change(temp);
			cout << "SUCCESS!\n";
		}
		else if (command == "sc"){
			declare_results(player_list);
		}
		else if(command == "es"){
			vector<person>::iterator pos1;
			while(true){
				string temp;
				cout << "\n\nName of person to change score: ";
				cin >> temp;
				pos1 = find_person_with_name(temp, player_list);
				if(pos1 != player_list.end()){
					break;
				}
				else{
					// not found
					cout << "Invalid name\n";
				}
			}
			int new_scor;
			cout << "New Score:  ";
			new_scor = int_input();
			(*pos1).set_score(new_scor);
			cout << "SUCCESS!\n";
		}
		else{
			cout << "Invalid command\n";
		}
		cout << "\n\nDo you wish to give any command?   (Y/N)\n";
		if(!input_yes()){
			break;
		}
	}
}

//plays a single round
void play_round(vector<person> &player_list, int curr_hand, int dealer_pos){
	player_list.at(dealer_pos).is_dealer();
	int num_peep = player_list.size();
	vector<person>::iterator deal_i = find_person_with_name(player_list.at(dealer_pos).get_name(), player_list);
	
	// Take targets
	cout << "\n\nNow taking targets!\n\nCurrent hand is of "<< curr_hand << "\n";
	int temp_target, sum = 0;
	for(int i = 0; i < num_peep; i++){
		int player_index = (dealer_pos + 1 + i)%num_peep;
		while(true){
			// check if dealer or not
			if(i == num_peep-1){
				int restricted = curr_hand - sum;
				if(restricted < 0){
					cout << "Dealer!! No Restrictions on hands\n";	
				}
				else{
					cout << "Dealer!! " << restricted << " hands are restricted!\n";
				}
				cout << player_list.at(player_index).get_name() << ": ";
				temp_target = int_input();
				if(temp_target > curr_hand || temp_target == restricted){
					cout << "Invalid target!\n";
				}
				else{
					player_list.at(player_index).set_target(temp_target);
					sum += temp_target;
					break;
				}
			}
			else{ // not dealer
				cout << player_list.at(player_index).get_name() << ": ";
				temp_target = int_input();
				if(temp_target > curr_hand){
					cout << "Invalid target!\n";
				}
				else{
					player_list.at(player_index).set_target(temp_target);
					sum += temp_target;
					break;
				}
			}
		}
	}

	// add score
	cout << endl << "Please input the results:\n";
	for(int i = 0; i < num_peep; i++){
		int player_index = (dealer_pos + 1 + i)%num_peep;
		cout << "Did " << player_list.at(player_index).get_name() << " win?	  (Y/N)	:  ";
		if(input_yes()){
			player_list.at(player_index).add_score(10 + player_list.at(player_index).get_target());
		}
		else{/*Didnt win, dont add*/}
	}
	cout << "Round Over!\n\n\n";
	player_list.at(dealer_pos).round_over_reset();
}

int main(void){
	cout << "Welcome to judgement battle!\n\n\n";

	int num_peep;
	// take input of all people
	cout << "Number of people: ";
	num_peep = int_input();
	cout << "\n\nPlease enter names of all players in the sequence in which the round should progress\n";
	vector<person> player_list;
	for(int i = 0; i < num_peep; i++){
		string temp;
		cout << (i+1) << ": ";
		cin >> temp;
		player_list.push_back(person(temp));
	}



	while(true){
		int max_hand = 52/num_peep;
		int curr_hand;
		cout << "\n\nDo you wish to start the hand from 1?	(type in Y/N)\n";
		if(input_yes()){
			curr_hand = 1;

			while(curr_hand != max_hand+1){
				cout << "\n\nDo you wish to give any command?   (Y/N)\n";
				if(input_yes()){
					take_command(player_list, num_peep);
				}
				play_round(player_list, curr_hand, ((curr_hand-1)%player_list.size()));
				curr_hand++;
			}
			declare_results(player_list);
		}
		else{
			curr_hand = max_hand;

			while(curr_hand != 0){
				cout << "\n\nDo you wish to give any command?   (Y/N)\n";
				if(input_yes()){
					take_command(player_list, num_peep);
				}
				play_round(player_list, curr_hand, ((max_hand- curr_hand)%num_peep));
				curr_hand--;
			}
			declare_results(player_list);
		}

		// check if another round is to be played
		cout << "\n\nDo you wish to play another round?	  (Y/N)\n";
		if(!input_yes()){
			return 0;
		}
		else{/*play on*/}

		cout << "\n\nDo you wish to make any modifications to the name list?   (Y/N)\n";
		if(input_yes()){
			take_command(player_list, num_peep);
		}

		cout << "\n\nAlright, Lets start again\n\n\n";
		for(int i = 0; i < num_peep; i++){
			player_list.at(i).set_score(0);
		}
	}
}