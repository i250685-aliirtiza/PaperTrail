#pragma once
#include "BPlusTree.hpp"
namespace papertrail { class InvertedIndex { public: /** Adds distinct tokens from a saved line. */ StatusCode applyInsertLine(FileID,LineID,const char* text); /** Removes one saved line's postings. */ StatusCode applyDeleteLine(FileID,LineID,const char* text); /** Replaces postings for an edited saved line. */ StatusCode applyEditLine(FileID,LineID,const char* oldText,const char* newText); /** Copies all postings to a fork FileID. */ StatusCode copyDocumentPostings(FileID source,FileID destination); /** Purges one document. */ StatusCode purgeDocumentPostings(FileID); /** Exact saved-token search. */ SearchResult searchExact(const char* token) const; /** Prefix saved-token search. */ SearchResult searchPrefix(const char* prefix) const; /** Validates postings against saved content through caller callback. */ DiagnosticResult validateIndex() const; private: BPlusTree tree_; };
}
using namespace papertrail;
