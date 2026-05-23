// 0x8014AB00 WantFear::Node::GetEvent (44b)

struct Node {
    short pad;
    unsigned short id;
};

extern int g_eventDB[];
extern void* LookupEvent(void*, unsigned int);

void* WantFear_Node_GetEvent(Node* self) {
    unsigned int id = self->id;
    void* db = *(void**)((char*)g_eventDB + 0);
    return LookupEvent(db, id);
}
