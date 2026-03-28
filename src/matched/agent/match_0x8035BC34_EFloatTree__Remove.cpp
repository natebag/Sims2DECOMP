struct FTIteratorPtrType;

struct EFloatTree {
    FTIteratorPtrType *Find(float key, unsigned int *out) const;
    void Remove(FTIteratorPtrType *node);
    int Remove(float key);
};

int EFloatTree::Remove(float key) {
    FTIteratorPtrType *node = Find(key, 0);
    if (node == 0) goto not_found;
    Remove(node);
    return 1;
not_found:
    return 0;
}
