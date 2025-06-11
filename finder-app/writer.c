#include <stdio.h>
#include <syslog.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	openlog("Writer", 0, LOG_USER);
	if (argc != 3) {
		syslog(LOG_ERR, "Invalid number of arguments.");
		return 1;
	}
	char *writefile = argv[1];
	char *writestr = argv[2];
	syslog(LOG_DEBUG, "Writing string %s to file %s", writestr, writefile);
	int fd;
	fd = creat(writefile, 0644);
	if (fd == -1) {
		syslog(LOG_ERR, "Invalid writefile.");
		return 1;
	}
	ssize_t nr;
        nr = write(fd, writestr, strlen(writestr));
	if (nr != strlen(writestr)) {
		syslog(LOG_ERR, "Error writing string.");
		return 1;
	}
	return 0;
}
