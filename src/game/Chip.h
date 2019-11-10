#ifndef CHIP_H
#define CHIP_H

#include <string>
#include <ostream>

namespace game {

class Chip {
public:
    Chip(const std::string value);
    Chip(const int value);
    friend std::ostream& operator <<(std::ostream& os, const Chip& other);

    inline bool is_number() const
    {
        return (value_ != x_ && value_ != o_);
    }

    inline std::string get_value() const
    {
        return value_;
    }

    inline static Chip x()
    {
        return {x_};
    }

    inline static Chip o()
    {
        return {o_};
    }
private:
    inline static const std::string x_ = "X";
    inline static const std::string o_ = "O";

    std::string value_;
};

}

#endif