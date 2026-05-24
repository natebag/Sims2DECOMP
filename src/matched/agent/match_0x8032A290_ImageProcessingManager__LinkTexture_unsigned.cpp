// FLAGS: -fno-schedule-insns
// 0x8032A290 ImageProcessingManager::LinkTexture (8B)
// lwz r3,gLinkTexture(r13)
extern int gLinkTexture;
struct ImageProcessingManager { int LinkTexture(unsigned) const; };
int ImageProcessingManager::LinkTexture(unsigned) const { return gLinkTexture; }
