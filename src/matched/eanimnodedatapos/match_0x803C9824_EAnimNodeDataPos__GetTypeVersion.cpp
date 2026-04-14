// 0x803C9824 EAnimNodeDataPos::GetTypeVersion (12B) const
struct VerBlock_EAnimNodeDataPos { unsigned short ver[256]; };
extern VerBlock_EAnimNodeDataPos g_EAnimNodeDataPos_TypeVersion[3];
struct EAnimNodeDataPos_GTV { unsigned short GetTypeVersion() const; };
unsigned short EAnimNodeDataPos_GTV::GetTypeVersion() const { return g_EAnimNodeDataPos_TypeVersion[0].ver[0]; }
