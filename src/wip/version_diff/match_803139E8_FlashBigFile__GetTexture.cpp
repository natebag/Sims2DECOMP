struct EResource;
void EResource_AddRef(EResource *r);

struct TextureEntry {
    EResource *pTexture;
    int width;
    int height;
};

void *BIG_locateentry(void *big, char *name, int *pidx, int *poffset, int *psize);

struct FlashBigFile {
    void *m_bigFile;
    TextureEntry **m_dataArray;

    TextureEntry *GetDataSection(char *name);
    EResource *GetTexture(char *name, int &width, int &height);
};

EResource *FlashBigFile::GetTexture(char *name, int &width, int &height)
{
    TextureEntry *data = GetDataSection(name);
    EResource_AddRef(data->pTexture);
    width  = data->width;
    height = data->height;
    return data->pTexture;
}
