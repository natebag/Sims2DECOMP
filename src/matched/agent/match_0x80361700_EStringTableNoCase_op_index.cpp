// 0x80361700 EStringTableNoCase::operator[] (40b)

extern void EStringTbl_Find(void*, void*, void*);

int EStringTableNoCase_op_index(void* self, char* key) {
    int result;
    EStringTbl_Find(self, key, &result);
    return result;
}
