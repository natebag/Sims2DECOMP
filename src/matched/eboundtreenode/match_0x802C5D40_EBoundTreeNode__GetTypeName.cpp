// 0x802C5D40 EBoundTreeNode::GetTypeName (12B) const
extern char* g_EBoundTreeNode_TypeName[3];
struct EBoundTreeNode_GTN { const char* GetTypeName() const; };
const char* EBoundTreeNode_GTN::GetTypeName() const { return g_EBoundTreeNode_TypeName[0]; }
