#include "cliente.hpp"

int main() {
    
    // Instancia a View (O sistema web)
    LoginView view;

    // CENÁRIO 1: Login com Email
    // A view manda string, o Contexto deve acionar a EmailStrategy
    view.post("joao@email.com", "senha123");

    // CENÁRIO 2: Login com Telefone
    // O Contexto deve acionar a TelefoneStrategy
    view.post("11999998888", "senha123");

    // CENÁRIO 3: Login com Username
    // O Contexto deve acionar a UsernameStrategy
    view.post("joao123", "senha123");

    // CENÁRIO 4: Falha (Formato desconhecido)
    // Nenhuma estratégia deve aceitar
    view.post("999", "senha123");

    return 0;
}