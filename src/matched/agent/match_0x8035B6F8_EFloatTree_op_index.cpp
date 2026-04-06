// 0x8035B6F8 EFloatTree::operator[] (40b)

extern void EFloatTree_Find(void*, void*);

int EFloatTree_op_index(void* self, float key) {
    int result;
    EFloatTree_Find(self, &result);
    return result;
}
