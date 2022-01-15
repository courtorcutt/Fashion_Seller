using namespace std;

// string for BadJumbleException
#include <string>

class JumblePuzzle{
private:
    char** jumblePuzzle;
    int squareMatrixSize;
    int rowPosition;
    int columnPosition;
    char direction;

public:
    // default constructor
    JumblePuzzle();

    // at the start, a matrix is created using the word entered from the user and the string of the difficulty they want
    JumblePuzzle(const string& toHide, const string& difficulty);

    // once the jumble puzzle is created, a copy is created as well too
    JumblePuzzle(const JumblePuzzle& firstJumblePuzzle);

    // destructor to take the jumble matrix off the heap
    virtual ~JumblePuzzle();

    // In startGame(), two puzzles are being compared with each other
    JumblePuzzle& operator=(const JumblePuzzle& otherPuzzle);


    /* ACCESSOR METHODS from startGame() */

    // points to a copy of the matrix grid
    char** getJumble() const;

    // returns the size of the matrix
    int getSize() const;

    // get the row the user thinks the word is in
    int getRowPos() const;

    // get the column the user thinks the word is in
    int getColPos() const;

    // get the north, south, east, or west direction from user
    char getDirection() const;
};

class BadJumbleException{
private:
    // string to hold the error message
    string thrownError;

public:
    // in the playGame function an exception is thrown with an error message
    BadJumbleException(const string& error);
    string what() const;
};