// 0x80159DB4 ObjectDataBehaviorConstants::GetResourceName (40b)

extern int SomeStringOp(void*);

int ObjectDataBehaviorConstants_GetResourceName(void* self, void* buf) {
    SomeStringOp(buf);
    return 1;
}
