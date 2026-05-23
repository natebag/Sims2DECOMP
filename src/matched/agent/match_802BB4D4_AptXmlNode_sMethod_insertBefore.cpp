// FLAGS: -fno-elide-constructors
// 0x802BB4D4 AptXmlNode::sMethod_insertBefore(AptValue*) (8B)

extern void* g_constructorObject;

struct AptXmlNode {
    static void* sMethod_insertBefore();
};

void* AptXmlNode::sMethod_insertBefore() {
    return g_constructorObject;
}
