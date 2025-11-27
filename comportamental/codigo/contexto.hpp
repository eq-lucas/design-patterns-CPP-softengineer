#ifndef CONTEXTO_HPP
#define CONTEXTO_HPP

#include "login_strategy.hpp"
#include <vector> 


class Contexto {
private:
    // Lista polimórfica: Guarda ponteiros para a interface pai.
    // Aceita EmailStrategy, TelefoneStrategy, etc.
    std::vector<LoginStrategyValidar*> lista_encadeada_strategies;

public:
    /**
     * Construtor: Instanciação Interna.
     * O Contexto já nasce sabendo quais estratégias existem.
     */
    Contexto() {
        this->lista_encadeada_strategies.push_back(new EmailStrategy());
        this->lista_encadeada_strategies.push_back(new TelefoneStrategy());
        this->lista_encadeada_strategies.push_back(new UsernameStrategy());
    }

    /**
     * Destrutor: Limpeza de Memória.
     * Como demos 'new' no construtor, precisamos dar 'delete' aqui.
     */
    ~Contexto() {
        for (int i = 0; i < this->lista_encadeada_strategies.size(); i++) {
            delete this->lista_encadeada_strategies[i];
        }
        this->lista_encadeada_strategies.clear();
    }


    User* authenticate(std::string identifier, std::string password) {
        
        for (int i = 0; i < this->lista_encadeada_strategies.size(); i++) {
            
            LoginStrategyValidar* strategy = this->lista_encadeada_strategies[i];


            if (strategy->validar(identifier) == true) {
                
                return strategy->buscar_suposto_usuario(identifier);
            }
        }
        
        return nullptr;
    }
};

#endif