#ifndef MEDICO_HPP
#define MEDICO_HPP

#include "pessoa.hpp"
#include <string>
#include <vector>
#include <memory>

class Medico : public Pessoa{
    private: 
        string crm;
        string especialidade;
    public:
        Medico();
        Medico(string crm, string nome, string especialidade);
        string getCrm() const;
        string getEspecialidade() const;
        string getNome() const;
        void setCrm(string crm);
        void setNome(string nome);
        void setEspecialidade(string especialidade);
};

class GerenciadorMedicos{
    private:
        vector<Medico*> medicos;
    public:
        void incluir(Medico* medico);
        void incluir(string crm, string  nome, string  especialidade);
        bool excluir(string crm);
        bool alterar(string crm, string nome, string especialidade);
        vector<Medico*> obter_medicos();
        Medico* localizar(string crm);     
};

#endif