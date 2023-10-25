// #include "menu.hpp"
#include "gerenciador.hpp"
#include <iostream>

using namespace std;

void limparTela();
void pausar();
void exibirMenu(const std::string& menu);
int solicitarOpcao();
void menuGerenciarPacientes(Gerenciador& gerenciador);
void menuDerenciarMedicos(Gerenciador& gerenciador);


int main() {
    Gerenciador gerenciador;

    while (true) {
        limparTela();
        exibirMenu("\nMenu Principal:\n"
                   "1. Gestao de Pacientes\n"
                   "2. Gestao de Medicos\n"
                   "0. Sair");

        int opcaoPrincipal = solicitarOpcao();

        if (opcaoPrincipal == 0) {
            break;
        }

        switch (opcaoPrincipal) {
            case 1:
                menuGerenciarPacientes(gerenciador);
                break;
            case 2:
                menuDerenciarMedicos(gerenciador);
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                pausar();
        }
    }

    return 0;
}

// Funçao para limpar a tela
void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system ("clear");
    #endif
}

// Funçao para pausa aguardando uma tecla no Unix
void pausar() {
    cout << "Pressione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void exibirMenu(const string& menu) {
    cout << menu << endl;
}

int solicitarOpcao() {
    int opcao;
    cout << "Digite a opcao desejada: ";
    cin >> opcao;
    return opcao;
}

void menuGerenciarPacientes(Gerenciador& gerenciador) {
    while (true) {
        limparTela();
        exibirMenu("\nSubmenu - Gestao de Pacientes:\n"
                   "1. Incluir Paciente\n"
                   "2. Excluir Paciente\n"
                   "3. Alterar Paciente\n"
                   "4. Listar Pacientes\n"
                   "5. Localizar Paciente\n"
                   "0. Voltar ao Menu Principal");
        int opcaoPacientes = solicitarOpcao();

        if (opcaoPacientes == 0) {
            break;
        }

        switch (opcaoPacientes) {
            case 1:
                limparTela();
                gerenciador.incluirPaciente();
                pausar();
                break;
            case 2:
                limparTela();
                gerenciador.excluirPaciente();
                pausar();
                break;
            case 3:
                limparTela();
                gerenciador.alterarPaciente();
                pausar();
                break;
            case 4:
                limparTela();
                gerenciador.listarPacientes();
                pausar();
                break;
            case 5:
                limparTela();
                gerenciador.localizarPaciente();
                pausar();
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
}

void menuDerenciarMedicos(Gerenciador& gerenciador) {
    while (true) {
        limparTela();
        exibirMenu("\nSubmenu - Gestao de Medicos:\n"
                   "1. Incluir Medico\n"
                   "2. Excluir Medico\n"
                   "3. Alterar Medico\n"
                   "4. Listar Medicos\n"
                   "5. Localizar Medico\n"
                   "0. Voltar ao Menu Principal");
        int opcaoMedicos = solicitarOpcao();

        if (opcaoMedicos == 0) {
            break;
        }

        switch (opcaoMedicos) {
            case 1:
                limparTela();
                gerenciador.incluirMedico();
                pausar();
                break;
            case 2:
                limparTela();
                gerenciador.excluirMedico();
                pausar();
                break;
            case 3:
                limparTela();
                gerenciador.alterarMedico();
                pausar();
                break;
            case 4:
                limparTela();
                gerenciador.listarMedicos();
                pausar();
                break;
            case 5:
                limparTela();
                gerenciador.localizarMedico();
                pausar();
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
}

