// 0x8036A614 ERSoundTrackData::GetTypeName (12B) const
extern char* g_ERSoundTrackData_TypeName[3];
struct ERSoundTrackData_GTN { const char* GetTypeName() const; };
const char* ERSoundTrackData_GTN::GetTypeName() const { return g_ERSoundTrackData_TypeName[0]; }
