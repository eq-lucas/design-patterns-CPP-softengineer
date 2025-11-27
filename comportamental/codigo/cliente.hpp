#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "contexto.hpp"
#include <iostream>
#include <string>

/**
 * Simula a View do Django (LoginView).
 * O 'Cliente' no padrão Strategy é quem consome o Contexto.
 */
class LoginView {

public:

    void post(std::string identifier_front, std::string password_front) {

        std::cout << "------------------------------------------------\n";
        std::cout << "VIEW: Recebido POST com identifier: '" << identifier_front << "'\n";


        Contexto contexto; // n vou precisar fazero  metodo delete pq ela eh estatica ent o contexto eh deletado


        User* user = contexto.authenticate(identifier_front, password_front);


        if (user != nullptr) {

            std::cout << "HTTP 200 OK: Login realizado para o usuario: " << user->getUsername() << "\n";
            delete user; 

        } else {

            std::cout << "HTTP 400 Bad Request: Formato invalido ou usuario nao encontrado.\n";
        }

        std::cout << "------------------------------------------------\n\n";
    }
};

#endif