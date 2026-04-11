// AptViewer::IsWaitingForPlayerInput(void)
// Address: 0x80011E2C | Size: 44 bytes
// FLAGS: -fno-elide-constructors

struct AptViewer {
    char pad[0x350];
    void* m_field350;
    char pad2[0x3A4 - 0x350 - 4];
    void* m_field3A4;
};

int AptViewer__IsWaitingForPlayerInput(AptViewer* self) {
    if (self->m_field350 == 0) return 0;
    if (self->m_field3A4 == 0) return 0;
    return 1;
}
