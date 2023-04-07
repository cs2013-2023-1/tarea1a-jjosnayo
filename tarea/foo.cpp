#include "foo.h"

Matriz2D::Matriz2D(){
    srand(time(nullptr));
    filas = 3;
    columnas = 3;
    ptr = new float*[filas];
    for(int i = 0; i < filas; i += 1){
        ptr[i] = new float[columnas];
        for(int j = 0; j < columnas; j += 1){
            float r = float(1 + rand() % 99)/100;
            ptr[i][j] = r;
        }
    }
}

Matriz2D::Matriz2D(int n) {
    srand(time(nullptr));
    filas = n;
    columnas = n;
    ptr = new float*[filas];
    for(int i = 0; i < filas; i += 1){
        ptr[i] = new float[columnas];
        for(int j = 0; j < columnas; j += 1){
            float r = float(1 + rand() % 99)/100;
            ptr[i][j] = r;
        }
    }
}

Matriz2D::Matriz2D(int n, int m){
    srand(time(nullptr));
    filas = n;
    columnas = m;
    ptr = new float*[filas];
    for(int i = 0; i < filas; i += 1){
        ptr[i] = new float[columnas];
        for(int j = 0; j < columnas; j += 1){
            float r = float(1 + rand() % 99)/100;
            ptr[i][j] = r;
        }
    }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    filas = m.filas;
    columnas = m.columnas;
    ptr = m.ptr;
}

Matriz2D::Matriz2D(Matriz2D&& m){
    filas = m.filas;
    columnas = m.columnas;
    ptr = m.ptr;
    m.ptr = nullptr;
}

