// FLAGS: -msdata=eabi -G 8
// 0x8026B76C (16B) AptDebugEnableSavedInputs(int)

extern int g_aptDebugSavedInputs;
extern int g_aptDebugInputMode;

void AptDebugEnableSavedInputs(int val) {
    g_aptDebugSavedInputs = val;
    g_aptDebugInputMode = 0;
}
