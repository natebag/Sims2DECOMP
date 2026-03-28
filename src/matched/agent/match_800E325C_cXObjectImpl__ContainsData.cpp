/* cXObjectImpl::ContainsData(int) - 36 bytes */

struct DataArray {
    int ContainsData(int index);
};

class cXObjectImpl {
public:
    char pad[0x28];
    DataArray m_dataArray;

    int ContainsData(int index);
};

int cXObjectImpl::ContainsData(int index) {
    return m_dataArray.ContainsData(index);
}
