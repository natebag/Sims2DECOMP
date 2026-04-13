struct ObjDef { char pad[20]; short m_tileCount; short m_tileIndex; };
struct ObjSel { char pad[56]; ObjDef* m_def; int GetIsMultiTileSubObject(); };
int ObjSel::GetIsMultiTileSubObject() {
    int r = 0;
    if (m_def->m_tileCount) {
        if (m_def->m_tileIndex != -1) r = 1;
    }
    return r;
}
