#include "ServoControl.h"
#include "ServeurTCP.h"


int main()
{
 
	/*int fd = SerialConfig("/dev/ACM0", 9600);
	int position =0;
	position = ServosGetPosition(fd, 5);
	printf("Current position is %d.\n", position);

	ServosSetTarget(fd, 5, 8000);

	close(fd);*/
	int hSocket = CreateTCPSrv();
	int hSocketDiscute = ConnectClientTCP(hSocket);
	return 0;

}
