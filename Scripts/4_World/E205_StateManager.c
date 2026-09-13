class E205_StateManager
{
    static bool SetState(E205_Town town, E205_TownState newState)
    {
        if(!town)
        {
            Print("[E205][SM] Given Town does not exist");
            return false;
        }

        E205_TownState oldState;
        oldState = town.m_State;

        town.m_State = newState;
        return true

    }
}