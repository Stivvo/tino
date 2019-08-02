#include "Byte.hpp"

core::Byte::Byte(std::vector<bool> v, std::vector<std::string> desc,
                 std::string name)
{
    this->v    = v;
    this->desc = desc;
    this->name = name;
}

std::string core::Byte::getDesc(long unsigned i)
{
    return desc[i];
}
bool core::Byte::operator[](long unsigned i)
{
    return v[i];
}

void core::Byte::set(long unsigned i)
{
    v[i] = !v[i];
}

std::string core::Byte::getName() const
{
    return name;
}

core::Byte &core::Byte::operator=(const core::Byte &other)
{
    this->v    = other.v;
    this->desc = other.desc;
    this->name = other.name;

    return *this;
}

bool core::Byte::operator==(const core::Byte &other) const
{
    if ((name != other.name) || (desc.size() != other.desc.size()))
        return false;

    unsigned long i = 0;
    while (i < 8 && v[i] == other.v[i])
        ++i;

    if (i != 8)
        return false;

    i = 0;

    while (i < desc.size() && desc[i] == other.desc[i])
        ++i;

    return i == desc.size();
}

int core::Byte::getInt()
{
    double value           = 0;
    unsigned long int cont = 0;

    for (int i = 7; i >= 0; --i)
        value += (v[cont++] ? pow(2, i) : 0);

    return static_cast<int>(value);
}

void core::Byte::setInt(int n)
{
    for (int i = 7; i >= 0; --i) {
        v[static_cast<unsigned long int>(i)] = (n > 0) && (n % 2 == 1);
        n /= 2;
    }
}
