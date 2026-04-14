// 0x8030FBDC EREdithTreeSet::GetReadVersion (12B)
struct RVBlock_EREdithTreeSet { unsigned short ver[256]; };
extern RVBlock_EREdithTreeSet g_EREdithTreeSet_ReadVersion[3];
struct EREdithTreeSet_GRV { unsigned short GetReadVersion(); };
unsigned short EREdithTreeSet_GRV::GetReadVersion() { return g_EREdithTreeSet_ReadVersion[0].ver[0]; }
