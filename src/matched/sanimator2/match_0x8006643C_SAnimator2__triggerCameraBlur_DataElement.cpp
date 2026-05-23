/* 0x8006643C (52 bytes) - SAnimator2::triggerCameraBlur(CameraBlurDataElement *) */
struct CameraBlurDataElement { float x, y, z, w; };
extern void* gCameraBlurTarget;
extern "C" void applyCameraBlur(void*, float, float, float, float);

struct SAnimator2 {
    void triggerCameraBlur(CameraBlurDataElement* data);
};

void SAnimator2::triggerCameraBlur(CameraBlurDataElement* data) {
    applyCameraBlur(gCameraBlurTarget, data->x, data->y, data->z, data->w);
}
