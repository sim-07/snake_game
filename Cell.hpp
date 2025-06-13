#ifndef CELL_HPP
#define CELL_HPP

enum CellType { EMPTY, SNAKE, APPLE };

class Cell {
    public: 
        CellType type;
        
    Cell() : type(EMPTY) {} // costruttore che imposta inizialmente type a EMPTY
};

#endif