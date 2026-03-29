void *BIG_locateentry(void *big, char *name, int *pidx, int *poffset, int *psize);

struct FlashBigFile {
    void *m_bigFile;
    void **m_dataArray;
    void *m_texture;
    void *m_field_0C;
    void *m_field_10;
    void *m_field_14;

    void *GetDataSection(char *name);
};

void *FlashBigFile::GetDataSection(char *name)
{
    int idx, offset, size;
    BIG_locateentry(m_bigFile, name, &idx, &offset, &size);
    return m_dataArray[idx];
}
