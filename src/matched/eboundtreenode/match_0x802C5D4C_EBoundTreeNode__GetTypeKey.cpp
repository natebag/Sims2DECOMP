// 0x802C5D4C EBoundTreeNode::GetTypeKey (12B) const
extern int g_EBoundTreeNode_TypeKey[3];
struct EBoundTreeNode_GTK { int GetTypeKey() const; };
int EBoundTreeNode_GTK::GetTypeKey() const { return g_EBoundTreeNode_TypeKey[0]; }
