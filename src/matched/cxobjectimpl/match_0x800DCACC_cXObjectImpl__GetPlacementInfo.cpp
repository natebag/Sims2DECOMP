// cXObjectImpl::GetPlacementInfo(FTilePt*, int*, cXObject**, short*, bool*) at 0x800DCACC (132B)

struct FTilePt { int x; int y; };

struct cXObject { char pad[4]; cXObject *m_link; };

struct cXObjectImpl;

struct PlacementSpec {
    int m_field_0;
    FTilePt m_tile;
    cXObject *m_carrier;
    char pad[2];
    short m_field_18;
    int m_field_20;
    PlacementSpec(cXObjectImpl *);
};

struct cXObjectImpl {
    void GetPlacementInfo(FTilePt *p1, int *p2, cXObject **p3, short *p4, bool *p5);
};

void cXObjectImpl::GetPlacementInfo(FTilePt *p1, int *p2, cXObject **p3, short *p4, bool *p5) {
    PlacementSpec local(this);
    *p1 = local.m_tile;
    *p2 = local.m_field_20;
    *p4 = local.m_field_18;
    cXObject *carrier = 0;
    if (local.m_carrier != 0) {
        carrier = local.m_carrier->m_link;
    }
    *p3 = carrier;
    *(int *)p5 = local.m_field_0;
}
