// 0x803C2F10 (8 bytes)
// EString2::operator unsigned wchar_t*(void) const
class EString2 {
    void* m_buffer;
public:
    operator void*() const;
};

EString2::operator void*() const {
    return m_buffer;
}
