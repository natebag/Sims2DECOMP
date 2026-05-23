// 0x80104E58 PresetHouseGameStatus(void) (104B)
//
// objectsim TU free function. Initializes the 16-entry g_houseGameStatus
// table (12B-stride entries at 0x804864D0). Each entry has three int fields:
//   field0: 1 if i == 0 OR i in [13,16]; else 0
//   field4: 15 (constant)
//   field8:  0 (constant)
//
// The compiler emits the i-in-[13,16] check as an unsigned-trick range
// (`(unsigned)(i - 13) <= 3`) and pre-hoists base+4 / base+8 pointer
// constants so the loop body uses three stores via stw + 2×stwx.

struct HouseGameStatusEntry {
    int field0;
    int field4;
    int field8;
};

extern HouseGameStatusEntry g_houseGameStatus[];

void PresetHouseGameStatus() {
    for (int i = 0; i < 16; i++) {
        if (i == 0 || (unsigned)(i - 13) <= 3) {
            g_houseGameStatus[i].field0 = 1;
        } else {
            g_houseGameStatus[i].field0 = 0;
        }
        g_houseGameStatus[i].field4 = 15;
        g_houseGameStatus[i].field8 = 0;
    }
}
