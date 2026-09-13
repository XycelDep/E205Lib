class E205_Town
{
	string m_ID;
    string m_Name;
    string m_Type;
    string m_ConfigEntry;
    vector m_Position;
	float m_ActivationRadius;
	E205_TownState m_State;
	bool m_Enabled;

    void E205_Town()
    {
    }
	
	void setState(E205_TownState newState)
	{
		if (m_State == newState)
			return
		
		Print("[E205][TOWN] " + m_Name + " state changing");

		m_State = newState;

		Print("[E205][TOWN] " + m_Name + " state changed");
	}
};