// 0x8014020C cSimulator::DestroyInstance (64B)

struct cSimulator {
    virtual ~cSimulator();
    static void DestroyInstance(cSimulator *p);
};

void cSimulator::DestroyInstance(cSimulator *p) {
    if (p) {
        delete p;
    }
}
