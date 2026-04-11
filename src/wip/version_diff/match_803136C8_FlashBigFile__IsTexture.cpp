int strlen(const char *s);
int strcasecmp(const char *a, const char *b);

void *BIG_locateentry(void *big, char *name, int *pidx, int *poffset, int *psize);

extern char FlashBigFile_imageExt[];

struct FlashBigFile {
    void *m_bigFile;
    void **m_dataArray;

    int IsTexture(int index);
};

int FlashBigFile::IsTexture(int index)
{
    char *entry = (char *)BIG_locateentry(m_bigFile, 0, &index, 0, 0);
    int len = strlen(entry);
    if (len <= 3)
        return 0;
    int ext = len - 4;
    int match = strcasecmp(entry + ext, FlashBigFile_imageExt);
    return (match == 0) ? 1 : 0;
}
