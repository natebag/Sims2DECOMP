// 0x803608C0 EStringRedBlackTreeNoCase::operator[] (40b)

extern void EStringRBT_Find(void*, void*, void*);

int EStringRedBlackTreeNoCase_op_index(void* self, char* key) {
    int result;
    EStringRBT_Find(self, key, &result);
    return result;
}
