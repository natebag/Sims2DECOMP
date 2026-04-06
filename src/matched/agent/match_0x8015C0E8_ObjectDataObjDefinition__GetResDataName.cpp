// 0x8015C0E8 ObjectDataObjDefinition::GetResDataName (40b)

extern int SomeStringOp(void*);

int ObjectDataObjDefinition_GetResDataName(void* self, unsigned int a, short b, void* buf) {
    SomeStringOp(buf);
    return 0;
}
