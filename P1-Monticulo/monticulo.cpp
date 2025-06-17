
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

}
