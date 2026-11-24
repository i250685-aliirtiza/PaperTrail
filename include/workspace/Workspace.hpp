#pragma once
#include "../shared/Results.hpp"
#include "../shared/DynamicArray.hpp"
namespace papertrail { class Document; class VersionControl; class ContentServices;
class Workspace { public:
    explicit Workspace(VersionControl& versionControl); ~Workspace();
    void bindContentServices(ContentServices& content);
    ExplorerResult createDocument(const char* parent,const char* name,Tick tick);
    StatusCode createFolder(const char* parent,const char* name);
    ExplorerResult findDocument(const char* path) const;
    StatusCode openDocument(FileID file); Document* getCurrentDocument();
    StatusCode changeDirectory(const char* path); FolderID getCurrentDirectory() const; std::string getCurrentPath() const;
    ExplorerListResult listDirectory(const char* path,SortKey key=SortKey::Name,SortDirection direction=SortDirection::Ascending) const;
    PropertiesResult getProperties(FileID file) const; StatusCode starDocument(FileID file); StatusCode unstarDocument(FileID file);
    BinResult moveToBin(const char* path); BinListResult listRecycleBin() const; BinResult restoreFromBin(BinID bin,const char* destination,const char* name); EmptyBinResult emptyRecycleBin();
    ExplorerResult createForkDestination(FileID source,const char* name); StatusCode rollbackForkDestination(FileID file);
    StatusCode enumerateLiveDocuments(DynamicArray<Document*>& output) const;
    Document* getDocumentByFileID(FileID file); const Document* getDocumentByFileID(FileID file) const;
    StatusCode resetForFuzz();
private: void* implementation_{}; VersionControl* versionControl_{}; ContentServices* content_{};
}; }
