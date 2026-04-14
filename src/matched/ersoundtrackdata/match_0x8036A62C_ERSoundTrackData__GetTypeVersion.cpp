// 0x8036A62C ERSoundTrackData::GetTypeVersion (12B) const
struct VerBlock_ERSoundTrackData { unsigned short ver[256]; };
extern VerBlock_ERSoundTrackData g_ERSoundTrackData_TypeVersion[3];
struct ERSoundTrackData_GTV { unsigned short GetTypeVersion() const; };
unsigned short ERSoundTrackData_GTV::GetTypeVersion() const { return g_ERSoundTrackData_TypeVersion[0].ver[0]; }
