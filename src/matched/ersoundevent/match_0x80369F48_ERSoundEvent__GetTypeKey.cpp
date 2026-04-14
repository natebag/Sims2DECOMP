// 0x80369F48 ERSoundEvent::GetTypeKey (12B) const
extern int g_ERSoundEvent_TypeKey[3];
struct ERSoundEvent_GTK { int GetTypeKey() const; };
int ERSoundEvent_GTK::GetTypeKey() const { return g_ERSoundEvent_TypeKey[0]; }
