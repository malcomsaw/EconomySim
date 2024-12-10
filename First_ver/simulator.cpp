#include "simulator.hpp"


Simulator::Simulator() {
	cout << "Initializing industries " << endl;
	for (int i = 0; i < Industry::MAX_INDUSTRY; i++) {
		industry_list.push_back(new Industries(static_cast<Industry>(i)));
	}
	cout << "Industries initialize completed " << endl;
}

Simulator::~Simulator() {

	for (Firm* ptr : firm_list) {
		delete ptr;
	}

	for (Agent* ptr : agent_list) {
		delete ptr;
	}

	for (Industries* ptr : industry_list) {
		delete ptr;
	}

	for (Bank* ptr : bank_list) {
		delete ptr;
	}
}

bool Simulator::add_agent(int agent_index) {
	double health = 0.0;
	double init_saving = 0.0;

	for (int c = 0; c < agent_index; c++) {
		health = (50 + (rand() % 50)) / 100.00;
		init_saving = 50 + (rand() % 4950);
		agent_list.push_back(new Agent(c + 1, health, init_saving));
	}

	return true;
}

bool Simulator::add_bank(string bank_name, double capital, double interest_rate) {
	bank_list.push_back(new Bank(bank_name, capital, interest_rate));
	return true;
}

bool Simulator::add_firm(Industries* inds, Firm* firm) {
	bool result = true;
	inds->add_new_firm(firm);
	return result;
}

void Simulator::add_production_value(double pv) {
	m_gdp += pv;
}

vector<Firm*> Simulator::get_firm_list() {
	return firm_list;
}

bool Simulator::run_sim() {
	assert(!agent_list.empty());
	assert(!bank_list.empty());
	assert(!industry_list.empty());

	cout << "Starting simulation" << endl;
	int input = 0;
	AgentAction action = NONE;
	do {
		input = 0;
		for (auto* agent : agent_list) {
			action = agent->perform_an_action();
			switch (action) {
			case START_A_FIRM: {
				vector<Agent*> owner_list = { agent };// Starts with only one agent
				agent->set_employment_status(BUSINESS_OWNER); // Now owner dont need to pay to start a firm
				Firm* new_firm = new Firm(to_string(agent->get_agent_index()) + "_agent_firm", owner_list, static_cast<FirmType>(rand() % FirmType::CHARITY));
				add_firm(industry_list.at(rand() % int(MAX_INDUSTRY)), new_firm);
			}
			break;
			case FIND_A_JOB: {
				// Need something to handle what if there is no firm
				if (firm_list.size() == 0) {
					cout << "No firm was established yet" << endl;
					// We change move points from getting a job to starting do nothing, start a firm (if start a firm has higher scoring to do nothing, then enhance start a firm)
					break;
				}
				int random_firm = rand() % firm_list.size();
				Firm* firm = firm_list[random_firm];
				firm->hire_employee(agent);
			}
			break;
			}
		}
		cout << "All agent iteration has ended... Displaying report...." << endl;

		for (auto firm : firm_list) { // Iterate through all firm in every ind to make an action
			
		}
		cout << "Getting user input... (1 to exit)" << endl;
		cin >> input;
	} while (input != 1);

	return true;
}

