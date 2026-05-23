/* EString::Empty(void) @ 0x802D2D40 (56 bytes) */

struct EString_E {
    char* m_buffer;
    void Deallocate(char* buf);
    void SetToNull();
    void Empty();
};

void EString_E::Empty() {
    Deallocate(m_buffer);
    SetToNull();
}
