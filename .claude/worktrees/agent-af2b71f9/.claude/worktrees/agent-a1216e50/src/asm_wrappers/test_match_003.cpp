// Test: Match ACTTarget::IsActionQueueActive
// Target: 0x801A23BC (8 bytes)
// Expected PPC: lwz r3, 0xD0(r3); blr
// Expected bytes: 80 63 00 D0 4E 80 00 20

class ACTTarget {
public:
    char _pad[0xD0];
    int m_actionQueueActive;

    int IsActionQueueActive();
};

int ACTTarget::IsActionQueueActive() {
    return m_actionQueueActive;
}
