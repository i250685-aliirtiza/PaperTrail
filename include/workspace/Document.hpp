#pragma once
#include "../shared/Types.hpp"
#include "OrderStatisticAVL.hpp"
namespace papertrail { class Document { public: /** Constructs document metadata and an empty authoritative text tree. */ Document(FileID id,const char* name); /** Releases document-owned text and metadata. */ ~Document(); /** Returns stable file ID. */ FileID getFileID() const; /** Returns document name. */ const char* getName() const; /** Returns authoritative working text. */ OrderStatisticAVL& getText(); /** Returns read-only working text. */ const OrderStatisticAVL& getText() const; /** Returns line count. */ std::size_t getLineCount() const; /** Returns byte size. */ std::size_t getSizeBytes() const; /** Returns creation tick. */ Tick getCreatedTick() const; /** Returns modification tick. */ Tick getModifiedTick() const; /** Updates modification tick under Workspace control. */ void setModifiedTick(Tick tick); /** Reports star state. */ bool isStarred() const; /** Reports recycle-bin state. */ bool isBinned() const; private: FileID id_{}; const char* name_{}; OrderStatisticAVL text_; Tick created_{},modified_{}; bool starred_{},binned_{}; };
}
using namespace papertrail;
