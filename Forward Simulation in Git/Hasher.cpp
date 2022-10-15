

#include "Enumerations.h"

std::map<std::string, building_name> Hash_Building_Name::hasher = { {"probe",probe},{"nexus",nexus},{"pylon",pylon},{"assimilator",assimilator},{"zealot",zealot},{"gateway",gateway},{"mothership",mothership},{"forge",forge},{"stalker",stalker},{"cybernetics_core",cybernetics_core},{"high_templar",high_templar},{"dark_templar",dark_templar},{"photon_cannon",photon_cannon},{"sentry",sentry},{"warp_prism",warp_prism},{"robotics_facility",robotics_facility},{"immortal",immortal}, {"twilight_council",twilight_council},{"stargate",stargate},{"phoenix",phoenix},{"void_ray",void_ray},{"observer",observer},{"robotics_bay",robotics_bay},{"templar_archives",templar_archives},{"dark_shrine",dark_shrine},{"colossus",colossus},{"fleet_beacon",fleet_beacon },{"carrier",carrier} };

building_name hash_it(std::string const & string_value)
{
	
	auto iter = Hash_Building_Name::hasher.find(string_value);
	building_name decoded = iter->second;
	return decoded;
}


