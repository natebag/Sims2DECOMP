extern "C" void AptAuxPCEorGL_Shutdown(void);
extern "C" void _freeFontTable(void);
extern "C" void AptShutdown(int);

void closeFunc(void)
{
    AptAuxPCEorGL_Shutdown();
    _freeFontTable();
    AptShutdown(0);
}

