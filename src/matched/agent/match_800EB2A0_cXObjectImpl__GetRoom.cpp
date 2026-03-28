/* cXObjectImpl::GetRoom(void) - 44 bytes */

struct DataArray {
    short* GetDataPtr(int index);
};

class cXObjectImpl {
public:
    char pad[0x28];
    DataArray m_dataArray;

    unsigned short GetRoom(void);
};

unsigned short cXObjectImpl::GetRoom(void) {
    short* p = m_dataArray.GetDataPtr(29);
    return *(unsigned short*)p;
}
