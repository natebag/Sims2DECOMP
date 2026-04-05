void del_fn_cam(void*);
void d_CameraMotionSystem(void* self, int __in_chrg) {
    if (__in_chrg & 1) {
        del_fn_cam(self);
    }
}
