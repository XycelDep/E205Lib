class E205_Config
{
    static bool Load()
    {
         Print("[E205][CONFIG] ========================================");
        Print("[E205][CONFIG] Loading configuration");

        CF_XML_Document document;

        if (!CF_XML.ReadDocument("E205Lib/Config/Settings.xml", document))
        {
            Print("[E205][CONFIG] ERROR: Failed to read configuration");
            return false;
        }

        Print("[E205][CONFIG] XML document read successfully");

        array<CF_XML_Tag> settings;
        settings = document.Get("E205_Settings");

        if (settings.Count() == 0)
        {
            Print("[E205][CONFIG] ERROR: E205_Settings root not found");
            return false;
        }

        Print("[E205][CONFIG] E205_Settings root found");

        array<CF_XML_Tag> messages;
        messages = settings[0].GetTag("TestMessage");

        if (messages.Count() == 0)
        {
            Print("[E205][CONFIG] ERROR: TestMessage not found");
            return false;
        }

        string message;
        message = messages[0].GetContent().GetContent();

        Print("[E205][CONFIG] TestMessage: " + message);
        Print("[E205][CONFIG] Configuration loaded successfully");
        Print("[E205][CONFIG] ========================================");

        return true;
    }
}