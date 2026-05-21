// 0x80110C20 GetNpcShaderId(int, bool) (96B)

struct Row {
    char pad_00[4];
    int  m_id1;
    int  m_id2;
};

class EGlobal {
public:
    Row* GetRelationshipTableRow(unsigned int id);
};

extern char _globals[16];  // at 0x80475DCC — char[16] forces ADDR16_HA/LO (Tech#17)

int GetNpcShaderId(int id, bool useId2) {
    Row* row = ((EGlobal*)_globals)->GetRelationshipTableRow((unsigned int)id);
    if (row == 0) return 0;
    if (useId2 != 0) {
        int v = row->m_id2;
        if (v != 0) return v;
    }
    return row->m_id1;
}
