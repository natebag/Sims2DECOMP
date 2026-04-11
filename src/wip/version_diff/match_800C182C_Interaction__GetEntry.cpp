/* Interaction::GetEntry(void) const - 0x800C182C (112 bytes) */

typedef void *(*Method0)(void *);
typedef void *(*Method1)(void *, int);

struct MethodDesc0 {
    short delta;
    short pad;
    Method0 method;
};

struct MethodDesc1 {
    short delta;
    short pad;
    Method1 method;
};

struct Interaction {
    void *GetEntry(void) const;
};

void *Interaction::GetEntry(void) const {
    int *self;
    void *stackObject;
    int *vtable;
    void *treeTable;
    MethodDesc0 *desc0;
    MethodDesc1 *desc1;

    self = (int *)this;
    stackObject = (void *)self[3];
    if (stackObject == 0) {
        return 0;
    }
    vtable = *(int **)((char *)stackObject + 4);
    desc0 = (MethodDesc0 *)((char *)vtable + 864);
    treeTable = desc0->method((char *)stackObject + desc0->delta);
    vtable = *(int **)treeTable;
    desc1 = (MethodDesc1 *)((char *)vtable + 136);
    return desc1->method((char *)treeTable + desc1->delta, self[5]);
}
