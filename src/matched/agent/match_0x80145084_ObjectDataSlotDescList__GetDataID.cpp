extern "C" void lookupData(void*, void*);
void* ObjectDataSlotDescList_GetDataID(void* self, void* desc) {
    lookupData(self, (char*)desc + 76);
    return self;
}
