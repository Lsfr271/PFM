#include "PFM.hpp"
#include "pfm_operators.hpp"

int main() {
    userLevel["Alice"] = USER;
    userLevel["Bob"]   = ADMIN;
    userLevel["Charlie"] = OWNER;

    PFM file1(PL_NONE);
    PFM file2(PL_MED);
    PFM file3(PL_READONLY);
    PFM file4(PL_HIDDEN);

    for (auto&[name, level] : userLevel) {
        std::cout << name << ":\n" << file2.AccessReport(level) << "\n";
    }

    PFM fileDummy;

    fileDummy.promoteToAdmin("Alice");
    fileDummy.promoteToOwner("Bob");

    for (auto&[name, level] : userLevel) {
        std::cout << name << ":\n" << file2.AccessReport(level) << "\n";
    }

    try {
        file1.setPermissions(PL_FULL, OWNER);

        std::cout << "New file1 level: " << file1.getPermissionLevel_file() << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
    }

    try {
        file2.setPermissions(PL_READONLY, USER);
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "Can USER delete file2?: " << (file2.canDeleteFile(USER) ? "Yes" : "No") << "\n";
    std::cout << "Can ADMIN see file3?: " << (file3.canSeeFile(ADMIN) ? "Yes" : "No") << "\n";
    std::cout << "Can OWNER modify file3?: " << (file3.canModifyFile(OWNER) ? "Yes" : "No") << "\n";
    std::cout << "Is file4 hidden from USER?: " << (file4.isHidden(USER) ? "Yes" : "No") << "\n";

    PFM anotherFile(PL_MED);
    
    std::cout << "file2 == anotherFile? " << (file2 == anotherFile ? "Yes" : "No") << "\n";
    std::cout << "file1 != file3? " << (file1 != file3 ? "Yes" : "No") << "\n";

    return 0;
}
