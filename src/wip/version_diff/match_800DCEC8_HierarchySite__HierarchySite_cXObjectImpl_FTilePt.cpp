/* HierarchySite::HierarchySite(cXObjectImpl *, FTilePt &, int) - 48 bytes */

struct FTilePt {
    int x;
    int y;
};

struct cXObjectImpl {
    char m_pad[0x80];
    int m_level;
};

struct HierarchySite {
    int m_type;
    FTilePt m_tilePt;
    cXObjectImpl *m_objImpl;
    int m_slot;
    int m_level;

    HierarchySite(cXObjectImpl *obj, FTilePt &tilePt, int slot);
};

HierarchySite::HierarchySite(cXObjectImpl *obj, FTilePt &tilePt, int slot) {
    m_slot = slot;
    m_objImpl = obj;
    m_tilePt = tilePt;
    m_level = obj->m_level;
    m_type = 1;
}
