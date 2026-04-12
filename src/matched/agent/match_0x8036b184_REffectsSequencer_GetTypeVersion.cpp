// 0x8036b184 REffectsSequencer_GetTypeVersion (12b)

extern char gREffectsSequencer_typeVer[12];
unsigned short REffectsSequencer_GetTypeVersion() { return *(unsigned short *)gREffectsSequencer_typeVer; }
