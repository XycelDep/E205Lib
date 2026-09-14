class E205_WaveManager
{
    protected static ref array<Object> m_ActiveEnemies;
    protected static E205_Town m_WaveTown;
    protected static float m_WaveRadius;
    protected static int m_WaveAmount;
    protected static int m_WaveSpawned;
    protected static int m_WaveBatchSize;
    protected static int m_WaveSpawnDelay;

    static void StartWave(E205_Town town, float radius, int amount, int batchSize, int spawnDelay)
    {
        if(!town)
        {
            Print("[E205][WM] ERROR : Null Town");
            return;
        }

        if(batchSize <= 0)
        {
            Print("[E205][WM] ERROR : Invalid Batch Size");
            return;
        }

        if(amount <= 0)
        {
            Print("[E205][WM] ERROR : Invalid Amount");
            return;
        }

        if(spawnDelay < 0)
        {
            Print("[E205][WM] ERROR : Invalid Spawn Delay");
            return;
        }

        m_ActiveEnemies = new array<Object>;
        m_WaveTown = town;
        m_WaveRadius = radius;
        m_WaveAmount = amount;
        m_WaveSpawned = 0;
        m_WaveBatchSize = batchSize;
        m_WaveSpawnDelay = spawnDelay;

        SpawnWaveBatch();
    }

    static void SpawnWaveBatch()
    {
        if(!m_WaveTown)
        {
            Print("[E205][WM] ERROR : Null Town!");
            return;
        }

        int remaining;
        remaining = m_WaveAmount - m_WaveSpawned;

        if(remaining <= 0)
        {
            Print("[E205][WM] Wave Spawn Complete");
            return;
        }

        int currentBatch;
        currentBatch = m_WaveBatchSize;

        if (currentBatch > remaining)
        {
            currentBatch = remaining;
        }

        for (int i = 0; i < currentBatch; i++)
        {
            if(SpawnInfected(m_WaveTown, m_WaveRadius))
            {
                m_WaveSpawned++;
            }
            else
            {
                Print("[E205][WM] ERROR : Failed to spawn infected");
            }
        }

        Print("[E205][WM] Spawned: " + m_WaveSpawned + "/" + m_WaveAmount);
        remaining = m_WaveAmount - m_WaveSpawned;

        if (remaining > 0)
        {
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(SpawnWaveBatch, m_WaveSpawnDelay, false);
        }
        else
        {
            Print("[E205][WM] Wave spawning complete");
        }

    }

    protected static bool SpawnInfected(E205_Town town, float radius)
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
            return true;
        }

        return false;
    }
}

