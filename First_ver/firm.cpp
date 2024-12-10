#include "firm.hpp"

Firm::Firm(std::string name, std::vector<Agent*> owner, FirmType firmtype) : m_firm_name(name), m_firm_type(firmtype) {
	m_ownership.clear();
	double equal_shares = 100.00 / owner.size();

	for (int k = 0; k < owner.size(); k++) {
		m_ownership[owner.at(k)] = equal_shares;
	}

	m_firm_name = name;
	m_firm_type = firmtype;
}

Firm::~Firm() {

}

void Firm::pay_salary() {
	for (std::pair<Agent*, double> emp : m_employees) {
		(*emp.first).get_salary(emp.second);
	}
}

double Firm::produce_goods() {
	double produced_goods = {};

	return produced_goods;
}

bool Firm::sell_service() { // Return true if transaction pass
	bool result = true;

	return result;
}

bool Firm::sell_goods() { // Return true if transaction pass
	bool result = true;

	return result;
}
bool Firm::hire_employee(Agent* employee) {
	bool result = true;
	m_employees[employee] = 3000; // Temporary average salary for everyone
	std::cout << "Firm: " << m_firm_name << " hired agent " << employee->get_agent_index() << std::endl;
	return result;
}