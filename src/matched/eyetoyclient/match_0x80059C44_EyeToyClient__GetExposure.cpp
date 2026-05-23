// 0x80059C44 (92B) EyeToyClient::GetExposure(void)
void PlumbBob_Shutdown(void* self);

struct Physics {
    void dtor(int flag);
};

struct EyeToyClient : Physics {
    void GetExposure(int flag);
};

void EyeToyClient::GetExposure(int flag) {
    PlumbBob_Shutdown(this);
    int lo = (int)(char*)this + 372;
    if (!lo) goto call_dtor;
    {
        int hi = (int)(char*)this + 436;
        if (lo == hi) goto call_dtor;
        do { hi -= 16; } while (lo != hi);
    }
call_dtor:
    Physics::dtor(flag);
}
