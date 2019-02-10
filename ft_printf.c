#include <stdio.h>
#include <stdarg.h>

void ft_printf(char *format, ...)
{
    va_list ap;
    int d;
    char c, *s;

    va_start(ap, format);
    while (*format)
    {
      switch (*format++) {
        case 's':              /* string */
            s = va_arg(ap, char *);
            printf("string %s\n", s);
            break;
        case 'd':              /* int */
            d = va_arg(ap, int);
            printf("int %d\n", d);
            break;
        case 'c':              /* char */
            /* need a cast here since va_arg only
               takes fully promoted types */
            c = (char) va_arg(ap, int);
            printf("char %c\n", c);
            break;
        }
    }
    va_end(ap);
}

int main(int ac, char **av) {
    ft_printf("d s", 1, "Hey");
    return (0);
}
