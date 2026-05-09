// 0x8000DFA8 (80B) AptLine::UnlinkWord(AptWord*)

struct AptWord {
    AptWord* m_next;
};

struct AptLine {
    char pad[4];
    AptWord* m_first;

    void UnlinkWord(AptWord* word);
};

void AptLine::UnlinkWord(AptWord* word) {
    AptWord* current = m_first;
    AptWord* prev = 0;
    while (true) {
        if (current == 0) {
            return;
        }
        if (current == word) {
            break;
        }
        prev = current;
        current = current->m_next;
    }
    if (current == 0) {
        return;
    }
    if (prev != 0) {
        prev->m_next = current->m_next;
    } else {
        m_first = current->m_next;
    }
}
