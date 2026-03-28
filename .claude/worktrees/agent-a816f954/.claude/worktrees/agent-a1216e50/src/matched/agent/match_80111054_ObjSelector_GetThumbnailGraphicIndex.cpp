// 0x80111054 (12 bytes)
// ObjSelector::GetThumbnailGraphicIndex(void)
// lwz r9, 56(r3); lha r3, 150(r9); blr
class ObjSelector;

struct ObjSelectorData {
    char m_pad[150];
    short m_thumbnailGraphicIndex;
};

class ObjSelector {
public:
    char m_pad[56];
    ObjSelectorData* m_data;
    short GetThumbnailGraphicIndex();
};

short ObjSelector::GetThumbnailGraphicIndex() {
    return m_data->m_thumbnailGraphicIndex;
}
