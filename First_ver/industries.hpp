#include "firm.hpp"

enum Industry {
	TECHNOLOGY = 0,
	MINING,
	RESTAURANT,
	CONSTRUCTION,
	REAL_ESTATE,
	AUTOMOTIVE,
	EDUCATION,
	MAX_INDUSTRY
};

const std::string IndustryName[] {
	"TECHNOLOGY"
	"MINING",
	"SERVICE",
	"CONSTRUCTION",
	"REAL_ESTATE",
	"AUTOMOTIVE",
	"EDUCATION",
	"MAX_INDUSTRY"
};


class Industries {
private:

	Industry m_industry_type = Industry::MAX_INDUSTRY;
	double m_industry_saturation = {0.0}; // 1 is max saturation for now. Means 100 is full
	std::vector<Firm*> m_registered_firm = {};
	

public:

	Industries(Industry ind);
	~Industries(); // Destructor

	// Setter
	void add_new_firm(Firm *firm);

	// Getter
	double get_saturation();

};