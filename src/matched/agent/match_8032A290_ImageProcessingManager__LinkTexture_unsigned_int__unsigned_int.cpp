static int s_linkedTexture;
class ImageProcessingManager { public: int LinkTexture(unsigned int, unsigned int); };
int ImageProcessingManager::LinkTexture(unsigned int, unsigned int) { return s_linkedTexture; }
