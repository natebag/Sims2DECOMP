// 0x80213700 InteractorModule::IsCameraDirectorInControl(int) (76B)

struct cXObject;

extern cXObject* g_cameraDirectors[];

int IsCameraDirectorInControl(int playerId) {
    cXObject* obj = g_cameraDirectors[playerId];
    if (obj == 0) {
        return 0;
    }
    int state = *(int*)((char*)obj + 352);
    if (state == 0 || state == 8) {
        return 0;
    }
    return 1;
}
