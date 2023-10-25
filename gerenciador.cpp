#include "gerenciador.hpp"
#include <iostream>
#include <iomanip>

Gerenciador::Gerenciador()
{
    // Adiciona pacientes aleatorios pra teste
    gerenc_pacientes.incluir(new Paciente("123.456.789-00", "Joao Silva", "15/03/1985"));
    gerenc_pacientes.incluir(new Paciente("987.654.321-00", "Maria Souza", "28/07/1990"));
    gerenc_pacientes.incluir(new Paciente("111.223.344-55", "Carlos Oliveira", "10/11/1978"));
    gerenc_pacientes.incluir(new Paciente("555.666.777-88", "Ana Santos", "02/05/2000"));

     // Adiciona médicos aleatórios
    gerenc_medicos.incluir(new Medico("12345", "Dr. Pedro", "Cardiologia"));
    gerenc_medicos.incluir(new Medico("67890", "Dra. Ana", "Dermatologia"));
    gerenc_medicos.incluir(new Medico("54321", "Dr. Carlos", "Pediatria"));
    gerenc_medicos.incluir(new Medico("98765", "Dra. Maria", "Ortopedia"));
}

/**
 * @brief Realiza a inclusão de um novo paciente no sistema.
 *
 * Esta função exibe um título para a operação e solicita ao usuário que forneça as informações
 * necessárias para criar um novo paciente, incluindo CPF, nome e data de nascimento. Após a
 * obtenção dos dados, um objeto Paciente é criado e adicionado à lista de pacientes gerenciada
 * pela instância de GerenciadorPacientes.
 * 
 * @see GerenciadorPacientes
 */
void Gerenciador::incluirPaciente()
{
    // Exibe uma linha de separação e um título para a operação
    cout << "------------------------------" << endl;
    cout << "Inclusao de Paciente" << endl;
    cout << "------------------------------" << endl;

    string cpf, nome, data_nascimento;

    // Solicita e lê o CPF do paciente, limpando o buffer de entrada
    cout << "CPF do Paciente: ";
    cin.ignore();  
    getline(cin, cpf);

    // Solicita e lê o nome do paciente
    cout << "Nome do Paciente: ";
    getline(cin, nome);

    // Solicita e lê a data de nascimento no formato DD/MM/AAAA
    cout << "Data de Nascimento (DD/MM/AAAA): ";
    getline(cin, data_nascimento);

    // Cria um novo objeto Paciente com as informações fornecidas
    Paciente* paciente = new Paciente(cpf, nome, data_nascimento);

    // Adiciona o paciente à lista de pacientes gerenciada pelo objeto "gerenc_pacientes"
    this->gerenc_pacientes.incluir(paciente);

    // Exibe uma mensagem de confirmação após a inclusão do paciente
    cout << endl << ":::::::::Paciente " << nome << " incluido com sucesso!:::::::::" << endl;
}

/**
 * @brief Realiza a exclusão de um paciente no sistema com base em seu CPF.
 *
 * Esta função exibe um título para a operação, solicita ao usuário que insira o CPF do paciente a ser excluído
 * e chama a função de exclusão do GerenciadorPacientes para realizar a remoção do paciente com o CPF fornecido.
 * Se a exclusão for bem-sucedida, exibe uma mensagem de confirmação, caso contrário, informa que o paciente não foi encontrado.
 * 
 * @see GerenciadorPacientes
 */
void Gerenciador::excluirPaciente() {
    // Exibe uma linha de separação e um título para a operação
    cout << "------------------------------" << endl;
    cout << "    Exclusao de Paciente      " << endl;
    cout << "------------------------------" << endl;

    // Solicita o CPF do paciente a ser excluído
    string cpf;
    cout << "Digite o CPF do paciente a ser excluido: ";
    cin >> cpf;

    // Chama a função de exclusão do GerenciadorPacientes
    if (gerenc_pacientes.excluir(cpf)){
        cout << ":::::::::Paciente com CPF " << cpf << " excluido com sucesso.:::::::::" << endl;
    } else {
        cout << ":::::::::Paciente com CPF " << cpf << " nao encontrado.:::::::::" << endl;
    }
    
}

/**
 * @brief Realiza a alteração de informações de um paciente com base em seu CPF.
 *
 * Esta função exibe um título para a operação e solicita ao usuário que insira o CPF do paciente a ser alterado.
 * A função então chama a função de localização no GerenciadorPacientes para encontrar o paciente com o CPF fornecido.
 * Se o paciente for encontrado, exibe suas informações e oferece a opção de alterar o nome e a data de nascimento.
 * Se as alterações forem realizadas com sucesso, uma mensagem de confirmação é exibida. Caso o paciente não seja encontrado, uma mensagem de erro é mostrada.
 * 
 * @see GerenciadorPacientes
 */
