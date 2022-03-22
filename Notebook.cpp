#include "Notebook.hpp"

namespace ariel {
    Notebook::Notebook() {
        _line_length = 100;
        _placeholder = '_';
        _eraser = '~';
    }
    Notebook::~Notebook() {
        
    }

    void Notebook::write(int page, int row, int column, Direction direction, const string& text) {

    }
    string Notebook::read(int page, int row, int column, Direction direction, int length) {
        return "";
    }
    void Notebook::erase(int page, int row, int column, Direction direction, int length) {

    }
    void Notebook::show(int page) {

    }
}