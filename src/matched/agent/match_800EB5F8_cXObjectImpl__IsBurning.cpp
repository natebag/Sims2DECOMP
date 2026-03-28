/* cXObjectImpl::IsBurning(void) - 48 bytes */

typedef unsigned short ushort;

struct FlagsData { char data[1]; };
ushort* GetFlagsPtr(FlagsData* data, int index);

class cXObjectImpl {
public:
    char pad[0x28];
    FlagsData m_flagsData;

    int IsBurning(void);
};

int cXObjectImpl::IsBurning(void) {
    ushort* ptr = GetFlagsPtr(&m_flagsData, 8);
    return (*ptr >> 9) & 1;
}
