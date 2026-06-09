/* ECheats::ReadCheatsFile(void) at 0x80020CB0 (20B) */

struct ECheats {
    char pad_00[0x104];
    int m_cheatsLoaded;

    void ReadCheatsFile(void);
};

void ECheats::ReadCheatsFile(void) {
    char buffer[0x2D8];
    m_cheatsLoaded = 1;
}
