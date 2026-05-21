// 0x8023ABEC CDirtyXmlNode::previousSibling() (76B)

class CDirtyXmlNode {
public:
    char pad0[0xC];
    CDirtyXmlNode* m_C;
    CDirtyXmlNode* previousSibling();
};

struct ParentNode {
    char pad0[0x10];
    int m_10;
    char pad14[8];
    CDirtyXmlNode** m_1C;
};

CDirtyXmlNode* CDirtyXmlNode::previousSibling() {
    ParentNode* parent = (ParentNode*)m_C;
    CDirtyXmlNode* result = 0;
    if (parent != 0) {
        int count = parent->m_10;
        if (count > 1) {
            int n = count - 1;
            CDirtyXmlNode** arr = parent->m_1C + 1;
            do {
                if (*arr == this) result = *(arr - 1);
                arr++;
            } while (--n);
        }
    }
    return result;
}
