#include "agent.hpp"

enum FirmType {
	PRODUCTION = 0,
	SERVICE,
	CHARITY
};

const std::string FirmTypeName[]{
	"PRODUCTION",
	"SERVICE",
	"CHARITY"
};

class Firm {
private:
	// Firm basic info
	FirmType m_firm_type = CHARITY;

	std::string m_firm_name = { "" };
	// [agent] = share (max 100%)
	std::map<Agent*, double> m_ownership;
	// [employee] = salary
	std::map<Agent*, double> m_employees;
	// pair(product_name, price) = quantity
	std::map<std::pair<std::string, double>, int> m_inventory;
	// [service_name] = price
	std::map<std::string, double> m_service;
	

	// Asset
	// [Raw material index,price] = quanity
	std::map<std::pair<int, double>, int> m_raw_material;

	// Service cost

	// Revenue
	double profi_margin = 0.0;
	double m_corporate_revenue = 0.0;
	double m_corporate_profit = 0.0;
	double m_corporate_reserved_fund = 0.0;


public:

	Firm(std::string name, std::vector<Agent*> owner, FirmType firmtype);
	~Firm();
	
	void pay_salary();
	double produce_goods();
	bool sell_service(); // Return true if transaction pass
	bool sell_goods(); // Return true if transaction pass
	bool hire_employee(Agent *employee);
	// Setter

	// Getter
};