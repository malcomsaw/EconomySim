// First_ver.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author : Malcom

#include "simulator.hpp"

using namespace std;

#define AGENT_COUNT 5

int main() {
	srand(time(0));
	cout << "Economy Sim" << endl;

	Simulator sim;
	sim.add_bank("Central bank", 1000000000, 2.1);
	sim.add_agent(AGENT_COUNT);
	sim.run_sim();

	return 0;
}


