// 0x8036b19c REffectsSequencer_GetReadVersion (12b)

extern char gREffectsSequencer_readVer[12];
unsigned short REffectsSequencer_GetReadVersion() { return *(unsigned short *)gREffectsSequencer_readVer; }
