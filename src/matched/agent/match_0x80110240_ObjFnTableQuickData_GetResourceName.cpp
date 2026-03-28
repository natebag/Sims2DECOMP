/* ObjFnTableQuickData::GetResourceName(StringBuffer&) const - 0x80110240 - 8 bytes */
/* li r3, 0; blr */

struct StringBuffer;

class ObjFnTableQuickData {
public:
    int GetResourceName(StringBuffer& buf) const;
};

int ObjFnTableQuickData::GetResourceName(StringBuffer& buf) const {
    return 0;
}
