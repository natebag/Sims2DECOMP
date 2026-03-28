/* cXObjectImpl::GetWallPlacementFlags(void) - 44 bytes */

struct DataArray {
    short* GetDataPtr(int index);
};

class cXObjectImpl {
public:
    char pad[0x28];
    DataArray m_dataArray;

    short GetWallPlacementFlags(void);
};

short cXObjectImpl::GetWallPlacementFlags(void) {
    short* p = m_dataArray.GetDataPtr(13);
    return *p;
}
