// 0x801415E4 (16 bytes) - cSimulatorImpl::SetGlobal(short, short)
// rlwinm r4,r4,1,0,30; addi r3,r3,20; sthx r5,r3,r4; blr
// Array store: this->globals[index] = value

struct cSimulatorImpl_SG {
    char pad[0x14];
    short m_globals[1];

    void SetGlobal(short index, short value);
};

void cSimulatorImpl_SG::SetGlobal(short index, short value) {
    m_globals[index] = value;
}
