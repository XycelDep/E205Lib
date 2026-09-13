class CFXMLTest
{
    static void Test()
    {
        Print("[E205][CFXML] ========================================");
        Print("[E205][CFXML] CF XML Test Starting");

        CF_XML xml = new CF_XML();

        Print("[E205][CFXML] CF_XML object created");

        if (!xml.LoadFile("E205Lib/Config/Settings.xml"))
        {
            Print("[E205][CFXML] ERROR: Failed to load Settings.xml");
            return;
        }

        Print("[E205][CFXML] Settings.xml loaded successfully");

        CF_XMLNode root = xml.GetRoot();

        if (!root)
        {
            Print("[E205][CFXML] ERROR: XML root is null");
            return;
        }

        Print("[E205][CFXML] Root node obtained");

        CF_XMLNode messageNode = root.Find("TestMessage");

        if (!messageNode)
        {
            Print("[E205][CFXML] ERROR: TestMessage node not found");
            return;
        }

        Print("[E205][CFXML] TestMessage: " + messageNode.GetValue());

        Print("[E205][CFXML] ========================================");
        Print("[E205][CFXML] CF XML Test Complete");
        Print("[E205][CFXML] ========================================");
    }
};