Matriz2D t(Matriz2D& m){
    Matriz2D t(m.columnas, m.filas);
    for(int f = 0; f < m.columnas; f += 1){
        for(int c = 0; c < m.filas; c += 1){
            t.ptr[f][c] = m.ptr[c][f];
        }
    }
    return t;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    for(int f = 0; f < m.filas; f += 1){
        for(int c = 0; c < m.columnas; c += 1){
            os << m.ptr[f][c] << " ";
        }
        os << endl;
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    if(m1.filas == m2.filas & m1.columnas == m2.columnas){
        Matriz2D sum(m1.filas,m1.columnas);
        for(int i = 0; i < m1.filas; i += 1){
            for(int j = 0; j < m1.columnas; j += 1){
                sum.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
            }
        }
        return sum;
    }
    if(m1.filas == m2.filas & m1.columnas < m2.columnas){
        Matriz2D sum(m1.filas,m2.columnas);
        for(int i = 0; i < m1.filas; i += 1){
            for(int j = 0; j < m1.columnas; j += 1){
                sum.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
            }
        }
        for(int a = 0; a < m1.filas; a += 1){
            for(int b = m1.columnas; b < m2.columnas; b += 1){
                sum.ptr[a][b] = m2.ptr[a][b];
            }
        }
        return sum;
    }
    if(m1.filas == m2.filas & m1.columnas > m2.columnas){
        Matriz2D sum(m1.filas,m1.columnas);
        for(int i = 0; i < m1.filas; i += 1){
            for(int j = 0; j < m2.columnas; j += 1){
                sum.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
            }
        }
        for(int a = 0; a < m1.filas; a += 1){
            for(int b = m2.columnas; b < m1.columnas; b += 1){
                sum.ptr[a][b] = m1.ptr[a][b];
            }
        }
        return sum;
    }
    if(m1.filas < m2.filas & m1.columnas == m2.columnas){
        Matriz2D sum(m2.filas,m1.columnas);
        for(int i = 0; i < m1.filas; i += 1){
            for(int j = 0; j < m1.columnas; j += 1){
                sum.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
            }
        }
        for(int a = m1.filas; a < m2.filas; a += 1){
            for(int b = 0; b < m1.columnas; b += 1){
                sum.ptr[a][b] = m2.ptr[a][b];
            }
        }
        return sum;
    }
    if(m1.filas > m2.filas & m1.columnas == m2.columnas){
        Matriz2D sum(m1.filas,m1.columnas);
        for(int i = 0; i < m2.filas; i += 1){
            for(int j = 0; j < m1.columnas; j += 1){
                sum.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
            }
        }
        for(int a = m2.filas; a < m1.filas; a += 1){
            for(int b = 0; b < m1.columnas; b += 1){
                sum.ptr[a][b] = m1.ptr[a][b];
            }
        }
        return sum;
    }
    else{
        Matriz2D sum;
        return sum;
    }
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    if(m1.filas == m2.filas & m1.columnas == m2.columnas){
        Matriz2D res(m1.filas,m1.columnas);
        for(int i = 0; i < m1.filas; i += 1){
            for(int j = 0; j < m1.columnas; j += 1){
                res.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
            }
        }
        return res;
    }
    if(m1.filas == m2.filas & m1.columnas < m2.columnas){
        Matriz2D res(m1.filas,m2.columnas);
        for(int i = 0; i < m1.filas; i += 1){
            for(int j = 0; j < m1.columnas; j += 1){
                res.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
            }
        }
        for(int a = 0; a < m1.filas; a += 1){
            for(int b = m1.columnas; b < m2.columnas; b += 1){
                res.ptr[a][b] = m2.ptr[a][b];
            }
        }
        return res;
    }
    if(m1.filas == m2.filas & m1.columnas > m2.columnas){
        Matriz2D res(m1.filas,m1.columnas);
        for(int i = 0; i < m1.filas; i += 1){
            for(int j = 0; j < m2.columnas; j += 1){
                res.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
            }
        }
        for(int a = 0; a < m1.filas; a += 1){
            for(int b = m2.columnas; b < m1.columnas; b += 1){
                res.ptr[a][b] = m1.ptr[a][b];
            }
        }
        return res;
    }
    if(m1.filas < m2.filas & m1.columnas == m2.columnas){
        Matriz2D res(m2.filas,m1.columnas);
        for(int i = 0; i < m1.filas; i += 1){
            for(int j = 0; j < m1.columnas; j += 1){
                res.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
            }
        }
        for(int a = m1.filas; a < m2.filas; a += 1){
            for(int b = 0; b < m1.columnas; b += 1){
                res.ptr[a][b] = m2.ptr[a][b];
            }
        }
        return res;
    }
    if(m1.filas > m2.filas & m1.columnas == m2.columnas){
        Matriz2D res(m1.filas,m1.columnas);
        for(int i = 0; i < m2.filas; i += 1){
            for(int j = 0; j < m1.columnas; j += 1){
                res.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
            }
        }
        for(int a = m2.filas; a < m1.filas; a += 1){
            for(int b = 0; b < m1.columnas; b += 1){
                res.ptr[a][b] = m1.ptr[a][b];
            }
        }
        return res;
    }
    else{
        Matriz2D res;
        return res;
    }
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    if(m1.filas == m2.filas & m1.columnas == m2.columnas){
        Matriz2D prod(m1.filas,m1.columnas);
        for(int i = 0; i < m1.filas; i += 1){
            for(int j = 0; j < m1.columnas; j += 1){
                prod.ptr[i][j] = m1.ptr[i][j] * m2.ptr[i][j];
            }
        }
        return prod;
    }
    if(m1.filas == m2.filas & m1.columnas < m2.columnas){
        Matriz2D prod(m1.filas,m2.columnas);
        for(int i = 0; i < m1.filas; i += 1){
            for(int j = 0; j < m1.columnas; j += 1){
                prod.ptr[i][j] = m1.ptr[i][j] * m2.ptr[i][j];
            }
        }
        for(int a = 0; a < m1.filas; a += 1){
            for(int b = m1.columnas; b < m2.columnas; b += 1){
                prod.ptr[a][b] = m2.ptr[a][b];
            }
        }
        return prod;
    }
    if(m1.filas == m2.filas & m1.columnas > m2.columnas){
        Matriz2D prod(m1.filas,m1.columnas);
        for(int i = 0; i < m1.filas; i += 1){
            for(int j = 0; j < m2.columnas; j += 1){
                prod.ptr[i][j] = m1.ptr[i][j] * m2.ptr[i][j];
            }
        }
        for(int a = 0; a < m1.filas; a += 1){
            for(int b = m2.columnas; b < m1.columnas; b += 1){
                prod.ptr[a][b] = m1.ptr[a][b];
            }
        }
        return prod;
    }
    if(m1.filas < m2.filas & m1.columnas == m2.columnas){
        Matriz2D prod(m2.filas,m1.columnas);
        for(int i = 0; i < m1.filas; i += 1){
            for(int j = 0; j < m1.columnas; j += 1){
                prod.ptr[i][j] = m1.ptr[i][j] * m2.ptr[i][j];
            }
        }
        for(int a = m1.filas; a < m2.filas; a += 1){
            for(int b = 0; b < m1.columnas; b += 1){
                prod.ptr[a][b] = m2.ptr[a][b];
            }
        }
        return prod;
    }
    if(m1.filas > m2.filas & m1.columnas == m2.columnas){
        Matriz2D prod(m1.filas,m1.columnas);
        for(int i = 0; i < m2.filas; i += 1){
            for(int j = 0; j < m1.columnas; j += 1){
                prod.ptr[i][j] = m1.ptr[i][j] * m2.ptr[i][j];
            }
        }
        for(int a = m2.filas; a < m1.filas; a += 1){
            for(int b = 0; b < m1.columnas; b += 1){
                prod.ptr[a][b] = m1.ptr[a][b];
            }
        }
        return prod;
    }
    else{
        Matriz2D prod;
        return prod;
    }
}

Matriz2D operator+(const Matriz2D& m, float n){
    Matriz2D se(m.filas,m.columnas);
    for(int i = 0; i < m.filas; i += 1){
        for(int j = 0; j < m.columnas; j += 1){
            se.ptr[i][j] = m.ptr[i][j] + n;
        }
    }
    return se;
}

Matriz2D operator-(const Matriz2D& m, float n){
    Matriz2D re(m.filas,m.columnas);
    for(int i = 0; i < m.filas; i += 1){
        for(int j = 0; j < m.columnas; j += 1){
            re.ptr[i][j] = m.ptr[i][j] - n;
        }
    }
    return re;
}

Matriz2D operator*(const Matriz2D& m, float n){
    Matriz2D me(m.filas,m.columnas);
    for(int i = 0; i < m.filas; i += 1){
        for(int j = 0; j < m.columnas; j += 1){
            me.ptr[i][j] = m.ptr[i][j] * n;
        }
    }
    return me;
}

Matriz2D operator/(const Matriz2D& m, float n){
    Matriz2D de(m.filas,m.columnas);
    for(int i = 0; i < m.filas; i += 1){
        for(int j = 0; j < m.columnas; j += 1){
            de.ptr[i][j] = m.ptr[i][j] / n;
        }
    }
    return de;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}