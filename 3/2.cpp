#include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
 int main(int argc,char *argv[])
 {
        int fd;
        char buffer[255];
        struct flock lock;
        if(argc==1)
        {
                printf("usage: %s filename\n",argv[0]);
                return -1;
        }
        if((fd=open(argv[1],O_RDWR))==-1)
        {
                perror("open");
                exit(1);
        }
        
        lock.l_type=F_WRLCK;
        lock.l_whence=SEEK_END;
        lock.l_start=SEEK_END-100;
        lock.l_len=100;
       
        printf("press enter to set lock\n");
        getchar();
       
        printf("trying to get lock..\n");
       
        if((fcntl(fd,F_SETLK,&lock))==-1)
        {     fcntl(fd,F_GETLK,&lock);
              printf("\nFile already locked by process (pid):    \t%d\n",lock.l_pid);        
              return -1;        
        }
        
        
        
        
        printf("locked\n");
        if((lseek(fd,SEEK_END-50,SEEK_END))==-1)
        {
                perror("lseek");
                exit(1);
        }
        if((read(fd,buffer,100))==-1)
        {
                perror("read");
                exit(1);
        }
        printf("data read from file..\n");
        puts(buffer);
        printf("press enter to release lock\n");
        getchar();
        lock.l_type = F_UNLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        if((fcntl(fd,F_UNLCK,&lock))==-1)
        {
                perror("fcntl");
                exit(0);
        }
        printf("Unlocked\n");
        close(fd);
        return 0;
 }
