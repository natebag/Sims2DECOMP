// 0x8023A72C _Parse (116b)

struct CDirtyXmlNode {
    char pad0[4];
    unsigned char* data;
    char pad1[4];
    CDirtyXmlNode* parent;
    int numChildren;
    char pad2[8];
    CDirtyXmlNode** children;
};

extern void _ParseLevel(CDirtyXmlNode*, unsigned char*);

void _Parse(CDirtyXmlNode* parentNode, CDirtyXmlNode* node, unsigned char* data) {
    node->parent = parentNode;
    _ParseLevel(node, data);
    int i = 0;
    if (i < node->numChildren) {
        do {
            CDirtyXmlNode* child = node->children[i];
            i++;
            _Parse(node, child, child->data);
        } while (i < node->numChildren);
    }
}
