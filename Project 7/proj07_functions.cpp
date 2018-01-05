#include<string>
using std::string; using std::stod;
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<fstream>
using std::ifstream;
#include<utility>
using std::pair;
#include<sstream>
using std::ostringstream;
#include<cmath>
#include <iostream> 
using std::ostream;
using std::endl;
#include<iterator>
using std::ostream_iterator;
#include <algorithm>
using std::transform;
#include <iomanip>

/*
Project 07
Project focuses on the use of maps

Ana Lopez 
Section 11
10/30/17
*/

/*
function takes in a string and seperates it by the delim seperating character, returns as a vector
*/

vector<string> split(const string &s, char delim) {
    vector<string> result = {};
	string s_copy = s;
	while (s_copy.size() != 0) {
		string term = s_copy.substr(0, s_copy.find_first_of(delim));
		result.push_back(term);
		s_copy.erase(0, (term.size()+1));
	}
	return result;
}

/*
reads the every line from an already opened file and passes in an empty map and fills map m throughout the function. 
*/
void read_data(map<vector<double>, string> &m, unsigned int feature_count, ifstream &inf) {
    vector<string> s_vect;
    vector<double> doub_vect;
    string line;
    while(getline(inf, line)) {
        //map<vector<double>, string> &m;
        s_vect = split(line, ','); //calls split, delim is a comma
        for (int i = 0; i < (int)s_vect.size()-1; i++){
            doub_vect.push_back(stod(s_vect[i])); //stod = string to double
            //when the contents of string vector are put into double vector it              is now a double instead of string contents
        }
        m[doub_vect] = s_vect[s_vect.size()-1]; //doesnt include the last element of string vector because it is a string and not an int
        doub_vect.clear();
        s_vect.clear();
    }
}
/*
iterates through the elements of vector and pairs with a string
*/
string pair_to_string(const pair<vector<double>, string> &p) {
    //loop thru elements of vect doubles and pair with a string
    ostringstream oss;
    oss << std::fixed;
    oss << std::setprecision(3);
    for (auto d : p.first) {
        oss << d << " "; //adds elements to ostring stream oss
        //followed by a space
    }
    oss << p.second; //adds the string from the pair onto oss
    return oss.str();
}

/*
takes the map and prints it to the opened ostream and out
*/
void print_map(const map<vector<double>, string> &m, ostream &out) {
   transform (m.cbegin(), m.cend(), ostream_iterator<string>(out, "\n"), pair_to_string);
}

/*
Finds the euclidean distance between two vectors as a double.
*/
double distance(const vector<double> &v1, const vector<double> &v2, unsigned int feature_count) {
    double dist;
    double sqroot;
    for (int i = 0; i <= feature_count; i++) {
        dist += pow((v1[i] - v2[i]), 2); //pow, squares the difference between element of v1 and element of v2
    }
    sqroot = sqrt(dist); //takes the square root of the total differences between all elements of the vectors
    return sqroot; 
}

/*
Takes in a map with the contents of the opened file. will return a smaller version of that map and will only contain k elements, the k nearest neighbors from map when measured with the test. 
*/
map<vector<double>, string> k_neighbors(const map<vector<double>, string> &m, const vector<double> &test, int k) {
    //iterate through map and compare distances for the 
    //access vector pair in map and compare which one is shorter to add to new vector
    map<vector<double>, string> new_map;
    map<double, pair<vector<double>, string>> temp_map;

    int total = 0;
    for (auto element: m) { //iterate throughout the map 
        
        if (element.first != test) { //element cant be the test 
        //distance is the key, element is value
            double dist = distance(element.first, test, test.size());
            temp_map[dist] = element; //add it onto the temporary map
        }
    }
    for (auto i : temp_map) { //iterate through the temporary map
        if (total == k)  { 
            break;
        }
        else {
            new_map.insert(pair<vector<double>, string> (i.second));
            //adds the pair onto the new map
        }
        ++total; //increments so that it continues going 
    }
    return new_map;  
}

/*
takes in map m and the pair test, uses k neighbors to find the k nearest neighbors. Checks whether the neighbor found matches with the test element.
*/
double test_one(const map<vector<double>, string> &m, pair<vector<double>, string> test, int k) {
    //gets k neighbors for each one see which one matches the test 
    double match = 0;
    double count = 0;
    map<vector<double>, string> k_map = k_neighbors(m, test.first, k);
    //the map created from k_neighbors is set to the k_map
    for (auto i: k_map) { //iterate through the k_map
        if (i.second == test.second) { //compares element from map to the test
            match++;
        }
    }
    return match / k_map.size(); //returns percentage of times near-neighbors wer correct label. 
}

/*
tests the elements in the map with the remaining elements to get the accurracy. then finds the average.
*/
double test_all(const map<vector<double>, string> &m, int k) {
    //takes the average of all
    double sum = 0;
    double average_all = 0;
    double counter = 0;
    //double end_size = 0;
    vector<double> test1;
    for (auto element : m) { //iterates through the map
        sum += test_one(m, element, k); //the percentage returned from test one is added onto a sum each time it loops through
        counter++; 
    }
    average_all = sum/counter; //calculates the average of that

    return average_all;
}
