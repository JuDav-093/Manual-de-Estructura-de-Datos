
#include <iostream>

class Vector {
private:
    int* vect;

public:
    Vector();
    Vector(int*);
    ~Vector();
    void setVect(int*);
    int* getVect();
};
