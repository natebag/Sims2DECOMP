/* cXObjectImpl::GetData(int) - 40 bytes */

struct DataArray {
    short* GetDataPtr(int index);
};

class cXObjectImpl {
public:
    char pad[0x28];
    DataArray m_dataArray;

    short GetData(int index);
};

short cXObjectImpl::GetData(int index) {
    short* p = m_dataArray.GetDataPtr(index);
    return *p;
}
