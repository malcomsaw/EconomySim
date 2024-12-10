#include "bank.hpp"
//#include "industries.hpp"
//#include "agent.hpp"

using namespace std;

class Simulator {
private:
	vector<Bank*> bank_list;
	vector<Agent*> agent_list;
	vector<Industries*> industry_list;
	vector<Firm*> firm_list;

	// Member
	double m_gdp;

public:
	Simulator();
	~Simulator();

	bool add_bank(string bank_name, double capital, double interest_rate);
	bool add_agent(int agent_index);
	bool add_firm(Industries*inds, Firm *firm);
	bool run_sim();

	void add_production_value(double pv);
	vector<Firm*> get_firm_list();

};