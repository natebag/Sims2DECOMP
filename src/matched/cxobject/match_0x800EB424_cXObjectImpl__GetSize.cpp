// 0x800EB424 cXObjectImpl::GetSize (44B)

/* cXObjectImpl::GetSize(void) - 44 bytes */

struct DataArray {
    short* GetDataPtr(int index);
};

class cXObjectImpl {
public:
    char pad[0x28];
    DataArray m_dataArray;

    short GetSize(void);
};

short cXObjectImpl::GetSize(void) {
    short* p = m_dataArray.GetDataPtr(49);
    return *p;
}
