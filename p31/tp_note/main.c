#include "containers/trie.h"
#include "algos/parentheses.h"

#include <stdio.h>
#include <stdlib.h>

/*************************************************************************/
// main
/*************************************************************************/

int main(int argc, char *argv[argc]) {
    trie t;
    trie_init(&t);

    trie_insert(&t, "chat");
    trie_insert(&t, "chien");
    trie_insert(&t, "chaton");
    trie_insert(&t, "chatte");

    printf("trie_contains : chat -> %d\n", trie_contains(&t, "chat"));   // 1
    printf("trie_contains : chien -> %d\n", trie_contains(&t, "chien")); // 1
    printf("trie_contains : lapin -> %d\n", trie_contains(&t, "lapin")); // 0
    char word[256] = "";
    trie_first_word(&t, "", word);
    printf("trie_first_word : prefix= -> %s\n", word); // chat
    trie_first_word(&t, "c", word);
    printf("trie_first_word : prefix=c -> %s\n", word); // chat
    trie_first_word(&t, "chat", word);
    printf("trie_first_word : prefix=chat -> %s\n", word); // chat
    trie_first_word(&t, "chato", word);
    printf("trie_first_word : prefix=chato -> %s\n", word); // chaton
    trie_first_word(&t, "a", word);
    printf("trie_first_word : prefix=a -> %s\n", word); // (vide)

    trie_free(&t);

    printf("check_parentheses : (abc) -> %d\n", check_parentheses("(abc)"));           // 1
    printf("check_parentheses : (abc -> %d\n", check_parentheses("(abc"));             // 0
    printf("check_parentheses : abc) -> %d\n", check_parentheses("abc)"));             // 0
    printf("check_parentheses : (ab(c)) -> %d\n", check_parentheses("(ab(c))"));       // 1
    printf("check_parentheses : ((a)(b)c) -> %d\n", check_parentheses("((a)(b)c)"));   // 1
    printf("check_parentheses : (ab()(c) -> %d\n", check_parentheses("(ab()(c)"));     // 0
    printf("check_parentheses : -> %d\n", check_parentheses(""));                      // 1
    printf("check_parentheses : (a]bc) -> %d\n", check_parentheses("(a]bc)"));         // 0
    printf("check_parentheses : [a(b)](c) -> %d\n", check_parentheses("[a(b)](c)"));   // 1
    printf("check_parentheses : a(b[]c[(]) -> %d\n", check_parentheses("a(b[]c[(])")); // 0

    return EXIT_SUCCESS;
}
