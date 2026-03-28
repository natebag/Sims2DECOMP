// 0x8003535C (8 bytes) — lwz r3, 0x3EC(r3); blr

class ESim {
public:
    char _pad[0x3EC];
    unsigned int m_plumbBobState;

    unsigned int GetPlumbBobState();
};

unsigned int ESim::GetPlumbBobState() {
    return m_plumbBobState;
}
