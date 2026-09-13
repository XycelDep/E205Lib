class E205_TownManager
{
    protected static ref array<ref E205_Town> m_Towns;

    static void Initialize()
    {
        m_Towns = new array<ref E205_Town>;

        string worldName = GetGame().GetWorldName();
        string namesPath = "CfgWorlds " + worldName + " Names";

        int locationCount = GetGame().ConfigGetChildrenCount(namesPath);

        Print("[E205][TOWN] ========================================");
        Print("[E205][TOWN] Initializing Town Registry");
        Print("[E205][TOWN] World: " + worldName);
        Print("[E205][TOWN] Locations available: " + locationCount);

        for (int i = 0; i < locationCount; i++)
        {
            string className;

            if (!GetGame().ConfigGetChildName(namesPath, i, className))
                continue;

            string locationPath = namesPath + " " + className;

            string name;
            string type;

            GetGame().ConfigGetText(locationPath + " name", name);
            GetGame().ConfigGetText(locationPath + " type", type);

            // Only settlements we're interested in.
            if (type != "Capital" && type != "City" && type != "Village")
                continue;

			vector configPosition;
			configPosition = GetGame().ConfigGetVector(locationPath + " position");
				
            vector position;
			position[0] = configPosition[0];
			position[1] = 0;
			position[2] = configPosition[1];

			E205_Town town;
			town = new E205_Town;
			
			
			town.m_Name = name;
			town.m_Type = type;
			town.m_ConfigEntry = className;
			town.m_Position = position;
			town.m_ID = town.m_ConfigEntry;


			if (type == "Village")
				town.m_ActivationRadius = 150;
			else if (type == "City")
				town.m_ActivationRadius = 250;
			else if (type == "Capital")
				town.m_ActivationRadius = 500;
			
			town.m_State = E205_TownState.UNTOUCHED;
			town.m_Enabled = true;
			
			m_Towns.Insert(town);

        }

        Print("[E205][TOWN] Towns Registered: " + m_Towns.Count());
        Print("[E205][TOWN] ========================================");
    }

    static array<ref E205_Town> GetTowns()
    {
        return m_Towns;
    }
	
	static E205_Town FindNearestTown(vector position)
	{
		if (!m_Towns)
			return null;

		E205_Town nearestTown;
		float nearestDistance = -1;

		foreach (E205_Town town : m_Towns)
		{
			float distance = vector.Distance(position, town.m_Position);
			
			if (distance <= town.m_ActivationRadius);

				if (nearestDistance < 0 || distance < nearestDistance)
				{
					nearestDistance = distance;
					nearestTown = town;
				}
		}
		return nearestTown;
	}
};