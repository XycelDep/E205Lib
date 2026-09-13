class E205_Config
{
    static bool Load()
    {
        Print("[E205][CONFIG] ========================================");
        Print("[E205][CONFIG] Loading overrides");

        CF_XML_Document document;

        if (!CF_XML.ReadDocument("$mission:E205/Overrides.xml", document))
        {
            Print("[E205][CONFIG] ERROR: Failed to read overrides");
            return false;
        }

        array<CF_XML_Tag> overrides;
        overrides = document.Get("E205_Overrides");

        if (overrides.Count() == 0)
        {
            Print("[E205][CONFIG] ERROR: E205_Overrides root not found");
            return false;
        }

        array<CF_XML_Tag> towns;
        towns = overrides[0].GetTag("Town");

        Print("[E205][CONFIG] Towns found: " + towns.Count());

        for (int i = 0; i < towns.Count(); i++)
        {
            array<CF_XML_Tag> idTags;
            idTags = towns[i].GetTag("ID");
            
            if (idTags.Count() > 0)
            {
                string id;
                id = idTags[0].GetContent().GetContent();

                array<CF_XML_Tag> enabledTags;
                enabledTags = towns[i].GetTag("Enabled");

                if (enabledTags.Count() > 0)
                {
                    string enabledValue;
                    enabledValue = enabledTags[0].GetContent().GetContent();

                    bool enabled = true;

                    if (enabledValue == "false")
                        enabled = false;

                    ApplyTownOverride(id, enabled);
                }
            }
        }

        Print("[E205][CONFIG] ========================================");

        return true;
    }

    static void ApplyTownOverride(string id, string name, array position, int activationRadius, bool enabled)
    {
        array<ref E205_Town> towns;
        towns = E205_TownManager.GetTowns();

        Print("[E205][CONFIG] ----------------------------------------");
        Print("[E205][CONFIG] Applying Town Override");
        Print("[E205][CONFIG] Override ID: [" + id + "]");
        Print("[E205][CONFIG] Override Enabled: " + enabled);
        Print("[E205][CONFIG] Registered Towns: " + towns.Count());

        for (int i = 0; i < towns.Count(); i++)
        {
            E205_Town town;
            town = towns[i];

            Print("[E205][CONFIG] Checking Town: [" + town.m_ID + "]");

            if (town.m_ID == id)
            {
                Print("[E205][CONFIG] Applied override to: " + town.m_ID);
                Print("[E205][CONFIG] Enabled: " + town.m_Enabled);

                return;
            } 
        }

        Print("[E205][CONFIG] WARNING: No matching town found for ID: [" + id + "]");
    }
};