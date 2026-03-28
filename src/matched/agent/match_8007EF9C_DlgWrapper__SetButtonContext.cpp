typedef unsigned char u8;
typedef unsigned int uint;

uint strlen_func(char*);

void DlgWrapper_SetButtonContext(u8* pThis, char* ctx) {
    u8* pInner = *(u8**)(pThis + 0xAC);
    *(char**)(pInner + 0x38) = ctx;
    if (ctx != 0) {
        ctx = (char*)strlen_func(ctx);
    }
    *(uint*)(pInner + 0x3C) = (uint)ctx;
}
