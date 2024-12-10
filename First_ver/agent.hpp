// Agent is human
#include "personality_model.hpp"

class Bank;
class Industries;
class Firm;

enum EmploymentStatus {
	UNEMPLOYED,
	EMPLOYED,
	BUSINESS_OWNER,
	SELF_EMPLOYED,
};


enum AgentAction {
	// For making money
	START_A_FIRM, // Risky
	FIND_A_JOB, // 

	// For spending money
	GET_WANT,
	GET_NEED,

	// Neutral action
	DO_NOTHING,
	FOLLOW_TREND,
	BUY_ASSET, // House
	DEPOSIT_MONEY_TO_BANK,
	NONE
};

const std::string AgentActionName[]{
	"START_A_FIRM",
	"FIND_A_JOB",

	// For spending money
	"GET_WANT", // Expense / liability
	"GET_NEED",

	// Neutral action
	"DO_NOTHING",
	"FOLLOW_TREND",
	"BUY_ASSET", // House
	"DEPOSIT_MONEY_TO_BANK",
	"NONE"
};



class Agent {
private:

	int m_agent_index = 0;
	Personality* m_agent_personality = nullptr;
	double m_agent_health = 0.0; // 0 to 1
	double m_agent_psy_health = 0.0;
	double m_annual_income = 0.0;
	double m_local_saving = 0.0;
	EmploymentStatus m_emp_status = UNEMPLOYED;
	std::map<AgentAction, double> m_agent_action_tendencies;
	// Asset and liability for later
	
	void initialize_action_tendencies();
	void refresh_action_tendencies();

public:

	Agent(const int a_idx, double a_health, double init_saving);
	~Agent();
	
	AgentAction perform_an_action();
	
	bool start_a_firm(Firm *firm);
	bool get_a_job();
	bool get_want();
	bool get_need();
	bool follow_trend();
	bool buy_asset();
	bool deposit_money();

	// Setter
	void set_employment_status(EmploymentStatus es);
	// Getter
	int get_agent_index();
	void get_salary(double salary);
};