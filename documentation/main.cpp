#include "../PFM/fpm_operators.hpp"
#include "../PFM/FPM.hpp"
#include <iostream>

int main() {
    // Setup users
    userLevel["Alice"] = USER;
    userLevel["Bob"] = ADMIN;
    userLevel["Charlie"] = OWNER;

    // Create a file with no protection
    FPM file(PL_NONE);

    std::cout << "=== FPM Tutorial ===\n\n";

    // 1. Check who can see the file
    std::cout << "Can Alice see the file? "
              << (file.canSeeFile(userLevel["Alice"]) ? "Yes" : "No") << "\n";
    std::cout << "Can Bob see the file? "
              << (file.canSeeFile(userLevel["Bob"]) ? "Yes" : "No") << "\n";
    std::cout << "Can Charlie see the file? "
              << (file.canSeeFile(userLevel["Charlie"]) ? "Yes" : "No") << "\n";
    file.logAction(OWNER, "Checked who can see the file");

    // 2. Modify and rename file
    if (file.canModifyFile(userLevel["Alice"])) {
        std::cout << "Alice modifies the file.\n";
        file.logAction(USER, "Modified the file");
    }
    if (file.canRenameFile(userLevel["Bob"])) {
        std::cout << "Bob renames the file.\n";
        file.logAction(ADMIN, "Renamed the file");
    }

    // 3. Delete file
    if (file.canDeleteFile(userLevel["Alice"])) {
        std::cout << "Alice deletes the file.\n";
        file.logAction(USER, "Deleted the file");
    } else {
        std::cout << "Alice cannot delete the file.\n";
        file.logAction(USER, "Attempted to delete file but failed");
    }

    // 4. Lock and unlock the file (OWNER only)
    std::cout << "Charlie locks the file (read-only)...\n";
    file.lockFile(userLevel["Charlie"]);
    file.logAction(OWNER, "Locked the file");

    std::cout << "Charlie unlocks the file...\n";
    file.unlockFile(userLevel["Charlie"]);
    file.logAction(OWNER, "Unlocked the file");

    // 5. Change file permissions (OWNER only)
    std::cout << "Charlie sets file protection to PL_MED.\n";
    file.setPermissions(PL_MED, userLevel["Charlie"]);
    file.logAction(OWNER, "Changed file protection to PL_MED");

    // 6. Promote users
    std::cout << "Alice promoted to Admin.\n";
    file.promoteToAdmin("Alice");
    file.logAction(OWNER, "Promoted Alice to Admin");

    std::cout << "Bob promoted to Owner (Charlie demoted automatically).\n";
    file.promoteToOwner("Bob");
    file.logAction(OWNER, "Promoted Bob to Owner");

    // 7. Demote user
    std::cout << "Alice demoted to User.\n";
    file.demoteToUser("Alice");
    file.logAction(OWNER, "Demoted Alice to User");

    // 8. Check owner and full control
    std::cout << "Current owner: " << file.getOwner() << "\n";
    std::cout << "Does Bob have full control? "
              << (file.hasFullControl(userLevel["Bob"]) ? "Yes" : "No") << "\n";
    file.logAction(OWNER, "Checked owner and full control");

    // 9. Check if file is hidden or protected
    std::cout << "Is the file hidden for Alice? "
              << (file.isHidden(userLevel["Alice"]) ? "Yes" : "No") << "\n";
    std::cout << "Is the file protected? "
              << (file.isProtected() ? "Yes" : "No") << "\n";
    file.logAction(OWNER, "Checked hidden/protected status");

    // 10. Access report
    std::cout << "\nAccess Report for Bob:\n";
    std::cout << file.AccessReport(userLevel["Bob"]) << "\n";
    file.logAction(OWNER, "Viewed access report");

    // 11. View history
    std::cout << "\n--- File History ---\n";
    
    for (const auto& entry : file.getHistory()) {
        std::cout << entry << "\n";
    }

    return 0;
}
