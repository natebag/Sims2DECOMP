/* cSimulator::CreateInstance(void) at 0x801401E4 (40B) */

struct cSimulatorImpl_CI {
    char m_pad[384];
    static void* operator new(unsigned int size);
    cSimulatorImpl_CI();
};

struct cSimulator_CI {
    static cSimulatorImpl_CI* CreateInstance();
};

cSimulatorImpl_CI* cSimulator_CI::CreateInstance() {
    return new cSimulatorImpl_CI();
}
