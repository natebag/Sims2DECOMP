void static_deinit_texman(int a, unsigned int b);

void global_dtor_texman() {
    static_deinit_texman(0, 0xFFFF);
}
