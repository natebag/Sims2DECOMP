// 0x80369F30 ERSoundEvent::GetTypeInfo (12B) const
struct TypeInfo_ERSoundEvent { char data[256]; };
extern TypeInfo_ERSoundEvent g_ERSoundEvent_TypeInfo[3];
struct ERSoundEvent_GTI { TypeInfo_ERSoundEvent* GetTypeInfo() const; };
TypeInfo_ERSoundEvent* ERSoundEvent_GTI::GetTypeInfo() const { return &g_ERSoundEvent_TypeInfo[0]; }
