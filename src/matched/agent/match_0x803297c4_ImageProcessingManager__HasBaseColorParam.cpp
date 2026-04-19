// 0x803297c4 (24B) ImageProcessingManager::HasBaseColorParam(eFilter)
// Loads m_paramMask[filter], returns bit 0.
enum eFilter { eFilter_dummy };
struct ImageProcessingManager {
    static unsigned int m_paramMask[];
    static bool HasBaseColorParam(eFilter filter);
};
unsigned int ImageProcessingManager::m_paramMask[15];
bool ImageProcessingManager::HasBaseColorParam(eFilter filter) {
    return (m_paramMask[filter] >> 0) & 1;
}
