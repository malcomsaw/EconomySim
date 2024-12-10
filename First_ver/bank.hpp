#include "industries.hpp"

class Bank {
private:

	std::string m_bnk_name = {};
	double m_init_funding = {0.0};
	double m_reserve_fund = 0.0;
	double m_reserve_fund_percentage = 0.0;
	double m_prime_rate = {0.0}; // Interest rate

	// [agent] = money
	std::map<Agent*, double> m_agents_saving;
	double m_total_saving = 0.0;

	// Loan to agent

public:

	Bank(std::string bank_name, double initial_funding, double interest_rate);
	~Bank(); // Destructor

	// Setter

	// Getter
};