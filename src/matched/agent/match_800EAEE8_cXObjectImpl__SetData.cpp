/* cXObjectImpl::SetData(int, short) - 36 bytes */

struct DataArray {
    void SetData(int index, short value);
};

class cXObjectImpl {
public:
    char pad[0x28];
    DataArray m_dataArray;

    void SetData(int index, short value);
};

void cXObjectImpl::SetData(int index, short value) {
    m_dataArray.SetData(index, value);
}
