// 0x800D93CC (8B) NghResFile::GetSourceType(void) const
// Getter for field at offset 0x20.

class NghResFile {
public:
    char pad_000[0x20];
    int m_field_20;
    int GetSourceType(void) const;
};

int NghResFile::GetSourceType(void) const {
    return m_field_20;
}
