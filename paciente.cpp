#include "paciente.hpp"

Paciente::Paciente(string cpf, string nome, string dt_nascimento)
{
    this->cpf = cpf;
    this->nome = nome;
    this->dt_nascimento = dt_nascimento;
}

string Paciente::getCpf() const
{
    return this->cpf;
}

string Paciente::getDt_nascimento() const
{
    return this->dt_nascimento;
}

string Paciente::getNome() const
{
    return this->nome;
}

void Paciente::setDt_nascimento(string dt_nascimento)
{
    this->dt_nascimento = dt_nascimento;
}

void Paciente::setNome(string nome){
    this->nome = nome;
}

void Paciente::setCpf(string cpf){
    this->cpf = cpf;
}

/**
 * Realiza a inclusão de um paciente na lista de pacientes.
 *
 * Esta função permite adicionar um objeto de paciente à lista de pacientes gerenciada pela classe GerenciadorPacientes.
 *
 * @param Paciente* Um ponteiro para o objeto do paciente que será incluído.
 */
void GerenciadorPacientes::incluir(Paciente* paciente)
{
    pacientes.push_back(paciente);
}

/**
 * Inclui um novo paciente na lista de pacientes.
 *
 * Esta função permite incluir um novo paciente na lista de pacientes gerenciada
 * pela classe GerenciadorPacientes.
 *
 * @param cpf O CPF do paciente a ser incluído.
 * @param nome O nome do paciente.
 * @param dt_nascimento A data de nascimento do paciente no formato DD/MM/AAAA.
 */
void GerenciadorPacientes::incluir(string cpf, string nome, string dt_nascimento) {
    // Cria um novo objeto Paciente com os parâmetros fornecidos
    Paciente *paciente = new Paciente(cpf, nome, dt_nascimento);

    // Adiciona o paciente ao vetor de pacientes
    pacientes.push_back(paciente);
}


/**
 * Exclui um paciente da lista de pacientes.
 *
 * Esta função permite excluir um paciente da lista de pacientes gerenciada pela classe GerenciadorPacientes.
 *
 * @param cpf O CPF do paciente que deve ser excluído.
 * @return true se o paciente foi excluído com sucesso, false se o paciente não foi encontrado.
 */
bool GerenciadorPacientes::excluir(string cpf) {
    // Procurar o paciente com o CPF fornecido no vetor de pacientes
    for (auto it = pacientes.begin(); it != pacientes.end(); ++it) {
        if ((*it)->getCpf() == cpf) {
            // Encontrou o paciente, agora excluir
            delete *it; // Libera a memória do paciente excluído
            pacientes.erase(it); // Remove o paciente do vetor
            return true;
        }
    }
    return false;
}

bool GerenciadorPacientes::alterar(string cpf, string nome, string dt_nascimento)
{
    for (auto paciente : pacientes) {
        if (paciente->getCpf() == cpf) {
            // Encontrou o médico, agora alterar os campos
            paciente->setNome(nome);             // Altera o nome
            paciente->setDt_nascimento(dt_nascimento); // Altera a especialidade
            return true; // A alteração foi bem-sucedida
        }
    }
    return false; // O médico com o CRM fornecido não foi encontrado
}

/**
 * Obtém a lista de pacientes.
 *
 * Esta função retorna a lista de pacientes gerenciada pela classe GerenciadorPacientes.
 *
 * @return Um vetor de ponteiros para objetos Paciente representando a lista de pacientes.
 */
vector<Paciente *> GerenciadorPacientes::obter_pacientes()
{
    return this->pacientes;
}


/**
 * Localiza um paciente pelo CPF.
 *
 * Esta função permite localizar um paciente pelo seu CPF na lista de pacientes gerenciada
 * pela classe GerenciadorPacientes.
 *
 * @param cpf O CPF do paciente a ser localizado.
 * @return Um ponteiro para o objeto Paciente encontrado ou nullptr se não for encontrado.
 */
Paciente* GerenciadorPacientes::localizar(string cpf) 
{
    for (Paciente* paciente : pacientes) {
        if (paciente->getCpf() == cpf) {
            return paciente;
        }
    }
    // Se o paciente não for encontrado, retorne um objeto Paciente vazio
    return NULL;
}