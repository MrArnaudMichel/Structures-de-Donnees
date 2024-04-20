#include "parentheses.h"
#include "containers/stack.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>


bool check_parentheses(char const *str)
{
    stack s;
    stack_init(&s, sizeof(char));
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(' || str[i] == '[')
        {
            stack_push(&s, &str[i]);
        }
        else if (str[i] == ')')
        {
            char c;
            if (s.size == 0)
            {
                stack_free(&s);
                return false;
            }
            stack_pop(&s, &c);
            if (c != '(')
            {
                stack_free(&s);
                return false;
            }
        }
        else if (str[i] == ']')
        {
            char c;
            if (s.size <= 0)
            {
                stack_free(&s);
                return false;
            }
            stack_pop(&s, &c);
            if (c != '[')
            {
                stack_free(&s);
                return false;
            }
        }
    }
    if (s.size == 0)
    {
        stack_free(&s);
        return true;
    }
    stack_free(&s);
    return false;
}
