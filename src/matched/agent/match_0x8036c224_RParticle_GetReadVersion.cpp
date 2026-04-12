// 0x8036c224 RParticle_GetReadVersion (12b)

extern char gRParticle_readVer[12];
unsigned short RParticle_GetReadVersion() { return *(unsigned short *)gRParticle_readVer; }
