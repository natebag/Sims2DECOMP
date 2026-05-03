// 0x80065B68 SAnimator2::PreloadEvents(AnimRef *) (264 B)
typedef unsigned char u8;

extern char _animman[];
extern char g_soundeventman[];
extern char g_effectsAttachmentMan[];

u8* EResourceManager__GetRef_unsigned_int(u8* mgr, unsigned int id);
void TArray_EAnimNote__ctor(u8* self);
void TArray_EAnimNote__assign(u8* self, u8* src);
void TArray_EAnimNote__dtor(u8* self, int mode);
void EResourceManager__PreloadResource_char_ptr(u8* mgr, char* name);
u8* EResourceManager__AddRef_char_ptr_EFile_ptr_int(u8* mgr, char* name, u8* efile, int flags);
void SAnimator2__PreloadBoneParticleEvent_REffectsAttachment_ptr(u8* self, u8* reff);
void EResource__DelRef_void(u8* res);

void SAnimator2__PreloadEvents_AnimRef_ptr(u8* self, u8* animRef) {
    u8 arr[12];

    u8* res = EResourceManager__GetRef_unsigned_int((u8*)_animman, *(unsigned int*)animRef);
    int count = 0;
    TArray_EAnimNote__ctor(arr);

    if (res) {
        u8* src = res + 0x88;
        count = *(int*)(src + 4);
        TArray_EAnimNote__assign(arr, src);
    }

    if (count > 0) {
        int byte_off = 0;
        do {
            u8* data = *(u8**)arr;
            u8* ep = data + byte_off;
            int event_type = *(int*)(ep + 4);
            u8* reff;
            if (event_type > 9) {
                if (event_type == 10) goto handle10;
                goto next;
            }
            if (event_type < 6) {
                if (event_type < 0) goto next;
                if (event_type <= 4) goto next;
                EResourceManager__PreloadResource_char_ptr(
                    (u8*)g_soundeventman,
                    *(char**)(ep + 8));
            }
            goto next;
        handle10:
            reff = EResourceManager__AddRef_char_ptr_EFile_ptr_int(
                (u8*)g_effectsAttachmentMan,
                *(char**)(ep + 8), 0, 0);
            if (reff) {
                SAnimator2__PreloadBoneParticleEvent_REffectsAttachment_ptr(self, reff);
                EResource__DelRef_void(reff);
            }
        next:
            byte_off += 12;
        } while (--count);
    }

    TArray_EAnimNote__dtor(arr, 2);
}
