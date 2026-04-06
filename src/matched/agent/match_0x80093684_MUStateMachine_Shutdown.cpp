// FLAGS: -fno-elide-constructors
// 0x80093684 MUStateMachine::Shutdown (60b)
void mu_clear(void*);
void mu_reset(void*);

void Shutdown_test(char* self) {
    mu_stop_all(self);
    mu_clear(self + 60);
    mu_reset(self);
}
