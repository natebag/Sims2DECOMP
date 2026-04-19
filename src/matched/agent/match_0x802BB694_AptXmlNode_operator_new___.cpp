// 0x802BB694 (8B) AptXmlNode::operator new [](unsigned int)
// return 0 stub.

class AptXmlNode {
public:
    void* operator new [](unsigned int a0);
};

void* AptXmlNode::operator new [](unsigned int a0) {
    return 0;
}
