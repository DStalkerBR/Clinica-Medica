#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include "pessoa.hpp"
#include <string>
#include <vector>

class Paciente : public Pessoa {
    private:
        string cpf;
        string dt_nascimento;
    public:
        Paciente();
        Paciente (string cpf, string  nome, string  dt_nascimento);
        string getCpf() const;
        string getDt_nascimento() const;
        string getNome() const;

        void setNome(string nome);
        void setCpf(string cpf);
        void setDt_nascimento(string dt_nascimento);
};

class GerenciadorPacientes{
    private:
        vector<Paciente*> pacientes;
    public:
        void incluir(Paciente* paciente);
        void incluir(string cpf, string  nome, string  dt_nascimento);
        bool excluir(string cpf);
        bool alterar(string cpf, string nome, string dt_nascimento);
        vector<Paciente*> obter_pacientes();
        Paciente* localizar(string cpf);       
};

#endif