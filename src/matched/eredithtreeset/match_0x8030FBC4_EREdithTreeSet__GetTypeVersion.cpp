// 0x8030FBC4 EREdithTreeSet::GetTypeVersion (12B) const
struct VerBlock_EREdithTreeSet { unsigned short ver[256]; };
extern VerBlock_EREdithTreeSet g_EREdithTreeSet_TypeVersion[3];
struct EREdithTreeSet_GTV { unsigned short GetTypeVersion() const; };
unsigned short EREdithTreeSet_GTV::GetTypeVersion() const { return g_EREdithTreeSet_TypeVersion[0].ver[0]; }
