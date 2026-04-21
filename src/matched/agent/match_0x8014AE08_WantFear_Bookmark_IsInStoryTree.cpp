// 0x8014AE08 (52B) WantFear::Bookmark::IsInStoryTree(void) const

struct StoryTree;
struct StoryNode {
    char pad[2];
    unsigned short m_flags;
};

extern char g_storyTree[16];
extern StoryNode* LookupStory(StoryTree* st, unsigned short key);

namespace WantFear {
    struct Bookmark {
        unsigned short m_key;
        bool IsInStoryTree() const;
    };
}

bool WantFear::Bookmark::IsInStoryTree() const {
    StoryNode* n = LookupStory(*(StoryTree**)g_storyTree, m_key);
    return n->m_flags & 1;
}
