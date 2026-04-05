extern int IsBoundTreeNode_impl(void*, void*);
extern char gBoundTreeNodeTypeInfo[];

int EBoundTreeNode__IsBoundTreeNode(void* obj) {
    return IsBoundTreeNode_impl(obj, gBoundTreeNodeTypeInfo);
}
