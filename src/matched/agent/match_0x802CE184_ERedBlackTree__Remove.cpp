struct RBIteratorPtrType;

struct ERedBlackTree {
    RBIteratorPtrType *Find(unsigned int key, unsigned int *out) const;
    void Remove(RBIteratorPtrType *node);
    int Remove(unsigned int key);
};

int ERedBlackTree::Remove(unsigned int key) {
    RBIteratorPtrType *node = Find(key, 0);
    if (node == 0) goto not_found;
    Remove(node);
    return 1;
not_found:
    return 0;
}
