#pragma once
#include "BPlusTree.hpp"
namespace papertrail {
class InvertedIndex { public:
    StatusCode applyInsertLine(FileID,LineID,const char* text);
    StatusCode applyDeleteLine(FileID,LineID,const char* text);
    StatusCode applyEditLine(FileID,LineID,const char* oldText,const char* newText);
    StatusCode copyDocumentPostings(FileID source,FileID destination);
    StatusCode purgeDocumentPostings(FileID);
    PostingResult searchExact(const char* token) const;
    PostingResult searchPrefix(const char* prefix) const;
    DiagnosticResult validateIndex() const;
private: BPlusTree tree_;
};
}
