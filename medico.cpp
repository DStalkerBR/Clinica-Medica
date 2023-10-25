#include "medico.hpp"

Medico::Medico(string crm, string nome, string especialidade)
{
    this->crm = crm;
    this->nome = nome;
    this->especialidade = especialidade;
}


string Medico::getCrm() const
{
    return this->crm;
}

string Medico::getEspecialidade() const
{
    return this->especialidade;
}

string Medico::getNome() const
{
    return this->nome;
}

void Medico::setCrm(string crm)
{
    this->crm = crm;
}

void Medico::setNome(string nome)
{
    this->nome = nome;
}

void Medico::setEspecialidade(string especialidade)
{
    this->especialidade = especialidade;
}

/**
 * Inclui um médico no sistema.
 * 
 * @param medico Um ponteiro para o objeto Medico que será incluído.
 */
void GerenciadorMedicos::incluir(Medico *medico)
{
    // Adiciona o médico ao vetor de médicos.
    medicos.push_back(medico);
}

/**
 * Inclui um novo médico no sistema com base nos parâmetros fornecidos.
 * 
 * @param crm          O número de registro do médico (CRM).
 * @param nome         O nome do médico.
 * @param especialidade A especialidade do médico.
 */
void GerenciadorMedicos::incluir(string crm, string nome, string especialidade) {
    // Cria um novo objeto Medico com os parâmetros fornecidos
    Medico *medico = new Medico(crm, nome, especialidade);

    // Adiciona o médico ao vetor de médicos
    medicos.push_back(medico);
}

/**
 * Exclui um médico do sistema com base no número de registro do médico (CRM) fornecido.
 * 
 * @param crm O número de registro do médico (CRM) a ser excluído.
 * @return true se a exclusão foi bem-sucedida, false caso contrário.
 */
bool GerenciadorMedicos::excluir(string crm) {
    // Procura o médico com o CRM fornecido no vetor de médicos
    for (auto it = medicos.begin(); it != medicos.end(); ++it) {
        if ((*it)->getCrm() == crm) {
            // Encontrou o médico, agora excluir
            delete *it;       // Libera a memória do médico excluído
            medicos.erase(it); // Remove o médico do vetor
            return true;
        }
    }
    return false; // O médico com o CRM fornecido não foi encontrado
}

/**
 * Altera o nome e a especialidade de um médico com base no CRM fornecido.
 * @param crm          O CRM do médico a ser alterado.
 * @param nome         O novo nome do médico.
 * @param especialidade A nova especialidade do médico.
 * @return true se a alteração foi bem-sucedida, false caso contrário.
 */
bool GerenciadorMedicos::alterar(string crm, string nome, string especialidade) {
    // Procura o médico com o CRM fornecido no vetor de médicos
    for (auto medico : medicos) {
        if (medico->getCrm() == crm) {
            // Encontrou o médico, agora alterar os campos
            medico->setNome(nome);             // Altera o nome
            medico->setEspecialidade(especialidade); // Altera a especialidade
            return true; // A alteração foi bem-sucedida
        }
    }
    return false; // O médico com o CRM fornecido não foi encontrado
}

/**
 * Obtém a lista de médicos cadastrados no sistema.
 * 
 * @return Um vetor contendo ponteiros para os médicos cadastrados.
 */
vector<Medico*> GerenciadorMedicos::obter_medicos() {
    return this->medicos;
}

/**
 * Localiza um médico no sistema com base no número de registro do médico (CRM) fornecido.
 * 
 * @param crm O número de registro do médico (CRM) a ser localizado.
 * @return Um ponteiro para o médico encontrado ou nullptr se o médico não for encontrado.
 */
Medico* GerenciadorMedicos::localizar(string crm) {
    for (Medico* medico : medicos) {
        if (medico->getCrm() == crm) {
            return medico; // Retorna o ponteiro para o médico encontrado
        }
    }
    // Se o médico não for encontrado, retorne nullptr (em C++ moderno)
    return nullptr;
}