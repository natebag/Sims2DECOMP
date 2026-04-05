// VERSION_DIFF: callee-saved register assignment for 5 output params differs
/* cXObjectImpl::GetPlacementInfo(FTilePt *, int *, cXObject **, short *, bool *) at 0x800DCACC (132B) */
// FLAGS: -fno-elide-constructors

struct FTilePt { int x; int y; };
struct PlacementSpec { int m_bool; int m_tileX; int m_tileY; void *m_objPtr; short m_pad; short m_slot; int m_level; };

extern void PlacementSpec_ctor(PlacementSpec *, void *);

struct cXObjGPI {
    void GetPlacementInfo(FTilePt *outTile, int *outLevel, void **outObj, short *outSlot, int *outBool);
};

void cXObjGPI::GetPlacementInfo(FTilePt *outTile, int *outLevel, void **outObj, short *outSlot, int *outBool) {
    PlacementSpec spec;
    PlacementSpec_ctor(&spec, this);
    outTile->x = spec.m_tileX;
    outTile->y = spec.m_tileY;
    void *obj = 0;
    *outLevel = spec.m_level;
    *(unsigned short *)outSlot = *(unsigned short *)&spec.m_slot;
    if (spec.m_objPtr != 0) {
        obj = *(void **)((char *)spec.m_objPtr + 4);
    }
    int boolVal = spec.m_bool;
    *outObj = obj;
    *outBool = boolVal;
}
