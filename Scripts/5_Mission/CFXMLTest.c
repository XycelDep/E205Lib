class CFXMLTest
{
    static void Test()
    {
        Print("[E205][CFXML] ========================================");
        Print("[E205][CFXML] CF XML Test Starting");

        CF_XML_Reader reader = CF_XML.Open("E205Lib/Config/Settings.xml");

        if (!reader)
        {
            Print("[E205][CFXML] ERROR: Failed to open Settings.xml");
            return;
        }

        Print("[E205][CFXML] Settings.xml opened successfully");
        Print("[E205][CFXML] Reader returned successfully");

        Print("[E205][CFXML] ========================================");
        Print("[E205][CFXML] CF XML Test Complete");
        Print("[E205][CFXML] ========================================");
    }
};