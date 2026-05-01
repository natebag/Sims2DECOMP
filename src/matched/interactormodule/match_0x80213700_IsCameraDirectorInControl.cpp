// 0x80213700 InteractorModule::IsCameraDirectorInControl(int) (76B)

class EGlobal {
public:
    char pad[0x118];
    void* m_camDirArr[1];
};

extern EGlobal g_egl;  // SDA @ 0x80475DCC

namespace InteractorModule {

int IsCameraDirectorInControl(int idx) {
    void* item = g_egl.m_camDirArr[idx];
    if (item == 0) goto ret_zero;
    {
        int state = *(int*)((char*)item + 0x160);
        int x = 0;
        if (state != 0 && state != 8) x = 1;
        if (x) return 1;
    }
ret_zero:
    return 0;
}

}
