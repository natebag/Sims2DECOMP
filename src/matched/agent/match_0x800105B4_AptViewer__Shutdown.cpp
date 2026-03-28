/* AptViewer::Shutdown(void) at 0x800105B4 (36B) */

void SaveInputHistory(void);
void closeFunc(void);

void AptViewer_Shutdown(void) {
    SaveInputHistory();
    closeFunc();
}
