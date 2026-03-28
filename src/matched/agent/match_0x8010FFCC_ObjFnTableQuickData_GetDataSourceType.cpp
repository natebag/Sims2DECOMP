/* ObjFnTableQuickData::GetDataSourceType(void) const - 0x8010FFCC - 8 bytes */
/* li r3, 1; blr */

class ObjFnTableQuickData {
public:
    int GetDataSourceType(void) const;
};

int ObjFnTableQuickData::GetDataSourceType(void) const {
    return 1;
}
