modded class Land_Radio_PanelPAS
{
    override void OnWorkStart()
    {
        super.OnWorkStart();

		vector pasPosition = GetPosition();
		E205_Town nearestTown = E205_TownManager.FindNearestTown(pasPosition);

		if (nearestTown)
		{	
			E205_LiberationManager.StartLiberation(nearestTown);
		}
		else
		{
			Print("[E205][PAS] ERROR: No nearest town found!");
		}
    }
}