void Gerenciador::alterarPaciente() {
    // Exibe uma linha de separação e um título para a operação
    cout << "------------------------------" << endl;
    cout << "    Alteracao de Paciente     " << endl;
    cout << "------------------------------" << endl;

    // Solicita o CPF do paciente a ser alterado
    string cpf;
    cout << "Digite o CPF do paciente a ser alterado: ";
    cin >> cpf;

    // Chama a função de localização para encontrar o paciente com o CPF fornecido
    Paciente* paciente = gerenc_pacientes.localizar(cpf);

    if (paciente != nullptr) {
        exibirDadosPaciente(paciente);

        if (alterarCampo("Nome", paciente->getNome())) {
            string novoNome;
            cout << "Novo nome: ";
            cin.ignore();
            getline(cin, novoNome);
            paciente->setNome(novoNome);
            cout << ":::::::::Nome alterado com sucesso.:::::::::" << endl;
        }

        if (alterarCampo("Data de Nascimento", paciente->getDt_nascimento())) {
            string novaDataNascimento;
            cout << "Nova data de nascimento (DD/MM/AAAA): ";
            cin.ignore();
            getline(cin, novaDataNascimento);
            paciente->setDt_nascimento(novaDataNascimento);
            cout << ":::::::::Data de nascimento alterada com sucesso.:::::::::" << endl;
        }
    } else {
        cout << ":::::::::Paciente com CPF " << cpf << " nao encontrado.:::::::::" << endl;
    }
}

/**
 * @brief Lista os pacientes cadastrados no sistema.
 *
 * Esta função exibe um título e um cabeçalho da lista de pacientes, incluindo as colunas de CPF, Nome e Data de Nascimento.
 * Em seguida, obtém a lista de pacientes da classe GerenciadorPacientes usando a função "obter_pacientes".
 * Se a lista estiver vazia, a função exibe uma mensagem informando que nenhum paciente está cadastrado.
 * Caso contrário, a função itera sobre a lista de pacientes, exibindo as informações de cada paciente nas colunas correspondentes.
 * 
 * @see GerenciadorPacientes
 */
void Gerenciador::listarPacientes() {
    // Título e cabeçalho da lista de pacientes
    cout << "=========================================================" << endl;
    cout << "                    Lista de Pacientes                   " << endl;
    cout << "=========================================================" << endl;
    cout << left << setw(15) << "CPF" << left << setw(25) << "Nome" << left << setw(25) << "Data de Nascimento" << endl;
    cout << "---------------------------------------------------------" << endl;

    // Obtém a lista de pacientes da classe GerenciadorPacientes
    vector<Paciente*> pacientes = gerenc_pacientes.obter_pacientes();

    if (pacientes.empty()) {
        cout << "Nenhum paciente cadastrado." << endl;
    } else {
        for (const Paciente* paciente : pacientes) {
            cout << left << setw(15) << paciente->getCpf();
            cout << left << setw(25) << paciente->getNome();
            cout << left << setw(25) << paciente->getDt_nascimento();
            cout << endl;  // Avança para a próxima linha para o próximo paciente
        }
    }
}

/**
 * @brief Localiza e exibe informações de um paciente com base no CPF fornecido.
 *
 * Esta função exibe um título para a operação e solicita ao usuário que insira o CPF do paciente a ser localizado.
 * Em seguida, chama a função de localização na classe GerenciadorPacientes para encontrar o paciente com o CPF fornecido.
 * Se o paciente for encontrado, exibe suas informações chamando a função "exibirDadosPaciente".
 * Caso o paciente não seja encontrado, uma mensagem de erro é mostrada.
 * 
 * @see GerenciadorPacientes
 * @see exibirDadosPaciente
 */
void Gerenciador::localizarPaciente() {
    // Exibe uma linha de separação e um título para a operação
    cout << "------------------------------" << endl;
    cout << "     Localizar um Paciente    " << endl;
    cout << "------------------------------" << endl;

    // Solicita o CPF do paciente a ser localizado
    string cpf;
    cout << "Digite o CPF do paciente a ser localizado: ";
    cin >> cpf;

    // Chama a função de localização na classe GerenciadorPacientes
    Paciente* paciente = gerenc_pacientes.localizar(cpf);

    if (!paciente) {
        cout << ":::::::::Paciente com CPF " << cpf << " nao encontrado.:::::::::" << endl;
    } else {
        // Exibe os dados do paciente localizado
        exibirDadosPaciente(paciente);
    }
}


