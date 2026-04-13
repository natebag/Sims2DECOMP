/* ERDataset::SafeDelete(void) - 0x803697F4 (64 bytes) */

struct ERDataset {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERDataset();
    static void SafeDelete(ERDataset *p);
};

void ERDataset::SafeDelete(ERDataset *p)
{
    if (p) {
        delete p;
    }
}
