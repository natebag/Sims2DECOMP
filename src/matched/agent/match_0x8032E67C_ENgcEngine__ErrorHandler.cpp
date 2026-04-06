// 0x8032E67C ENgcEngine::ErrorHandler (40b)

extern char g_errorFlag[4];
extern void HandleError(void);

void ENgcEngine_ErrorHandler(unsigned short, void*, unsigned int, unsigned int) {
    *(int*)g_errorFlag = 1;
    HandleError();
}
