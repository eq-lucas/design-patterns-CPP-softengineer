#ifndef LOGIN_STRATEGY_HPP
#define LOGIN_STRATEGY_HPP

#include <iostream>
#include <string>



/**
 * Simulacao de um banco de dados, onde so existeu m user com um nome...
 * @param username o nome do cara
 */
class User {

private:
    std::string username;

public:
    // O Construtor é público, então ele consegue acessar o 'private' username
    User(std::string nome) {
        this->username = nome;
    }

    // GETTER: para LER
    std::string getUsername() const {
        return this->username;
    }
};

/**
 * interface do contrato
 *
 * @param validar funcao responsavel pela logica de se o conteudo corresponde ao objetivo
 * @param buscar_suposto_usuario simular que encontrou o tal identifier com tal password no banco de dados
 * @param DESTRUTOR virtual para destruir alem de si, se vc for um filho, destruir o filho e dps tudo herdado
 */
class LoginStrategyValidar {

public:

    virtual ~LoginStrategyValidar() {}

    virtual bool validar(std::string identifier) const = 0;

    virtual User* buscar_suposto_usuario(std::string identifier) const = 0;
};




class EmailStrategy : public LoginStrategyValidar {

public:

    bool validar(std::string  identifier) const override {
        for (int i = 0; i < identifier.length(); i++) {
            if (identifier[i] == '@') {
                return true; 
            }
        }
        return false;
    }


    User* buscar_suposto_usuario(std::string identifier) const override {
        std::cout << "   [EmailStrategy] Buscando no banco por Email: " << identifier << "...\n";
        return new User("UsuarioDoEmail");
    }

};




class TelefoneStrategy : public LoginStrategyValidar {
public:
    bool validar(std::string identifier) const override {
        if (identifier.length() != 11) return false;

        for (int i = 0; i < identifier.length(); i++) {
            if (isdigit(identifier[i]) == false) return false;
        }
        return true;
    }

    User* buscar_suposto_usuario(std::string identifier) const override {
        std::cout << "   [TelefoneStrategy] Buscando no banco por Telefone: " << identifier << "...\n";
        return new User("UsuarioDoTelefone");
    }
};




class UsernameStrategy : public LoginStrategyValidar {
public:
    bool validar(std::string identifier) const override {
        bool tem_arroba = false;
        for (int i = 0; i < identifier.length(); i++) {
            if (identifier[i] == '@') {
                tem_arroba = true;
                break;
            }
        }
        if (tem_arroba) return false; 

        bool so_tem_numeros = true;
        for (int i = 0; i < identifier.length(); i++) {
            if (isdigit(identifier[i]) == false) {
                so_tem_numeros = false;
                break;
            }
        }

        if (so_tem_numeros) return false;
        return true;
        
    }

    User* buscar_suposto_usuario(std::string identifier) const override {
        std::cout << "   [UsernameStrategy] Buscando no banco por Username: " << identifier << "...\n";
        return new User("UsuarioDoUsername");
    }
};

#endif