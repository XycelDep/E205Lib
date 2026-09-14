class E205_LiberationManager
{
    static bool StartLiberation(E205_Town town)
    {
        if (!town)
        {
            Print("[E205][LM] ERROR : Null Town");
            return false;
        }

        if (!E205_StateManager.SetState(town, E205_TownState.LIBERATING))
        {
            Print("[E205][LM] ERROR : Failed to change state");
            return false;
        }

        E205_WaveManager.StartWave(town, 100, 30, 5);
        Print("[E205][LM] Transitioning Town state");
        return true;
    }
}