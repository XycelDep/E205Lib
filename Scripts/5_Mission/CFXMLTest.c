class CFXMLTest
{
    static void Test()
    {
        Print("[E205][XML] ========================================");
        Print("[E205][XML] Testing CF XML");

        CF_XML_Document document;

        if (!CF_XML.ReadDocument("E205Lib/Config/Settings.xml", document))
        {
            Print("[E205][XML] ERROR: Failed to read document");
            return;
        }

        Print("[E205][XML] Document loaded successfully");

        array<CF_XML_Tag> settings;
        settings = document.Get("E205_Settings");

        Print("[E205][XML] Settings tags found: " + settings.Count());

        if (settings.Count() > 0)
        {
            array<CF_XML_Tag> messages;
            messages = settings[0].GetTag("TestMessage");

            Print("[E205][XML] TestMessage tags found: " + messages.Count());

            if (messages.Count() > 0)
            {
                string message;
                message = messages[0].GetContent().GetContent();

                Print("[E205][XML] Message: " + message);
            }
        }

        Print("[E205][XML] ========================================");
    }
};