// 0x8013F268 LogInteraction::PrintHeader() (64B)

class CTGDump {
public:
    CTGDump& operator<<(char* s);
};

extern CTGDump g_logDump;
extern char fmt_header_a[];
extern char fmt_header_b[];

class LogInteractionSample {
public:
    static void PrintHeader();
};

class LogInteraction {
public:
    static void PrintHeader();
};

void LogInteraction::PrintHeader() {
    g_logDump << fmt_header_a;
    g_logDump << fmt_header_b;
    LogInteractionSample::PrintHeader();
}
