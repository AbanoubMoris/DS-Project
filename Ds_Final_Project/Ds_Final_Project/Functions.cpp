#include"Functions.h"
void displayMaps() {
	cout << "\n\t\t\t\t  " << "Welcome" << "\n\n\t\t";
	cout << "\t  Here's All map are recently Saved\n\t\t" << endl;
	cout << "\n\t\t\t\t  " << "Welcome" << "\n\n\t\t";
	cout << "\t  Here's All map are recently Saved\n\t\t" << endl;
	ifstream display("Mapsname.txt", ios::in);
	string choices;
	while (getline(display, choices)) {
		cout << "\n\t\t ->> " << choices << endl;
	}
	cout << endl;
}
//****************************************************************************
void addGraph() {
	displayMaps();
	Graph Map;
	Map.addMap();
}
//*****************************************************************************************************
vector<string> displayGraph(string input) {
		Graph recall;
		string x;
		recall.mp.clear();
		ifstream mapDetails(input + ".txt");
		string seperate;

		vector<string> L;//Put All Line before split in vector of string
		L.clear();
		while (getline(mapDetails, seperate)) {
			string str[3];
			string reference = "#";
			size_t pos = 0;
			string token;
			int counter = 0;
		    
			L.push_back(seperate); //Put All Line before split in vector of string

			seperate.erase(seperate.begin()); //erase first #
			while ((pos = seperate.find(reference)) != -1) {
				token = seperate.substr(0, pos);
				str[counter] = token;
				seperate.erase(0, pos + reference.length());
				counter++;

			}
			str[counter] = seperate;
			int dis = stoi(str[2]);
			recall.putINmap(str[0], str[1], dis);
		}
		recall.outMap();
		return L;
}
//*********************************************************************************
void deleteMap() {
	displayMaps();
	string delname;
	unordered_set<string> del;
	unordered_set<string>::iterator it;
	cout << "Entre Map's Name" << endl;
	getline(cin, delname);
	fstream mapsNames("Mapsname.txt", ios::in | ios::out | ios::app);
	string line;
	while (mapsNames >> line)
	{
		del.insert(line);
	}
	do
	{

		if (del.find(delname) != del.end()) {
			del.erase(delname);
			it = del.begin();
			ofstream ofs;
			ofs.open("Mapsname.txt", std::ofstream::out | std::ofstream::trunc);
			ofstream append("Mapsname.txt", ios::out | ios::app);
			for (auto it = del.begin(); it != del.end(); it++) {
				ofs << *it << endl;
			}
			delname = delname + ".txt";
			char delfile[1024];
			strcpy_s(delfile, delname.c_str());
			remove(delfile);
			break;


		}
		else {
			cout << "there is Map that have such Name,please check Map name and entre again" << endl;
		}
		cout << "Entre Map Name" << endl;
		getline(cin, delname);

	} while (true);
	mapsNames.close();

}
//*********************************************************************************
void EditGraph() {
	cout << "\t\t What do you want to Edit ?\n ";
	cout << "\t\t\t 1-> Add new City \n";
	cout << "\t\t\t 2-> Update Map \n";
	cout << "\t\t\t 3-> Delete Node Or Edge \n\n";
	cout << "Enter Your choice : ";
	int choose;
	cin >> choose;
	if (choose == 1) {
		//AddNewCity();
	}
	else if (choose == 2) {
		//UpdateMap();
	}
	else if (choose == 3) {
		system("CLS");
		cout << "\t 1-> Delete Node \n";
		cout << "\t 2-> Delete Edge \n";
		cout << "Enter Your choice : ";
		cin >> choose;
		if (choose == 1) {
			displayMaps();
			cout << "\n\t\t  please write Name of the Map that you want to display\n\t\t" << endl;
			cout << "\t\t";
			string input;
			cin >> input;
			vector<string>s = displayGraph(input);

			string NodeName;
			cout << "\tEnter Node Name : ";
			cin.ignore(1000, '\n');
			getline(cin,NodeName);
			DeleteNode(NodeName,s,input);
		}
		else if (choose == 2) {
			displayMaps();
			cout << "\n\t\t  please write Name of the Map that you want to display\n\t\t" << endl;
			cout << "\t\t";
			string input;
			cin >> input;
			vector<string>x = displayGraph(input);

			string City1,City2;
			cout << "\tEnter City1 Name : ";
			cin.ignore(1000, '\n');
			getline(cin, City1);
			cout << "\tEnter City2 Name : ";
			getline(cin, City2);
			DeleteEdge(City1, City2, x, input);
		}
	}
}
void DeleteNode(string NodeName,vector<string> s, string fileName) {
	string del = '#' + NodeName + '#';
	int i = 0;
	while ( i < s.size()) {
		if (s[i].find(del) != -1) {
			s.erase(s.begin() + i);
			i = 0;
		}
		else i++;
	}
	fstream f;
	f.open(fileName + ".txt", ios::end);
	f << "Deleted";
	f.close();
	f.open(fileName + ".txt",ios::end);
	for (int i = 0; i < s.size(); i++) {
		f << s[i] << endl;
	}
	f.close();
}

void DeleteEdge(string City1, string City2, vector<string> s, string fileName) {
	string del1 = '#' + City1 + '#' + City2 + '#' ;
	string del2 = '#' + City2 + '#' + City1 + '#';
	int i = 0;
	while (i < s.size()) {
		if (s[i].find(del1) != -1 || s[i].find(del2) != -1) {
			s.erase(s.begin() + i);
			i = 0;
		}
		else i++;
	}
	fstream f;
	f.open(fileName + ".txt", ios::end);
	f << "Deleted";
	f.close();
	f.open(fileName + ".txt", ios::end);
	for (int i = 0; i < s.size(); i++) {
		f << s[i] << endl;
	}
	f.close();
}