// 0x8023AB80 (8 bytes)
class CDirtyXmlNode {
public:
    int nodeType();
};

int CDirtyXmlNode::nodeType() {
    return *(int*)((char*)this + 0x8);
}
