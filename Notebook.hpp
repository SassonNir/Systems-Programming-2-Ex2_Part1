#include <iostream>
// #include <stdexcept>
// #include <functional>
#include "Direction.hpp"
using namespace std;
// using namespace std::placeholders;

namespace ariel {
class Notebook {
   private:
    unsigned int _line_length = 100;
    char _placeholder = '_';
    char _eraser = '~';

   public:
    Notebook();
    ~Notebook();
    void write(int page, int row, int column, Direction direction, const string& text);
    string read(int page, int row, int column, Direction direction, int length);
    void erase(int page, int row, int column, Direction direction, int length);
    void show(int page);
};
};  // namespace ariel