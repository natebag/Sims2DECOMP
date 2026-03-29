// 0x802BB694 (8 bytes)
class AptXmlNode {
public:
    void* operator new[](unsigned int size);
};

void* AptXmlNode::operator new[](unsigned int size) {
    return 0;
}
