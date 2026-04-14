// 0x8036A644 ERSoundTrackData::GetReadVersion (12B)
struct RVBlock_ERSoundTrackData { unsigned short ver[256]; };
extern RVBlock_ERSoundTrackData g_ERSoundTrackData_ReadVersion[3];
struct ERSoundTrackData_GRV { unsigned short GetReadVersion(); };
unsigned short ERSoundTrackData_GRV::GetReadVersion() { return g_ERSoundTrackData_ReadVersion[0].ver[0]; }
