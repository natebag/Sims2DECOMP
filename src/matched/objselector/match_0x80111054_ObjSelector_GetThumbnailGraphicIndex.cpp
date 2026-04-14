/* ObjSelector::GetThumbnailGraphicIndex(void) - 0x80111054 - 12 bytes */
/* lwz r9, 56(r3); lha r3, 0x96(r9); blr */

struct ObjFnData {
    char _pad[0x96];
    short m_thumbnailGraphicIndex;
};

class ObjSelector {
public:
    char _pad[0x38];
    ObjFnData* m_fnData;

    int GetThumbnailGraphicIndex(void);
};

int ObjSelector::GetThumbnailGraphicIndex(void) {
    return m_fnData->m_thumbnailGraphicIndex;
}
