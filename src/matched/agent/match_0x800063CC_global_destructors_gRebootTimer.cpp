void static_init_reboot(int, unsigned int);
void global_destructors_gRebootTimer() {
    static_init_reboot(0, 0xFFFF);
}
