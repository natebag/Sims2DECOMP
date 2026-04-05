// AptViewer::IsWaitingForPlayerInput(void)
// Address: 0x80011E2C | Size: 44 bytes
// FLAGS: -fno-elide-constructors

struct AptViewer {
    char pad[0x350];
    void* m_field350;
    char pad2[0x3A4 - 0x350 - 4];
    void* m_field3A4;
    
    int IsWaitingForPlayerInput();
};

int AptViewer::IsWaitingForPlayerInput() {
    if (m_field350 == 0) goto fail;
    {
        register int result = 0;
        if (m_field3A4 == 0) return result;
        return 1;
    }
fail:
    return 0;
}
