class E205_WorldLocations
{
    static void DumpLocations()
    {
        string worldName = GetGame().GetWorldName();

        Print("[E205][WORLD] ========================================");
        Print("[E205][WORLD] World Location Dump");
        Print("[E205][WORLD] World: " + worldName);
        Print("[E205][WORLD] ========================================");

        string namesPath = "CfgWorlds " + worldName + " Names";

        int locationCount = GetGame().ConfigGetChildrenCount(namesPath);

        Print("[E205][WORLD] Config Path: " + namesPath);
        Print("[E205][WORLD] Location Count: " + locationCount);

        for (int i = 0; i < locationCount; i++)
        {
            string className;

            if (!GetGame().ConfigGetChildName(namesPath, i, className))
                continue;

            string locationPath = namesPath + " " + className;

            string locationName;
            string locationType;

            GetGame().ConfigGetText(locationPath + " name", locationName);
            GetGame().ConfigGetText(locationPath + " type", locationType);

            Print("[E205][WORLD] ------------------------------");
            Print("[E205][WORLD] Class: " + className);
            Print("[E205][WORLD] Name: " + locationName);
            Print("[E205][WORLD] Type: " + locationType);
        }

        Print("[E205][WORLD] ========================================");
        Print("[E205][WORLD] Location Dump Complete");
        Print("[E205][WORLD] ========================================");
    }
};