typedef void *CamDir;

CamDir GetCameraDirectorA();
void SetCameraDirectorPlayerB(CamDir dir, int player, int val);
void ShutdownInteractorManagerA();
void ShutdownInteractorManagerB();

void ShutdownInteractorModule() {
    CamDir d;
    d = GetCameraDirectorA();
    SetCameraDirectorPlayerB(d, 0, 0);
    d = GetCameraDirectorA();
    SetCameraDirectorPlayerB(d, 1, 0);
    ShutdownInteractorManagerA();
    ShutdownInteractorManagerB();
}
