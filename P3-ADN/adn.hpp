
#ifndef ADN_HPP
#define ADN_HPP

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
    ADN(const ADN& B);
    ADN(ADN&& B) noexcept;
    ~ADN();

private:
    size_t n;
    Base* b;
};



#endif //ADN_HPP
