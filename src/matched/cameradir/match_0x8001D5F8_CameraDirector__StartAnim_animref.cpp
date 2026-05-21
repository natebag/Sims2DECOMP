// 0x8001D5F8 CameraDirector::StartAnim(AnimRef*, bool, bool) (76B)

class AnimRef;

class CameraDirector {
public:
    int StartAnim(int, bool, bool);
    int StartAnim(AnimRef*, bool, bool);
};

int CameraDirector::StartAnim(AnimRef* ref, bool a, bool b) {
    int r;
    if (StartAnim(*(int*)ref, a, b) == 0) goto fail;
    *(AnimRef**)((char*)this + 544) = ref;
    r = 1;
    goto end;
fail:
    r = 0;
end:
    return r;
}
