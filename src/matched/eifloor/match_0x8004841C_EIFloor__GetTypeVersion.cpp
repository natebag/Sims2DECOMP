// 0x8004841C EIFloor::GetTypeVersion (12B) const
struct VerBlock_EIFloor { unsigned short ver[256]; };
extern VerBlock_EIFloor g_EIFloor_TypeVersion[3];
struct EIFloor_GTV { unsigned short GetTypeVersion() const; };
unsigned short EIFloor_GTV::GetTypeVersion() const { return g_EIFloor_TypeVersion[0].ver[0]; }
