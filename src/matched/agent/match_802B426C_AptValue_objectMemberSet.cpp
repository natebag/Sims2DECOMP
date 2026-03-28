struct EAStringC;
struct AptValue_OMS {
    int objectMemberSet(void* v, EAStringC* s, void* val);
};
int AptValue_OMS::objectMemberSet(void* v, EAStringC* s, void* val) {
    return 0;
}
