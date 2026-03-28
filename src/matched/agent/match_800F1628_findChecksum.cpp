/* findChecksum(unsigned int, ChecksumList &) - 52 bytes */

struct ChecksumNode {
    unsigned int checksum;
    char pad[4];
    ChecksumNode* next;
};

struct ChecksumList {
    ChecksumNode* head;
};

int findChecksum(unsigned int target, ChecksumList* list) {
    ChecksumNode* node = list->head;
    while (node != 0) {
        if (node->checksum == target) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}
