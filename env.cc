#include <stdio.h>
#include <stdlib.h>

int main ()
{
   printf("PATH : %s\n", getenv("PATH"));
   printf("HOME : %s\n", getenv("HOME"));
   printf("ROOT : %s\n", getenv("ROOT"));
   printf("CEPH_BUFFER_TRACK : %s\n", getenv("CEPH_BUFFER_TRACK"));
   printf("CHECK_CEPH_BUFFER_LEN : %s\n", getenv("CHECK_CEPH_BUFFER_LEN"));

   return(0);
}