/**
 * @brief Realiza a inclusão de um novo médico no sistema.
 *
 * Esta função exibe um título para a operação e solicita ao usuário que insira o CRM, nome e especialidade do médico a ser incluído.
 * Após a leitura das informações, um novo objeto Medico é criado com as informações fornecidas.
 * O médico é adicionado à lista de médicos gerenciada pela classe GerenciadorMedicos, utilizando a função "incluir" do objeto "gerenc_medicos".
 * Em seguida, a função exibe uma mensagem de confirmação da inclusão do médico.
 * 
 * @see GerenciadorMedicos
 */
void Gerenciador::incluirMedico() {
    // Exibe uma linha de separação e um título para a operação
    cout << "------------------------------" << endl;
    cout << "    Inclusao de Medico        " << endl;
    cout << "------------------------------" << endl;

    string crm, nome, especialidade;

    // Solicita e lê o CRM do médico
    cout << "CRM do Medico: ";
    cin >> crm;

    // Solicita e lê o nome do médico
    cout << "Nome do Medico: ";
    cin.ignore();
    getline(cin, nome);

    // Solicita e lê a especialidade do médico
    cout << "Especialidade do Medico: ";
    getline(cin, especialidade);

    // Cria um novo objeto Medico com as informações fornecidas
    Medico* medico = new Medico(crm, nome, especialidade);

    // Adiciona o médico à lista de médicos gerenciada pelo objeto "gerenc_medicos"
    this->gerenc_medicos.incluir(medico);

    // Exibe uma mensagem de confirmação após a inclusão do médico
    cout << endl << ":::::::::Medico " << nome << " incluido com sucesso!:::::::::" << endl;
}

/**
 * @brief Realiza a exclusão de um médico do sistema com base no CRM fornecido.
 *
 * Esta função exibe um título para a operação e solicita ao usuário que insira o CRM do médico a ser excluído.
 * Após a leitura do CRM, a função chama a função de exclusão do objeto GerenciadorMedicos para tentar excluir o médico com o CRM fornecido.
 * Se a exclusão for bem-sucedida, a função exibe uma mensagem de confirmação.
 * Caso o médico com o CRM fornecido não seja encontrado, a função exibirá uma mensagem informando que o médico não foi encontrado.
 *
 * @see GerenciadorMedicos
 */
void Gerenciador::excluirMedico() {
    // Exibe uma linha de separação e um título para a operação
    cout << "------------------------------" << endl;
    cout << "    Exclusao de Medico      " << endl;
    cout << "------------------------------" << endl;

    // Solicita o CRM do médico a ser excluído
    string crm;
    cout << "Digite o CRM do medico a ser excluido: ";
    cin >> crm;

    // Chama a função de exclusão do GerenciadorMedicos
    if (this->gerenc_medicos.excluir(crm)) {
        cout << ":::::::::Medico com CRM " << crm << " excluido com sucesso.:::::::::" << endl;
    } else {
        cout << ":::::::::Medico com CRM " << crm << " nao encontrado.:::::::::" << endl;
    }
}

/**
 * @brief Realiza a operação de alteração de dados de um médico.
 *
 * Esta função permite ao usuário alterar informações de um médico, como nome e especialidade.
 * Primeiramente, solicita o CRM do médico a ser alterado e verifica se o médico existe.
 * Em caso afirmativo, exibe os dados do médico e pergunta se o usuário deseja alterar o nome e/ou especialidade.
 * Se o usuário optar por alterar um campo, ele pode inserir o novo valor.
 *
 * @see GerenciadorMedicos.
 */
