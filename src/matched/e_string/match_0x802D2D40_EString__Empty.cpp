/* EString::Empty(void) @ 0x802D2D40 (56 bytes) */
/* Canonical class layout from include/types/EString.h — inline copy for verify_match.sh compatibility */

class EString {
public:
    char* m_buffer;

    void Deallocate(char* buf);
    void SetToNull(void);
    void Empty(void);
};

void EString::Empty(void) {
    Deallocate(m_buffer);
    SetToNull();
}
