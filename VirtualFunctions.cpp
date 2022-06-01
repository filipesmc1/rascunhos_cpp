#include<iostream>
#include<string>


class Pessoa{
    private:
        std::string nome;
        std::string endereco;
    public:
        const std::string &getNomePessoa() const { return nome; }
        const std::string &getEndereco() const { return endereco; }
        virtual void Print() const;
        virtual void IsA() const;
        Pessoa();
        Pessoa(const std::string &, const std::string &);
        Pessoa(const Pessoa &);
        virtual ~Pessoa();
};

Pessoa::Pessoa(){}
Pessoa::Pessoa(const std::string &n, const std::string &e) : nome{n}, endereco{e} {}
Pessoa::Pessoa(const Pessoa &p) : nome{p.nome}, endereco{p.endereco}{};
Pessoa::~Pessoa(){ std::cout << "Destrutor de Pessoa : " << this << std::endl; }

void Pessoa::Print() const {
    std::cout << getNomePessoa() << " " << getEndereco() << std::endl;
}

void Pessoa::IsA() const { std::cout << "Pessoa" << std::endl; }

class Estudante : public Pessoa{
    private:
        std::string curso;
        std::string instituicao;
    public:
        const std::string &getCurso() const { return curso; }
        const std::string &getInstituicao() const { return instituicao; }
        void Print() const override;
        void IsA() const override;
        Estudante();
        Estudante(const std::string &, const std::string &e, const std::string &, const std::string &);
        Estudante(const Estudante &);
        ~Estudante() override;
};

Estudante::Estudante(){}
Estudante::Estudante(const std::string &n, const std::string &e, const std::string &c, const std::string &i) : Pessoa(n,e), curso{c}, instituicao{i}{}
Estudante::Estudante(const Estudante &e) : curso{e.curso}, instituicao{e.instituicao}{}
Estudante::~Estudante(){ std::cout << "Destrutor de Estudante: " << this << std::endl; }

void Estudante::Print() const 
{ 
    std::cout << getNomePessoa() << " " << getEndereco() << " " << curso << " " << instituicao << std::endl; 
}

void Estudante::IsA() const { std::cout << "Estudante" << std::endl; }


int main(){

    Pessoa* p[2] = {nullptr};
    p[0] = new Pessoa{"Filipe Cruz", "Rua Dionisio da Costa"};
    p[1] = new Estudante{"Bruna Bittar", "Rua Dionisio da Costa", "Design", "Cruzeiro do Sul"};

    for(size_t i{0}; i < 2; i++){
        p[i]->getNomePessoa();
        p[i]->getEndereco();
        p[i]->IsA();
        p[i]->Print();
    }

    for(size_t i{0}; i < 2; i++)
        delete p[i];   
    
}
