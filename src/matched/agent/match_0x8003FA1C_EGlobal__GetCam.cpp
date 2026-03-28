/* EGlobal::GetCam(void) - 0x8003FA1C (8 bytes) */

struct ESimsCam;

struct EGlobal {
    char pad[0xD0];
    ESimsCam *m_cam;

    ESimsCam* GetCam();
};

ESimsCam* EGlobal::GetCam() {
    return m_cam;
}
