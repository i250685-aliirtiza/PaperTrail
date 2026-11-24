#pragma once
#include <string>
#include "../shared/Types.hpp"
namespace papertrail {
class Operation {
public:
    Operation();
    static Operation insert(LineID newLine,LineID anchor,const std::string& text,const std::string& author);
    static Operation remove(LineID line,LineID previous,const std::string& oldText,const std::string& oldAuthor);
    static Operation edit(LineID line,const std::string& oldText,const std::string& newText,const std::string& oldAuthor,const std::string& newAuthor);
    OperationType type() const;
    LineID lineID() const;
    LineID relatedLineID() const;
    const std::string& oldText() const;
    const std::string& newText() const;
    const std::string& oldAuthor() const;
    const std::string& newAuthor() const;
    Operation inverse() const;
private:
    OperationType type_{}; LineID line_{}; LineID related_{};
    std::string oldText_,newText_,oldAuthor_,newAuthor_;
};
}
