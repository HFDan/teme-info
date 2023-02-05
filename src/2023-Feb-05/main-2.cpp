#include <cstddef>
#include <fstream>
#include <cstring>

constexpr std::size_t text_size = 5000;

auto main(int argc, char** argv) -> int {
    auto fin = std::fstream("text.in", std::ios_base::in);
    auto fout = std::fstream("text.out", std::ios_base::out);
    char text[text_size + 1];
    char text_copy[text_size+1];

    char* longest_words[text_size] = {nullptr};
    std::size_t longest_words_sz = 0;

    //? Why static_cast?
    //? C arrays are super weird, as they automatically decay to pointers if you look at them wrong.
    //? Implicitly decaying a C array to a pointer is a code smell, so we do it *explicitly*
    fin.read(static_cast<char*>(text), text_size);

    strcpy(static_cast<char*>(text_copy), static_cast<char*>(text));

    // Could this be done faster? Yes
    // Am i too lazy to do it faster? Also yes
    {
        std::size_t longest_word_sz = 0;

        char* tokens[text_size] = {nullptr};
        std::size_t tokens_size = 0;

        for (char* tok = strtok(text, " \n"); tok != nullptr; tok = strtok(nullptr, " \n")) {
            tokens[tokens_size] = tok;
            tokens_size++;
        }

        for (std::size_t i = 0; i < tokens_size; i++) {
            const auto size = strlen(tokens[i]);
            if (size > longest_word_sz)
                longest_word_sz = size;
        }


        // Now follows a shitty algorithm. Don't do this at home, kids.
        // Why the fuck did i have to quit coffee???????

        for (std::size_t i = 0; i < tokens_size; i++) {
            char* const tok = tokens[i];

            if (strlen(tok) == longest_word_sz) {
                longest_words[longest_words_sz] = tok;
                longest_words_sz++;
            }
        }
    }

    for (std::size_t i = 0; i < longest_words_sz; i++) {
        const char* const word = longest_words[i];
        std::size_t sz = strlen(word);
        auto found = strstr(text_copy, word);


        // Reverse stuff
        for (std::size_t i = 0; i < sz/2; i++) {
            std::swap(found[i], found[sz-i-1]);
        }
    }

    fout << text_copy << std::endl;

    return 0;
}