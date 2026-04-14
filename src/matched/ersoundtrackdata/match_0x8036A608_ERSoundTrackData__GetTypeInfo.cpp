// 0x8036A608 ERSoundTrackData::GetTypeInfo (12B) const
struct TypeInfo_ERSoundTrackData { char data[256]; };
extern TypeInfo_ERSoundTrackData g_ERSoundTrackData_TypeInfo[3];
struct ERSoundTrackData_GTI { TypeInfo_ERSoundTrackData* GetTypeInfo() const; };
TypeInfo_ERSoundTrackData* ERSoundTrackData_GTI::GetTypeInfo() const { return &g_ERSoundTrackData_TypeInfo[0]; }
