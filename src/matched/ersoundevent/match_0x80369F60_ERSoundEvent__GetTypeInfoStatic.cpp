// 0x80369F60 ERSoundEvent::GetTypeInfoStatic (12B)
struct TypeInfo_ERSoundEvent { char data[256]; };
extern TypeInfo_ERSoundEvent g_ERSoundEvent_TypeInfo[3];
TypeInfo_ERSoundEvent* ERSoundEvent_GetTypeInfoStatic() { return &g_ERSoundEvent_TypeInfo[0]; }
