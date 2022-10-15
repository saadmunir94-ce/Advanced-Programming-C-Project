#pragma once
#include<string>
#include<map>
enum building_name
{
	probe,
	nexus,
	pylon,
	assimilator,
	zealot,
	gateway,
	mothership,
	forge,
	stalker,
	cybernetics_core,
	high_templar,
	dark_templar,
	photon_cannon,
	sentry,
	warp_prism,
	robotics_facility,
	twilight_council,
	stargate,
	phoenix,
	void_ray,
	immortal,
	observer,
	robotics_bay,
	templar_archives,
	dark_shrine,
	colossus,
	fleet_beacon,
	carrier

};

class Hash_Building_Name
{


public:
	static std::map<std::string, building_name> hasher;
};
building_name hash_it(std::string const & string_value);
