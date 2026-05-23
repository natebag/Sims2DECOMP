// 0x802C5DF0 EBoundTreeNode::IsBoundTreeNode(EStorable *) (40 B)
// PRAGMA_STUB: EBoundTreeNode::IsBoundTreeNode(EStorable *)
extern int IsBoundTreeNode_impl(void*, void*);
extern char gBoundTreeNodeTypeInfo[];

int EBoundTreeNode__IsBoundTreeNode(void* obj) {
    return IsBoundTreeNode_impl(obj, gBoundTreeNodeTypeInfo);
}
