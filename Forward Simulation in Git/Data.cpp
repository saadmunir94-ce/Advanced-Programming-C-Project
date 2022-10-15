#include "Enumerations.h"
#include "Data.h"
Data  Return_Data(std::string name)
{
	Producer_Plus_Dependency dependencies;
	switch (hash_it(name))
	{
	case probe:
	{
		dependencies.builder_name = "nexus";
		return Data(500, 0, 17, 1, dependencies);

	}
	case nexus:
	{
		return Data(4000, 0, 100, 0, dependencies);
	}
	case pylon:
	{
		return Data(1000, 0, 25, 0, dependencies);
	}
	case assimilator:
	{
		return Data(750, 0, 30, 0, dependencies);
	}
	case zealot:
	{
		dependencies.builder_name = "gateway";
		return Data(1000, 0, 38, 2, dependencies);
	}
	case gateway:
	{
		dependencies.builder_dependency = "nexus";
		dependencies.building_dependency = "pylon";
		return Data(1500, 0, 65, 0, dependencies);
	}
	case mothership:
	{
		dependencies.builder_name = "nexus";
		dependencies.building_dependency = "fleet_beacon";
		return Data(4000, 40000, 160, 8, dependencies);
	}
	case forge:
	{
		dependencies.builder_dependency = "nexus";
		dependencies.building_dependency = "pylon";
		return Data(1500, 0, 45, 0, dependencies);
	}
	case stalker:
	{
		dependencies.builder_name = "gateway";
		dependencies.building_dependency = "cybernetics_core";
		return Data(1250, 5000, 42, 2, dependencies);

	}
	case sentry:
	{
		dependencies.builder_name = "gateway";
		dependencies.building_dependency = "cybernetics_core";
		return Data(500, 10000, 37, 2, dependencies);
	}

	case cybernetics_core:
	{
		dependencies.builder_dependency = "gateway";
		return Data(1500, 0, 50, 0, dependencies);
	}
	case high_templar:
	{
		dependencies.builder_name = "gateway";
		dependencies.building_dependency = "templar_archives";
		return Data(500, 15000, 55, 2, dependencies);
	}
	case dark_templar:
	{
		dependencies.builder_name = "gateway";
		dependencies.building_dependency = "dark_shrine";
		return Data(1250, 12500, 55, 2, dependencies);
	}
	case photon_cannon:
	{
		dependencies.building_dependency = "forge";
		return Data(1500, 0, 40, 0, dependencies);
	}

	case warp_prism:
	{
		dependencies.builder_name = "robotics_facility";
		return Data(2000, 0, 50, 2, dependencies);
	}

	case robotics_facility:
	{
		dependencies.building_dependency = "cybernetics_core";
		return Data(2000, 10000, 65, 0, dependencies);
	}
	case immortal:
	{
		dependencies.builder_name = "robotics_facility";
		return Data(2500, 10000, 55, 4, dependencies);
	}

	case observer:
	{
		dependencies.builder_name = "robotics_facility";
		return Data(250, 7500, 30, 1, dependencies);
	}

	case twilight_council:
	{
		dependencies.building_dependency = "cybernetics_core";
		return Data(1500, 10000, 50, 0, dependencies);
	}

	case stargate:
	{
		dependencies.building_dependency = "cybernetics_core";
		return Data(1500, 15000, 60, 0, dependencies);
	}

	case phoenix:
	{
		dependencies.builder_name = "stargate";
		return  Data(1500, 10000, 35, 2, dependencies);
	}

	case void_ray:
	{
		dependencies.builder_name = "stargate";
		return Data(2500, 15000, 60, 3, dependencies);
	}

	case colossus:
	{
		dependencies.builder_name = "robotics_facility";
		dependencies.building_dependency = "robotics_bay";
		return Data(3000, 20000, 75, 6, dependencies);
	}
	case robotics_bay:
	{
		dependencies.builder_dependency = "robotics_facility";
		return Data(2000, 20000, 65, 0, dependencies);
	}

	case templar_archives:
	{
		dependencies.building_dependency = "twilight_council";
		return Data(1500, 20000, 50, 0, dependencies);
	}
	case dark_shrine:
	{
		dependencies.building_dependency = "twilight_council";
		return Data(1000, 25000, 100, 0, dependencies);
	}
	case fleet_beacon:
	{
		dependencies.builder_dependency = "stargate";
		return Data(3000, 20000, 60, 0, dependencies);
	}

	case carrier:
	{
		dependencies.builder_name = "stargate";
		dependencies.building_dependency = "fleet_beacon";
		return Data(3500, 25000, 120, 6, dependencies);
	}
	default:
	{
		std::cout << "Error!" << std::endl;
		return Data(0, 0, 0);
	}

	}
}