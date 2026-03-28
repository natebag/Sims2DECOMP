/* O2TTarget::OnSaveGameComplete - 0x801CEA74 - 76 bytes */

extern void SomeUIFunc(const char *, int, int, int, int);

struct O2TTarget {
    char pad[0x90];
    int m_saveGameStatus;
    void OnSaveGameComplete(int success);
};

extern const char kOnSaveGameStr[];

void O2TTarget::OnSaveGameComplete(int success)
{
    SomeUIFunc(kOnSaveGameStr, 0, 0, 0, 0);
    m_saveGameStatus = 0;
}
