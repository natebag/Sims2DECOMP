// 0x800579C0 EMemoryMeterWin::GetAffordable(ObjSelector *) (92B)

class ObjSelector;

class EMemoryMeterWin {
public:
    char _pad0[8];
    float m_threshold;

    void PollMemoryLevels();
    int GetAffordable(ObjSelector* sel);
};

extern char gv_AffordableLimit_block[16];

int EMemoryMeterWin::GetAffordable(ObjSelector* sel) {
    if (sel == 0) return 0;
    PollMemoryLevels();
    float v = m_threshold;
    if (v >= *(float*)gv_AffordableLimit_block) return 0;
    return 1;
}
