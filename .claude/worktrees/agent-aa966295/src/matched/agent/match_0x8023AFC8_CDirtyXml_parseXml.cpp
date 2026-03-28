typedef unsigned int size_t;

int strlen_xml(char*);
void* malloc_xml(size_t);
void strcpy_xml(void*, char*);
void* ParseNode(void*, unsigned char*);
void* Parse(void*, void*, unsigned char*);

struct CDirtyXml {
    char pad0[4];
    unsigned char* m_buffer;
    char pad8[8];
    int m_parsed;
    char pad14[8];
    void** m_rootNodePtr;
    char pad20[4];

    void parseXml(char* xml);
};

void CDirtyXml::parseXml(char* xml) {
    int len = strlen_xml(xml);
    m_buffer = (unsigned char*)malloc_xml(len + 1);
    strcpy_xml(m_buffer, xml);
    m_rootNodePtr = (void**)malloc_xml(4);
    void* node = ParseNode(0, m_buffer);
    *m_rootNodePtr = node;
    m_parsed = 1;
    Parse(this, *m_rootNodePtr, m_buffer);
}
