// 0x802C9208 EMat4::Mult4x4 (48b)
void mat_mult_internal(void* src, void* dst, void* self);

void EMat4_Mult4x4(void* self, void* src, void* dst) {
    mat_mult_internal(src, dst, self);
}
