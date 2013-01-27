#ifndef SPMUTILS_H
#define SPMUTILS_H

#include <string>

namespace llvm
{
    class Function;
    class Module;
    class Type;
}

struct FunctionCcInfo
{
    // number of bytes of stack arguments
    unsigned argsLength;

    // 0x0: none
    // 0x1: r12:r13:r14:r15
    // 0x2: r13:r14:r15
    // 0x4: r14:r15
    // 0x8: r15
    unsigned argRegsUsage;

    // number of bytes of stack reserved space for return value
    unsigned retLength;

    // 0x0: none
    // 0x1: r15:r14:r13:r12
    // 0x2: r15:r14
    // 0x4: r15
    unsigned retRegsUsage;
};

class SpmUtils
{
    public:

        static std::string getTextSection();
        static std::string getEntrySection();
        static std::string getDataSection();
        static std::string getStubName(const std::string& origName);
        static std::string getFunctionTableName();
        static std::string getStackName();
        static std::string getSpmSpName();
        static std::string getUnprotectedSpName();
        static std::string getSpmExitName();
        static FunctionCcInfo getFunctionCcInfo(llvm::Function* f);
        static unsigned getStackSize();

    private:

        static unsigned getTypeSize(llvm::Type* type, const llvm::Module* m);
};

#endif
