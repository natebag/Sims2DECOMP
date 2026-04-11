/* cXObjectImpl::GetLightingContribution(void) - 44 bytes */

struct DataArray {
    short* GetDataPtr(int index);
};

class cXObjectImpl {
public:
    char pad[0x28];
    DataArray m_dataArray;

    short GetLightingContribution(void);
};

short cXObjectImpl::GetLightingContribution(void) {
    short* p = m_dataArray.GetDataPtr(51);
    return *p;
}
