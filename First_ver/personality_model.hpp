#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cassert>


class Personality {
private:
	// create a personality's function

	// Attribute of a personality
	
	double m_stability_or_risk = 0.0; // High means high risk
	double m_fear_of_missing_out = 0.0; // High means likely to follow trend
	double m_openess = 0.0; // High means likely to try out and give up fast
	double m_conscentiousness = 0.0; // High mean less likely to do unneccessary expenses
	
	void initialize_personality();
	
public:
	Personality();
	~Personality();
	
	void set_stability_or_risk(double val);
	void set_fear_of_missing_out(double val);
	void set_openess(double val);
	void set_conscentiousness(double val);

	double get_stability_or_risk();
	double get_fear_of_missing_out();
	double get_openess();
	double get_conscentiousness();

};