// 0x803c1444 EStorable_GetTypeVersion (12b)

extern char gEStorable_typeVer[12];
unsigned short EStorable_GetTypeVersion() { return *(unsigned short *)gEStorable_typeVer; }
