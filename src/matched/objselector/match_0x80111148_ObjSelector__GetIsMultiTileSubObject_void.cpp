// 0x80111148 ObjSelector::GetIsMultiTileSubObject(void) (40 B)

struct MultiTileInfo {
    char pad_0000[0x14];
    short m_field14;
    short m_field16;
};

struct ObjSelector {
    char pad_0000[0x38];
    MultiTileInfo* m_info;

    int GetIsMultiTileSubObject();
};

int ObjSelector::GetIsMultiTileSubObject() {
    MultiTileInfo* info = m_info;
    return info->m_field14 != 0 && info->m_field16 != -1;
}
