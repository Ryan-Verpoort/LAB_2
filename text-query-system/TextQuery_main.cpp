#include "Word.h"
#include "Line.h"
#include "Paragraph.h"
#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    string Input;
    string Text_file;
    vector<int> LineNumbers;


    cout << "Please enter file name: ";
    cin >> Text_file;

    // Run until user prompts to quit

    while(Input != ".") {
	// clear vector for new run
	LineNumbers.clear();
	FileReader InputFile(Text_file);

	cout << endl << "Please enter a word to search for or \".\" to to quit: ";
	cin >> Input;
	// User does not prompt to quit
	if(Input != ".") {
	    Word SearchWord(Input);
	    Paragraph paragraph;
	    InputFile.readFileInto(paragraph);
	    // If the word is in the paragraph return lines
	    if(paragraph.contains(SearchWord, LineNumbers)) {
		cout << endl << "Word Found: ";
		for(unsigned int i = 0; i < LineNumbers.size(); i++) {
		    if(i == 0) { // aligning the outputs correctly
			cout << "line " << LineNumbers[i] << endl;
		    } else
			cout << setw(17) << "line " << LineNumbers[i] << endl;
		}
	    } else
		cout << "Word not found" << endl;
	}
    }

    return 0;
}

//If there are more then one word in a line it only gives the line once it does not state how many times it appears
//This is because in Line.cpp the contains function only returns true if a instance is found since it only takes the word in
//Does not allow for output of how many occurances it can however be modified to take in an int where it then specificies how many occurances