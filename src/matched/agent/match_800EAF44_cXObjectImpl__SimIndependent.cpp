/* cXObjectImpl::SimIndependent(void) - 60 bytes */

struct DataArray {
    short* GetDataPtr(int index);
};

class cXObjectImpl {
public:
    char pad[0x28];
    DataArray m_dataArray;

    int SimIndependent(void);
};

int cXObjectImpl::SimIndependent(void) {
    short* p = m_dataArray.GetDataPtr(60);
    if (*p != 0) {
        return 1;
    }
    return 0;
}
