// 0x80022694 (12 bytes) — stw r4, 0x2C(r3); mr r3, r4; blr
// Stores position and returns it

class EDummyFile {
public:
    char _pad[0x2C];
    int m_position;

    int Seek(int pos, int seekType);
};

int EDummyFile::Seek(int pos, int seekType) {
    m_position = pos;
    return pos;
}
