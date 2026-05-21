// 0x8001E944 (96B) ESimsCam::ESimsCam(void)

extern char ESimsCam_vt[];

namespace E3DWindow {
extern "C" void E3DWindow_ctor(void* p);
}
namespace EAnimController_ns {
extern "C" void EAnimController_ctor(void* p);
}

class ESimsCam {
public:
    ESimsCam();
};

ESimsCam::ESimsCam() {
    *(int*)((char*)this + 1388) = (int)ESimsCam_vt;
    E3DWindow::E3DWindow_ctor((char*)this + 16);
    int i;
    for (i = 0; i < 4; i++) ;
    for (i = 0; i < 4; i++) ;
    EAnimController_ns::EAnimController_ctor((char*)this + 1224);
}
