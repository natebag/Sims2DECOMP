// 0x8023A6D0 _ParseLevel (92b)

extern int _ParseNumChildNodes(unsigned char*);
extern void* __nw__FUl(unsigned long);
extern void _ParseChildNodes(void**, int, unsigned char*);

struct CDirtyXmlNode {
    char pad[16];
    int numChildren;
    char pad2[8];
    void** children;
};

void _ParseLevel(CDirtyXmlNode* node, unsigned char* data) {
    int count = _ParseNumChildNodes(data);
    node->numChildren = count;
    if (count > 0) {
        void** arr = (void**)__nw__FUl((unsigned long)count * 4);
        node->children = arr;
        _ParseChildNodes(arr, node->numChildren, data);
    }
}
