/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Nir Sasson
 *
 * Date: 2022-03
 */
#include "Direction.hpp"
#include "Notebook.hpp"
#include "doctest.h"
using namespace ariel;

#include <algorithm>
#include <string>
using namespace std;

TEST_CASE("Good input") {
    ariel::Notebook notebook;

    notebook.write(0, 0, 0, Direction::Horizontal, "Hello");
    notebook.write(0, 0, 5, Direction::Horizontal, "World");
    notebook.write(0, 0, 10, Direction::Horizontal, "!");
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 5) == "Hello");
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 10) == "HelloWorld");
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 11) == "HelloWorld!");
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 12) == "HelloWorld!_");

    notebook.erase(0, 0, 0, Direction::Horizontal, 1);
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 5) == "~ello");
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 10) == "~elloWorld");
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 11) == "~elloWorld!");

    notebook.erase(0, 0, 1, Direction::Horizontal, 2);
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 5) == "~~~lo");
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 10) == "~~~loWorld");
    CHECK(notebook.read(0, 0, 0, Direction::Horizontal, 11) == "~~~loWorld!");

    notebook.write(1, 2, 2, Direction::Vertical, "Hello");
    notebook.write(1, 2, 5, Direction::Vertical, "World");
    notebook.write(1, 2, 10, Direction::Vertical, "!");
    CHECK(notebook.read(1, 2, 2, Direction::Vertical, 5) == "Hello");
    CHECK(notebook.read(1, 2, 2, Direction::Vertical, 10) == "HelloWorld");
    CHECK(notebook.read(1, 2, 2, Direction::Vertical, 11) == "HelloWorld!");
    CHECK(notebook.read(1, 2, 2, Direction::Vertical, 12) == "HelloWorld!_");
    CHECK(notebook.read(1, 2, 2, Direction::Horizontal, 5) == "H____");
    notebook.write(1, 4, 0, Direction::Horizontal, "He");
    notebook.write(1, 4, 3, Direction::Horizontal, "loWorld!");
    CHECK(notebook.read(1, 4, 0, Direction::Horizontal, 11) == "HelloWorld!");
}

/**
 * Test for bad input. Should throw an exception.
 */
TEST_CASE("Bad input") {
    ariel::Notebook notebook;
    notebook.write(0, 0, 0, Direction::Horizontal, "Hello");
    notebook.write(0, 0, 5, Direction::Horizontal, "World");
    notebook.write(0, 0, 10, Direction::Horizontal, "!");
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Horizontal, "Hello"));
    CHECK_THROWS(notebook.write(0, 0, 0, Direction::Vertical, "Hello"));
    CHECK_THROWS(notebook.write(0, 0, 1, Direction::Horizontal, "E"));
    CHECK_THROWS(notebook.write(0, 0, 1, Direction::Vertical, "E"));
    CHECK_THROWS(notebook.write(0, 0, 2, Direction::Horizontal, "H"));
    CHECK_THROWS(notebook.write(0, 0, 2, Direction::Vertical, "H"));
    
}

// /**
//  * Test for a matrix with at least one of the dimensions 1.
//  * Function format is mat(col, row, a, b) where (col or row) is 1.
//  */
// TEST_CASE("One dimension") {
//     CHECK();
// }

// /**
//  * Test for a matrix with equal rows and columns.
//  * Function format is mat(dim, dim, a, b)
//  */
// TEST_CASE("SQUARE") {
//     CHECK();
// }