#pragma once
#include "../shared/Results.hpp"
#include "../shared/DynamicArray.hpp"
namespace papertrail { class Document; class VersionControl; class ContentServices;
class Workspace { public:
    explicit Workspace(VersionControl& versionControl); ~Workspace(); Workspace(const Workspace&) = delete; Workspace& operator=(const Workspace&) = delete; Workspace(Workspace&&) = delete; Workspace& operator=(Workspace&&) = delete;
    void bindContentServices(ContentServices& content);
    ExplorerResult createDocument(const char* parent,const char* name,Tick tick);
    StatusCode createFolder(const char* parent,const char* name);
    ExplorerResult findDocument(const char* path) const;
    StatusCode openDocument(FileID file); Document* getCurrentDocument(); const Document* getCurrentDocument() const;
    StatusCode changeDirectory(const char* path); FolderID getCurrentDirectory() const; std::string getCurrentPath() const;
    ExplorerListResult listDirectory(const char* path,SortKey key=SortKey::Name,SortDirection direction=SortDirection::Ascending) const;
    PropertiesResult getProperties(FileID file) const; StatusCode starDocument(FileID file); StatusCode unstarDocument(FileID file);
    BinResult moveToBin(const char* path); BinListResult listRecycleBin() const; BinResult restoreFromBin(BinID bin,const char* destination,const char* name); EmptyBinResult emptyRecycleBin();
    ExplorerResult createForkDestination(FileID source,const char* name,Tick tick); StatusCode rollbackForkDestination(FileID file);
    StatusCode enumerateLiveDocuments(DynamicArray<Document*>& output) const;
    Document* getDocumentByFileID(FileID file); const Document* getDocumentByFileID(FileID file) const;
    StatusCode resetForFuzz();
private: struct Impl; Impl* implementation_{}; /* Owns FileID, FolderID, BinID counters, Document objects and FolderTree. */ VersionControl* versionControl_{}; ContentServices* content_{};
}; }
