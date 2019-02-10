#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void ft_printf(char *format, ...)
{
    va_list ap;
    char c, *s;
    int d;

    va_start(ap, format);
    while (*format)
    {
      while (*format != '%') //or /0 ?
      {
        write(1,format,1);
        format++;
      }
      format++; //Handle %% ?
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
            c = /*(char) */va_arg(ap, int);
            printf("char %c\n", c);
            break;
        }
        format++;
    }
    va_end(ap);
}

//add a convert() same as atoi base

int main(int ac, char **av) {
    //ft_printf("%d %s", 1, "Hey");
    printf("%-10s n\nHey","Hey");
    return (0);
}
