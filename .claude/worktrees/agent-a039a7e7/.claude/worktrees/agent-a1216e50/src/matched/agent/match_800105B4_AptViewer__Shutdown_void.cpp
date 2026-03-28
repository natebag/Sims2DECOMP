extern "C" void closeFunc(void);

struct AptViewer {
    void Shutdown(void);
    void UnLoad(void);
};

void AptViewer::Shutdown(void)
{
    UnLoad();
    closeFunc();
}

