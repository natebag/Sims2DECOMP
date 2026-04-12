// 0x8036a62c ERSoundTrackData_GetTypeVersion (12b)

extern char gERSoundTrackData_typeVer[12];
unsigned short ERSoundTrackData_GetTypeVersion() { return *(unsigned short *)gERSoundTrackData_typeVer; }
