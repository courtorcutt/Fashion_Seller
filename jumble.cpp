using namespace std;

#include "jumble.h"

// default constructor
JumblePuzzle::JumblePuzzle() {
    // sets the chars to NULL
    jumblePuzzle = NULL;
    direction = NULL;

    // ints to zero
    squareMatrixSize = 0;
    rowPosition = 0;
    columnPosition = 0;
}

// create the actual matrix jumble puzzle
JumblePuzzle::JumblePuzzle(const string& toHide, const string& difficulty) {
    // first must check the length of the hidden word entered by the user as it must be between 3 and 10 characters
    int toHideCharacters= toHide.length();

    if (toHideCharacters < 3 ) {
        throw BadJumbleException("ERROR: entered word must be more than 3 characters");
    }
    if(toHideCharacters > 10){
        throw BadJumbleException("ERROR: entered word must be less than 10 characters");
    }


    // now that the word has been deemed okay, the user will enter a difficulty and the 2D heap will be created (create the size)
    if (difficulty == "easy") {
        squareMatrixSize = 2 * toHideCharacters;
    } else if (difficulty == "medium") {
        squareMatrixSize = 3 * toHideCharacters;
    } else if (difficulty == "hard") {
        squareMatrixSize = 4 * toHideCharacters;
    } else {
        throw BadJumbleException("Difficulty must be either, easy, medium, or hard.");
    }


    // now that size of 2D heap and the word has been chosen -> the algorithm for placement can start
    // ALGORITHM -> placement of word to hide in matrix

    // since there are four directions, we want north, south, east, west chosen at random
    int randomDirection = rand() % 4;

    // the variables for the algorithm and the nesw string
    int rows;
    int columns;
    string directions = "nesw";

    // random direction from the string "nesw"
    int placementDirectionS[4] = {-1, 0, 1, 0};
    int placementDirectionE[4] = {0, 1, 0, -1};

    // the direction attribute of JumblePuzzle has 4 directions, and we want one chosen at random for placement
    direction = directions[randomDirection];

    // for the placement of the word to be random
    int placementS = placementDirectionS[randomDirection];
    int placementE = placementDirectionE[randomDirection];

    // STEP 1. Generate a random row and column position between 0 and size-1, where size is the size of the array.
    // this uses conditional expressions to check if the row position and column position is large enough to fit the word,
    // otherwise it will move onto next direction to place at random until the word can fit
    rowPosition = rand() % (squareMatrixSize - (placementS ? toHideCharacters - 1 : 0)) + (placementS == -1 ? toHideCharacters - 1 : 0);
    columnPosition = rand() % (squareMatrixSize - ( placementE ? toHideCharacters - 1 : 0)) + ( placementE == -1 ? toHideCharacters - 1 : 0);

    // allocate the memory for the 2D heap
    jumblePuzzle = new char*[squareMatrixSize];

    // create the square matrix
    for (rows = 0; rows < squareMatrixSize; rows++) {
        // initialize the jungle puzzle filled with chars with the square matrix size determined above
        jumblePuzzle[rows] = new char[squareMatrixSize];
    }

    for (rows = 0; rows < squareMatrixSize; rows++) {

        for (columns = 0; columns < squareMatrixSize; columns++) {
            // this creates the random letters in the 2D array -> char *p = "abcdefghijklmnopqrstuvwxyz";
            jumblePuzzle[rows][columns] = rand() % 26 + 'a';
        }

    }

    // place the hidden word in the matrix
    rows = rowPosition;
    columns = columnPosition;
    int incrementer;
    for (incrementer = 0; incrementer < toHideCharacters; incrementer++) {
        // this will place the word in the matrix incrementing the row and column along until
        // there are no more characters left (word is placed in matrix)
        jumblePuzzle[rows][columns] = toHide[incrementer];
        rows = rows + placementS;
        columns = columns + placementE;
    }
}

