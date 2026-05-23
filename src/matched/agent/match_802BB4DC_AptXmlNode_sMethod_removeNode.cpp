// FLAGS: -fno-elide-constructors
// 0x802BB4DC AptXmlNode::sMethod_removeNode(AptValue*) (8B)

extern void* g_constructorObject;

struct AptXmlNode {
    static void* sMethod_removeNode();
};

void* AptXmlNode::sMethod_removeNode() {
    return g_constructorObject;
}
