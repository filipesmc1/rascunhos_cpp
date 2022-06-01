#include<iostream>
#include<string>
#include<memory>

class AirlineTicket{

    public:
        AirlineTicket();
        AirlineTicket(std::string const&, int, bool);
        ~AirlineTicket();

        double calculatePriceInDollars() const;

        const std::string& getPassengerName() const;
        void setPassengerName(std::string const&);

        int getNumberOfMiles() const;
        void setNumberOfMiles(int);

        bool hasEliteStatus() const;
        void setEliteStatus(bool);

    private:
        std::string name;
        int nMiles;
        bool status;

};
AirlineTicket::AirlineTicket(){}
AirlineTicket::AirlineTicket(std::string const& n, int nm, bool s): name(n), nMiles(nm), status(s){}
AirlineTicket::~AirlineTicket(){}

inline double AirlineTicket::calculatePriceInDollars() const
{ 
    if(hasEliteStatus())
    {
        return 0;
    }

    return getNumberOfMiles() * 0.1;
}

inline void AirlineTicket::setNumberOfMiles(int m)
{
    nMiles = m;
}

inline void AirlineTicket::setPassengerName(std::string const& n)
{
    name = n;
}

inline void AirlineTicket::setEliteStatus(bool s)
{
    status = s;
}

inline std::string const& AirlineTicket::getPassengerName() const 
{
    return name;
}

inline int AirlineTicket::getNumberOfMiles() const
{
    return nMiles;
}

inline bool AirlineTicket::hasEliteStatus() const
{
    return status;
}

int main(){

    /* Stack Based class object */
    AirlineTicket myTicket{"Filipe Cruz", 7890, true};
    std::cout << myTicket.getPassengerName() << std::endl;
    std::cout << myTicket.getNumberOfMiles() << std::endl;
    std::cout << (myTicket.hasEliteStatus() == 1 ? "Sim" : "Nao") << std::endl;
    
    /* Heap-base with smart pointer */
    auto my_ticket = std::make_unique<AirlineTicket>();
    my_ticket->setPassengerName("Bruna Bittar");
    my_ticket->setEliteStatus(false);
    my_ticket->setNumberOfMiles(34567);

    std::cout << "Nome: " << my_ticket->getPassengerName() << std::endl;
    std::cout << "Milhagem: " << my_ticket->getNumberOfMiles() << std::endl;
    std::cout << "Memebro Elite: " << (my_ticket->hasEliteStatus() == 1 ? "Sim" : "Nao") << std::endl;
    std::cout << "Preco Total: " << my_ticket->calculatePriceInDollars() << std::endl;
    



    return 0;
}