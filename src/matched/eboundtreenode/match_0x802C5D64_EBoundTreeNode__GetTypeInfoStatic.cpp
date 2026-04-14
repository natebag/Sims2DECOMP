// 0x802C5D64 EBoundTreeNode::GetTypeInfoStatic (12B)
struct TypeInfo_EBoundTreeNode { char data[256]; };
extern TypeInfo_EBoundTreeNode g_EBoundTreeNode_TypeInfo[3];
TypeInfo_EBoundTreeNode* EBoundTreeNode_GetTypeInfoStatic() { return &g_EBoundTreeNode_TypeInfo[0]; }
