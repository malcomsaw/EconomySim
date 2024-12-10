#include "industries.hpp"

Industries::Industries(Industry ind) {
	m_industry_type = ind;
}
Industries::~Industries() {
	for (auto firm : m_registered_firm) {
		delete firm;
	}
}

void Industries::add_new_firm(Firm *firm) {
	m_registered_firm.push_back(firm);
	m_industry_saturation += 0.01; // Need better formula to decide saturation point
	std::cout << "Industry : " << IndustryName[m_industry_type] << " saturation point : " << get_saturation() << std::endl;
}

double Industries::get_saturation() {
	return m_industry_saturation;
}