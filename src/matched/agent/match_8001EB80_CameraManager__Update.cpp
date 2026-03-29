/* CameraManager::Update(void) at 0x8001EB80 (208B) */

typedef void (*VoidFn)(void *);

struct VtableEntry {
    short delta;
    short pad;
    VoidFn func;
};

struct ESimsCam {
    char pad_000[0x44C];
    float m_rotAng;
    char pad_450[0x11C];
    VtableEntry *m_vtable;
};

struct CameraDirector;

struct EGlobal {
    char pad_000[0xE0];
    CameraDirector *m_cameraDirector;
    char pad_0E4[0x34];
    CameraDirector *m_directorP0;
    CameraDirector *m_directorP1;
    char pad_120[0x44];
    float m_field_164;
};

void EGlobal_SetCameraDirector(EGlobal *g, CameraDirector *dir);
int GameData_IsPlayerConnected(void *gd, unsigned char player);

extern EGlobal _globals;
extern char _gd[];

struct CameraManager {
    ESimsCam *m_cameras[2];

    void Update();
};

void CameraManager::Update() {
    EGlobal *g = &_globals;
    CameraDirector *savedDirector = g->m_cameraDirector;

    if (m_cameras[0] != 0) {
        EGlobal_SetCameraDirector(g, g->m_directorP0);

        ESimsCam *cam = m_cameras[0];
        VtableEntry *vt = cam->m_vtable;
        VoidFn fn = vt[2].func;
        short delta = vt[2].delta;
        fn((char *)cam + delta);

        g->m_field_164 = m_cameras[0]->m_rotAng;
    }

    if (m_cameras[1] != 0) {
        if (GameData_IsPlayerConnected(_gd, 1)) {
            EGlobal_SetCameraDirector(g, g->m_directorP1);

            ESimsCam *cam = m_cameras[1];
            VtableEntry *vt = cam->m_vtable;
            short delta = vt[2].delta;
            VoidFn fn = vt[2].func;
            fn((char *)cam + delta);
        }
    }

    EGlobal_SetCameraDirector(&_globals, savedDirector);
}
