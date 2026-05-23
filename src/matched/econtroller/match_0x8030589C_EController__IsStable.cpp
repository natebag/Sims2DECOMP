/* EController::IsStable(void) - 0x8030589C (12 bytes) */

struct EController {
    char pad[4];
    int m_flags;
    int IsStable();
};

int EController::IsStable() {
    return (m_flags >> 1) & 1;
}
