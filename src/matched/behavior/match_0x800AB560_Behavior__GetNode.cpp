// FLAGS: -fno-schedule-insns
// 0x800AB560 Behavior::GetNode(short, short, BehaviorNode*) (92B)

struct BehaviorNode {
    int m_0;
    int m_4;
    int m_8;
};

class Behavior {
public:
    int GetNodeRef(short id, short subid, BehaviorNode** outRef);
    int GetNode(short id, short subid, BehaviorNode* outNode);
};

int Behavior::GetNode(short id, short subid, BehaviorNode* outNode) {
    BehaviorNode* nodePtr = 0;
    int result = GetNodeRef(id, subid, &nodePtr);
    if (result != 0) {
        int v8 = nodePtr->m_8;
        int v0 = nodePtr->m_0;
        int v4 = nodePtr->m_4;
        outNode->m_8 = v8;
        outNode->m_0 = v0;
        outNode->m_4 = v4;
    }
    return result;
}
