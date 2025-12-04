#include "FPM.hpp"

bool operator==(const FPM& lhs, const FPM& rhs) {
    return lhs.getPermission() == rhs.getPermission();
}

bool operator!=(const FPM& lhs, const FPM& rhs){
    return !(lhs == rhs);
}

bool operator<(const FPM& lhs, const FPM& rhs)
{
    return lhs.getPermission() < rhs.getPermission();
}

bool operator>(const FPM& lhs, const FPM& rhs)
{
    return rhs < lhs;
}

bool operator<=(const FPM& lhs, const FPM& rhs)
{
    return !(lhs < rhs);
}

bool operator>=(const FPM& lhs, const FPM& rhs)
{
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& os, const FPM& f)
{
    os << f.getPermissionLevel_file();

    return os;
}

FPM &FPM::operator=(const FPM &other) {
    if (this != &other)
    {
        this->_fp = other._fp;
        this->_history = other._history;
    }

    return *this;
}
