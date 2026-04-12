// 0x8036ac6c REffectsEmitter_GetReadVersion (12b)

extern char gREffectsEmitter_readVer[12];
unsigned short REffectsEmitter_GetReadVersion() { return *(unsigned short *)gREffectsEmitter_readVer; }
