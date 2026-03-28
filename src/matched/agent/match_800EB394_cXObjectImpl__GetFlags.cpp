/* cXObjectImpl::GetFlags(void) - 44 bytes */

struct DataArray {
    short* GetDataPtr(int index);
};

class cXObjectImpl {
public:
    char pad[0x28];
    DataArray m_dataArray;

    short GetFlags(void);
};

short cXObjectImpl::GetFlags(void) {
    short* p = m_dataArray.GetDataPtr(8);
    return *p;
}
