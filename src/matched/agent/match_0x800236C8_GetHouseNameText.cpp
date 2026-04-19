// 0x800236C8 (48B) GetHouseNameText(int)
// Clamp (r3-1) to [0,15] then index s_houseNames[idx].

extern "C" const char* s_houseNames[16];

const char* GetHouseNameText(int i) {
    int idx = i - 1;
    if (idx < 0) {
        idx = 0;
    } else if (idx > 15) {
        idx = 15;
    }
    return s_houseNames[idx];
}
