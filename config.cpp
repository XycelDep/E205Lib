class CfgPatches
{
    class E205Lib_Scripts
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Scripts"};
    };
};

class CfgMods
{
    class E205Lib
    {
        dir = "E205Lib";
        name = "E205 Liberation";
        author = "E205";
        type = "servermod";

        dependencies[] = {"Mission"};

        class defs
        {
            class missionScriptModule
            {
                value = "";
                files[] = {"E205Lib/Scripts/5_Mission"};
            };
			
			class worldScriptModule
			{
				value = "";
				files[] = {"E205Lib/Scripts/4_World"};
			};
        };
    };
};