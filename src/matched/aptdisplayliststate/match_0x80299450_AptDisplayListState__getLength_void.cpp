// 0x80299450 AptDisplayListState::getLength(void) (40b)
struct AptCIH {
    char pad[0x54];
    AptCIH* next;
};

struct AptDisplayListState {
    AptCIH* head;
    int getLength();
};

int AptDisplayListState::getLength() {
    int count = 0;
    AptCIH* node = head;
    while (node) {
        node = node->next;
        ++count;
    }
    return count;
}
