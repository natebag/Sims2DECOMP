extern "C" void lookupTree(void*, void*);
void* ObjectDataBehaviorTree_GetDataID(void* self, void* desc) {
    lookupTree(self, (char*)desc + 88);
    return self;
}
