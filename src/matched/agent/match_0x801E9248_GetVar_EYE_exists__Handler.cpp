// 0x801E9248 GetVar_EYE_exists::Handler(char *) (36 B)
// FLAGS: -fno-schedule-insns

extern char invEYEexistsEventData[];

class GetVar_EYE_exists {
public:
    void Handler(char* out);
};

void GetVar_EYE_exists::Handler(char* out) {
    int* base = (int*)invEYEexistsEventData;
    int field0 = base[0];
    char field6 = *((char*)base + 6);
    unsigned short field4 = *(unsigned short*)((char*)base + 4);
    *(char*)(out + 6) = field6;
    *(int*)(out + 0) = field0;
    *(short*)(out + 4) = (short)field4;
}
