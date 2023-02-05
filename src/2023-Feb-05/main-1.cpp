#include <cstddef>
#include <fstream>
#include <cstring>

constexpr std::size_t text_size = 5000;

void remove_at_index(auto* const arr, const std::size_t size, const std::size_t idx) {
    for (auto i = idx; i < size-1; i++) {
        arr[i] = arr[i+1];
    }
}

auto main(int argc, char** argv) -> int {
    auto fin = std::fstream("poezie.in", std::ios_base::in);
    auto fout = std::fstream("poezie.out", std::ios_base::out);
    char text[text_size + 1];
    
    const char delims[] = {'.', ',', '!', '?'};
    
    //? Why static_cast?
    //? C arrays are super weird, as they automatically decay to pointers if you look at them wrong.
    //? Implicitly decaying a C array to a pointer is a code smell, so we do it *explicitly*
    fin.read(static_cast<char*>(text), text_size);
    
    // Iterate over every delimiter
    for (auto delim : delims) {
        
        auto found = strchr(text, delim);
        while (found != nullptr) {
            const std::size_t text_len = strlen(text);
            
            if (const std::size_t found_idx = found-text; text[found_idx+1] != '\n' && text[found_idx+1] != '\0') {
                remove_at_index(text, text_len+1, found_idx);
                found-=1; // If we found smth, we want to check for delimiters that are one next to each other
                          // Is this hacky? Yes
                          // Does it work? also yes
            }

            found = strchr(found+1, delim);
        }
    }
    
    fout << static_cast<char*>(text) << std::endl;

    return 0;
}