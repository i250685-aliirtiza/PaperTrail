#pragma once
#include <cstddef>
#include <string>
#include "../shared/Types.hpp"
#include "OrderStatisticAVL.hpp"
namespace papertrail {
/** A Workspace-owned document. Owns working text; VersionControl owns HEAD and staging. */
class Document {
public:
    /** Creates a new document; name is copied and both timestamps begin at createdTick.
     * Caller: Workspace. Owns text and name; failure cannot publish a partial document. */
    Document(FileID id, const std::string& name, Tick createdTick);
    /** Destroys working text and metadata; VersionControl must release history separately. */
    ~Document();
    Document(const Document&) = delete;
    Document& operator=(const Document&) = delete;
    Document(Document&&) = delete;
    Document& operator=(Document&&) = delete;
    /** Returns immutable FileID, O(1); no mutation. */
    FileID getFileID() const;
    /** Returns owned name by borrowed reference; invalidated on rename/destruction. */
    const std::string& getName() const;
    /** Returns borrowed mutable working text; only VersionControl should change it. */
    OrderStatisticAVL& getText();
    /** Returns borrowed const working text; no ownership transfer. */
    const OrderStatisticAVL& getText() const;
    /** Returns number of current lines, O(1). */
    std::size_t getLineCount() const;
    /** Returns sum of line byte lengths plus one newline per line; O(N) without caching. */
    std::size_t getSizeBytes() const;
    /** Returns creation tick, O(1). */
    Tick getCreatedTick() const;
    /** Returns tick of last successful save, or creation tick if never saved, O(1). */
    Tick getModifiedTick() const;
    /** VersionControl calls after successfully publishing save; rejected saves leave tick unchanged. */
    void setModifiedTick(Tick tick);
    /** Returns starred flag; used by Workspace listing, O(1). */
    bool isStarred() const;
    /** Workspace changes metadata only after star/unstar validation. */
    void setStarred(bool starred);
    /** Returns bin flag; no mutation, O(1). */
    bool isBinned() const;
    /** Workspace changes bin flag as part of an atomic lifecycle transition. */
    void setBinned(bool binned);
    /** Workspace copies validated name on restore/rename with matching folder table update. */
    void setName(const std::string& name);
private:
    FileID id_{};
    std::string name_;
    OrderStatisticAVL text_;
    Tick created_{},modified_{};
    bool starred_{},binned_{};
};
} // namespace papertrail
