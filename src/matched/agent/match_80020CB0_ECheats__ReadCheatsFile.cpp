/* ECheats::ReadCheatsFile(void) at 0x80020CB0 (20B) */

struct ECheats {
    char pad[0x104];
    int m_cheatsEnabled;
    void ReadCheatsFile();
};

void ECheats::ReadCheatsFile() {
    char buf[728];
    m_cheatsEnabled = 1;
}
