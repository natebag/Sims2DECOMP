// 0x8023ABE4 (8 bytes)
class CDirtyXmlNode {
public:
    int parentNode();
};

int CDirtyXmlNode::parentNode() {
    return *(int*)((char*)this + 0xC);
}
