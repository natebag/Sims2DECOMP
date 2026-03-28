/* cXObjectImpl::IsOccupied(void) - 48 bytes */

typedef unsigned short ushort;

struct FlagsData {
    char pad[0x28];
};

ushort* GetFlagsPtr(FlagsData* data, int index);

class cXObjectImpl {
public:
    char pad[0x28];
    FlagsData m_flagsData;

    int IsOccupied(void);
};

int cXObjectImpl::IsOccupied(void) {
    ushort* ptr = GetFlagsPtr(&m_flagsData, 8);
    return (*ptr >> 5) & 1;
}
