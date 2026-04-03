extern int VT_ObjectDataBehaviorTree_ObjectDataBehaviorTree[];
void del_ObjectDataBehaviorTree_ObjectDataBehaviorTree(void *);
void dtor_ObjectDataBehaviorTree_ObjectDataBehaviorTree(char *self, int __in_chrg) {
    *(int **)self = VT_ObjectDataBehaviorTree_ObjectDataBehaviorTree;
    if (__in_chrg & 1) {
        del_ObjectDataBehaviorTree_ObjectDataBehaviorTree(self);
    }
}
