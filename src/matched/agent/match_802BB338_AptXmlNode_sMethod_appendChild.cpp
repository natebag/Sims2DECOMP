// FLAGS: -fno-elide-constructors
// 0x802BB338 AptXmlNode::sMethod_appendChild(AptValue*) (8B)

extern void* g_constructorObject;

struct AptXmlNode {
    static void* sMethod_appendChild();
};

void* AptXmlNode::sMethod_appendChild() {
    return g_constructorObject;
}
