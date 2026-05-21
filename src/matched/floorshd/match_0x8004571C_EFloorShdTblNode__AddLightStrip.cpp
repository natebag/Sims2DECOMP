// 0x8004571C (64B) EFloorShdTblNode::AddLightStrip(EFloorStripInfo)

struct EFloorStripInfo {
    unsigned char m_idx;
    unsigned char m_pad[3];
};

extern char g_floorShdTbl_0x80489098[];

extern "C" void AddTail__9ENodeListFUi(void*, unsigned int);

class EFloorShdTblNode {
public:
    static void AddLightStrip(EFloorStripInfo info);
};

void EFloorShdTblNode::AddLightStrip(EFloorStripInfo info) {
    unsigned int s = *(unsigned int*)&info;
    EFloorStripInfo dummy;
    *(unsigned int*)&dummy = s;
    AddTail__9ENodeListFUi(&g_floorShdTbl_0x80489098[info.m_idx * 12], s);
}
