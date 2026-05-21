// 0x800456D4 (72B) EFloorShdTblNode::AddStripToTable(int, EFloorStripInfo&)

struct EFloorStripInfo {
    unsigned char m_idx;
    unsigned char m_pad[3];
};

extern char g_otherTbl_0x80478C1C[];
extern int g_addCounter_FFFF8110;   // SDA r13-32496

extern "C" void AddTail__9ENodeListFUi(void*, unsigned int);

class EFloorShdTblNode {
public:
    static void AddStripToTable(int idx, EFloorStripInfo& info);
};

void EFloorShdTblNode::AddStripToTable(int idx, EFloorStripInfo& info) {
    unsigned int s = *(unsigned int*)&info;
    EFloorStripInfo dummy;
    *(unsigned int*)&dummy = s;
    AddTail__9ENodeListFUi(&g_otherTbl_0x80478C1C[idx * 16], s);
    g_addCounter_FFFF8110++;
}
