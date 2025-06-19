
#ifndef ADN_HPP
#define ADN_HPP
#include <iosfwd>
#include <__ostream/basic_ostream.h>

// 1. Dado el siguiente esqueleto de una clase en C++ que representa una
// cadena de ADN:
// Teniendo en cuenta de que es admisible la cadena vacía y haciendo
// siempre uso de los métodos std::copy_n() y std::fill_n(), sabiendo que:
// - copy_n(): recibe iterador al origen del rango del que copiar, número de
// elementos a copiar e iterador al destino
// - fill_n(): recibe iterador al origen del rango a rellenar, número de
// elementos a rellenar y valor a ser asignado.
// Realiza:
// a) Defina e implemente el constructor por defecto de la clase
// b) Defina e implemente el constructor a partir de una única base
// con 4 elementos.
// c) ¿Es necesario constructor de copia?
// Si es así defínelo e impleméntelo, si no, explica el por qué.
// d) ¿Es necesario constructor por movimiento?
// Si es así defínelo e impleméntelo, si no, explica el por qué.
// NOTA: TODOS LOS MÉTODOS SERÁN DEFINIDOS INTERNAMENTE E
// IMPLEMENTADOS EXTERNAMENTE A LA CLASE PROPORCIONADA

class ADN
{
public:
    enum Base{G,A,C,T};
    ADN();
    explicit ADN(const Base& B);
    // Los por defecto no valen debido a la memoria dinámica,simplemente copiaria el puntero el por defecto
    ADN(const ADN& B);
    ADN& operator=(const ADN& B);
    ADN(ADN&& B) noexcept;
    ADN& operator=(ADN&& B) noexcept;
    ~ADN();

    // 2. Dada la clase ADN del ejercicio anterior:
    // a) Sobrecarga el operador + para que permita la concatenación de
    // varias bases.
    ADN operator+(const ADN& B) const;
    // Sobrecarga el operador [] tanto const como no-const para que
    // permita acceder al elemento de una base concreta dado un índice
    const Base& operator[](size_t ind) const;
    Base& operator[](size_t ind);
    // Sobrecarga el operador << para imprimir todos los componentes de
    // un ADN, para ello haz uso de un objeto a función.
    struct base_to_char {
        char operator()(const Base b) const {
            switch (b) {
                case G:
                    return 'G';
                case A:
                    return 'A';
                case C:
                    return 'C';
                case T:
                    return 'T';
            }
            return ' ';
        }
    };


private:
    size_t n;
    Base* b;
};

std::ostream& operator<<(std::ostream& os,const ADN& A);

#endif //ADN_HPP
