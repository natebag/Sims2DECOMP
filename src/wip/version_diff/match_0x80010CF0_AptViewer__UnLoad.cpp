struct AptViewer {
    char pad[0x350];
    int m_loaded;
};

void AptPrintfMsg(char* a, char* b);
void SleepFunc(int frames);

extern char gUnloadMsgA[];
extern char gUnloadMsgB[];

void AptViewer_UnLoad(AptViewer* self) {
    if (self->m_loaded != 0) {
        AptPrintfMsg(gUnloadMsgA, gUnloadMsgB);
        SleepFunc(500);
        SleepFunc(500);
        SleepFunc(500);
        SleepFunc(500);
        SleepFunc(500);
        self->m_loaded = 0;
    }
}
