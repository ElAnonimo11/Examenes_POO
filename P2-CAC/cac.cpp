
#include "cac.hpp"

void Operador::Recibir(Llamada &l)
{
    llamadas.insert(&l);
}

void Operador::Desasignar(Llamada &l)
{
    llamadas.erase(&l);
}

const Operador::Llamadas_operador &Operador::LLamadas() const
{
    return llamadas;
}

Llamada::Llamada(size_t id, std::string fch, std::string h_ini, std::string h_fin, Operador& op)
    : ID{id} , fecha{std::move(fch)} , hora_ini{std::move(h_ini)} , hora_fin{std::move(h_fin)} , operador_{&op}
{
    operador_->Recibir(*this);
}

void Llamada::Asignar(Operador &op)
{
    operador_->Desasignar(*this);
    operador_ = &op;
    operador_->Recibir(*this);
}

const Operador *Llamada::Asistente() const
{
    return operador_;
}

Llamada::~Llamada()
{
    operador_->Desasignar(*this);
    delete operador_;
}



