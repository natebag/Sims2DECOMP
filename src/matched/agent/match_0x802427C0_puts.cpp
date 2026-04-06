// 0x802427C0 puts (40b)

extern char g_stdout[4];
extern int fputs_internal(void*, const char*);

int puts(const char* str) {
    return fputs_internal(*(void**)g_stdout, str);
}
