// 0x802B6174 (76 bytes)
/* AptPrototype::objectMemberLookup(AptValue *, EAStringC *) const */

// Forward declarations
extern int EAStringC_Equals(void* self, const char* str);  /* 0x802B65C4 */
extern void* AptPrototype_lookupMember(void* self);  /* 0x802B6218 */

struct AptPrototype_MemberLookup {
    void* objectMemberLookup(void* value, void* str) const;
};

void* AptPrototype_MemberLookup::objectMemberLookup(void* value, void* str) const {
    int result = EAStringC_Equals(str, "prototype");
    if (result != 0) {
        return AptPrototype_lookupMember((void*)this);
    }
    return 0;
}
