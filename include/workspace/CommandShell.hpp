#pragma once
#include <string>
#include "../shared/Types.hpp"
#include "../version/MergeEngine.hpp"
namespace papertrail {
class Workspace; class VersionControl; class ContentServices; class InvariantChecker; class Fuzzer;
class CommandShell : public ConflictResolver {
public:
    CommandShell(Workspace&,VersionControl&,ContentServices&,InvariantChecker&,Fuzzer&);
    ~CommandShell() override;
    StatusCode runInteractive(); StatusCode executeLine(const char* line); StatusCode runScript(const char* path); StatusCode dispatch(const char* command);
    std::string formatBreadcrumb(const std::string& path) const;
    ConflictChoice resolve(const ConflictInfo& conflict) override;
    std::string formatResult(StatusCode status) const;
    Tick currentTick() const; void requestExit(); StatusCode resetForFuzz();
private: Workspace* workspace_{}; VersionControl* versionControl_{}; ContentServices* content_{}; InvariantChecker* checker_{}; Fuzzer* fuzzer_{}; Tick tick_{}; bool exiting_{};
};
}
