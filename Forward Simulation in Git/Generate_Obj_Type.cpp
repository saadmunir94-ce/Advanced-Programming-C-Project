#include "Enumerations.h"

char Generate_Obj_Type(std::string name)
{
	switch (hash_it(name))
	{
	case probe:
	{
		return 'u';
		
	}
	
	case nexus:
	{
		return 'b';
		
	}
	case zealot:
	{
		return 'u';
		
	}
	case pylon:
	{
		return 'o';
		
	}
	case gateway:
	{

		return 'b';
		
	}
	case forge:
	{
		return 'o';
		
	}
	case stalker:
	{
		return 'u';
	
	}
	case mothership:
	{
		return 'u';
	
	}

	case sentry:
	{
		return 'u';
	}

	case assimilator:
	{
		return 'o';
	}

	case cybernetics_core:
	{
		return 'o';
	}

	case high_templar:
	{
		return 'u';
	}

	case dark_templar:
	{
		return 'u';
	}

	case photon_cannon:
	{
		return 'o';
	}

	case warp_prism:
	{
		return 'u';
	}

	case robotics_facility:
	{
		return 'b';
	}

	case immortal:
	{
		return 'u';
	}

	case twilight_council:
	{
		return 'o';
	}

	case observer:
	{
		return 'u';
	}
	case stargate:
	{
		return 'b';
	}

	case phoenix:
	{
		return 'u';
	}

	case void_ray:
	{
		return 'u';
	}

	case colossus:
	{
		return 'u';
	}

	case robotics_bay:
	{
		return 'o';
	}


	case templar_archives:
	{
		return 'o';
	}

	case dark_shrine:
	{
		return 'o';
	}

	case fleet_beacon:
	{
		return 'o';
	}

	case carrier:
	{
		return 'u';
	}
	default:
	{
		return 'n';
	}
  }

}