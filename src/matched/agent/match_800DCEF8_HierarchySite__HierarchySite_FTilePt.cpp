/* HierarchySite::HierarchySite(FTilePt &, int) - 52 bytes */

struct FTilePt {
    int x;
    int y;
};

struct cXObjectImpl;

struct HierarchySite {
    int m_type;
    FTilePt m_tilePt;
    cXObjectImpl *m_objImpl;
    int m_slot;
    int m_level;

    HierarchySite(FTilePt &tilePt, int level);
};

HierarchySite::HierarchySite(FTilePt &tilePt, int level) {
    m_tilePt = tilePt;
    m_objImpl = 0;
    m_slot = -1;
    m_level = level;
    m_type = 1;
}
