#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int function(vector<pair<int,int> > input, vector<int> s)
{
	sort(input.begin(), input.end());
	int initialvariable =0;
	int previousStart = input[0].first;

	for (int i = 1; i < input.size(); i++) {
		if (s[input[i].second] >= previousStart) {
			previousStart = input[i].first;
			initialvariable++;
		}
	}
	return initialvariable;
}

int main()
{
	string inputLine;
	ifstream myFile("./data2.txt");
	vector<pair<int,int> > array1 = {};
	vector<int> array2 = {};
	int counter =0;
	while(getline(myFile, inputLine)){

		stringstream stringParser( inputLine);
		getline(stringParser, inputLine, ' ');
		int start, duration;
		stringParser  >> start >> duration; 
		array1.push_back(make_pair(duration+start, counter++));
		array2.push_back(start);
	}
	myFile.close();
	cout << function(array1, array2) << endl;

	return 0;
}
	
