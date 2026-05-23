typedef unsigned char u8;

extern u8* g_controllers[4];
int isActive(u8*);

int EControllerManager_FindActiveController() {
    int found = -1;
    int i = 0;
    u8** ptr = g_controllers;
    while (i <= 3) {
        if (isActive(*ptr) != 0) {
            found = i;
            break;
        }
        ptr++;
        i++;
    }
    return found;
}
