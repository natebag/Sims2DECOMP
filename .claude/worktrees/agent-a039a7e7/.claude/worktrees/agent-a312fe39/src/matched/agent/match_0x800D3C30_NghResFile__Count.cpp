/* NghResFile::Count(int) - 0x800D3C30 (68 bytes) */

struct NghResFileNode {
    NghResFileNode *m_next;
};

struct NghResFileList {
    NghResFileNode *m_head;
};

struct NghResFile {
    NghResFileList *findListByResType(unsigned int);
    short Count(int resType);
};

short NghResFile::Count(int resType)
{
    NghResFileNode *node = findListByResType(resType)->m_head;
    int count = 0;
    while (node != 0) {
        node = node->m_next;
        count++;
    }
    return (short)count;
}
