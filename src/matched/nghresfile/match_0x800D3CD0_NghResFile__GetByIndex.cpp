/* NghResFile::GetByIndex(int, short, void (*)(void *, int)) - 0x800D3CD0 (108 bytes) */

struct NghResFileNode {
    NghResFileNode *m_next;
    void *m_data;
    unsigned short m_id;
};

struct NghResFileList {
    NghResFileNode *m_head;
};

typedef void (*NghCallback)(void *, int);

struct NghResFile {
    char _pad[0x180];
    void *m_lastByIndex;

    NghResFileList *findListByResType(unsigned int);
    void *GetByIndex(int resType, short index, NghCallback cb);
};

void *NghResFile::GetByIndex(int resType, short index, NghCallback cb)
{
    NghResFileNode *node = findListByResType(resType)->m_head;
    short count = 1;
    while (node != 0) {
        if (count == index) {
            m_lastByIndex = node;
            return node->m_data;
        }
        node = node->m_next;
        count++;
    }
    return 0;
}
