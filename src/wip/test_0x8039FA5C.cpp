// 0x8039FA5C (92b) - TEST
// Linked list traversal/deletion function

struct ListNode {
    ListNode* next;
    char _pad[4];
    void* data;
};

class TargetClass {
public:
    void ProcessNode(ListNode* node);
};

extern void DeleteNode(void* node, int size);

void TargetClass::ProcessNode(ListNode* node) {
    while (node) {
        this->ProcessNode(node->next);
        ListNode* next = node->next;
        DeleteNode(node, 32);
        node = next;
    }
}
