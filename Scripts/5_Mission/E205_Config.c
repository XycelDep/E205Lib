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
            string id;
            string name;
            string type;
            vector position;
            float activationRadius;
            bool enabled = true;
            string fortification;

            bool hasName = false;
            bool hasType = false;
            bool hasPosition = false;
            bool hasActivationRadius = false;
            bool hasEnabled = false;
            bool hasFortification = false;

            array<CF_XML_Tag> idTags;
            idTags = towns[i].GetTag("ID");
            
            if (idTags.Count() > 0)
            {
                id = idTags[0].GetContent().GetContent();
            }

            hasName = towns[i].GetTag("Name").Count() > 0;
            if(hasName)
                name = towns[i].GetTag("Name")[0].GetContent().GetContent();

            hasType = towns[i].GetTag("Type").Count() > 0;
            if(hasType)
                type = towns[i].GetTag("Type")[0].GetContent().GetContent();

            hasPosition = towns[i].GetTag("Position").Count() > 0;
            if(hasPosition)
            {
                string tPosition;
                tPosition = towns[i].GetTag("Position")[0].GetContent().GetContent();
                // Convert to Vector
                TStringArray pParts;
                pParts = new TStringArray;
                tPosition.Split(" ", pParts);
                if(pParts.Count() == 3)
                {
                    position[0] = pParts[0].ToFloat();
                    position[1] = pParts[1].ToFloat();
                    position[2] = pParts[2].ToFloat();
                }
            }

            hasActivationRadius = towns[i].GetTag("ActivationRadius").Count() > 0;
            if(hasActivationRadius)
            {   
                string tActivationRadius;
                tActivationRadius = towns[i].GetTag("ActivationRadius")[0].GetContent().GetContent();
                activationRadius = tActivationRadius.ToFloat(); // Convert to Float
            }

            hasEnabled = towns[i].GetTag("Enabled").Count() > 0;
            if(hasEnabled)
            {
                string tEnabled;
                tEnabled = towns[i].GetTag("Enabled")[0].GetContent().GetContent();
                if(tEnabled == "true")
                    enabled = true;
                else if(tEnabled == "false")
                    enabled = false;
            }
                


            hasFortification = towns[i].GetTag("Fortification").Count() > 0;
            if(hasFortification)
                fortification = towns[i].GetTag("Fortification")[0].GetContent().GetContent();
            
            ApplyTownOverride(id,name,type,position,activationRadius,enabled,fortification,hasName,hasType,hasPosition,hasActivationRadius,hasEnabled,hasFortification);
            
        }

        Print("[E205][CONFIG] ========================================");

        return true;
    }

    static void ApplyTownOverride(
        string id,
        string name,
        string type,
        vector position,
        float activationRadius,
        bool enabled,
        string fortification,
        bool hasName,
        bool hasType,
        bool hasPosition,
        bool hasActivationRadius,
        bool hasEnabled,
        bool hasFortification
    )
    {
        E205_Town town;
        town = E205_TownManager.GetTownByID(id);

        if (town)
        {

            if(hasName)
                town.m_Name = name;
                
            if(hasType)
                town.m_Type = type;

            if(hasPosition)
                town.m_Position = position;

            if(hasActivationRadius)
                town.m_ActivationRadius = activationRadius;

            if(hasEnabled)
                town.m_Enabled = enabled;

            if(hasFortification)
                town.m_Fortification = fortification;

            Print("[E205][CONFIG] Applied config override to: " + town.m_ID);

            return;
        }
        
        if (id == "")
        {
            Print("[E205][CONFIG] WARNING : Town has no ID");
            return;
        }


        if(!hasPosition)
        {
            Print("[E205][CONFIG] WARNING: Custom Town has no position defined!");
            return;
        }

        E205_Town customTown;
        customTown = new E205_Town;

        customTown.m_ID = id;
        customTown.m_Position = position;

        if (hasName)
            customTown.m_Name = name;

        if (hasType)
            customTown.m_Type = type;

        if (hasActivationRadius)
            customTown.m_ActivationRadius = activationRadius;

        if (hasEnabled)
            customTown.m_Enabled = enabled;

        if (hasFortification)
            customTown.m_Fortification = fortification;

        E205_TownManager.AddTown(customTown);

        Print("[E205][CONFIG] Created custom town: " + id);
    }
};