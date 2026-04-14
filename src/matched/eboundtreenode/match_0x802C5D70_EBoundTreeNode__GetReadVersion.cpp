// 0x802C5D70 EBoundTreeNode::GetReadVersion (12B)
struct RVBlock_EBoundTreeNode { unsigned short ver[256]; };
extern RVBlock_EBoundTreeNode g_EBoundTreeNode_ReadVersion[3];
struct EBoundTreeNode_GRV { unsigned short GetReadVersion(); };
unsigned short EBoundTreeNode_GRV::GetReadVersion() { return g_EBoundTreeNode_ReadVersion[0].ver[0]; }
