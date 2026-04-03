/* Behavior::GetNodeText(short, BehaviorNode *, StringBuffer &) at 0x800AB8C0 (4B) */

struct BehaviorNode;
struct StringBuffer;

struct Behavior {
    void GetNodeText(short id, BehaviorNode* node, StringBuffer* buf);
};

void Behavior::GetNodeText(short id, BehaviorNode* node, StringBuffer* buf) {
}