// create the copy of the jumble puzzle matrix
JumblePuzzle::JumblePuzzle(const JumblePuzzle& firstJumblePuzzle) {
    // first I want to get the size of the first matrix
    squareMatrixSize = firstJumblePuzzle.getSize();

    // then I want to get column and row positions of the hidden word
    columnPosition = firstJumblePuzzle.getColPos();
    rowPosition = firstJumblePuzzle.getRowPos();

    // then I want to get the direction of the hidden word
    direction = firstJumblePuzzle.getDirection();

    // in order to deep copy, I need to first get the jumble
    if (firstJumblePuzzle.getJumble()) {
        // then I need to allocate memory to the puzzle with new char*
        jumblePuzzle = new char*[squareMatrixSize];

        int rows, columns;
        for (rows=0; rows<squareMatrixSize; rows++)
            // initialization
            jumblePuzzle[rows] = new char[squareMatrixSize];

        // must increment through each in a double for loop in order to copy
        for (rows=0; rows<squareMatrixSize; rows++) {
            for (columns=0; columns<squareMatrixSize; columns++) {
                // to make a deep copy without changing anything, the new jumble puzzle
                jumblePuzzle[rows][columns] = firstJumblePuzzle.getJumble()[rows][columns];
            }
        }
    }
}

// destructor
JumblePuzzle::~JumblePuzzle() {
    int sizeAmount;
    for (sizeAmount = squareMatrixSize-1; sizeAmount >= 0; sizeAmount--){
        delete[] jumblePuzzle[sizeAmount];
    }
    // free the array of pointers
    delete[] jumblePuzzle;
}

// comparison operator
JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& otherPuzzle) {
    // first I want to get the size of the first matrix
    squareMatrixSize = otherPuzzle.getSize();

    // then I want to get column and row positions
    columnPosition = otherPuzzle.getColPos();
    rowPosition = otherPuzzle.getRowPos();

    // then I want to get the direction
    direction = otherPuzzle.getDirection();

    // first I want to check if they aren't equal
    if (this != &otherPuzzle) {
        // want to assert that they aren't equal
        int rows;
        int columns;
        // position between 0 and size-1 needs to then be deleted
        for (rows=squareMatrixSize-1; rows>=0; rows--) {
            delete[] jumblePuzzle[rows];
        }
        delete[] jumblePuzzle;

        // OTHERWISE THEY ARE and I want to get the Jumble to deep copy
        // although if this isn't the case and they are equal
        if (otherPuzzle.getJumble()) {
            // do the same thing -> allocate enough memory
            jumblePuzzle = new char*[squareMatrixSize];

            // then perform deep copy of the jumble puzzle (same as below)
            for (rows = 0; rows < squareMatrixSize; rows++) {
                jumblePuzzle[rows] = new char[squareMatrixSize];
            }

            for (rows = 0; rows < squareMatrixSize; rows++) {
                for (columns=0; columns<squareMatrixSize; columns++) {
                    jumblePuzzle[rows][columns] = otherPuzzle.getJumble()[rows][columns];
                }
            }
        }

    }
    return *this;
}


// ACCESSOR METHODS from playGame()
char** JumblePuzzle::getJumble() const {
    // allocate memory for the 2D jumble array
    char** copyJumble = new char*[squareMatrixSize];

    // for a 2D jumble array, this will assign values to the allocated memory size from above.
    // since it is a square, the rows and column amount will be the same starting at 0
    int rows;
    int columns;

    for (rows=0; rows<squareMatrixSize; rows++) {
        copyJumble[rows] = new char[squareMatrixSize];
    }

    for(rows = 0; rows < squareMatrixSize; rows++){
        for(columns=0; columns < squareMatrixSize; columns++){
            copyJumble[rows][columns] = jumblePuzzle[rows][columns];
        }
    }

    // return the deep copied 2D jumble array
    return copyJumble;
}

 // get the size of the matrix
int JumblePuzzle::getSize() const {
    return squareMatrixSize;
}

// accessor - get the row position
int JumblePuzzle::getRowPos() const {
    return rowPosition;
}

// accessor - get the column position
int JumblePuzzle::getColPos() const {
    return columnPosition;
}

// accessor - get the direction (north, south, east, or west)
char JumblePuzzle::getDirection() const{
    return direction;
}

// the thrown message to be returned to user
BadJumbleException::BadJumbleException(const string& error) {
    thrownError = error;
}

string BadJumbleException::what() const {
    // the north, south, east, or west direction from user error
    // or 3 - 10 character check from hidden word error
    return thrownError;
}