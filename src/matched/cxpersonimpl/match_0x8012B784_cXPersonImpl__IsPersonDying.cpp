// 0x8012B784 cXPersonImpl::IsPersonDying(void) (128B)

extern int TreeStack_GetStackSize(int*);
extern void* TreeStack_GetElem(int*, int);
extern int StackElem_GetTreeID(void*);

struct cXPersonImpl_IPD {
    int** m_treeStackPtr;
    char pad[152];
    unsigned short m_flags;
};

int cXPersonImpl_IsPersonDying(cXPersonImpl_IPD* self) {
    int count = TreeStack_GetStackSize(*self->m_treeStackPtr + 3);
    for (int i = count - 1; i >= 0; i--) {
        void* elem = TreeStack_GetElem(*self->m_treeStackPtr + 3, i);
        int treeID = StackElem_GetTreeID(elem);
        if (treeID == 393) {
            self->m_flags |= 4;
            return 1;
        }
    }
    return 0;
}
