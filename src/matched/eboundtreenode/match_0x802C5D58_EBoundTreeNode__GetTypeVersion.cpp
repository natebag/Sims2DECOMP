// 0x802C5D58 EBoundTreeNode::GetTypeVersion (12B) const
struct VerBlock_EBoundTreeNode { unsigned short ver[256]; };
extern VerBlock_EBoundTreeNode g_EBoundTreeNode_TypeVersion[3];
struct EBoundTreeNode_GTV { unsigned short GetTypeVersion() const; };
unsigned short EBoundTreeNode_GTV::GetTypeVersion() const { return g_EBoundTreeNode_TypeVersion[0].ver[0]; }
