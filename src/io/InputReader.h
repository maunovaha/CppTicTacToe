#ifndef IO_INPUT_READER_H
#define IO_INPUT_READER_H

#include <iostream>
#include <limits>
#include <string>

namespace io {

class InputReader {
public:
    InputReader() = delete;

    template <typename T>
    static T read_between(const T& min, const T& max, const std::string& error_msg)
    {
        T input{};

        const bool valid_input = read_once(input) && (input >= min && input <= max);

        if (!valid_input) {
            std::cerr << error_msg << std::endl;
            return read_between<T>(min, max, error_msg);
        }

        return input;
    }

    template <typename T>
    static bool read_once(T& input)
    {
        const bool valid_input = static_cast<bool>(std::cin >> input);

        // Ensures stream is back to normal after reading invalid input.
        reset();

        return valid_input;
    }
private:
    static void reset()
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
};

}

#endif