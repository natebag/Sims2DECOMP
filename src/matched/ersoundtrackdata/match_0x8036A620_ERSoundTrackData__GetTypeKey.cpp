// 0x8036A620 ERSoundTrackData::GetTypeKey (12B) const
extern int g_ERSoundTrackData_TypeKey[3];
struct ERSoundTrackData_GTK { int GetTypeKey() const; };
int ERSoundTrackData_GTK::GetTypeKey() const { return g_ERSoundTrackData_TypeKey[0]; }
