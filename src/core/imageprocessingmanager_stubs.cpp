// imageprocessingmanager_stubs.cpp - Stub implementations for Imageprocessingmanager
// Auto-generated from symbols.json - 13 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x80501DFC | 104 bytes
void ImageProcessingManager::Open(int) { }

// 0x80501E64 | 60 bytes
void ImageProcessingManager::Close(void) { }

// 0x80501EA0 | 108 bytes
void ImageProcessingManager::SetStageFilter(int, ImageProcessingManager::FilterDescriptor *) { }

// 0x80501F0C | 20 bytes
void ImageProcessingManager::SetStageCallback(int, void (*)(ETexture *)) { }

// 0x80501F20 | 60 bytes
void ImageProcessingManager::ExecuteAsync(ETexture *, ETexture *, void (*)(ETexture *)) { }

// 0x80501F5C | 620 bytes
void ImageProcessingManager::Execute(ETexture *, ETexture *) { }

// 0x805021C8 | 24 bytes
void ImageProcessingManager::HasBaseColorParam(ImageProcessingManager::eFilter) { }

// 0x805021E0 | 24 bytes
void ImageProcessingManager::HasHSVParam(ImageProcessingManager::eFilter) { }

// 0x805021F8 | 24 bytes
void ImageProcessingManager::HasThreshParam(ImageProcessingManager::eFilter) { }

// 0x80502210 | 24 bytes
void ImageProcessingManager::HasBlendParam(ImageProcessingManager::eFilter) { }

// 0x80502C94 | 8 bytes
void ImageProcessingManager::LinkTexture(unsigned int, unsigned int) { }

// 0x80502C9C | 4 bytes
void ImageProcessingManager::DummyFree(void *) { }

// 0x80502CA0 | 1384 bytes
void ImageProcessingManager::CompositeEdges(short *, short *, int, int, ImageProcessingManager::BlendParams *) { }
