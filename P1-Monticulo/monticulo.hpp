#ifndef MONTICULO_HPP
#define MONTICULO_HPP

// Se quiere implementar en C++ una clase llamada “montículo” que
// represente un árbol binario parcialmente ordenado de mínimos de tipo
// double. Su estructura consistirá en un único atributo privado no estático
// “m” que será un vector de la STL. A continuación, se le proporciona todas
// las operaciones de la STL que deberá usar para manejar el montículo:
// a. std::make_heap(): Recibe dos iteradores, principio y final, y
// construye un montículo.
// b. std::insert(): Recibe dos iteradores, principio y final, y un
// elemento “x”, flotando el elemento hasta que el árbol quede  ;; Asi no funciona insert
// reorganizado.
// c. std::erase(): Recibe un elemento “x”, hundiendo el elemento   ;; asi no funciona erase
// hasta que el árbol quede reorganizado.
// Entonces, realiza, definiendo externamente a la clase, los métodos
// siguientes:
// a) Define la clase, incluyendo las cabeceras de los métodos
// posteriores.
// b) Un constructor que construya un montículo vacío.
// c) Un constructor que construya un montículo dado un vector.
// d) Un método insertar, que inserte un elemento en el árbol.
// e) Un método eliminar, que elimine un elemento.
// f) Un método que devuelva una referencia constante al vector.
// g) Sobrecargue el operador << para que imprima los elementos del
// montículo.
// Reservados todos los derechos. No se permite la explotación económica ni la transformación de esta obra. Queda permitida la impresión en su totalidad.
// a64b0469ff35958ef4ab887a898bd50bdfbbe91a-11691214

#include <vector>

class Monticulo
{
public:
    Monticulo()                                     = default;
    Monticulo(const Monticulo &B)                   = default;
    Monticulo(Monticulo &&B) noexcept               = default;
    Monticulo & operator=(const Monticulo &B)       = default;
    Monticulo & operator=(Monticulo &&B) noexcept   = default;
    ~Monticulo()                                    = default;
    explicit Monticulo(const std::vector<double>& v);
    void insertar(double e);
    void eliminar(double e);
    const std::vector<double>& referencia_vector() const;

private:
    std::vector<double> m;
};

std::ostream& operator<<(std::ostream& os,const Monticulo& M);

#endif
