/* NghResFile::GetByID(int, short, void (*)(void *, int)) - 0x800D3C74 (84 bytes) */

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
    NghResFileList *findListByResType(unsigned int);
    void *GetByID(int resType, short id, NghCallback cb);
};

void *NghResFile::GetByID(int resType, short id, NghCallback cb)
{
    NghResFileNode *node;
    node = findListByResType(resType)->m_head;
    while (node != 0) {
        if (node->m_id == id) {
            return node->m_data;
        }
        node = node->m_next;
    }
    return 0;
}
