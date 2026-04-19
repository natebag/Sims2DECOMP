// 0x8032980c (24B) ImageProcessingManager::HasBlendParam(eFilter)
// Loads m_paramMask[filter], returns bit 1.
enum eFilter { eFilter_dummy };
struct ImageProcessingManager {
    static unsigned int m_paramMask[];
    static bool HasBlendParam(eFilter filter);
};
unsigned int ImageProcessingManager::m_paramMask[15];
bool ImageProcessingManager::HasBlendParam(eFilter filter) {
    return (m_paramMask[filter] >> 1) & 1;
}
