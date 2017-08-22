// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"

Line::Line(const string& line)
{

    // Hint: some of string's member functions might come in handy here
    // for extracting words.
    unsigned int Word_Start = 0;
    unsigned int Word_Length = 0;
    unsigned int i = 0;
    // while there are stil remaining characters in the string line split the string into multiple Word objects
    while(i != line.length()) {
	// determine the length of the new word
	Word_Length++;
	if(line[i] == ' ') {
	    _line.push_back(Word(line.substr(Word_Start, Word_Length - 1)));
	    Word_Start = i + 1;	//Remove spaces from word
	    Word_Length = 0;
	} else if(line[i + 1] == '\0') {
	    _line.push_back(Word(line.substr(Word_Start, Word_Length)));
	    Word_Start = i + 1;
	    Word_Length = 0;
	}
	i++;
    }
}

bool Line::contains(const Word& search_word) const
{
    if(search_word.isQueryable()) {	//If queryable then for loop else return false

	for(unsigned int i = 0; i < _line.size(); i++) {
	    if(_line[i] == search_word) {	//Check if words are equal
		return true;
	    }
	}
    } else
	return false;
}