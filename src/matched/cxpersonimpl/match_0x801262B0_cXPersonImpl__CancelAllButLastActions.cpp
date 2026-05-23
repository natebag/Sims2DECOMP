// 0x801262B0 cXPersonImpl::CancelAllButLastActions (176B)
// Iterates action queue from count-1 down to 0. For each, dispatches:
//   * slot 0xE0/0xE4 on m_subPtr.vt — GetActionAtIndex(idx, 0) -> action
//   * slot 0xB8/0xBC on m_subPtr.vt — Cancel(action.field_0x38)
// Returns 0 if any cancel returns 0, else 1 when loop completes.
// Initial count obtained via slot 0xD8/0xDC on m_subPtr.vt with arg 0.

typedef int   (*FnCount)(void*, int);
typedef void* (*FnGetAction)(void*, int, int);
typedef int   (*FnOp)(void*, int);

struct cXPerson_CABLA {
    char* m_implPtr;   // 0x0
    char* m_subPtr;    // 0x4
    int CancelAllButLastActions();
};

int cXPerson_CABLA::CancelAllButLastActions() {
    char* sub0 = m_subPtr;
    char* vt0 = *(char**)(sub0 + 4);
    short adj0 = *(short*)(vt0 + 0xD8);
    FnCount count_fn = (FnCount)*(void**)(vt0 + 0xDC);
    int count = count_fn(sub0 + adj0, 0);

    int i = count - 1;
    while (i >= 0) {
        char* sub1 = m_subPtr;
        char* vt1 = *(char**)(sub1 + 4);
        FnGetAction get_fn = (FnGetAction)*(void**)(vt1 + 0xE4);
        short adj1 = *(short*)(vt1 + 0xE0);
        void* action = get_fn(sub1 + adj1, i, 0);

        char* sub2 = m_subPtr;
        int arg = *(int*)((char*)action + 0x38);
        char* vt2 = *(char**)(sub2 + 4);
        short adj2 = *(short*)(vt2 + 0xB8);
        FnOp op_fn = (FnOp)*(void**)(vt2 + 0xBC);
        if (op_fn(sub2 + adj2, arg) == 0) return 0;
        --i;
    }
    return 1;
}
