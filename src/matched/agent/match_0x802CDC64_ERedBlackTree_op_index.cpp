// 0x802CDC64 ERedBlackTree::operator[] (40b)

extern void ERedBlackTree_Find(void*, unsigned int, void*);

int ERedBlackTree_op_index(void* self, unsigned int key) {
    int result;
    ERedBlackTree_Find(self, key, &result);
    return result;
}
