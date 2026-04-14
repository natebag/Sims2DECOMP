// 0x80369F3C ERSoundEvent::GetTypeName (12B) const
extern char* g_ERSoundEvent_TypeName[3];
struct ERSoundEvent_GTN { const char* GetTypeName() const; };
const char* ERSoundEvent_GTN::GetTypeName() const { return g_ERSoundEvent_TypeName[0]; }
