// cXPersonImpl::IsCarrying - 0x8012C788 (84B)

typedef void* (*FnIsCarrying)(void*, int);

struct cXPerson_IsCarrying {
    char* m_inner;  // offset 0

    bool IsCarrying();
};

bool cXPerson_IsCarrying::IsCarrying() {
    char* a = m_inner;
    char* b = *(char**)(a + 4);
    char* vt = *(char**)(b + 4);
    short adj = *(short*)(vt + 0x2B8);
    FnIsCarrying fn = (FnIsCarrying)*(void**)(vt + 0x2BC);
    char* result = (char*)fn(b + adj, 0);
    return *(short*)(result + 4) != 0;
}
