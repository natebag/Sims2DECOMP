/* fseek wrapper at 0x803C7124 (68 bytes) */

int CheckAvail(void* ctx);
void DoSeek(void* ctx);

int fseek_wrapper1(void* ctx)
{
    int result = CheckAvail(ctx);
    if (result == 0) {
        return 0;
    }
    DoSeek(ctx);
    return 1;
}
