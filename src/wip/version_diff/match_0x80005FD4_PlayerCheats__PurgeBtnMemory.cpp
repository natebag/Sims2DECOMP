// PlayerCheats::PurgeBtnMemory(void) — 40B @ 0x80005FD4

class PlayerCheats {
public:
    void PurgeBtnMemory(void);
private:
    char pad[0x14];
    int field_0x14;
    int field_0x18;
    short field_0x1C[6];
};

void PlayerCheats::PurgeBtnMemory(void) {
    int zero = 0;
    int count = 6;
    field_0x14 = zero;
    field_0x18 = zero;
    short *p = (short*)((char*)this + 0x26);
    do {
        *p = zero;
        p--;
        count--;
    } while (count != 0);
}
