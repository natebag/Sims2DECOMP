// 0x802B61C0 (88 bytes)
/* AptPrototype::objectMemberSet(AptValue *, EAStringC *, AptValue *) */

// Forward declarations
extern int EAStringC_Equals(void* self, const char* str);  /* 0x802B65C4 */
extern void AptPrototype_setMember(void* self, void* value);  /* 0x802B6220 */

struct AptPrototype_MemberSet {
    int objectMemberSet(void* value, void* str, void* newValue);
};

int AptPrototype_MemberSet::objectMemberSet(void* value, void* str, void* newValue) {
    int result = EAStringC_Equals(str, "prototype");
    if (result != 0) {
        AptPrototype_setMember(this, newValue);
        return 1;
    }
    return 0;
}
