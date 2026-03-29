/* ObjectDataID::operator!=(ObjectDataID &) const at 0x8015BB9C (36B) */

extern int ObjectDataID_IsEqual(void*, void*);

int ObjectDataID_IsNotEqual(void* self, void* other) {
    return ObjectDataID_IsEqual(self, other) ^ 1;
}
