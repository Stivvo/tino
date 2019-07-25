#include "Block.hpp"

core::Block::Block(std::vector<core::Group> v, int startAddress,
                   std::string name)
{
    this->v     = v;
    this->name  = name;
    this->start = startAddress;
}
std::string core::Block::getName()
{
    return name;
}
core::Group &core::Block::operator[](long unsigned i)
{
    return v[i];
}

long unsigned core::Block::getDim() const
{
    return v.size();
}

bool core::Block::operator==(const core::Block &other) const
{
    if ((name != other.name) || (v.size() != other.v.size()))
        return false;

    long unsigned i = 0;

    while (i < v.size() && v[i] == other.v[i])
        ++i;

    return i == v.size() ? true : false;
}

core::Block &core::Block::operator=(const core::Block &other)
{
    this->v = other.v;

    name = other.name;
    return *this;
}

int core::Block::getStart()
{
    return start;
}

int core::Block::getNbyte()
{
    int n = 0;

    std::for_each(v.begin(), v.end(),
                  [&n](core::Group &g) { n += g.getDim(); });

    return n;
}
