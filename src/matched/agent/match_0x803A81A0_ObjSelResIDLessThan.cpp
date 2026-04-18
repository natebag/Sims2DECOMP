/* ObjSelResIDLessThan(ObjSelector *, ObjSelector *) at 0x803A81A0 (32B) */

struct ResEntry_ORL {
    char pad[188];
    short m_resID;
};

struct ObjSelector_ORL {
    char pad[56];
    ResEntry_ORL* m_resData;
};

bool ObjSelResIDLessThan(ObjSelector_ORL* a, ObjSelector_ORL* b) {
    return a->m_resData->m_resID < b->m_resData->m_resID;
}
