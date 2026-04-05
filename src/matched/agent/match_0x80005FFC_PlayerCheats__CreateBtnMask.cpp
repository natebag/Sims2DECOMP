// PlayerCheats::CreateBtnMask(void) — 40B @ 0x80005FFC
// FLAGS: -fno-elide-constructors

class PlayerCheats {
public:
    int CreateBtnMask(void);
private:
    char pad[0x1C];
    unsigned short field_0x1C[6];
};

int PlayerCheats::CreateBtnMask(void) {
    unsigned int mask = 0;
    unsigned short *ptr = field_0x1C;
    for (int i = 0; i < 6; i++) {
        mask |= ptr[i];
    }
    return (int)mask;
}
