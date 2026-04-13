// FLAGS: -fno-elide-constructors
// 0x802CA720 EMat4::ExtractAxisRotation (64b)
void quat_to_axis(void* quat, void* out);

void ExtractAxisRotation_test(void* self, void* out) {
    char quat[16];
    mat_to_quat(quat, self);
    quat_to_axis(quat, out);
}
