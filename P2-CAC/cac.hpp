
#ifndef CAC_HPP
#define CAC_HPP

// El CAC (Centro de Atención al Cliente) de cierta empresa recibe
// llamadas telefónicas de sus clientes. Una llamada es inicialmente
// asignada a un operador hasta que se atiende.
// La dirección del CAC está interesada en mantener un histórico de las
// llamadas recibidas por su plantilla de operadores. Un operador atenderá
// diversas llamadas durante su jornada laboral quedando registrada tanto
// el ID (size_t) usado como clave, la fecha (string), hora de inicio (string) y
// hora de fin (string).
// Implemente las clases Operador y Llamada con los atributos mínimos
// para implementar la relación entre ellas, así como los siguientes
// métodos:
// • Recibir(): Un operador recibe una llamada.
// • Asignar(): Una llamada es asignada a un operador.
// • Llamadas(): Llamadas atendidas por un operador.
// • Asistente(): Operador que atendió una llamada

#include <set>
#include <string>

class Llamada;

class Operador
{
public:
    using Llamadas_operador = std::set<Llamada*>;
    Operador() = default;
    void Recibir(Llamada &l);
    void Desasignar(Llamada &l);      // Para cuando se asigna la llamada a otro operador
    const Llamadas_operador& LLamadas() const;

private:
    Llamadas_operador llamadas;
};

class Llamada
{
public:
    Llamada(size_t id,std::string fch,std::string h_ini,std::string h_fin,Operador& op);
    const Operador* Asistente() const;
    void Asignar(Operador& op);
    ~Llamada();
private:
    size_t ID;
    std::string fecha,
                hora_ini,
                hora_fin;
    Operador* operador_;
};

#endif
