extern char s_nodeNameBuf[128];

int GetNodeValue(void*, char*, int);

struct CDirtyXmlNode {
    int m_field00;
    char* m_data;
    int m_nodeType;
    char* nodeValue(void);
};

char* CDirtyXmlNode::nodeValue(void) {
    char* result = 0;
    if (m_nodeType == 3) {
        if (GetNodeValue(m_data, s_nodeNameBuf, 128) <= 0) {
            result = s_nodeNameBuf;
        }
    }
    return result;
}
