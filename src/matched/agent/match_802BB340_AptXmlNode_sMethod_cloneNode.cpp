// FLAGS: -fno-elide-constructors
// 0x802BB340 AptXmlNode::sMethod_cloneNode(AptValue*) (8B)

extern void* g_constructorObject;

struct AptXmlNode {
    static void* sMethod_cloneNode();
};

void* AptXmlNode::sMethod_cloneNode() {
    return g_constructorObject;
}
