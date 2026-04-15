// FLAGS: -fno-schedule-insns
// 0x801CEA60 O2TTarget::SaveGame(char*, char*) (20B)

struct O2TTarget {
    char pad[144];
    int m_field144;   // +144
    char pad2[444];
    int m_field592;   // +592
    void SaveGame(char* a, char* b);
};

void O2TTarget::SaveGame(char*, char*) {
    m_field592 = 0;
    m_field144 = 1;
}
