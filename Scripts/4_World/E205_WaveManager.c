class E205_WaveManager
{
    protected static ref array<Object> m_ActiveEnemies;

    static void StartWave(E205_Town town, float radius, int amount)
    {
        if(!town)
        {
            Print("[E205][WM] ERROR : Null Town");
            return;
        }

        m_ActiveEnemies = new array<Object>;

        for (int i = 0; i < amount; i++)
        {
            SpawnInfected(town, radius);
        }

    }

    protected static void SpawnInfected(E205_Town town, float radius)
    {
        vector spawnPosition;
        spawnPosition = town.m_Position;
        
        spawnPosition[0] = spawnPosition[0] + Math.RandomFloatInclusive(-radius, radius);
        spawnPosition[2] = spawnPosition[2] + Math.RandomFloatInclusive(-radius, radius);

        spawnPosition[1] = GetGame().SurfaceY(spawnPosition[0],spawnPosition[2]);

        Object infected;
        infected = GetGame().CreateObject("ZmbM_CitizenASkinny_Blue", spawnPosition, false, true, true);

        if(infected)
        {
            m_ActiveEnemies.Insert(infected);
        }
        else
        {
            Print("[E205][WM] ERROR Failed to spawn infected!");
        }

    }
}

