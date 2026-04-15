// GetMotiveConstantsClient(void) at 0x800C2008 (8B) — SDA address getter

class MotiveConstantsClient;
extern int g_motiveConstantsClient;  // SDA-accessible (within -G 8 threshold)

MotiveConstantsClient* GetMotiveConstantsClient() {
    return (MotiveConstantsClient*)&g_motiveConstantsClient;
}
