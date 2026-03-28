// 0x801A7B28 (12 bytes)
// get_blank_shader_id(void)
// lis r3, 0x9F93; ori r3, r3, 0xFF74; blr
// Returns constant 0x9F93FF74
unsigned int get_blank_shader_id() {
    return 0x9F93FF74;
}
