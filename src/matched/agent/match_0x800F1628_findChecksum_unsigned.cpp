// 0x800F1628 findChecksum(unsigned int, ChecksumList&) (52 B)
// FLAGS: -fno-schedule-insns
struct ChecksumNode {
    int value;        // offset 0
    char _pad[4];
    ChecksumNode* next; // offset 8
};
struct ChecksumList {
    ChecksumNode* head; // offset 0
};
int findChecksum(int target, ChecksumList& list) {
    ChecksumNode* node = list.head;
    if (!node) goto exit;
top:
    if (node->value == target) return 1;
    node = node->next;
    if (node) goto top;
exit:
    return 0;
}
