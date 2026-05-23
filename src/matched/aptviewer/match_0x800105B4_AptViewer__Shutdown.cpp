void AptViewer_UnLoad(void* self);
void closeFunc();

void AptViewer_Shutdown(void* self) {
    AptViewer_UnLoad(self);
    closeFunc();
}
