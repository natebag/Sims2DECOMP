// FLAGS: -fno-schedule-insns
// 0x803122AC EResource::GetResName(void) (12B)
// lis r3,gName@ha; addi r3,r3,gName@l; blr  -- returns address of fixed name string
// large array forces non-SDA absolute lis/addi addressing
extern char gUnnamedResName[16];

struct EResource {
    const char* GetResName();
};

const char* EResource::GetResName() {
    return gUnnamedResName;
}
