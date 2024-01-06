#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

class Matriz
{
public:
    int get_nfilas();
    void set_nfilas(int);
    int get_ncol();
    void set_ncol(int);
    int** get_matriz();
    void set_matriz(int**);
    Matriz(){
    }
    Matriz(int nf, int nc){
        this->nfilas=nf;
        this->ncol=nc;
        matriz = (int**)calloc(nfilas*ncol, sizeof(int));
    }
private:
    int nfilas;
    int ncol;
    int** matriz;
protected:

};


#endif // MATRIZ_H_INCLUDED
