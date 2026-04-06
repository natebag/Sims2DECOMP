extern "C" void registerRefs(void*, void*);
void AptValueWithHash_RegisterReferences(void* self) {
    registerRefs((char*)self + 12, self);
}
