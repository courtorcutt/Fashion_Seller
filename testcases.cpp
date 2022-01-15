void testJumble() {
    // BLACK BOX ADDITIONAL TESTS

    // Testing accessors
    cout << "Testing accessors:" << endl;

    JumblePuzzle test("coding", "medium");
    showJumble(test.getJumble(), test.getSize());

    // assert all the accessors in the puzzle is the correct size and is formed properly
    int rowsAmount = test.getRowPos();
    int columnsAmount = test.getColPos();
    int sizeMatrix = test.getSize();
    char directionMatrix = test.getDirection();
    cout << "Row position: " << rowsAmount << endl;
    cout << "Column position: " << columnsAmount << endl;
    cout << "Size of matrix (18): " << sizeMatrix << endl;
    cout << "Direction (n/s/e/w): " << directionMatrix << endl;
    cout << "" <<  endl;

    // Test to make sure that exceptions are thrown when they should be
    cout << "Testing BadJumbleException class:" << endl;
    // testing difficulty - input partitioning - black box all input possibilities
    try {
        JumblePuzzle test1("hello", "wind");
    } catch (const BadJumbleException& e) {
        cout << e.what() << endl;
    }
    try {
        JumblePuzzle test2("hello", "");
    } catch (const BadJumbleException& e) {
        cout << e.what() << endl;
    }

    // testing hidden word - input partitioning all input possibilities
    try {
        JumblePuzzle test3("HELLOTHEREJUMBLE1", "easy");
    } catch (const BadJumbleException& e) {
        cout << e.what() << endl;
    }
    try {
        JumblePuzzle test4("HI", "easy");
    } catch (const BadJumbleException& e) {
        cout << e.what() << endl;
    }
    try {
        JumblePuzzle test5("", "easy");
    } catch (const BadJumbleException& e) {
        cout << e.what() << endl;
    }

    // Test copy constructor for proper operation
    cout << "Testing copy constructor:" << endl;
    // While debugging, you can use capital letters to make the hidden string easier to locate
    JumblePuzzle jp1("HELLO", "easy");
    showJumble(jp1.getJumble(), jp1.getSize());
    JumblePuzzle jp2(jp1);
    cout << "Should look the same:" << endl;
    showJumble(jp2.getJumble(), jp2.getSize());

    // Test aliasing from copy constructor
    char** puzzle = jp2.getJumble();
    int sz = jp2.getSize();
    for (int i = 0; i < sz; i++)
        puzzle[i][i] = '.';
    cout << "Dotted diagonal:" << endl;
    showJumble(puzzle, sz);
    cout << "Should be same as original 1:" << endl;
    showJumble(jp1.getJumble(), sz);
    cout << "Should be same as original 2:" << endl;
    showJumble(jp2.getJumble(), sz);

    // Test assignment operator for proper operation
    cout << "Testing assignment operator:" << endl;
    JumblePuzzle jp3("BYE", "easy");
    showJumble(jp3.getJumble(), jp3.getSize());
    JumblePuzzle jp4 = jp3;
    cout << "Should look the same:" << endl;
    showJumble(jp4.getJumble(), jp4.getSize());

    // aliasing test
    puzzle = jp4.getJumble();
    sz = jp4.getSize();
    for (int i = 0; i < sz; i++)
        puzzle[i][i] = '*';
    cout << "Star diagonal:" << endl;
    showJumble(puzzle, sz);
    cout << "Should be same as original 3:" << endl;
    showJumble(jp3.getJumble(), sz);
    cout << "Should be same as original 4:" << endl;
    showJumble(jp4.getJumble(), sz);

    // self-assignment test
    jp4 = jp4;
    cout << "Should be same as original 4:" << endl;
    showJumble(jp4.getJumble(), sz);

    // memory test leak
    int loopLimit = 1000;
    for (int i = 0; i < loopLimit; i++)
        JumblePuzzle jp("HIDDENWORD", "hard");
    cout << "\nPassed memory leak test!" << endl;

} // end testJumble