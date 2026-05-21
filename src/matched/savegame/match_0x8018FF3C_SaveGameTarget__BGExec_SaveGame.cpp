// 0x8018FF3C SaveGameTarget::BGExec_SaveGame(void*) (80B)

class SimsMemCardWrap {
public:
    static int SaveGame(int slot, bool a, bool b, int magic);
};

extern int g_saveFlag;  // SDA -21480

class SaveGameTarget {
public:
    char pad_000[296];
    int  m_slot;        // 296
    char pad_124[16];
    int  m_result;      // 316
};

void BGExec_SaveGame(SaveGameTarget* self);

void BGExec_SaveGame(SaveGameTarget* self) {
    if (self != 0) {
        self->m_result = SimsMemCardWrap::SaveGame(self->m_slot, true, false, 0xABCDEF);
    }
    g_saveFlag = 1;
}
