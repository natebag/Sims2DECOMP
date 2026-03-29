int strcmp(const char *a, const char *b);

extern char FlashBigFile_geomStr[];

void *BIG_locateentry(void *big, char *name, int *pidx, int *poffset, int *psize);

struct FlashBigFile {
    void *m_bigFile;
    void **m_dataArray;

    void *GetDataSection(char *name);
    void *GetGeometry(char *name);
};

void *FlashBigFile::GetGeometry(char *name)
{
    void *data = GetDataSection(name);
    if (strcmp((char *)data, FlashBigFile_geomStr) == 0)
        return data;
    return 0;
}
