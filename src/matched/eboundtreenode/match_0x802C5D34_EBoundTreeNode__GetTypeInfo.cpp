// 0x802C5D34 EBoundTreeNode::GetTypeInfo (12B) const
struct TypeInfo_EBoundTreeNode { char data[256]; };
extern TypeInfo_EBoundTreeNode g_EBoundTreeNode_TypeInfo[3];
struct EBoundTreeNode_GTI { TypeInfo_EBoundTreeNode* GetTypeInfo() const; };
TypeInfo_EBoundTreeNode* EBoundTreeNode_GTI::GetTypeInfo() const { return &g_EBoundTreeNode_TypeInfo[0]; }
