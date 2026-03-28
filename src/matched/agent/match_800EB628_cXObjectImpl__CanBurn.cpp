/* cXObjectImpl::CanBurn(void) - 48 bytes */

typedef unsigned short ushort;

struct FlagsData { char data[1]; };
ushort* GetFlagsPtr(FlagsData* data, int index);

class cXObjectImpl {
public:
    char pad[0x28];
    FlagsData m_flagsData;

    int CanBurn(void);
};

int cXObjectImpl::CanBurn(void) {
    ushort* ptr = GetFlagsPtr(&m_flagsData, 40);
    return (*ptr >> 5) & 1;
}
