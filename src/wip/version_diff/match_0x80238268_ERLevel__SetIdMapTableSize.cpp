struct ERLevel;
extern void SetIdMapTableSize_impl(ERLevel* self, int size);

void ERLevel__SetIdMapTableSize(void* self, int size) {
    SetIdMapTableSize_impl((ERLevel*)((char*)self + 0x3A264), size);
}
