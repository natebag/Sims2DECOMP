extern "C" void InitPerformanceCounter(void);

struct ESimsApp {
    void LoadSimulatorGlobs(void);
};

void ESimsApp::LoadSimulatorGlobs(void)
{
    InitPerformanceCounter();
}

