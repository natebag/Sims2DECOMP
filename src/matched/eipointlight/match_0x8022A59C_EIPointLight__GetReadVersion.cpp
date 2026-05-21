// 0x8022A59C EIPointLight::GetReadVersion(void) (12B)
struct VerBlock_EIPL { unsigned short ver[256]; };
extern VerBlock_EIPL g_EIPointLight_ReadVersion[3];
unsigned short EIPointLight_GetReadVersion() { return g_EIPointLight_ReadVersion[0].ver[0]; }
