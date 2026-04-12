// 0x8036c20c RParticle_GetTypeVersion (12b)

extern char gRParticle_typeVer[12];
unsigned short RParticle_GetTypeVersion() { return *(unsigned short *)gRParticle_typeVer; }
