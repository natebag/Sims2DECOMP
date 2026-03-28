/* HierarchySite::HierarchySite(PlacementSpec *) - 76 bytes */

struct FTilePt {
    int x;
    int y;
};

struct cXObjectImpl;

struct PlacementSpec {
    int m_type;
    FTilePt m_tilePt;
    cXObjectImpl *m_objImpl;
    int m_slot;
    int m_level;
};

struct HierarchySite {
    int m_type;
    FTilePt m_tilePt;
    cXObjectImpl *m_objImpl;
    int m_slot;
    int m_level;

    HierarchySite(PlacementSpec *spec);
};

HierarchySite::HierarchySite(PlacementSpec *spec) {
    m_type = spec->m_type;
    m_slot = spec->m_slot;
    if (m_slot != -1)
        m_slot = m_slot + 1;
    m_tilePt = spec->m_tilePt;
    m_level = spec->m_level;
    m_objImpl = spec->m_objImpl;
}
