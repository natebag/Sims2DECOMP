// 0x800226A0 (8 bytes) — lwz r3, 0x2C(r3); blr

class EDummyFile {
public:
    char _pad[0x2C];
    int m_position;

    int Tell() const;
};

int EDummyFile::Tell() const {
    return m_position;
}
