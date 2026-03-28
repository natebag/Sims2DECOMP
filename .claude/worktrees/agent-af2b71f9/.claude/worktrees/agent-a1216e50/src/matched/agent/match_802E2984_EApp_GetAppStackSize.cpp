// 0x802E2984 (12 bytes) - EApp::GetAppStackSize(void)
// lis r3, 1; ori r3, r3, 0x8000; blr  =>  return 0x18000;

int EApp_GetAppStackSize() {
    return 0x18000;
}
