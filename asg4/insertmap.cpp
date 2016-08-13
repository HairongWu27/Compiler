// $Id: insertmap.cpp,v 1.4 2014-11-20 16:01:18-08 - - $

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
   unordered_map<string,int> um;
   for (const string& s: vector<string> {"foo", "bar", "baz"}) {
      cout << s << ": " << um[s] << endl;
   }
   for (const auto& i: um) {
      cout << i.first << ": " << i.second << endl;
   }
   return 0;
}
