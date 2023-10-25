#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP

#include "paciente.hpp"
#include "medico.hpp"

class Gerenciador{
    private:
        GerenciadorPacientes gerenc_pacientes;
        GerenciadorMedicos gerenc_medicos; 

    public:
        Gerenciador();

        // Funções para pacientes        
        void incluirPaciente();
        void excluirPaciente();
        void alterarPaciente();
        void listarPacientes();
        void localizarPaciente();

        // Funções para médicos
        void incluirMedico();
        void excluirMedico();
        void alterarMedico();
        void listarMedicos();
        void localizarMedico();
        

        // Funções utilitarias
        void exibirDadosPaciente(Paciente *paciente);
        void exibirDadosMedico(Medico *medico);
        bool alterarCampo(const string &campo, const string &valorAtual);
};

#endif