// 0x8036A638 ERSoundTrackData::GetTypeInfoStatic (12B)
struct TypeInfo_ERSoundTrackData { char data[256]; };
extern TypeInfo_ERSoundTrackData g_ERSoundTrackData_TypeInfo[3];
TypeInfo_ERSoundTrackData* ERSoundTrackData_GetTypeInfoStatic() { return &g_ERSoundTrackData_TypeInfo[0]; }
