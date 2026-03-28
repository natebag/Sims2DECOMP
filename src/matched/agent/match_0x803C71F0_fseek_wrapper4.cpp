/* fseek wrapper at 0x803C71F0 (68 bytes) */

int CheckAvail4(void* ctx);
void DoSeek4(void* ctx);

int fseek_wrapper4(void* ctx)
{
    int result = CheckAvail4(ctx);
    if (result == 0) {
        return 0;
    }
    DoSeek4(ctx);
    return 1;
}
