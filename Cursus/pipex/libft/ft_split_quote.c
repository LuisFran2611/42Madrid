#include "libft.h"

static const char *skip_spaces(const char *s)
{
    while (*s == ' ' || *s == '\t')
        s++;
    return s;
}

static int count_tokens(const char *s)
{
    int count = 0;
    s = skip_spaces(s);
    while (*s)
    {
        if (*s == '\'' || *s == '\"')
        {
            char quote = *s;
            s++;
            while (*s && *s != quote)
                s++;
            if (*s)
                s++;
            count++;
        }
        else
        {
            while (*s && *s != ' ' && *s != '\t')
                s++;
            count++;
        }
        s = skip_spaces(s);
    }
    return count;
}

static int token_length(const char *s)
{
    int len = 0;
    if (*s == '\'' || *s == '\"')
    {
        char quote = *s;
        s++;
        while (*s && *s != quote)
        {
            len++;
            s++;
        }
    }
    else
    {
        while (*s && *s != ' ' && *s != '\t')
        {
            len++;
            s++;
        }
    }
    return len;
}

static char *extract_token(const char **s_ptr)
{
    const char *s = *s_ptr;
    s = skip_spaces(s);
    int len = token_length(s);
    char *token = ft_calloc(len + 1, sizeof(char));
    if (!token)
        return NULL;
    if (*s == '\'' || *s == '\"')
    {
        char quote = *s;
        s++;
        int i = 0;
        while (*s && *s != quote && i < len)
        {
            token[i++] = *s;
            s++;
        }
        if (*s == quote)
            s++;
    }
    else
    {
        int i = 0;
        while (*s && *s != ' ' && *s != '\t' && i < len)
        {
            token[i++] = *s;
            s++;
        }
    }
    token[len] = '\0'; *s_ptr = s; return token;
}
char **ft_split_quote(const char *s)
{
    char **result; int tokens, i; const char *ptr;
    if (!s)
        return NULL;
    tokens = count_tokens(s);
    result = ft_calloc(tokens + 1, sizeof(char *));
    if (!result)
        return NULL;
    i = 0; ptr = s;
    while (*ptr)
    {
        ptr = skip_spaces(ptr);
        if (!*ptr)
            break;
        result[i] = extract_token(&ptr);
        if (!result[i]) { free_char_matrix(result); return NULL; }
        i++;
    }
    result[i] = NULL;
    return result;
}
