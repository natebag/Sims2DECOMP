// 0x801E9248 GetVar_EYE_exists::Handler(char *) (36B)
//
// Copies invEYEexistsEventData[0..6] to *out. DOL emits stores in order
// stb, stw, sth; GCC reorders to stb, sth, stw. Single swap_adj fixes it.
//
// Plus source uses `unsigned short` cast (forces lhz instead of lha sign-
// extend), matching DOL's zero-extend load.
//
// ASMPROC_swap_adj: a=sth b=stw which=first

extern char invEYEexistsEventData[];

class GetVar_EYE_exists {
public:
    void Handler(char* out);
};

void GetVar_EYE_exists::Handler(char* out) {
    int* base = (int*)invEYEexistsEventData;
    int field0 = base[0];
    unsigned short field4 = *(unsigned short*)((char*)base + 4);
    char field6 = *(char*)((char*)base + 6);
    *(char*)(out + 6) = field6;
    *(int*)(out + 0) = field0;
    *(short*)(out + 4) = (short)field4;
}
