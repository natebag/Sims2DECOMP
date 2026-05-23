// 0x8001E2E0 CameraDirector::ProcessAnimEvents(AnimRef *, int, int) (256 B)
typedef unsigned char u8;

extern char _animman[];

u8* EResourceManager__GetRef_unsigned_int(u8* mgr, unsigned int id);
void TArray_EAnimNote__ctor(u8* self);
void TArray_EAnimNote__assign(u8* self, u8* src);
void TArray_EAnimNote__dtor(u8* self, int mode);
int CameraDirector__AnimEventHandler(u8* self, u8* animRef, u8* event, int idx);

int CameraDirector__ProcessAnimEvents_AnimRef_ptr_int_int(u8* self, u8* animRef, int lower, int upper) {
    u8 arr[12];

    u8* res = EResourceManager__GetRef_unsigned_int((u8*)_animman, *(unsigned int*)animRef);
    int count = 0;
    TArray_EAnimNote__ctor(arr);

    if (res) {
        u8* src = res + 0x88;
        count = *(int*)(src + 4);
        TArray_EAnimNote__assign(arr, src);
    }

    int end = lower + upper;
    int result = end;

    int i = 0;
    if (i < count) {
        int byte_off = 0;
        do {
            u8* data = *(u8**)arr;
            int v = *(int*)(data + byte_off);
            u8* ep = data + byte_off;
            if (v >= lower) {
                if (upper < 0 || v < end) {
                    if (CameraDirector__AnimEventHandler(self, animRef, ep, i)) {
                        data = *(u8**)arr;
                        int v2 = *(int*)(data + byte_off);
                        if (result > v2) result = v2;
                    }
                }
            }
            i++;
            byte_off += 12;
        } while (i < count);
    }

    TArray_EAnimNote__dtor(arr, 2);
    return result;
}
