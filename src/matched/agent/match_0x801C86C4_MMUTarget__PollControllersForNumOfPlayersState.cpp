// 0x801C86C4 MMUTarget::PollControllersForNumOfPlayersState() (92B)

class UIObjectBase {
public:
    static void AptViewer_CallFunction(char* name, char* arg1, char* arg2, int p3, char** p4);
};

extern char g_str_checkForTwoPlayer[16];

class MMUTarget {
public:
    char pad[0x100];
    int m_100;
    int GetNumberOfControllers();
    void PollControllersForNumOfPlayersState();
};

void MMUTarget::PollControllersForNumOfPlayersState() {
    int n = GetNumberOfControllers();
    if (m_100 != n) {
        m_100 = n;
        UIObjectBase::AptViewer_CallFunction(g_str_checkForTwoPlayer, 0, 0, 0, 0);
    }
}
