#include "bank.hpp"

using namespace std;
Bank::Bank(string bank_name, double initial_funding, double interest_rate) {
	cout << "New bank \"" << bank_name << "\" is up and running" << endl;
	m_bnk_name = bank_name;
	m_init_funding = initial_funding;
	m_prime_rate = interest_rate;
}

Bank::~Bank() {

}