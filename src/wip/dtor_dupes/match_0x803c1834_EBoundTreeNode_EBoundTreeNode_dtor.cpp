extern int VT_EBoundTreeNode_EBoundTreeNode[];
void del_EBoundTreeNode_EBoundTreeNode(void *);
void dtor_EBoundTreeNode_EBoundTreeNode(char *self, int __in_chrg) {
    *(int **)self = VT_EBoundTreeNode_EBoundTreeNode;
    if (__in_chrg & 1) {
        del_EBoundTreeNode_EBoundTreeNode(self);
    }
}
