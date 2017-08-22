// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"

Word::Word(const string& word)
    : _word{ word }
{
    // throws an exception (in the form of WordContainsNoLetters object)
    // indicating that the word being constructed contains no letters
    if(_word.empty())
	throw WordContainsNoLetters();
    // Convert string to all upper case
    Case_Sensitive();
	//Remove Punctuation
    Remove_punct();
	//Check for only Punctuation
	Just_punct();
	//Check for spaces
	Spaces();
    // Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
    if(_word == rhs._word)
	return true;
    else
	return false;
}

bool Word::isQueryable() const
{
    if(_word.length() >= 3)
	return true;
    else
	return false;
}

// Remove Case sensitive
void Word::Case_Sensitive()
{
    // Convert lower case to upper case using ASCII shift

    for(unsigned int i = 0; i < _word.length(); i++) {
	_word[i] = toupper(_word[i]);
    }
    return;
}

void Word::Remove_punct()
{
    for(unsigned int i = 0; i < _word.length(); i++) {

	if(ispunct(char((int)_word[i]))) // Check if punctuation if true delete and shift
	{
	    _word.erase(i, 1); // Remove Punctuation
	    i = i - 1;
	}
    }
}

void Word::Just_punct()
{
	unsigned int count = 0;
    for(unsigned int i = 0; i < _word.length(); i++) {

	if(ispunct(char((int)_word[i]))) // Check if punctuation 
	{
	    count++;		//Count number of punctuation marks
	}
    }
	if(_word.length()== count)	//IF count is equal to word length word is just punctuation
	{
		throw WordContainsNoLetters();
	}
}

 void Word::Spaces()
{
    for(unsigned int i = 0; i < _word.length(); i++) {
	if(_word[i] == ' ') { // Check For Spaces
	throw WordContainsSpace();
	}
    }
    return;
}