extern "C" void sendCmd(void*, void* cmd, int flags);
void BackgroundImpl_SendCommand(void* self, void* cmd) {
    sendCmd((char*)self + 0x368, cmd, 1);
}
