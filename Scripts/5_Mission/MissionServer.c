modded class MissionServer
{
	override void OnInit()
	{
		super.OnInit();

		E205_TownManager.Initialize();
		CFXMLTest.Test();
	}
}