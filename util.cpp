#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
  //adds letter to a temp string until it encounters a non-letter.
  //adds word to the set of keywords if it has 3 or more characters.
  std::set<std::string> keywords;
  rawWords = trim(rawWords);
  rawWords = convToLower(rawWords);
  int start =0;
  std::string temp = "";
  bool found_word = false;
  bool found_end = false;
  while (!found_end){
      if(rawWords[start]>=97 && rawWords[start]<=122){
          found_word = true;
          temp+= rawWords[start];
          start++;
      }
      else{ // if char not a letter
          if (found_word == true){
              if(temp.size() < 3){
                  temp = "";
              }
              else{
                  keywords.insert(temp);
                  temp = "";
              }
          }
          found_word=false;
          if (rawWords[start] == '\0'){
            found_end = true;
          }
          start++;
      }
  }
  return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
