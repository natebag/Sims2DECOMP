/* fseek wrapper at 0x803C7168 (68 bytes) */

int CheckAvail2(void* ctx);
void DoSeek2(void* ctx);

int fseek_wrapper2(void* ctx)
{
    int result = CheckAvail2(ctx);
    if (result == 0) {
        return 0;
    }
    DoSeek2(ctx);
    return 1;
}
