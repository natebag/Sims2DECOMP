class cSimulator {
public:
    virtual void dtor(int);

    static void DestroyInstance(cSimulator *pSim);
};

void cSimulator::DestroyInstance(cSimulator *pSim) {
    if (pSim != 0) {
        pSim->dtor(3);
    }
}
