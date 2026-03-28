struct EAStringC;
struct AptValue_OML {
    int objectMemberLookup(void* v, EAStringC* s) const;
};
int AptValue_OML::objectMemberLookup(void* v, EAStringC* s) const {
    return 0;
}
