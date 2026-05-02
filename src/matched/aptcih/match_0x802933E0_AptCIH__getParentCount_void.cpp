// 0x802933E0 AptCIH::getParentCount(void) (36b)
struct AptCIH {
    char pad[0x48];
    AptCIH* parent;
    int getParentCount();
};

int AptCIH::getParentCount() {
    int count = 0;
    AptCIH* node = parent;
    if (!node) {
        return count;
    }
    do {
        node = node->parent;
        ++count;
    } while (node);
    return count;
}
