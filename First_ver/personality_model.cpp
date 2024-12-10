#include "personality_model.hpp"

Personality::Personality() {
	// Initialize all personality

	// Assign a type to personality_percentage
	initialize_personality();
}

Personality::~Personality() {

}

void Personality::initialize_personality() {
	

	double random_val = double(rand() % 100) / 100;
	set_stability_or_risk(random_val);

	random_val = double(rand() % 100) / 100;
	set_fear_of_missing_out(random_val);

	random_val = double(rand() % 100) / 100;
	set_openess(random_val);

	random_val = double(rand() % 100) / 100;
	set_conscentiousness(random_val);

}


void Personality::set_stability_or_risk(double val) {
	m_stability_or_risk = val;
}

void Personality::set_fear_of_missing_out(double val) {
	m_fear_of_missing_out = val;
}

void Personality::set_openess(double val) {
	m_openess = val;
}

void Personality::set_conscentiousness(double val) {
	m_conscentiousness = val;
}

double Personality::get_stability_or_risk() {
	return m_stability_or_risk;
}

double Personality::get_fear_of_missing_out() {
	return m_fear_of_missing_out;
}

double Personality::get_openess() {
	return m_openess;
}

double Personality::get_conscentiousness() {
	return m_conscentiousness;
}