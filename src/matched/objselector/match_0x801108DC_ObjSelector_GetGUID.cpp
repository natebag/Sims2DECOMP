/* ObjSelector::GetGUID(void) const - 0x801108DC - 12 bytes */
/* lwz r9, 56(r3); lwz r3, 28(r9); blr */

struct ObjFnData {
    char _pad[0x1C];
    int m_guid;
};

class ObjSelector {
public:
    char _pad[0x38];
    ObjFnData* m_fnData;

    int GetGUID(void) const;
};

int ObjSelector::GetGUID(void) const {
    return m_fnData->m_guid;
}
