// 0x8036ac54 REffectsEmitter_GetTypeVersion (12b)

extern char gREffectsEmitter_typeVer[12];
unsigned short REffectsEmitter_GetTypeVersion() { return *(unsigned short *)gREffectsEmitter_typeVer; }
