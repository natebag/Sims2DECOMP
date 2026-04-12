// 0x803c9824 EAnimNodeDataPos_GetTypeVersion (12b)

extern char gEAnimNodeDataPos_typeVer[12];
unsigned short EAnimNodeDataPos_GetTypeVersion() { return *(unsigned short *)gEAnimNodeDataPos_typeVer; }
