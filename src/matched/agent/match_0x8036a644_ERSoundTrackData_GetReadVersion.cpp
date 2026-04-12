// 0x8036a644 ERSoundTrackData_GetReadVersion (12b)

extern char gERSoundTrackData_readVer[12];
unsigned short ERSoundTrackData_GetReadVersion() { return *(unsigned short *)gERSoundTrackData_readVer; }
