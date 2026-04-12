// 0x8015A990 ObjectDataBehaviorTree_ObjectDataBehaviorTree_dtor52 (52b)
// FLAGS: -fno-schedule-insns
extern int VT[];
void del_fn(void *);
void d_ObjectDataBehaviorTree_ObjectDataBehaviorTree(char *self, int __in_chrg) {
    *(int **)self = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
