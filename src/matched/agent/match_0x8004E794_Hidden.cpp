// 0x8004E794 Hidden(unsigned int) (72B) — Tech #47 MI-vcall via vt+4, slot 0x260/0x264

extern "C" int Hidden(unsigned int handle);

int Hidden(unsigned int handle) {
    char* obj = (char*)handle;
    char* vt = *(char**)(obj + 4);
    short adj = *(short*)(vt + 0x260);
    void* fn = *(void**)(vt + 0x264);
    int ret = ((int(*)(void*, int))fn)(obj + adj, 0x22);
    if (ret != 0) return 1;
    return 0;
}
