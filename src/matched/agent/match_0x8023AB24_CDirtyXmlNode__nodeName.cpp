extern char s_nodeNameBuf[128];

int GetNodeName(void*, char*, int);

struct CDirtyXmlNode {
    int m_field00;
    char* m_data;
    int m_nodeType;
    char* nodeName(void);
};

char* CDirtyXmlNode::nodeName(void) {
    char* result = 0;
    if (m_nodeType == 1) {
        if (GetNodeName(m_data, s_nodeNameBuf, 128) <= 0) {
            result = s_nodeNameBuf;
        }
    }
    return result;
}
