/* Batch of trivial 4B functions (blr only) */

// 0x800067D4 (4B) - getRealTimeClock
void getRealTimeClock(void* a, bool b) {}

// 0x80006B74 (4B) - debugSetScreenGrabPending  
void debugSetScreenGrabPending(char* a) {}

// 0x80006B78 (4B) - debugAddSavedInput
void debugAddSavedInput(void* a, int b) {}

// 0x80007424 (4B) - startSoundStream
void startSoundStream(void* a, int b) {}

// 0x80007428 (4B) - startSound
void startSound(void* a, char* b) {}

// 0x8000742C (4B) - freeSound
void freeSound(void* a) {}

// 0x80007430 (4B) - setBackgroundColour
void setBackgroundColour(unsigned int a) {}

// 0x80007434 (4B) - myassert
void myassert(char* a, char* b, unsigned int c) {}

// 0x8000744C (4B) - freeRenderingUnit
void freeRenderingUnit(void* a) {}

// 0x80009420 (4B) - hardwareInit
void hardwareInit(float a, float b) {}
