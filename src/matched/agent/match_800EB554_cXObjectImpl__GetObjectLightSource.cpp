/* cXObjectImpl::GetObjectLightSource(void) - 44 bytes */

struct DataArray {
    short* GetDataPtr(int index);
};

class cXObjectImpl {
public:
    char pad[0x28];
    DataArray m_dataArray;

    short GetObjectLightSource(void);
};

short cXObjectImpl::GetObjectLightSource(void) {
    short* p = m_dataArray.GetDataPtr(16);
    return *p;
}
