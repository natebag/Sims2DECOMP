// 0x80286C94 AptArray::objectMemberSet(AptValue*, EAStringC*, AptValue*) (116B) — clean
//
// AptScript member-set: if the member name parses as a numeric index, set that
// array slot (defaulting a null value to the undefined sentinel) and return 1;
// otherwise return 0. The dispatch object (this) is unused — the target array,
// name, and value arrive as explicit arguments.

struct AptValue;
extern AptValue* gpAptUndefined;          // SDA -0x5998
extern "C" int  _isIndex(char* s);        // @0x80286C48
extern "C" int  atoi(char* s);            // @0x8036E510

struct EAStringC { char* m_ptr; };

struct AptArray {
    void set(int index, AptValue* value);                                  // @0x80285FEC
    int  objectMemberSet(AptArray* a, EAStringC* name, AptValue* value);
};

int AptArray::objectMemberSet(AptArray* a, EAStringC* name, AptValue* value) {
    if (_isIndex(name->m_ptr + 8)) {
        int index = atoi(name->m_ptr + 8);
        AptValue* v = value ? value : gpAptUndefined;
        a->set(index, v);
        return 1;
    }
    return 0;
}
