/* IFFBehaviorTree::LoadFromIndex(unsigned int, int) at 0x80227394 (32B) */
/* Simple thunk: prologue, call parent LoadFromIndex, epilogue */

extern int ResourceBehaviorTree_LoadFromIndex(void *self, unsigned int index, int param);

struct IFFBehaviorTree {
    int LoadFromIndex(unsigned int index, int param);
};

int IFFBehaviorTree::LoadFromIndex(unsigned int index, int param) {
    return ResourceBehaviorTree_LoadFromIndex(this, index, param);
}
