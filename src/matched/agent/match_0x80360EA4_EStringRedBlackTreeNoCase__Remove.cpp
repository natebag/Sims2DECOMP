struct SRBNCIteratorPtrType;

struct EStringRedBlackTreeNoCase {
    SRBNCIteratorPtrType *Find(char *key, unsigned int *out) const;
    void Remove(SRBNCIteratorPtrType *node);
    int Remove(char *key);
};

int EStringRedBlackTreeNoCase::Remove(char *key) {
    SRBNCIteratorPtrType *node = Find(key, 0);
    if (node == 0) goto not_found;
    Remove(node);
    return 1;
not_found:
    return 0;
}
