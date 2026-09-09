#include "cmd.h"

int _write(int fd,char *ptr,int len)
{
    int i = 0;
    /*
        Write "len" of char from "ptr" to file id "fd"
        return number of char written
        Only work for STDOUT, STDIN,STDERR
    */
   if (fd > 2)
   {
    return -1;
   }
   while (*ptr && (i < len))
   {
    if (*ptr == '\n')
    {
        usart_write_byte(USART1,'\r');
    }
    usart_write_byte(USART1,*ptr);
    i++;
    ptr++;

   }
   return i;
   

}



