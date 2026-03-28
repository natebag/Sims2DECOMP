/* ObjFnTableQuickData::SaveDataByID(ObjectDataID&) - 0x80110238 - 8 bytes */
/* li r3, 0; blr */

struct ObjectDataID;

class ObjFnTableQuickData {
public:
    int SaveDataByID(ObjectDataID& id);
};

int ObjFnTableQuickData::SaveDataByID(ObjectDataID& id) {
    return 0;
}
