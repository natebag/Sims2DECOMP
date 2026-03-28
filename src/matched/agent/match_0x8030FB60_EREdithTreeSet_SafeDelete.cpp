/* EREdithTreeSet::SafeDelete(void) - 0x8030FB60 (64 bytes) */

struct EREdithTreeSet {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~EREdithTreeSet();
    static void SafeDelete(EREdithTreeSet *p);
};

void EREdithTreeSet::SafeDelete(EREdithTreeSet *p)
{
    if (p) {
        delete p;
    }
}
