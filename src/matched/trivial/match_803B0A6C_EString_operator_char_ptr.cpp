// 0x803B0A6C (8 bytes)
// EString::operator char*(void) const
class EString {
    char* m_buffer;
public:
    operator char*() const;
};

EString::operator char*() const {
    return m_buffer;
}
