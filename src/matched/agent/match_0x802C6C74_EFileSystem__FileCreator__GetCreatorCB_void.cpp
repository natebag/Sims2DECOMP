// 0x802C6C74 EFileSystem::FileCreator::GetCreatorCB(void) (8 B)
namespace EFileSystem { struct FileCreator { unsigned m_creatorCB; unsigned GetCreatorCB(); }; }
unsigned EFileSystem::FileCreator::GetCreatorCB() { return m_creatorCB; }