void Gerenciador::alterarMedico() {
    // Exibe uma linha de separação e um título para a operação
    cout << "------------------------------" << endl;
    cout << "Alteracao de Medico" << endl;
    cout << "------------------------------" << endl;

    // Solicita o CRM do médico a ser alterado
    string crm;
    cout << "Digite o CRM do medico a ser alterado: ";
    cin >> crm;

    // Chama a função de localização para encontrar o médico com o CRM fornecido
    Medico* medico = gerenc_medicos.localizar(crm);

    if (medico) {
        exibirDadosMedico(medico);

        if (alterarCampo("Nome", medico->getNome())) {
            string novoNome;
            cout << "Novo nome: ";
            cin.ignore();
            getline(cin, novoNome);
            medico->setNome(novoNome);
            cout << ":::::::::Nome alterado com sucesso.:::::::::" << endl;
        }

        if (alterarCampo("Especialidade", medico->getEspecialidade())) {
            string novaEspecialidade;
            cout << "Nova especialidade: ";
            cin.ignore();
            getline(cin, novaEspecialidade);
            medico->setEspecialidade(novaEspecialidade);
            cout << ":::::::::Especialidade alterada com sucesso.:::::::::" << endl;
        }
    } else {
        cout << ":::::::::Medico com CRM " << crm << " nao encontrado.:::::::::" << endl;
    }
}

/**
 * @brief Realiza a operação de listar médicos cadastrados.
 *
 * Esta função exibe a lista de médicos cadastrados, incluindo informações como CRM, nome e especialidade.
 * Se não houver médicos cadastrados, uma mensagem indicando a ausência de médicos será exibida.
 *
 * @see GerenciadorMedicos 
 */
void Gerenciador::listarMedicos() {
    // Título e cabeçalho da lista de médicos
    cout << "=========================================================" << endl;
    cout << "                     Lista de Medicos                    " << endl;
    cout << "=========================================================" << endl;
    cout << left << setw(15) << "CRM" << left << setw(25) << "Nome" << left << setw(25) << "Especialidade" << endl;
    cout << "---------------------------------------------------------" << endl;

    // Obtém a lista de médicos da classe GerenciadorMedicos
    vector<Medico*> medicos = gerenc_medicos.obter_medicos();

    if (medicos.empty()) {
        cout << "Nenhum medico cadastrado." << endl;
    } else {
        for (const Medico* medico : medicos) {
            cout << left << setw(15) << medico->getCrm();
            cout << left << setw(25) << medico->getNome();
            cout << left << setw(25) << medico->getEspecialidade();
            cout << endl;  // Avança para a próxima linha para o próximo médico
        }
    }
}


/**
 * @brief Realiza a operação de localizar um médico por CRM.
 *
 * Esta função permite ao usuário buscar um médico com base em seu CRM. Se o médico for encontrado,
 * suas informações, como nome e especialidade, serão exibidas. Caso contrário, uma mensagem indicando
 * que o médico não foi encontrado será mostrada.
 *
 * @see Esta função assume que o GerenciadorMedicos e os médicos já foram devidamente inicializados.
 */
void Gerenciador::localizarMedico() {
    // Exibe uma linha de separação e um título para a operação
    cout << "------------------------------" << endl;
    cout << "   Localizar um Medico        " << endl;
    cout << "------------------------------" << endl;

    // Solicita o CRM do médico a ser localizado
    string crm;
    cout << "Digite o CRM do medico a ser localizado: ";
    cin >> crm;

    // Chama a função de localização na classe GerenciadorMedicos
    Medico* medico = gerenc_medicos.localizar(crm);

    if (!medico) {
        cout << "Medico com CRM " << crm << " nao encontrado." << endl;
    } else {
        // Exibe os dados do médico localizado
        exibirDadosMedico(medico);
    }
}


// Funções auxiliares
void Gerenciador::exibirDadosPaciente(Paciente* paciente) {
    cout << "================================================" << endl;
    cout << "Dados do paciente com CPF " << paciente->getCpf() << ":" << endl;
    cout << "Nome: " << paciente->getNome() << endl;
    cout << "Data de Nascimento: " << paciente->getDt_nascimento() << endl;
    cout << "================================================" << endl;
}

void Gerenciador::exibirDadosMedico(Medico* medico) {
    cout << "================================================" << endl;
    cout << "Dados do medico com CRM " << medico->getCrm() << ":" << endl;
    cout << "Nome: " << medico->getNome() << endl;
    cout << "Especialidade: " << medico->getEspecialidade() << endl;
    cout << "================================================" << endl;
}

bool Gerenciador::alterarCampo(const string& campo, const string& valorAtual) {
    char opcao;
    cout << "Deseja alterar o campo " << campo << " (Atual: "<< valorAtual << ") ? (S/N): ";
    cin >> opcao;

    if (opcao == 'S' || opcao == 's') {
        return true;
    } else if (opcao == 'N' || opcao == 'n') {
        return false;
    } else {
        throw invalid_argument("Opcão invalida. Use 'S' para Sim ou 'N' para Nao.");
    }
}
