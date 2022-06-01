#include<iostream>


class LifeForm{

    private:

    size_t expectativaVida{0};

    public:

    LifeForm() = default;
    LifeForm(size_t ev) : expectativaVida(ev) {}
    virtual ~LifeForm() = default;
    size_t getExpectativaVida() const { return expectativaVida; }
    virtual void Print() const = 0;
    virtual void IsA() const = 0;

};


class Pessoa : public LifeForm{

    private:

    std::string nome;
    static constexpr size_t VIDA {80};

    public:
    
    Pessoa();
    Pessoa(std::string const &);
    ~Pessoa() override;
    const std::string &getNome() const;
    void Print() const override;
    void IsA() const override;
    int getExpectativaVida() const;

    Pessoa &operator=(const Pessoa &);
    bool operator==(const Pessoa &);
};

Pessoa::Pessoa() : LifeForm(VIDA){}
Pessoa::~Pessoa() { std::cout << "Destruindo Pessoa!" << std::endl; }
Pessoa::Pessoa(std::string const &n) : LifeForm(VIDA), nome(n){
    std::cout << "Criando Pessoa!" << std::endl;
    std::cout << "Endereço Pessoa: " <<  this << std::endl;
}

Pessoa &Pessoa::operator=(const Pessoa &p){
    if(this != &p){
        nome = p.nome;
    }

    return *this;
}

bool Pessoa::operator==(const Pessoa &p){

    if(this == &p)
        return true;
    else if(nome.compare(p.nome))
        return true;
    else
        return false;
    

}

inline int Pessoa::getExpectativaVida() const { return VIDA; }
inline std::string const &Pessoa::getNome() const { return nome; }

void Pessoa::IsA() const { std::cout << "Sou uma Pessoa!" << std::endl; }

void Pessoa::Print() const {
    
    std::cout << "Nome: " << nome << std::endl;    
    std::cout << "Expectativa de vida: " << VIDA << std::endl; 
}


class Estudante: public Pessoa{

    private:
    std::string curso;
    public:
    Estudante() = default;
    Estudante(std::string const &, std::string const &);
    ~Estudante() override;
    std::string const &getCurso() const;
    void Print() const override;
    void IsA() const override;
};

Estudante::Estudante(std::string const &n, std::string const &c): Pessoa(n), curso(c){
    std::cout << "Criando Estudante!" << std::endl;
    std::cout << "Endereço Estudante: " <<  this << std::endl;
}


Estudante::~Estudante() { std::cout << "Destruindo Estudante!" << std::endl; }

inline std::string const &Estudante::getCurso() const { return curso; }

void Estudante::Print() const {

    std::cout << "Nome: " << getNome() << std::endl;    
    std::cout << "Curso: " << curso << std::endl; 
    std::cout << "Expectativa de vida: " << getExpectativaVida() << std::endl; 
}

void Estudante::IsA() const {  std::cout << "Sou Estudante!" << std::endl; }


int main(){
    // Estudante s{"Filipe Cruz", "Banco de Dados"};
    // s.Print();
    // s.IsA();

    Pessoa p{"Filipe Cruz"};
    Pessoa p1{"Adelia Cruz"};

    //p = p1;
    std::cout << p1.getNome() << std::endl;
    std::cout << p.getNome() << std::endl;

    std::cout << (p == p1) << std::endl;
}
