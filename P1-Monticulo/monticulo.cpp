
#include <algorithm>

#include "monticulo.hpp"

Monticulo::Monticulo(const std::vector<double> &v) : Monticulo()
{
    for (double elem : v) m.insert(m.end(),elem);
    std::make_heap(m.begin(),m.end());
}

void Monticulo::insertar(double e)
{
    m.insert(m.end(),e);
    std::make_heap(m.begin(),m.end());
}

void Monticulo::eliminar(double e)
{
    // Comprueba que existe el elemento, lo borra si existe
    if (const auto it = std::find(m.begin(),m.end(),e); it != m.end()) {
        m.erase(it);
        std::make_heap(m.begin(),m.end());
    }
}

const std::vector<double> &Monticulo::referencia_vector() const
{
    return m;
}

std::ostream &operator<<(std::ostream &os, const Monticulo &M)
{
    for (const double elem : M.referencia_vector()) os << elem << ' ';
    return os;
}
