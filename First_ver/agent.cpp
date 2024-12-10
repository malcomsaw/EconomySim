#include "agent.hpp"

using namespace std;

Agent::Agent(const int a_idx, double a_health, double init_saving) {
	//std::cout << "Agent " << a_idx << " health : " << a_health << " with initial saving " << init_saving << " is initiated" << std::endl;
	m_agent_index = a_idx;
	m_agent_health = a_health;
	m_local_saving = init_saving;

	// Initialize action tendencies
	m_agent_personality = new Personality();
	std::cout << "Agent index : " << m_agent_index << std::endl;
	initialize_action_tendencies();
}

Agent::~Agent() {
	if (m_agent_personality != nullptr) {
		delete m_agent_personality;
	}
}

AgentAction Agent::perform_an_action() {
	// Need a function to generation action tendencies
	refresh_action_tendencies(); // check market performance
	double random_action = (rand() % 10000) / 100.00;
	double threshold = 0.0;
	for (const auto& action_tendencies : m_agent_action_tendencies) {
		threshold += action_tendencies.second;
		if (random_action <= threshold) {
			std::cout << "Agent : " << m_agent_index << " performed action " << AgentActionName[action_tendencies.first] << std::endl;
			return action_tendencies.first;
		}
	}

	return AgentAction::DO_NOTHING;
}

void Agent::initialize_action_tendencies() {
	assert(m_agent_personality);
	m_agent_action_tendencies.clear();
	AgentAction a = AgentAction::NONE;
	const double max_value = 1.00;
	const double total_max_value = max_value * 3;
	double average_behaviour_points = double(100.00 / NONE);
	double behaviour_points = 0.0;
	double positive_points = 0.0;
	double negative_points = 0.0;
	double calculated_points = 0.0;
	double final_points_placeholder = 0.0;
	
	// Initialize a base value first
	for (int act = 0; act < AgentAction::NONE; act++) {
		m_agent_action_tendencies[static_cast<AgentAction>(act)] = average_behaviour_points;
	}

	// Adjust behaviour value according to personality
	for (int act = 0; act < AgentAction::NONE; act++) {
		a = static_cast<AgentAction>(act);
		switch (a) {
		case BUY_ASSET:
		case START_A_FIRM: {
			behaviour_points = m_agent_action_tendencies[a]; // 12.5
			// Calculate positive points
			positive_points = m_agent_personality->get_stability_or_risk();
			calculated_points = behaviour_points * positive_points;
			// Calculate negative points
			negative_points = max_value - m_agent_personality->get_openess();
			calculated_points -= behaviour_points * negative_points;
			// Update total value
			m_agent_action_tendencies[a] += calculated_points; // Done adding new points on top of 12.5

		}
			break;
		case DEPOSIT_MONEY_TO_BANK:
		case FIND_A_JOB: {
			behaviour_points = m_agent_action_tendencies[a]; // 12.5
			// Calculate negative points
			negative_points = max_value - m_agent_personality->get_stability_or_risk();
			calculated_points = behaviour_points * negative_points;
			// Calculate positive points
			positive_points = m_agent_personality->get_openess();
			calculated_points -= behaviour_points * positive_points;
			// Update total value
			m_agent_action_tendencies[a] += calculated_points; // Done adding new points on top of 12.5
		
		}
			break;
		case FOLLOW_TREND:
		case GET_WANT: {
			behaviour_points = 2 * m_agent_action_tendencies[a]; // 12.5
			// Calculate positive points
			positive_points = m_agent_personality->get_fear_of_missing_out();
			// Add positive points
			positive_points += m_agent_personality->get_openess();
			// Add negative points
			positive_points += max_value - m_agent_personality->get_conscentiousness();
			calculated_points = (behaviour_points / total_max_value) * positive_points;
			
			// Update total value
			m_agent_action_tendencies[a] = calculated_points;
		}
			break;
		case DO_NOTHING:
		case GET_NEED: {
			behaviour_points = 2 *  m_agent_action_tendencies[a]; // 12.5			
			// Add negative points
			negative_points = max_value - m_agent_personality->get_fear_of_missing_out();
			// Add negative points
			negative_points += max_value - m_agent_personality->get_openess();
			// Calculate positive points
			negative_points += m_agent_personality->get_conscentiousness();
			calculated_points = (behaviour_points / total_max_value) * negative_points;
			// Update total value
			m_agent_action_tendencies[a] = calculated_points;
		}
			break;	
		default:
			std::cout << "Unknown action made" << std::endl;
			assert(true);
			break;

		}
	}
	double total = 0;
	for (auto& action : m_agent_action_tendencies) {
		std::cout << "Action : " << AgentActionName[action.first] << " tendencies : " << action.second << std::endl;
		total += action.second;
	}
	std::cout << "Total : " << total << std::endl;
}

void Agent::refresh_action_tendencies() {
	
}

int Agent::get_agent_index() {
	return m_agent_index;
}

void Agent::get_salary(double salary) {
	m_local_saving += salary;
}

bool Agent::start_a_firm(Firm *firm) { // Revisit whether this line of code is needed
	// Random amount of startup money
	int startup_capital = rand() % 5000000; // 5,000,000
	// Check if local saving is enough
	bool result = true;
	if (m_local_saving >= startup_capital) {
		// No need loan bank
	}
	else {
	}

	return result;
}

void Agent::set_employment_status(EmploymentStatus es) {
	m_emp_status = es;
}