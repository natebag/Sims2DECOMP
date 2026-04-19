/* ELiveMode::TriggerIntroCamera(CameraDirector *) at 0x8008FBD0 (44B) */

struct CamDir_TIC {
    char _pad[0x160];
    int field_160;
    char _pad2[0xdc];
    int field_240;
    char _pad3[0xdc];
    int field_320;
};

struct ELiveMode_TIC {
    char _pad[0x0c];
    int field_c;
    char _pad2[0x24];
    int field_34;
    void TriggerIntroCamera(CamDir_TIC* cam);
};

void ELiveMode_TIC::TriggerIntroCamera(CamDir_TIC* cam) {
    field_c = 1;
    if (!cam) return;
    cam->field_160 = 1;
    cam->field_240 |= 1;
    field_34 = 1;
    cam->field_320 = 1;
}
