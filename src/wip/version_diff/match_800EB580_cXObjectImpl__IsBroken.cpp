/* cXObjectImpl::IsBroken(void) - 60 bytes */

struct DataArray {
    short* GetDataPtr(int index);
};

class cXObjectImpl {
public:
    char pad[0x28];
    DataArray m_dataArray;

    int IsBroken(void);
};

int cXObjectImpl::IsBroken(void) {
    short* p = m_dataArray.GetDataPtr(15);
    if (*p != 0) {
        return 1;
    }
    return 0;
}
