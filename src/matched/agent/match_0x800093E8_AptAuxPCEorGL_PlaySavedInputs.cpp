// FLAGS: -msdata=eabi -G 8
// 0x800093E8 AptAuxPCEorGL_PlaySavedInputs (56b)
extern int loadFileSize(void*, int*);
extern int g_fileResult;
extern int g_fileBuf;
extern int g_fileParam;

void PlaySavedInputs(void* filename, int param) {
    g_fileResult = loadFileSize(filename, &g_fileBuf);
    g_fileParam = param;
}
